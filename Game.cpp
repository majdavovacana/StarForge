#include "Game.hpp"
#include <cmath>

class Spaceship : public GameObject {
private:
    sf::CircleShape shape;
    sf::Vector2f position;
    sf::Vector2f velocity;

public:
    Spaceship(float x, float y) : position(x, y), velocity(0.f, 0.f) {
        shape.setRadius(10.f);
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(position);
    }

    void update(float deltaTime) override {
        position += velocity * deltaTime;
        shape.setPosition(position);
    }

    void render(sf::RenderWindow& window) const override {
        window.draw(shape);
    }

    sf::Vector2f getPosition() const override {
        return position;
    }

    void applyForce(const sf::Vector2f& force) override {
        velocity += force;
    }
};

class Asteroid : public GameObject {
private:
    sf::CircleShape shape;
    sf::Vector2f position;
    sf::Vector2f velocity;

public:
    Asteroid(float x, float y) : position(x, y), velocity(0.f, 0.f) {
        shape.setRadius(15.f);
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(position);
    }

    void update(float deltaTime) override {
        position += velocity * deltaTime;
        shape.setPosition(position);
    }

    void render(sf::RenderWindow& window) const override {
        window.draw(shape);
    }

    sf::Vector2f getPosition() const override {
        return position;
    }

    void applyForce(const sf::Vector2f& force) override {
        velocity += force;
    }
};

Game::Game(sf::RenderWindow& win) : window(win), isRunning(false), rng(std::random_device{}()), distX(0.f, 800.f), distY(0.f, 600.f) {
    // Initialize player
    player = std::make_unique<Spaceship>(100.f, 300.f);
    // Spawn initial asteroids
    spawnAsteroids(10);
}

void Game::spawnAsteroids(int count) {
    for (int i = 0; i < count; ++i) {
        float x = distX(rng);
        float y = distY(rng);
        objects.push_back(std::make_unique<Asteroid>(x, y));
    }
}

void Game::applyGravity(GameObject& obj, float deltaTime) {
    for (const auto& well : gravityWells) {
        sf::Vector2f direction = well - obj.getPosition();
        float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        if (distance > 1.f) { // Avoid division by zero
            float forceMagnitude = 1000.f / (distance * distance); // Inverse square law
            direction /= distance; // Normalize
            obj.applyForce(direction * forceMagnitude * deltaTime);
        }
    }
}

void Game::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                isRunning = !isRunning;
            } else if (event.key.code == sf::Keyboard::R) {
                objects.clear();
                gravityWells.clear();
                player = std::make_unique<Spaceship>(100.f, 300.f);
                spawnAsteroids(10);
                isRunning = false;
            } else if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        } else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            gravityWells.emplace_back(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
        }
    }
}

void Game::update(float deltaTime) {
    if (!isRunning) return;

    // Update player
    applyGravity(*player, deltaTime);
    player->update(deltaTime);

    // Update asteroids
    for (auto& obj : objects) {
        applyGravity(*obj, deltaTime);
        obj->update(deltaTime);
    }
}

void Game::render() {
    window.clear(sf::Color::Black);

    // Render gravity wells
    for (const auto& well : gravityWells) {
        sf::CircleShape wellShape(5.f);
        wellShape.setFillColor(sf::Color::Blue);
        wellShape.setPosition(well - sf::Vector2f(5.f, 5.f));
        window.draw(wellShape);
    }

    // Render objects
    player->render(window);
    for (const auto& obj : objects) {
        obj->render(window);
    }

    window.display();
}

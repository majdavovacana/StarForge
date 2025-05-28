#ifndef GAME_HPP
#define GAME_HPP
#include "GameObject.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <random>

class Game {
private:
    sf::RenderWindow& window;
    std::vector<std::unique_ptr<GameObject>> objects;
    std::unique_ptr<GameObject> player;
    std::vector<sf::Vector2f> gravityWells;
    bool isRunning;

    // Random number generator for asteroid placement
    std::mt19937 rng;
    std::uniform_real_distribution<float> distX;
    std::uniform_real_distribution<float> distY;

    void spawnAsteroids(int count);
    void applyGravity(GameObject& obj, float deltaTime);

public:
    Game(sf::RenderWindow& win);
    void handleEvents();
    void update(float deltaTime);
    void render();
};

#endif // GAME_HPP

#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP
#include <SFML/Graphics.hpp>

class GameObject {
public:
    virtual ~GameObject() = default;
    virtual void update(float deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) const = 0;
    virtual sf::Vector2f getPosition() const = 0;
    virtual void applyForce(const sf::Vector2f& force) = 0;
};

#endif // GAME_OBJECT_HPP

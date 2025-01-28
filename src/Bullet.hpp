#pragma once

#include "IEntity.hpp"

#include <SFML/Graphics.hpp>

class Bullet : public sf::Drawable, public sf::Transformable, public IEntity
{
public:
    Bullet(sf::Vector2f position);
    void update() override;
    sf::Vector2f getPosition() const { return m_Bullet.getPosition(); }
private:
    sf::RectangleShape m_Bullet;
    float m_Size = 4.0f;
    float m_Speed = 9.0f;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
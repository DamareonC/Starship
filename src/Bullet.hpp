#pragma once

#include "IEntity.hpp"

class Bullet : public IEntity
{
public:
    Bullet(sf::Vector2f position);
    void update() override;
    void destroy() override { m_Destroyed = true; };
    bool isDestroyed() const { return m_Destroyed; };
    sf::FloatRect getGlobalBounds() const override { return m_Bullet.getGlobalBounds(); };
    sf::Vector2f getPosition() const override { return m_Bullet.getPosition(); }
private:
    sf::RectangleShape m_Bullet;
    float m_Size = 4.0F;
    float m_Speed = 9.0F;
    bool m_Destroyed = false;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
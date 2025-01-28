#pragma once

#include "IEntity.hpp"
#include "Bullet.hpp"

class Ship : public IEntity
{
public:
    Ship();
    void update() override;
private:
    sf::Texture m_Texture;
    sf::Sprite m_Sprite;
    std::vector<Bullet> m_Bullets;
    const float m_Speed = 3.0f;
    uint8_t m_CooldownUpdates = 0;

    void shoot();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
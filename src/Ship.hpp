#pragma once

#include "IEntity.hpp"
#include "Bullet.hpp"

class Ship : public IEntity
{
public:
    Ship();
    void update() override;
    void destroy() { m_Destroyed = true; };
    bool isDestroyed() { return m_Destroyed; };
    sf::FloatRect getGlobalBounds() const override { return m_Sprite.getGlobalBounds(); };
    sf::Vector2f getPosition() const override { return m_Sprite.getPosition(); };
    std::vector<Bullet>& getBullets() { return m_Bullets; };
private:
    static inline sf::Texture m_Texture = sf::Texture(std::filesystem::path("res/sprites/ship.png"));
    sf::Sprite m_Sprite;
    std::vector<Bullet> m_Bullets;
    uint32_t m_CooldownUpdates = 0;
    float m_Speed = 3.0f;
    bool m_Destroyed = false;

    void updateBullets();
    void shoot();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void drawBullets(sf::RenderTarget& target, sf::RenderStates states) const;
};
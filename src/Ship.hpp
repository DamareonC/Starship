#pragma once

#include "IEntity.hpp"
#include "Bullet.hpp"

#include <SFML/Audio.hpp>

class Ship : public IEntity
{
public:
    Ship();
    void update() override;
    void reset();
    void destroy() override { m_Destroyed = true; };
    bool isDestroyed() const override { return m_Destroyed; };
    std::vector<Bullet>& getBullets() { return m_Bullets; };
    sf::FloatRect getGlobalBounds() const override { return m_Sprite.getGlobalBounds(); };
    sf::Vector2f getPosition() const override { return m_Sprite.getPosition(); };
private:
    const sf::Texture m_TEXTURE = sf::Texture(std::filesystem::path("res/sprites/ship.png"));
    const sf::SoundBuffer m_SHOOT_SOUND_BUFFER = sf::SoundBuffer(std::filesystem::path("res/sounds/shoot.ogg"));
    sf::Sprite m_Sprite;
    sf::Sound m_ShootSound;
    std::vector<Bullet> m_Bullets;
    uint32_t m_CooldownUpdates = 0U;
    float m_Speed = 3.0F;
    bool m_Destroyed = false;

    void updateBullets();
    void shoot();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void drawBullets(sf::RenderTarget& target, sf::RenderStates states) const;
};
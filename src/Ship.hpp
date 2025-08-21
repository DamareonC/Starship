#pragma once

#include <SFML/Audio.hpp>

#include "IEntity.hpp"
#include "IPowerUp.hpp"
#include "Bullet.hpp"

class Ship : public IEntity
{
public:
    Ship();
    void update() override;
    void reset();
    void destroy() override { m_Shielded == true ? m_Shielded = false : m_Destroyed = true; };
    void setPowerUp(PowerUp powerUp);
    bool isDestroyed() const override { return m_Destroyed; };
    std::vector<Bullet>& getBullets() { return m_Bullets; };
    sf::FloatRect getGlobalBounds() const override { return m_Sprite.getGlobalBounds(); };
    sf::Vector2f getPosition() const override { return m_Sprite.getPosition(); };
private:
    const sf::Texture m_TEXTURE = sf::Texture(std::filesystem::path("res/sprites/ship.png"));
    const sf::SoundBuffer m_SHOOT_SOUND_BUFFER = sf::SoundBuffer(std::filesystem::path("res/sounds/shoot.ogg"));
    sf::Sprite m_Sprite;
    sf::CircleShape m_Shield;
    sf::Sound m_ShootSound;
    std::vector<Bullet> m_Bullets;
    uint32_t m_CooldownUpdates = 0U;
    uint32_t m_DoubleShotsLeft = 0U;
    float m_Speed = 3.0F;
    bool m_Destroyed = false;
    bool m_Shielded = false;

    void updateBullets();
    void shoot();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void drawBullets(sf::RenderTarget& target, sf::RenderStates states) const;
};
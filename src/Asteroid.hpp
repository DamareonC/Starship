#pragma once

#include "IFallingEntity.hpp"

class Asteroid : public IFallingEntity
{
public:
    Asteroid(sf::Vector2f position, float speed);
    void update() override;
    void destroy() override { IFallingEntity::destroy(); m_Destroyed = true; };
    bool isDangerous() const override { return true; };
    bool isDestroyed() const override { return m_Destroyed; };
    uint32_t getScore() const override { return 1; };
    sf::FloatRect getGlobalBounds() const override { return m_Sprite.getGlobalBounds(); };
    sf::Vector2f getPosition() const override { return m_Sprite.getPosition(); };
private:
    static inline const sf::Texture m_Texture = sf::Texture(std::filesystem::path("res/sprites/asteroid.png"));
    sf::Sprite m_Sprite;
    float m_Speed;
    bool m_Destroyed = false;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
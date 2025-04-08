#pragma once

#include "IPowerUp.hpp"

class SpeedBoost : public IPowerUp
{
public:
    SpeedBoost(const sf::Vector2f position);
    void update() override;
    void destroy() override;
    PowerUp givePowerUp() const override { return PowerUp::SPEED_BOOST; };
    bool isDestroyed() const override { return m_Destroyed; };
    sf::FloatRect getGlobalBounds() const override { return m_Sprite.getGlobalBounds(); };
    sf::Vector2f getPosition() const override { return m_Sprite.getPosition(); };
private:
    static inline const sf::Texture m_Texture = sf::Texture(std::filesystem::path("res/sprites/speed_boost.png"));
    sf::Sprite m_Sprite;
    bool m_Destroyed = false;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
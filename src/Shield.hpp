#pragma once

#include "IPowerUp.hpp"

class Shield : public IPowerUp
{
public:
    Shield(const sf::Vector2f position);
    void update() override;
    void destroy() override;
    PowerUp givePowerUp() const override { return PowerUp::SHIELD; };
    bool isDestroyed() const override { return m_Destroyed; };
    sf::FloatRect getGlobalBounds() const override { return m_Sprite.getGlobalBounds(); };
    sf::Vector2f getPosition() const override { return m_Sprite.getPosition(); };
private:
    static inline const sf::Texture m_Texture = sf::Texture(std::filesystem::path("res/sprites/shield.png"));
    sf::Sprite m_Sprite;
    bool m_Destroyed = false;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
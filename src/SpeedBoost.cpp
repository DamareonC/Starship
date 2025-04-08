#include "SpeedBoost.hpp"

SpeedBoost::SpeedBoost(const sf::Vector2f position) :
    m_Sprite(m_Texture)
{
    m_Sprite.scale(sf::Vector2f(s_SCALE_FACTOR, s_SCALE_FACTOR));
    m_Sprite.setPosition(position);
}

void SpeedBoost::update()
{
    m_Sprite.move(sf::Vector2f(0.0F, s_POWERUP_SPEED));
}

void SpeedBoost::destroy()
{
    IPowerUp::destroy();
    m_Destroyed = true;
}

void SpeedBoost::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_Sprite, states);
}
#include "Missle.hpp"

Missle::Missle(const sf::Vector2f position, const float speed) :
    m_Sprite(m_Texture),
    m_Speed(speed)
{
    m_Sprite.scale(sf::Vector2f(s_SCALE_FACTOR, s_SCALE_FACTOR));
    m_Sprite.setPosition(position);
}

void Missle::update()
{
    m_Sprite.move(sf::Vector2f(0.0F, m_Speed * 2.0F));
}

void Missle::destroy()
{
    IFallingEntity::destroy();
    m_Destroyed = true;
}

void Missle::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_Sprite, states);
}
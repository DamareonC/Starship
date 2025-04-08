#include "Bullet.hpp"

Bullet::Bullet(const sf::Vector2f position)
{
    m_Bullet.setSize(sf::Vector2f(m_Size, m_Size));
    m_Bullet.scale(sf::Vector2f(s_SCALE_FACTOR, s_SCALE_FACTOR));
    m_Bullet.setFillColor(sf::Color(255U, 127U, 0U));
    m_Bullet.setPosition(position);
}

void Bullet::update()
{
    m_Bullet.move(sf::Vector2f(0.0F, -m_Speed));
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Bullet, states);
}
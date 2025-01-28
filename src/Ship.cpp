#include "Ship.hpp"

extern unsigned int g_WindowWidth, g_WindowHeight;

#include <iostream>

using namespace std::string_view_literals;

Ship::Ship() :
    m_Texture(std::filesystem::path("res/sprites/ship.png"sv)),
    m_Sprite(m_Texture)
{
    m_Sprite.scale(sf::Vector2f(s_SCALE_FACTOR, s_SCALE_FACTOR));
    m_Bullets.reserve(20);
}

void Ship::update()
{
    if (m_CooldownUpdates > 0) m_CooldownUpdates--;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && m_Sprite.getPosition().y >= 0)
        m_Sprite.move(sf::Vector2f(0.0f, -m_Speed));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && m_Sprite.getPosition().x >= 0)
        m_Sprite.move(sf::Vector2f(-m_Speed, 0.0f));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && m_Sprite.getPosition().y <= (g_WindowHeight - (m_Sprite.getTextureRect().size.x * s_SCALE_FACTOR)))
        m_Sprite.move(sf::Vector2f(0.0f, m_Speed));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && m_Sprite.getPosition().x <= (g_WindowWidth - (m_Sprite.getTextureRect().size.x * s_SCALE_FACTOR)))
        m_Sprite.move(sf::Vector2f(m_Speed, 0.0f));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && m_CooldownUpdates == 0.0F)
    {
        shoot();
        m_CooldownUpdates = 20;
    }

    for (size_t i = 0; i < m_Bullets.size(); i++)
    {
        m_Bullets[i].update();

        if (m_Bullets[i].getPosition().y < 0)
        {
            m_Bullets.erase(m_Bullets.begin() + i);
        }
    }
}

void Ship::shoot()
{
    m_Bullets.emplace_back(sf::Vector2f(m_Sprite.getPosition().x + (6.0f * s_SCALE_FACTOR), m_Sprite.getPosition().y - (3.0f * s_SCALE_FACTOR)));
}

void Ship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Sprite, states);

    for (size_t i = 0; i < m_Bullets.size(); i++) target.draw(m_Bullets[i], states);
}
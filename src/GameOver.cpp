#include "GameOver.hpp"

inline unsigned int g_WindowWidth, g_WindowHeight;
inline const sf::Font g_FONT;

GameOver::GameOver() :
    m_Title(g_FONT, "Game Over", 48U),
    m_Restart(g_FONT, "Restart"),
    m_Quit(g_FONT, "Quit")
{
    m_Title.setFillColor(sf::Color(255U, 0U, 0U));
    m_Quit.setFillColor(sf::Color(255U, 0U, 0U));

    m_Title.setPosition(sf::Vector2f((g_WindowWidth / 2.0F) - (m_Title.getGlobalBounds().size.x / 2.0F), g_WindowHeight * 0.1F));
    m_Restart.setPosition(sf::Vector2f((g_WindowWidth / 2.0F) - (m_Restart.getGlobalBounds().size.x / 2.0F), g_WindowHeight * 0.4F));
    m_Quit.setPosition(sf::Vector2f((g_WindowWidth / 2.0F) - (m_Quit.getGlobalBounds().size.x / 2.0F), g_WindowHeight * 0.6F));
}

Screen GameOver::onClick(const sf::Vector2f clickPosition) const
{
    if (m_Restart.getGlobalBounds().contains(clickPosition))
    {
        return Screen::GAME;
    }
    else if (m_Quit.getGlobalBounds().contains(clickPosition))
    {
        return Screen::QUIT;
    }
    else
    {
        return Screen::GAME_OVER;
    }
}

void GameOver::onHover(const sf::Vector2f mousePosition)
{
    if (m_Restart.getGlobalBounds().contains(mousePosition))
    {
        m_Restart.setFillColor(sf::Color(255U, 255U, 0U));
    }
    else
    {
        m_Restart.setFillColor(sf::Color(255U, 255U, 255U));
    }

    if (m_Quit.getGlobalBounds().contains(mousePosition))
    {
        m_Quit.setFillColor(sf::Color(255U, 255U, 0U));
    }
    else
    {
        m_Quit.setFillColor(sf::Color(255U, 0U, 0U));
    }
}

void GameOver::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_Title, states);
    target.draw(m_Restart, states);
    target.draw(m_Quit, states);
}

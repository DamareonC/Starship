#include "StartMenu.hpp"

inline unsigned int g_WindowWidth, g_WindowHeight;
inline const sf::Font g_FONT;

StartMenu::StartMenu() :
    m_Title(g_FONT, "Starship", 48U),
    m_Start(g_FONT, "Start"),
    m_Quit(g_FONT, "Quit")
{
    m_Quit.setFillColor(sf::Color(255U, 0U, 0U));

    m_Title.setPosition(sf::Vector2f((g_WindowWidth / 2.0F) - (m_Title.getGlobalBounds().size.x / 2.0F), g_WindowHeight * 0.1F));
    m_Start.setPosition(sf::Vector2f((g_WindowWidth / 2.0F) - (m_Start.getGlobalBounds().size.x / 2.0F), g_WindowHeight * 0.4F));
    m_Quit.setPosition(sf::Vector2f((g_WindowWidth / 2.0F) - (m_Quit.getGlobalBounds().size.x / 2.0F), g_WindowHeight * 0.6F));
}

Screen StartMenu::onClick(const sf::Vector2f clickPosition) const
{
    if (m_Start.getGlobalBounds().contains(clickPosition))
    {
        return Screen::GAME;
    }
    else if (m_Quit.getGlobalBounds().contains(clickPosition))
    {
        return Screen::QUIT;
    }
    else
    {
        return Screen::START_MENU;
    }
}

void StartMenu::onHover(const sf::Vector2f mousePosition)
{
    if (m_Start.getGlobalBounds().contains(mousePosition))
    {
        m_Start.setFillColor(sf::Color(255U, 255U, 0U));
    }
    else
    {
        m_Start.setFillColor(sf::Color(255U, 255U, 255U));
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

void StartMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_Title, states);
    target.draw(m_Start, states);
    target.draw(m_Quit, states);
}

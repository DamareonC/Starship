#include "StartMenu.hpp"

#include <iostream>

inline unsigned int g_WindowWidth, g_WindowHeight;

StartMenu::StartMenu() :
    m_Title(m_FONT, "Starship", 48U),
    m_Start(m_FONT, "Start"),
    m_Quit(m_FONT, "Quit")
{
    m_Title.setPosition(sf::Vector2f((g_WindowWidth / 2.0F) - (m_Title.getGlobalBounds().size.x / 2.0F), g_WindowHeight * 0.1F));
    m_Start.setPosition(sf::Vector2f((g_WindowWidth / 2.0F) - (m_Start.getGlobalBounds().size.x / 2.0F), g_WindowHeight * 0.4F));
    m_Quit.setPosition(sf::Vector2f((g_WindowWidth / 2.0F) - (m_Quit.getGlobalBounds().size.x / 2.0F), g_WindowHeight * 0.6F));
}

Screen StartMenu::onClick(sf::Vector2f clickPosition) const
{
    if (m_Start.getGlobalBounds().contains(clickPosition))
        return Screen::GAME;
    else if (m_Quit.getGlobalBounds().contains(clickPosition))
        return Screen::QUIT;
    else
        return Screen::START_MENU;
}

void StartMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_Title, states);
    target.draw(m_Start, states);
    target.draw(m_Quit, states);
}

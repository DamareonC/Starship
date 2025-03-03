#pragma once

#include <SFML/Graphics.hpp>

enum class Screen
{
    QUIT = -1, START_MENU, GAME, GAME_OVER
};

class StartMenu : public sf::Drawable
{
public:
    StartMenu();
    Screen onClick(sf::Vector2f clickPosition) const;
private:
    const sf::Font m_FONT = sf::Font(std::filesystem::path("res/fonts/architext.ttf"));
    sf::Text m_Title, m_Start, m_Quit;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
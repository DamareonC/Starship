#pragma once

#include <SFML/Graphics.hpp>

enum class Screen
{
    QUIT = -1, START_MENU, GAME, GAME_OVER
};

class IMenu : public sf::Drawable
{
public:
    virtual Screen onClick(sf::Vector2f clickPosition) const = 0;
    virtual void onHover(sf::Vector2f mousePosition) = 0;
protected:
    virtual ~IMenu() = default;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};
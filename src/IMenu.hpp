#pragma once

#include <SFML/Graphics.hpp>

enum class Screen
{
    QUIT = -1, START_MENU, GAME, GAME_OVER
};

class IMenu : public sf::Drawable
{
public:
    virtual Screen onClick(const sf::Vector2f clickPosition) const = 0;
    virtual void onHover(const sf::Vector2f mousePosition) = 0;
    virtual void setMenuPosition() = 0;
protected:
    virtual ~IMenu() = default;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};
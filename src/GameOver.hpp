#pragma once

#include "IMenu.hpp"

class GameOver : public IMenu
{
public:
    GameOver();
    Screen onClick(sf::Vector2f clickPosition) const;
    void onHover(sf::Vector2f mousePosition) override;
private:
    sf::Text m_Title, m_Restart, m_Quit;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
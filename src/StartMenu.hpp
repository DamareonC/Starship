#pragma once

#include "IMenu.hpp"

class StartMenu : public IMenu
{
public:
    StartMenu();
    Screen onClick(const sf::Vector2f clickPosition) const override;
    void onHover(const sf::Vector2f mousePosition) override;
    void setMenuPosition() override;
private:
    sf::Text m_Title, m_Start, m_Quit;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
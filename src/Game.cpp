#include "Game.hpp"

void run()
{
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(g_WindowWidth, g_WindowHeight)), sf::String("Starship"), sf::Style::Close);
    window.setPosition(sf::Vector2i(window.getPosition().x / 2, window.getPosition().y / 2));

    Screen screen = Screen::START_MENU;
    StartMenu startMenu;

    Ship ship;
    Spawner spawner;
    
    const sf::Font font(std::filesystem::path("res/fonts/architext.ttf"));
    sf::Text scoreText(font), highScoreText(font);
    highScoreText.setPosition(sf::Vector2f(0.0F, 32.0F));

    readHighScore();
    
    int64_t lastTime, currentTime;
    const sf::Clock clock;

    lastTime = 0U;
    constexpr float usPerUpdate = 1000000.0F / 60.0F;
    float delta = 0.0F;

    while (window.isOpen())
    {
        switch (screen)
        {
            case Screen::START_MENU:
                renderStartMenu(window, startMenu);
                break;
            
            case Screen::GAME:
                currentTime = clock.getElapsedTime().asMicroseconds();

                if (lastTime != 0U)
                    delta += (currentTime - lastTime) / usPerUpdate;
                
                lastTime = currentTime;

                while (delta >= 1.0F)
                {
                    update(ship, spawner, scoreText, highScoreText);
                    delta--;
                }
                
                renderGame(window, ship, spawner, scoreText, highScoreText);
                break;
            
            case Screen::GAME_OVER:
                renderGameOver();
                break;
            
            default:
                window.close();
                break;
        }

        events(window, screen, startMenu);

        if (ship.isDestroyed())
            window.close();
    }

    if (g_HighScore == 0U || g_HighScore < g_Score) //g_Score and g_HighScore are included from Score.hpp
        saveHighScore();
}
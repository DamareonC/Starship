#pragma once

#include "Ship.hpp"
#include "Spawner.hpp"
#include "Score.hpp"
#include "CollisionDetector.hpp"
#include "StartMenu.hpp"
#include "GameOver.hpp"

inline unsigned int g_WindowWidth = 640U, g_WindowHeight = 480U; //Using unsigned int instead of uint32_t since SFML takes in unsigned int for Vector2u

static void update(Ship& ship, Spawner& spawner, sf::Text& scoreText, sf::Text& highScoreText, Screen& screen)
{
    ship.update();
    spawner.update();

    for (Bullet& bullet : ship.getBullets())
    {
        checkCollision(spawner.getFallingEntities(), bullet);
    }

    checkCollision(spawner.getFallingEntities(), ship);
    updateScores(scoreText, highScoreText);

    if (ship.isDestroyed())
    {
        screen = Screen::GAME_OVER;

        if (g_HighScore == 0U || g_HighScore < g_Score) //g_Score and g_HighScore are included from Score.hpp
        {
            saveHighScore();
        }

        g_Score = 0;

        ship.reset();
        spawner.reset();
    }
}

static void renderStartMenu(sf::RenderWindow& window, const StartMenu& startMenu)
{
    window.clear();

    window.draw(startMenu);

    window.display();
}

static void renderGame(sf::RenderWindow& window, const Ship& ship, const Spawner& spawner, const sf::Text& scoreText, const sf::Text& highScoreText)
{
    window.clear();

    window.draw(ship);
    window.draw(spawner);
    window.draw(scoreText);
    window.draw(highScoreText);

    window.display();
}

static void renderGameOver(sf::RenderWindow& window, const GameOver& gameOver)
{
    window.clear();

    window.draw(gameOver);

    window.display();
}

static void events(sf::RenderWindow& window, Screen& screen, StartMenu& startMenu, GameOver& gameOver, Spawner& spawner)
{
    while (const std::optional<sf::Event> event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
            continue;
        }
        if (event->is<sf::Event::Resized>())
        {
            sf::FloatRect visibleArea(sf::Vector2f(0.0F, 0.0F), sf::Vector2f(window.getSize().x, window.getSize().y));
            window.setView(sf::View(visibleArea));

            g_WindowWidth = window.getSize().x, g_WindowHeight = window.getSize().y;

            startMenu.setMenuPosition();
            gameOver.setMenuPosition();
            spawner.setSpawnRange();
        }
        if (const sf::Event::MouseButtonPressed* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
        {
            if (mouseButtonPressed->button == sf::Mouse::Button::Left)
            {
                switch (screen)
                {
                    case Screen::START_MENU:
                        screen = startMenu.onClick(sf::Vector2f(mouseButtonPressed->position.x, mouseButtonPressed->position.y));
                        break;
                    case Screen::GAME_OVER:
                        screen = gameOver.onClick(sf::Vector2f(mouseButtonPressed->position.x, mouseButtonPressed->position.y));
                        break;
                }

                if (screen == Screen::GAME)
                {
                    readHighScore();
                }
            }
        }
        if (const sf::Event::MouseMoved* mouseMoved = event->getIf<sf::Event::MouseMoved>())
        {
            switch (screen)
            {
                case Screen::START_MENU:
                    startMenu.onHover(sf::Vector2f(mouseMoved->position.x, mouseMoved->position.y));
                    break;
                case Screen::GAME_OVER:
                    gameOver.onHover(sf::Vector2f(mouseMoved->position.x, mouseMoved->position.y));
                    break;
            }
        }
    }
}
#pragma once

#include "Ship.hpp"
#include "Spawner.hpp"
#include "Score.hpp"
#include "CollisionDetector.hpp"

inline unsigned int g_WindowWidth = 640U, g_WindowHeight = 480U; //Using unsigned int instead of uint32_t since SFML takes in unsigned int for Vector2u

static void update(Ship& ship, Spawner& spawner, sf::Text& scoreText, sf::Text& highScoreText)
{
    ship.update();
    spawner.update();

    for (Bullet& bullet : ship.getBullets())
        checkCollision(spawner.getFallingEntities(), bullet);

    checkCollision(spawner.getFallingEntities(), ship);
    updateScores(scoreText, highScoreText);
}

static void render(sf::RenderWindow& window, const Ship& ship, const Spawner& spawner, const sf::Text& scoreText, const sf::Text& highScoreText)
{
    window.clear();

    window.draw(ship);
    window.draw(spawner);
    window.draw(scoreText);
    window.draw(highScoreText);

    window.display();
}

static void events(sf::RenderWindow& window)
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
        }
    }
}
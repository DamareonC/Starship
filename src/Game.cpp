#include "Ship.hpp"
#include "Spawner.hpp"
#include "CollisionDetector.hpp"

#include <iostream>

inline unsigned int g_WindowWidth = 640, g_WindowHeight = 480;
constexpr float g_UPDATES_PER_SECOND = 60.0f;

static void update(Ship& ship, Spawner& spawner)
{
    ship.update();
    spawner.update();

    for (Bullet& bullet : ship.getBullets())
        checkCollision(spawner.getFallingEntities(), bullet);

    checkCollision(spawner.getFallingEntities(), ship);
}

static void render(sf::RenderWindow& window, const Ship& ship, Spawner& spawner)
{
    window.clear();

    window.draw(ship);
    window.draw(spawner);

    window.display();
}

void run()
{
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(g_WindowWidth, g_WindowHeight)), "Starship", sf::Style::Close);
    window.setPosition(sf::Vector2i(window.getPosition().x / 2, window.getPosition().y / 2));

    Ship ship;
    Spawner spawner;
    
    int64_t lastTime, currentTime;
    const sf::Clock clock;

    lastTime = clock.getElapsedTime().asMicroseconds();
    constexpr float usPerUpdate = 1000000.0f / g_UPDATES_PER_SECOND;
    float delta = 0.0f;

    while (window.isOpen())
    {
        currentTime = clock.getElapsedTime().asMicroseconds();
        delta += (currentTime - lastTime) / usPerUpdate;
        lastTime = currentTime;

        while (delta >= 1)
        {
            update(ship, spawner);
            delta--;
        }

        render(window, ship, spawner);

        if (ship.isDestroyed())
        {
            window.close();
            continue;
        }

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
                continue;
            }
            if (event->is<sf::Event::Resized>())
            {
                sf::FloatRect visibleArea(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(window.getSize().x, window.getSize().y));
                window.setView(sf::View(visibleArea));
                g_WindowWidth = window.getSize().x, g_WindowHeight = window.getSize().y;
            }
        }
    }

    std::printf("Final Score: %u\n", g_Score);
}
#include "Ship.hpp"

inline unsigned int g_WindowWidth = 640, g_WindowHeight = 480;

void update(Ship& ship)
{
    ship.update();
}

void render(sf::RenderWindow& window, const Ship& ship)
{
    window.clear();

    window.draw(ship);

    window.display();
}

void run()
{
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(g_WindowWidth, g_WindowHeight)), "Starship", sf::Style::Close);

    Ship ship;
    
    int64_t lastTime, currentTime;
    const sf::Clock clock;

    lastTime = clock.getElapsedTime().asMicroseconds();
    constexpr float usPerUpdate = 1000000.0f / 60.0f;
    float delta = 0.0f;

    while (window.isOpen())
    {
        currentTime = clock.getElapsedTime().asMicroseconds();
        delta += (currentTime - lastTime) / usPerUpdate;
        lastTime = currentTime;

        while (delta >= 1)
        {
            update(ship);
            delta--;
        }

        render(window, ship);

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
}
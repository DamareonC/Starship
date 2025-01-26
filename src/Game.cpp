#include <SFML/Graphics.hpp>

void update()
{
    
}

void render(sf::RenderWindow& window)
{
    window.clear();

    window.display();
}

void run()
{
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(640, 480)), "Starship", sf::Style::Close);
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
            update();
            delta--;
        }

        render(window);

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
    }
}
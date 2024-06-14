#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    // Initial position
    sf::Vector2f position(200.f, 200.f);
    shape.setPosition(position);

    // Velocity
    sf::Vector2f velocity(0.1f, 0.1f); // Change these values to control the speed

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update position
        position += velocity;

        // Check for collision with window boundaries
        if (position.x <= 0 || position.x + shape.getRadius() * 2 >= window.getSize().x)
        {
            velocity.x = -velocity.x; // Reverse the horizontal direction
        }
        if (position.y <= 0 || position.y + shape.getRadius() * 2 >= window.getSize().y)
        {
            velocity.y = -velocity.y; // Reverse the vertical direction
        }

        shape.setPosition(position);

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}

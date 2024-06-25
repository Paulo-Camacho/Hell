#include <SFML/Graphics.hpp>

int main()
{
    // Create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Lava Lamp Simulation");

    // Create the circles
    sf::CircleShape circle1(50.f);
    circle1.setFillColor(sf::Color::Red);
    circle1.setPosition(100.f, 100.f);

    sf::CircleShape circle2(50.f);
    circle2.setFillColor(sf::Color::Blue);
    circle2.setPosition(200.f, 200.f);

    // Set the initial velocities
    sf::Vector2f velocity1(2.0f, 2.0f);
    sf::Vector2f velocity2(3.0f, 2.0f);

    // Limit the framerate to 60 frames per second
    window.setFramerateLimit(60);

    // Run the program as long as the window is open
    while (window.isOpen())
    {
        // Check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "Close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update the positions of the circles
        circle1.move(velocity1);
        circle2.move(velocity2);

        // Check for collisions with the window's borders for circle1
        if ((circle1.getPosition().x <= 0 && velocity1.x < 0) ||
            (circle1.getPosition().x + circle1.getRadius() * 2 >= window.getSize().x && velocity1.x > 0))
        {
            velocity1.x = -velocity1.x;
        }
        if ((circle1.getPosition().y <= 0 && velocity1.y < 0) ||
            (circle1.getPosition().y + circle1.getRadius() * 2 >= window.getSize().y && velocity1.y > 0))
        {
            velocity1.y = -velocity1.y;
        }

        // Check for collisions with the window's borders for circle2
        if ((circle2.getPosition().x <= 0 && velocity2.x < 0) ||
            (circle2.getPosition().x + circle2.getRadius() * 2 >= window.getSize().x && velocity2.x > 0))
        {
            velocity2.x = -velocity2.x;
        }
        if ((circle2.getPosition().y <= 0 && velocity2.y < 0) ||
            (circle2.getPosition().y + circle2.getRadius() * 2 >= window.getSize().y && velocity2.y > 0))
        {
            velocity2.y = -velocity2.y;
        }

        // Clear the window with black color
        window.clear(sf::Color::Black);

        // Draw the circles
        window.draw(circle1);
        window.draw(circle2);

        // End the current frame
        window.display();
    }

    return 0;
}

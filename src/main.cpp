#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test Window");

    // Create a circle shape
    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(375, 275); // Center of the window

    // Clock for animation
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Clear the window
        window.clear(sf::Color::Black);

        // Animate the circle
        float time = clock.getElapsedTime().asSeconds();


        // Draw the circle
        window.draw(circle);

        // Display the contents
        window.display();
    }

    return 0;
}

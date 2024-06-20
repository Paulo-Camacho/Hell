#include <SFML/Graphics.hpp>

int main() {
    // Create a window with the title "SFML Window"
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    // Create a circle shape with radius 50
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(375, 275); // Center the circle in the window

    // Main loop to keep the window open
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window button clicked
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window with a black color
        window.clear(sf::Color::Black);

        // Draw the circle
        window.draw(circle);

        // Display what has been drawn on the window so far
        window.display();
    }

    return 0;
}

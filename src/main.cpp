#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

int main() {
    std::cout << "Cout worked!" << std::endl;

    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML GAME");
    window.setFramerateLimit(60);

    // Loading font
    sf::Font font;
    std::string homeDir = std::getenv("HOME");
    std::string fontPath = homeDir + "/Projects/Hell/assets/JetBrainsMonoNerdFont.ttf";

    if (!font.loadFromFile(fontPath)) {
        std::cerr << "Failed to load font from: " << fontPath << std::endl;
        return -1;
    }

    sf::Text text;
    text.setFont(font);
    text.setString("CENTER ME!");

    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color(0, 0, 255));
    circle.setPosition(200.f, 200.f); // Set the position of the circle

    sf::Vector2f velocity(5.f, 10.f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Get the bounding box of the circle
        sf::FloatRect bounds = circle.getGlobalBounds();
        // Check for collisions with the edges of the window
        if (bounds.left <= 0 || bounds.left + bounds.width >= window.getSize().x) {
            velocity.x = -velocity.x; // Reverse x velocity
        }
        if (bounds.top <= 0 || bounds.top + bounds.height >= window.getSize().y) {
            velocity.y = -velocity.y; // Reverse y velocity
        }

        // Update the circle's position
        circle.move(velocity);


        window.clear();
        window.draw(circle);
        window.draw(text);
        window.display();
    }

    return 0;
}

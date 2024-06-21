#include <SFML/Graphics.hpp>
#include <cmath>

// Constants
const int WINDOW_WIDTH = 400;
const int WINDOW_HEIGHT = 400;
const float RADIUS = 20.0f;
const float VELOCITY = 100.0f; // pixels per second

struct Circle {
    sf::CircleShape shape;
    sf::Vector2f velocity;

    Circle(float x, float y, float vx, float vy) {
        shape.setRadius(RADIUS);
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(x, y);
        velocity = sf::Vector2f(vx, vy);
    }

    void move(float deltaTime) {
        shape.move(velocity * deltaTime);

        // Bounce off the walls
        if (left() < 0 || right() > WINDOW_WIDTH) {
            velocity.x = -velocity.x;
        }
        if (top() < 0 || bottom() > WINDOW_HEIGHT) {
            velocity.y = -velocity.y;
        }
    }

    float left() const { return shape.getPosition().x; }
    float right() const { return shape.getPosition().x + shape.getRadius() * 2; }
    float top() const { return shape.getPosition().y; }
    float bottom() const { return shape.getPosition().y + shape.getRadius() * 2; }
};

bool isColliding(const Circle& a, const Circle& b) {
    return std::sqrt(std::pow(b.shape.getPosition().x - a.shape.getPosition().x, 2) +
                     std::pow(b.shape.getPosition().y - a.shape.getPosition().y, 2)) <= 2 * RADIUS;
}

void resolveCollision(Circle& a, Circle& b) {
    sf::Vector2f delta = b.shape.getPosition() - a.shape.getPosition();
    float distance = std::sqrt(delta.x * delta.x + delta.y * delta.y);
    sf::Vector2f mtd = delta * ((2 * RADIUS - distance) / distance);

    // Push-pull circles apart
    a.shape.move(-mtd / 2.0f);
    b.shape.move(mtd / 2.0f);

    // Reflect velocities
    sf::Vector2f vDelta = b.velocity - a.velocity;
    float dotProduct = (delta.x * vDelta.x + delta.y * vDelta.y) / distance;

    if (dotProduct > 0.0f) {
        sf::Vector2f collisionScale = delta * (dotProduct / distance);
        a.velocity += collisionScale;
        b.velocity -= collisionScale;
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Bouncing Circles");

    Circle circle1(100, 100, VELOCITY, VELOCITY);
    Circle circle2(200, 200, -VELOCITY, -VELOCITY);

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        float deltaTime = clock.restart().asSeconds();

        circle1.move(deltaTime);
        circle2.move(deltaTime);

        if (isColliding(circle1, circle2)) {
            resolveCollision(circle1, circle2);
        }

        window.clear();
        window.draw(circle1.shape);
        window.draw(circle2.shape);
        window.display();
    }

    return 0;
}

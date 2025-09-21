
#include "SFML\Graphics.hpp"
int main() {
	sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "Studsa");
	window.setFramerateLimit(60);

	sf::CircleShape cirkel;
	sf::Vector2f startposition(600,370);
	cirkel.setFillColor(sf::Color::Green);
	cirkel.setPosition(startposition);
	cirkel.setRadius(50);

	//Physics variables
	float xVelocity = 6;
	float yVelocity = 6;



	while (window.isOpen()) {
		

		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
		}

		//movement
		startposition.x += xVelocity;
		startposition.y += yVelocity;
		
		cirkel.setPosition(startposition);
		if (startposition.x > 1190 || startposition.x < 0) xVelocity*= -1;
		if (startposition.y > 630 || startposition.y < 0) yVelocity *= -1;

		//render
		window.clear(sf::Color::Blue);
		window.draw(cirkel);
		window.display();

	}

	return 0;
}
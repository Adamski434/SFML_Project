
#include "SFML\Graphics.hpp"
#include <iostream>
#include <cmath>
int main() {
	sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "Studsa");
	window.setFramerateLimit(60);

	sf::CircleShape cirkel;
	sf::Vector2f startposition(600,370);
	cirkel.setFillColor(sf::Color::Green);
	cirkel.setPosition(startposition);
	cirkel.setRadius(50);
	cirkel.setOrigin({ 50,50 });

	sf::CircleShape Evilcirkel;
	sf::Vector2f Evilstartposition(0, 0);
	Evilcirkel.setFillColor(sf::Color::Magenta);
	Evilcirkel.setPosition({0,0});
	Evilcirkel.setRadius(50);
	Evilcirkel.setOrigin({ 50,50 });

	//Physics variables
	float xVelocity = 6;
	float yVelocity = 6;
	float Evil_xVelocity = 10;
	float Evil_yVelocity = 10;



	while (window.isOpen()) {
		

		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
		}

		//movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) { startposition.y -= yVelocity; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			startposition.y += yVelocity;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			startposition.x += xVelocity;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			startposition.x -= xVelocity;
		}
		
		cirkel.setPosition(startposition);
		
		if (startposition.x > 1190 || startposition.x < 0) xVelocity*= -1;
		if (startposition.y > 630 || startposition.y < 0) yVelocity *= -1;

		Evilstartposition.x += Evil_xVelocity;
		Evilstartposition.y += Evil_yVelocity;
		Evilcirkel.setPosition(Evilstartposition);


		sf::Vector2f bajs = cirkel.getGeometricCenter();
		sf::Vector2f bajs2 = Evilcirkel.getGeometricCenter();



		if (Evilstartposition.x > 1190 || Evilstartposition.x < 0) Evil_xVelocity *= -1;
		if (Evilstartposition.y > 630 || Evilstartposition.y < 0) Evil_yVelocity *= -1;

		if (std::pow(startposition.x - Evilstartposition.x, 2) + std::pow(startposition.y - Evilstartposition.y, 2) < std::pow(cirkel.getRadius() + Evilcirkel.getRadius(), 2)) {
			xVelocity = 0;
			yVelocity = 0;
			Evil_xVelocity = 0;
			Evil_yVelocity = 0;
		}

		std::cout<< cirkel.getGeometricCenter().x <<" "<< cirkel.getGeometricCenter().y << " onda: ";
		std::cout << Evilcirkel.getGeometricCenter().x << " " << Evilcirkel.getGeometricCenter().y<<"\n";
		
		//render
		window.clear(sf::Color::Blue);
		window.draw(cirkel);
		window.draw(Evilcirkel);
		window.display();

	}

	return 0;
}
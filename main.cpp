
#include "SFML\Graphics.hpp"
#include <iostream>
#include <cmath>
#include "OrbitingBalls.hpp"
int main() {
	sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode({ 1280, 720 }), "Studsa");
	window->setFramerateLimit(60);
	sf::Vector2f Evildistance;

	sf::CircleShape cirkel;
	sf::Vector2f startposition(600,370);
	cirkel.setFillColor(sf::Color::Green);
	cirkel.setPosition(startposition);
	cirkel.setRadius(50);
	cirkel.setOrigin(cirkel.getGeometricCenter());

	sf::CircleShape Evilcirkel;
	sf::Vector2f Evilstartposition(300,300);
	Evilcirkel.setFillColor(sf::Color::Magenta);
	Evilcirkel.setPosition(Evilstartposition);
	Evilcirkel.setRadius(50);
	Evilcirkel.setOrigin(Evilcirkel.getGeometricCenter());
	std::cout << Evilcirkel.getPosition().x << Evilcirkel.getPosition().y<<"\n";
	
	OrbitingBalls orbitingBalls(3, Evilcirkel.getRadius() * 2, Evilcirkel.getPosition(),window);

	//Physics variables
	float xVelocity = 6;
	float yVelocity = 6;
	sf::Vector2f Evil_velocity = { 10,10 };



	while (window->isOpen()) {
		

		while (const std::optional event = window->pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window->close();
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

		Evilstartposition += Evil_velocity;
		Evildistance = Evilstartposition - Evilcirkel.getPosition();
		Evilcirkel.setPosition(Evilstartposition);

		if (Evilstartposition.x > 1190 || Evilstartposition.x < 0) Evil_velocity.x *= -1;
		if (Evilstartposition.y > 630 || Evilstartposition.y < 0) Evil_velocity.y *= -1;

		if (std::pow(startposition.x - Evilstartposition.x, 2) + std::pow(startposition.y - Evilstartposition.y, 2) < std::pow(cirkel.getRadius() + Evilcirkel.getRadius(), 2)) {
			xVelocity = 0;
			yVelocity = 0;
			Evil_velocity.x = 0;
			Evil_velocity.y = 0;
		}
		
		

		//render
		window->clear(sf::Color::Blue);
		window->draw(cirkel);
		window->draw(Evilcirkel);
		switch(orBitingBalls.actionStatus())
		orbitingBalls.setPositions(Evilstartposition);
		window->display();

	}

	delete window;

	return 0;
}
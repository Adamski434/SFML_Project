
#include "SFML\Graphics.hpp"
#include <iostream>
#include <cmath>
#include "OrbitingBalls.hpp"
#include "EvilCircle.hpp"



int main() {


	bool isActive =  true;
	bool BallsDropped = false;
	std::vector<EvilCircle*> EvilCircleArray;
	sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode({ 1280, 720 }), "Studsa");
	window->setFramerateLimit(60);
	
	//Physics variables
	float xVelocity = 6;
	float yVelocity = 6;
	sf::Vector2f Evil_velocity = { 10,10 };

	sf::CircleShape Playercirkel;
	sf::Vector2f startposition(600,370);
	Playercirkel.setFillColor(sf::Color::Green);
	Playercirkel.setPosition(startposition);
	Playercirkel.setRadius(33);
	Playercirkel.setOrigin(Playercirkel.getGeometricCenter());


	sf::Vector2f Evilstartposition(300,300);
	EvilCircle* Evilcirkel = new EvilCircle(Evilstartposition,sf::Color::Magenta,50,Evil_velocity);
	Evilcirkel->circle->setPosition(Evilstartposition);
	Evilcirkel->circle->setRadius(50);
	Evilcirkel->circle->setOrigin(Evilcirkel->circle->getGeometricCenter());
	EvilCircleArray.push_back(Evilcirkel);
	
	
	OrbitingBalls orbitingBalls(2, Evilcirkel->circle->getRadius() * 2, Evilcirkel->circle->getPosition(),window);


	

	while (window->isOpen()) {
		

		while (const std::optional event = window->pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window->close();
			}
		}

		window->clear(sf::Color::Blue);

		//movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) { startposition.y -= yVelocity; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {startposition.y += yVelocity;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {startposition.x += xVelocity;}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {startposition.x -= xVelocity;}
		
		Playercirkel.setPosition(startposition);
		if (startposition.x > 1190 || startposition.x < 0) xVelocity*= -1;
		if (startposition.y > 630 || startposition.y < 0) yVelocity *= -1;
		


		if (orbitingBalls.AngleTraveled() && BallsDropped == false) {
			for (OrbitingBalls::orb sfär : orbitingBalls.getOrbitingBalls()) {
				EvilCircleArray.push_back(sfär.cirkel);
			}
			BallsDropped = true;
		}
		for (EvilCircle* evil_cirkel: EvilCircleArray) {
			evil_cirkel->Move();
			if (evil_cirkel->circle->getPosition().x > 1190 || evil_cirkel->circle->getPosition().x < 0) evil_cirkel->SetVelocityx(-1);
			if (evil_cirkel->circle->getPosition().y > 630 || evil_cirkel->circle->getPosition().y < 0) evil_cirkel->SetVelocityy(-1);
			Evil_velocity = evil_cirkel->circle->getPosition();
			if (evil_cirkel->MakesContact(Playercirkel)) {
				xVelocity = 0;
				yVelocity = 0;
				Evil_velocity = { 0,0 };
		
			}
			window->draw(*evil_cirkel->circle);
		}
		

		
		
		



		//render
		
		window->draw(Playercirkel);
		if (BallsDropped == false) {
			orbitingBalls.setPositions(Evilcirkel->circle->getPosition());
		}
		window->display();

	}

	delete window;

	return 0;
}
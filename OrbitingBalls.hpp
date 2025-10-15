#ifndef ORBITINGBALLS_HPP
#define ORBITINGBALLS_HPP
#include "SFML/Graphics.hpp"
#include <vector>
#include <cmath>
class OrbitingBalls {

private:
	
	sf::RenderWindow* window;
	const float PI = 3.141592653589793;
	float t = PI/35;
	float OrbitRadius;

	//stepositions variabler
	sf::Vector2f svängvector;
	sf::Vector2f boll_position;
	struct orb {
		sf::CircleShape cirkel;
		float angle;
	};
	std::vector<orb > mini_ball_pos_list;



public:
	enum Action {
		Orbiting = 0,
		Free = 1
	};

	enum Action action = Orbiting;

	int nrOfBalls;
	sf::Vector2f HostPosition;
	OrbitingBalls(int nrOfBalls, float OrbitRadius, sf::Vector2f HostPosition,sf::RenderWindow* fönster);
	void setPositions( sf::Vector2f new_position);
	int ActionStatus();
	};



OrbitingBalls::OrbitingBalls(int nrOfBalls, float OrbitRadius, sf::Vector2f HostPosition, sf::RenderWindow* fönster) {
	this->OrbitRadius = OrbitRadius;
	this->nrOfBalls = nrOfBalls;
	this->HostPosition = HostPosition;
	this->window = fönster;
	double ballPos = 2 * PI / nrOfBalls;
		
		for (float r = 0.0; r < 2 * PI; r += ballPos) {
			sf::CircleShape boll = sf::CircleShape(OrbitRadius / 5);
			boll.setOrigin(boll.getGeometricCenter());
			boll.setPosition({this->HostPosition.x + OrbitRadius * std::cos(r), this->HostPosition.x + OrbitRadius * std::sin(r) });
			boll.setFillColor(sf::Color::Yellow);

			orb klot = { boll,r };
			this->mini_ball_pos_list.push_back(klot);
		}



}
void OrbitingBalls::setPositions( sf::Vector2f new_position) {
	for ( orb &boll : this->mini_ball_pos_list) {
		boll_position = boll.cirkel.getPosition();
		
		boll.angle += t;
		//boll_position
		boll_position = new_position;
		boll_position.x += OrbitRadius * std::cos(boll.angle);
		boll_position.y += OrbitRadius * std::sin(boll.angle);
		boll.cirkel.setPosition(boll_position);
		
		
		window->draw(boll.cirkel);
	}
	

}
//int OrbitingBalls::ActionStatus() {
//	return 
//}

#endif
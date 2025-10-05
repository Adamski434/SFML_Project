#ifndef ORBITINGBALLS_HPP
#define ORBITINGBALLS_HPP
#include "SFML/Graphics.hpp"
#include <vector>
#include <cmath>
class OrbitingBalls {

private:
	
	sf::RenderWindow* window;
	const double PI = 3.141592653589793;
	float t = PI/6;
	float OrbitRadius;
	std::vector<sf::CircleShape> mini_ball_pos_list;



public:
	int nrOfBalls;
	sf::Vector2f HostPosition;
	OrbitingBalls(int nrOfBalls, float OrbitRadius, sf::Vector2f HostPosition,sf::RenderWindow* fönster);
	void setPositions( sf::Vector2f new_position);
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
			boll.setPosition({HostPosition.x + OrbitRadius * std::cos(r), HostPosition.x + OrbitRadius * std::sin(r) });
			sf::Vector2f boll_pos = boll.getPosition();
			
			boll.setFillColor(sf::Color::Yellow);
			this->mini_ball_pos_list.push_back(boll);
			//fixaskiten
			std::cout << boll.getPosition().x << " " << boll.getPosition().y << "\n";
		}



}
void OrbitingBalls::setPositions( sf::Vector2f new_position) {
	sf::Vector2f svängvector;
	for (sf::CircleShape &boll : this->mini_ball_pos_list) {
		sf::Vector2f boll_position = boll.getPosition();
		svängvector = { (boll.getPosition().y) * -1 / 10, (boll.getPosition().x * 1 / 10) }; 

		boll_position += new_position;
		boll.setPosition(boll_position);
		
		
		window->draw(boll);
	}
	
}
#endif
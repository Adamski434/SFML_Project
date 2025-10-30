#ifndef ORBITINGBALLS_HPP
#define ORBITINGBALLS_HPP
#include "Evilcircle.hpp"
#include <vector>
#include <cmath>
class OrbitingBalls {

private:

	sf::RenderWindow* window;
	const float PI = 3.141592653589793;
	float t = PI / 35;
	float delta_t = 0;
	float OrbitRadius;

	//stepositions variabler
	
	sf::Vector2f boll_position;
	sf::Vector2f Evil_Velocity = { 15,15 };



public:

	struct orb {
		EvilCircle* cirkel;
		float angle;
	};
	std::vector<orb > mini_ball_pos_list;
	bool AngleTraveled();
	int nrOfBalls;
	sf::Vector2f HostPosition;
	OrbitingBalls(int nrOfBalls, float OrbitRadius, sf::Vector2f HostPosition, sf::RenderWindow* fönster );
	~OrbitingBalls();
	void setPositions(sf::Vector2f new_position); // lägg till så att den returnerar tid
	std::vector<orb>  getOrbitingBalls();
	
};


#endif
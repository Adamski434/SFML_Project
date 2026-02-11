#ifndef BULLET_HPP
#define BULLET_HPP
#include <SFML/Graphics.hpp>
class Bullet {
private:
	// The bullet class will save and normalise the direction of the bullet

	sf::Vector2f DirectionVector{ 0,0 };
	float speed{ 0 };
	float radius{ 0 };

public:
	sf::CircleShape bullet;

	Bullet(float speed, sf::Color color, float radius);
	Bullet(float speed, sf::Color color, float radius,sf::Vector2f DestinationVector,sf::Vector2f start_position);


	~Bullet() = default;

	void SetDirectionVector(sf::Vector2f drv);

	void MoveBullet();
};


#endif
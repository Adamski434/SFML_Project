
#ifndef EVILCIRCLE_HPP
#define EVILCIRCLE_HPP
#include "Enemy.hpp"


class EvilCircle: public Enemy {
private:
	sf::Vector2f Velocity;
public:

	sf::CircleShape* circle;

	EvilCircle(sf::Vector2f startposition, sf::Color color, int radius, sf::Vector2f Velocity);
	EvilCircle(sf::Color color, float radius, sf::Vector2f Velocity);
	~EvilCircle();
	void Move();
	void SetVelocityx(int factor);
	void SetVelocityy(int factor);
	bool  MakesContact(const sf::CircleShape &player) override;
};
#endif
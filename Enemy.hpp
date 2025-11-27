
#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <SFML\Graphics.hpp>

class Enemy {
public: 

	virtual ~Enemy() = default;
	virtual bool MakesContact(const sf::CircleShape &player) = 0;
};

# endif
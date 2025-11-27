

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics.hpp>



class Player {


private:;
	sf::RenderWindow* window;
	int HP;
	int Speed = 8;
	sf::Vector2f Startposition = { 600, 370 };
	sf::Texture* texture = new sf::Texture();
public:
	sf::CircleShape chudcel;
	

	Player(sf::RenderWindow* window);
	void draw();
	~Player();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void setSpeed(int speed);

};








#endif 

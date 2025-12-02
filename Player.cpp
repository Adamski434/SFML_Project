#include "Player.hpp"

Player::Player(sf::RenderWindow* window) : HP(6), Speed(6) {

	
	if (!this->texture->loadFromFile("goku.jpg")) {
		throw std::runtime_error("Unable to open File");
	}
	this->PlayerCircle.setPosition(Startposition);
	this->PlayerCircle.setRadius(33);
	this->PlayerCircle.setOrigin(this->PlayerCircle.getGeometricCenter());
	this->PlayerCircle.setTexture(texture);

	this->window = window;
	
}

Player::~Player() {

	delete this->texture;
	this->texture = nullptr;

}

void Player::draw() {
	this->window->draw(this->PlayerCircle);
}

void Player::moveUp() {
	this->Startposition.y -= this->Speed;
	this->PlayerCircle.setPosition(this->Startposition);
}
void Player::moveDown() {
	this->Startposition.y += this->Speed;
	this->PlayerCircle.setPosition(this->Startposition);
}
void Player::moveLeft() {
	this->Startposition.x -= this->Speed;
	this->PlayerCircle.setPosition(this->Startposition);
}
void Player::moveRight() {
	this->Startposition.x += this->Speed;
	this->PlayerCircle.setPosition(this->Startposition);
}

void Player::setSpeed(int speed) {
	this->Speed = speed;
}

#include "Player.hpp"

Player::Player(sf::RenderWindow* window) : HP(6), Speed(6) {

	
	if (!this->texture->loadFromFile("chudjak.jpg")) {
		throw std::runtime_error("billions must öppna filen");
	}
	this->chudcel.setPosition(Startposition);
	this->chudcel.setRadius(33);
	this->chudcel.setOrigin(this->chudcel.getGeometricCenter());
	this->chudcel.setTexture(texture);

	this->window = window;
	
}

Player::~Player() {

	delete this->texture;
	this->texture = nullptr;

}

void Player::draw() {
	this->window->draw(this->chudcel);
}

void Player::moveUp() {
	this->Startposition.y -= this->Speed;
	this->chudcel.setPosition(this->Startposition);
}
void Player::moveDown() {
	this->Startposition.y += this->Speed;
	this->chudcel.setPosition(this->Startposition);
}
void Player::moveLeft() {
	this->Startposition.x -= this->Speed;
	this->chudcel.setPosition(this->Startposition);
}
void Player::moveRight() {
	this->Startposition.x += this->Speed;
	this->chudcel.setPosition(this->Startposition);
}

void Player::setSpeed(int speed) {
	this->Speed = speed;
}

#include "Evilcircle.hpp"
#include <cmath>

EvilCircle::EvilCircle(sf::Vector2f startposition, sf::Color color, int radius, sf::Vector2f Velocity) {
	this->circle = new sf::CircleShape();
	this->circle->setFillColor(color);
	this->circle->setRadius(radius);
	this->circle->setPosition(startposition);
	this->circle->setOrigin(this->circle->getGeometricCenter());
	this->Velocity = Velocity;
	


}

EvilCircle::EvilCircle(sf::Color color, float radius, sf::Vector2f Velocity) {
	this->circle = new sf::CircleShape();
	this->circle->setFillColor(color);
	this->circle->setRadius(radius);
	this->circle->setOrigin(this->circle->getGeometricCenter());
	this->Velocity = Velocity;

}

EvilCircle::~EvilCircle() {
	delete this->circle;
	circle = nullptr;
}

void EvilCircle::Move() {
	this->circle->setPosition(this->circle->getPosition() + this->Velocity);



}

bool EvilCircle::MakesContact(const sf::CircleShape &player){
	if ((std::pow(player.getPosition().x - this->circle->getPosition().x, 2)) + (std::pow(player.getPosition().y - this->circle->getPosition().y, 2)) < (std::pow(player.getRadius() + this->circle->getRadius(), 2))) {

		return true;
	}

	else { return false; };
}

void EvilCircle::SetVelocityx(int factor) {
	this->Velocity.x *= factor;

}
void EvilCircle::SetVelocityy(int factor) {
	this->Velocity.y *= factor;

}


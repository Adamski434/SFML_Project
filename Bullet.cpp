#include "Bullet.hpp"

Bullet::Bullet(float speed, sf::Color color, float radius) : speed(speed), radius(radius) {
	this->bullet.setFillColor(color);
	this->bullet.setRadius(radius);

}

Bullet::Bullet(float speed, sf::Color color, float radius, sf::Vector2f DestinationVector,sf::Vector2f start_position) : speed(speed), radius(radius), DirectionVector(DestinationVector) {
	this->bullet.setFillColor(color);
	this->bullet.setRadius(radius);
	this->bullet.setPosition(start_position);
	this->speed = speed / std::sqrt(std::pow(DirectionVector.x, 2) + std::pow(DirectionVector.y, 2)); //Vector normalization and size setting
	this->DirectionVector = DirectionVector * this->speed;
}



void Bullet::SetDirectionVector(sf::Vector2f drv) {
	
	speed = speed/ std::sqrt(std::pow(drv.x, 2) + std::pow(drv.y, 2)); //Vector normalization and size setting
	this->DirectionVector = DirectionVector * speed;
}

void Bullet::MoveBullet() {
	this->bullet.move(DirectionVector);
}
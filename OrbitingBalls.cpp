#include "OrbitingBalls.hpp"

OrbitingBalls::OrbitingBalls(int nrOfBalls, float OrbitRadius, sf::Vector2f HostPosition, sf::RenderWindow* fönster) {
	this->OrbitRadius = OrbitRadius;
	this->nrOfBalls = nrOfBalls;
	this->HostPosition = HostPosition;
	this->window = fönster;
	double ballPos = 2 * PI / nrOfBalls;

	for (float r = 0.0; r < 2 * PI; r += ballPos) {
		EvilCircle* boll = new EvilCircle({ this->HostPosition.x + OrbitRadius * std::cos(r), this->HostPosition.x + OrbitRadius * std::sin(r) }, sf::Color::Yellow, OrbitRadius / 5, { this->Evil_Velocity.x * std::cos(r+PI/3),this->Evil_Velocity.y * std::sin(r+PI/3)});
		orb klot = { boll,r };
		this->mini_ball_pos_list.push_back(klot);
	}



}
OrbitingBalls::~OrbitingBalls() {
	for (OrbitingBalls::orb orb : this->mini_ball_pos_list) {
		delete orb.cirkel;
		orb.cirkel = nullptr;
	}
}


void OrbitingBalls::setPositions(sf::Vector2f new_position) {
	for (orb &ball : this->mini_ball_pos_list) {
		ball.angle += t;
		delta_t += t;


	
		boll_position = new_position;
		boll_position.x += OrbitRadius * std::cos(ball.angle);
		boll_position.y += OrbitRadius * std::sin(ball.angle);
		ball.cirkel->circle->setPosition(boll_position);


		window->draw(*ball.cirkel->circle);
	}
}
bool OrbitingBalls::AngleTraveled() {
	return 8* 2*PI<delta_t;

}

std::vector<OrbitingBalls::orb> OrbitingBalls::getOrbitingBalls() {
	return this->mini_ball_pos_list;
}
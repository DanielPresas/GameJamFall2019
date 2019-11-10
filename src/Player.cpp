#include "Player.h"
#include "Cappuccino/HitBoxLoader.h"
using namespace Cappuccino;

Player::Player(Shader& shader, std::vector<Texture*>& textures, std::vector<Mesh*>& meshes, Gun* gun) :
	GameObject(shader, textures, meshes), _input(true, 0) {
	
	_rigidBody.setGrav(false);
	auto loader = HitBoxLoader("./Assets/Meshes/playerBox.obj");

	for (auto x : loader._boxes) 
		_rigidBody._hitBoxes.push_back(x);

	_gun = gun;

}

void Player::childUpdate(const float dt) {
	glm::vec3 movement(0.0f);

	if (_input.keyboard->keyPressed(KeyEvent::W)) {
		movement += glm::vec3(0.0f, 0.0f, -1.0f);
	}
	else if (_input.keyboard->keyPressed(KeyEvent::S)) {
		movement += glm::vec3(0.0f, 0.0f, 1.0f);
	}
	if (_input.keyboard->keyPressed(KeyEvent::A)) {
		movement += glm::vec3(-1.0f, 0.0f, 0.0f);
	}
	else if (_input.keyboard->keyPressed(KeyEvent::D)) {
		movement += glm::vec3(1.0f, 0.0f, 0.0f);
	}

	if (movement != glm::vec3(0.0f)) {
		_rigidBody._position += glm::normalize(movement) * _speed * dt;
	}

	glm::vec3 shootDirection(0.0f);
	bool isShooting = false;
	
	if(_input.keyboard->keyPressed(KeyEvent::LEFT_ARROW)) {
		shootDirection += glm::vec3(-1.0f, 0.0f, 0.0f);
		isShooting = true;
	}
	else if(_input.keyboard->keyPressed(KeyEvent::RIGHT_ARROW)) {
		shootDirection += glm::vec3(1.0f, 0.0f, 0.0f);
		isShooting = true;
	}
	if(_input.keyboard->keyPressed(KeyEvent::UP_ARROW)) {
		shootDirection += glm::vec3(0.0f, 0.0f, -1.0f);
		isShooting = true;
	}
	else if(_input.keyboard->keyPressed(KeyEvent::DOWN_ARROW)) {
		shootDirection += glm::vec3(0.0f, 0.0f, 1.0f);
		isShooting = true;
	}


	if(isShooting) {
		shootDirection = glm::normalize(shootDirection);

		_gun->_shootDir = shootDirection;
		_gun->shoot(dt, _rigidBody._position);
	}
}

#include "Player.h"

using namespace Cappuccino;

Player::Player(Shader& shader, std::vector<Texture*>& textures, std::vector<Mesh*>& meshes) :
	GameObject(shader, textures, meshes), _input(true, 0) {
	_rigidBody.setGrav(false);
}

void Player::childUpdate(const float dt) {
	glm::vec3 movement(0.0f);
	
	if(_input.keyboard->keyPressed(KeyEvent::W)) {
		movement += glm::vec3(0.0f, 0.0f, -1.0f);
	}
	else if(_input.keyboard->keyPressed(KeyEvent::S)) {
		movement += glm::vec3(0.0f, 0.0f, 1.0f);
	}
	if(_input.keyboard->keyPressed(KeyEvent::A)) {
		movement += glm::vec3(-1.0f, 0.0f, 0.0f);
	}
	else if(_input.keyboard->keyPressed(KeyEvent::D)) {
		movement += glm::vec3(1.0f, 0.0f, 0.0f);
	}
	
	if(movement != glm::vec3(0.0f)) {
		_rigidBody._position += glm::normalize(movement) * _speed * dt;
	}
}

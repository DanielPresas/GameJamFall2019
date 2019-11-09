#include "Player.h"

Player::Player(Cappuccino::Shader& shader, std::vector<Cappuccino::Texture*> textures, std::vector<Cappuccino::Mesh*> meshes) :
	GameObject(shader, textures, meshes), _input(true, 0) {
	
}

void Player::childUpdate(float dt) {
	if(_input.keyboard->keyPressed(Events::W)) {
		_rigidBody.addVelocity(glm::vec3());
	}
}

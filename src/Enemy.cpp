#include "Enemy.h"
#include "Cappuccino/HitBoxLoader.h"

using namespace Cappuccino;

Enemy::Enemy(Shader& shader, const std::vector<Texture*>& textures, const std::vector<Mesh*>& meshes, Gun* gun)
	:GameObject(shader, textures, meshes)
{
	auto loader = HitBoxLoader("./Assets/Meshes/playerBox.obj");

	for(auto x : loader._boxes) {
		_rigidBody._hitBoxes.push_back(x);
	}

	_rigidBody.drawHitBox = false;
	_rigidBody.setGrav(false);
	this->gun = gun;
}

void Enemy::childUpdate(float dt)
{
	triggerVolume._position = _rigidBody._position;

	//_rigidBody._shader.use();
	//triggerVolume.draw();
}

void Enemy::seek(GameObject* other, const float dt)
{
	const glm::vec3 norm = glm::normalize(other->_rigidBody._position - _rigidBody._position);
	_rigidBody.setVelocity(norm * 3.0f);

	attack(other, dt);
}

void Enemy::attack(GameObject* other, const float dt)
{
	if (!other->checkCollision(triggerVolume, _rigidBody._position))
		return;

	//auto dir = other->_rigidBody._position - _rigidBody._position;
	//auto norm = glm::normalize(dir);

	gun->_shootDir = glm::normalize(_rigidBody._vel);

	gun->shoot(dt, _rigidBody._position);

}


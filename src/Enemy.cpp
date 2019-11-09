#include "Enemy.h"
#include "Cappuccino/CappMacros.h"
#include "Cappuccino/HitBoxLoader.h"
using namespace Cappuccino;

Enemy::Enemy(Shader& shader, const std::vector<Texture*>& textures, const std::vector<Mesh*>& meshes, Gun* gun)
	:GameObject(shader, textures, meshes)
{
	auto loader = HitBoxLoader("./Assets/Meshes/playerBox.obj");

	for (auto x : loader._boxes)
		_rigidBody._hitBoxes.push_back(x);

	_rigidBody.setGrav(false);
	_gun = gun;
}

void Enemy::childUpdate(float dt)
{
	triggerVolume._position = _rigidBody._position;

	_rigidBody._shader.use();
	//triggerVolume.draw();
}

void Enemy::seek(Cappuccino::GameObject* other)
{
	auto dir = other->_rigidBody._position - _rigidBody._position;

	auto norm = glm::normalize(dir);

	_rigidBody.setVelocity(norm * 3.0f);

	attack(other);
}

void Enemy::attack(Cappuccino::GameObject* other)
{
	if (!other->checkCollision(triggerVolume, _rigidBody._position))
		return;


	auto dir = other->_rigidBody._position - _rigidBody._position;

	auto norm = glm::normalize(dir);

	_gun->_shootDir = glm::normalize(_rigidBody._vel);

	_gun->shoot(1.0f);

}


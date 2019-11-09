#include "Enemy.h"

using namespace Cappuccino;

Enemy::Enemy(Shader& shader, const std::vector<Texture*>& textures, const std::vector<Mesh*>& meshes,Gun* gun)
	:GameObject(shader, textures, meshes)
{
	_rigidBody.setGrav(false);

}

void Enemy::childUpdate(float dt)
{
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

	_gun->_shootDir = norm;

	_gun->shoot(1.0f);

}


#include "Enemy.h"

using namespace Cappuccino;

Enemy::Enemy(Cappuccino::Shader* SHADER, const std::vector<Cappuccino::Texture*>& texture, const std::vector<Cappuccino::Mesh*>& meshes)
	:GameObject(*SHADER,texture,meshes)
{
	_rigidBody.setGrav(false);
}

void Enemy::childUpdate(float dt)
{
}

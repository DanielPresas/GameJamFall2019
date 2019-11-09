#include "Enemy.h"

using namespace Cappuccino;

Enemy::Enemy(Shader& shader, const std::vector<Texture*>& textures, const std::vector<Mesh*>& meshes)
	:GameObject(shader, textures, meshes)
{
	_rigidBody.setGrav(false);
}

void Enemy::childUpdate(float dt)
{
}

#include "Gun.h"
#include "Cappuccino/HitBoxLoader.h"

Gun::Gun(float damage, float rateOfFire, Projectile* bullet)
	:_damage(damage), _rateOfFire(rateOfFire)
{

	for (unsigned i = 0; i < 100; i++)
		_bullets.push_back(new Projectile(*bullet));

}

Projectile::Projectile(Cappuccino::Shader* SHADER, const std::vector<Cappuccino::Texture*>& textures, const std::vector<Cappuccino::Mesh*>& meshes)
	:Cappuccino::GameObject(*SHADER,textures,meshes)
{
	auto loader = Cappuccino::HitBoxLoader("./Assets/Meshes/projectileBox.obj");
	
	for (auto x : loader._boxes)
		_rigidBody._hitBoxes.push_back(x);

	_rigidBody.setGrav(false);
}

void Projectile::childUpdate(float dt)
{
	lifetime -= dt;
	if (lifetime <= 0.0f) {
		setActive(false);
		return;
	}
}

Pistol::Pistol(Projectile* bullet)
	:Gun(1.0f,0.6f,bullet)
{
}

void Pistol::shoot(float dt)
{

	_bullets[index]->setActive(true);
	_bullets[index]->lifetime = 100.0f;
	_bullets[index]->_rigidBody.setVelocity(_shootDir);


	index++;
	if (index > _bullets.size() - 1)
		index = 0;

}

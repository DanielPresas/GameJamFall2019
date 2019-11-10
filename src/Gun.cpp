#include "Gun.h"
#include "Cappuccino/HitBoxLoader.h"

Gun::Gun(float damage, float rateOfFire, Cappuccino::Shader* shader)
	:_damage(damage), _rateOfFire(rateOfFire)
{

	_bullets.push_back(new Projectile(shader, std::vector<Cappuccino::Texture*>{new Cappuccino::Texture("nut.png", Cappuccino::TextureType::DiffuseMap)}, std::vector<Cappuccino::Mesh*>{new Cappuccino::Mesh("projectile.obj")}));
	for (unsigned i = 0; i < 99; i++)
		_bullets.push_back(_bullets[0]);
}

Projectile::Projectile(Cappuccino::Shader* SHADER, const std::vector<Cappuccino::Texture*>& textures, const std::vector<Cappuccino::Mesh*>& meshes)
	:Cappuccino::GameObject(*SHADER, textures, meshes)
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

Pistol::Pistol(Cappuccino::Shader* shader)
	:Gun(1.0f, 0.6f, shader)
{
}

void Pistol::shoot(float dt, const glm::vec3& startPos)
{

	static float timer = _rateOfFire;

	timer -= dt;

	if (!(timer <= 0.0f))
		return;
	timer = _rateOfFire;

	_bullets[index]->_rigidBody._position = startPos;
	_bullets[index]->setActive(true);
	_bullets[index]->lifetime = 10.0f;
	_bullets[index]->_rigidBody.setVelocity(_shootDir * 30.0f);


	index++;
	if (index > _bullets.size() - 1)
		index = 0;

}

Rapid::Rapid(Cappuccino::Shader* shader)
	:Gun(0.5f, 0.2f, shader)
{

}

void Rapid::shoot(float dt, const glm::vec3& startPos)
{

	static float timer = _rateOfFire;

	timer -= dt;

	if (!(timer <= 0.0f))
		return;
	timer = _rateOfFire;

	_bullets[index]->_rigidBody._position = startPos;
	_bullets[index]->setActive(true);
	_bullets[index]->lifetime = 10.0f;
	_bullets[index]->_rigidBody.setVelocity(_shootDir * 30.0f);


	index++;
	if (index > _bullets.size() - 1)
		index = 0;
}

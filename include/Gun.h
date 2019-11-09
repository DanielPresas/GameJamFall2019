#pragma once
#include "Cappuccino/GameObject.h"

class Projectile : public Cappuccino::GameObject {
public:
	Projectile(Cappuccino::Shader* SHADER, const std::vector<Cappuccino::Texture*>& textures, const std::vector<Cappuccino::Mesh*>& meshes);

	void childUpdate(float dt) override;

	float lifetime = 5.0f;

};

class Gun {
public:
	Gun(float damage, float rateOfFire, Projectile* bullet);

	virtual void shoot(float dt) = 0;

	glm::vec3 _shootDir;
protected:
	int index = 0;
	std::vector<Projectile*> _bullets;
private:
	float _damage = 0.0f;
	float _rateOfFire = 0.0f;

};

class Pistol : public Gun {
public:
	Pistol(Projectile* bullet);

	void shoot(float dt) override;
};

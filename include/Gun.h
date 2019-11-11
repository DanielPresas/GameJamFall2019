#pragma once
#include "Cappuccino/GameObject.h"

class Projectile : public Cappuccino::GameObject {
public:
	Projectile(Cappuccino::Shader* SHADER, const std::vector<Cappuccino::Texture*>& textures, const std::vector<Cappuccino::Mesh*>& meshes);

	void childUpdate(float dt) override;

	float lifetime = 20.0f;

};

class Gun {
public:
	Gun(float damage, float rateOfFire, Cappuccino::Shader* shader);
	virtual ~Gun() = default;

	virtual void shoot(float dt,const glm::vec3& startPos) = 0;

	std::vector<Projectile*> getProjectiles() const { return _bullets; }

	glm::vec3 _shootDir;
protected:
	std::vector<Projectile*> _bullets;
	unsigned int index = 0;
	
	float _rateOfFire = 0.0f;
private:
	float _damage = 0.0f;

};

class Pistol : public Gun {
public:
	Pistol(Cappuccino::Shader* shader);

	void shoot(float dt, const glm::vec3& startPos) override;
};

class Rapid : public Gun {
public:
	Rapid(Cappuccino::Shader* shader);

	void shoot(float dt, const glm::vec3& startPos) override;
};

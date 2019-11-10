#pragma once
#include "Cappuccino/GameObject.h"
#include "Gun.h"

class Enemy : public Cappuccino::GameObject {
public:
	Enemy(Cappuccino::Shader& shader, const std::vector<Cappuccino::Texture*>& textures, const std::vector<Cappuccino::Mesh*>& meshes,Gun* gun);

	void childUpdate(float dt) override;

	virtual void seek(Cappuccino::GameObject* other,float dt);
	virtual void attack(Cappuccino::GameObject* other,float dt);

	Cappuccino::HitBox triggerVolume{ glm::vec3(0.0f,0.0f,0.0f),glm::vec3(1.0f,0.5f,1.0f)*10.0f };
	Gun* _gun;
};
#pragma once

#include "Gun.h"

#include <Cappuccino/GameObject.h>
#include <Cappuccino/CappInput.h>

class Player : public Cappuccino::GameObject {
public:

	Player(Cappuccino::Shader& shader, std::vector<Cappuccino::Texture*>& textures, std::vector<Cappuccino::Mesh*>& meshes, Gun* gun);
	~Player() = default;

	void childUpdate(float dt) override;

	Gun* gun;

	int health = 3;
private:

	float _speed = 5.0f;
	
	Cappuccino::CappInput _input;
	
};

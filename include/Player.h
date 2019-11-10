#pragma once

#include "Gun.h"

#include <Cappuccino/GameObject.h>
#include <Cappuccino/CappInput.h>

class Player : public Cappuccino::GameObject {
public:

	Player(Cappuccino::Shader& shader, std::vector<Cappuccino::Texture*>& textures, std::vector<Cappuccino::Mesh*>& meshes, Gun* gun);
	~Player() = default;

	void childUpdate(float dt) override;

private:

	Gun* _gun;
	float _speed = 5.0f;
	
	Cappuccino::CappInput _input;
	
};

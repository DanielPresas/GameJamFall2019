#pragma once
#include "Cappuccino/GameObject.h"

class Enemy : public Cappuccino::GameObject {
public:
	Enemy(Cappuccino::Shader& shader, const std::vector<Cappuccino::Texture*>& textures, const std::vector<Cappuccino::Mesh*>& meshes);

	void childUpdate(float dt) override;

	void seek();
	void attack();

};
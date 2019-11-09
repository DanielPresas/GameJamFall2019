#pragma once
#include "Cappuccino/GameObject.h"

using namespace Cappuccino;
class Enemy : public GameObject {
public:
	Enemy(Cappuccino::Shader* SHADER, const std::vector<Cappuccino::Texture*>& texture, const std::vector<Cappuccino::Mesh*>& meshes);

	void childUpdate(float dt) override;

	void seek();
	void attack();

};
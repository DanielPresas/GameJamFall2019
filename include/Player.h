#pragma once

#include <Cappuccino/GameObject.h>
#include <Cappuccino/CappInput.h>

class Player : public Cappuccino::GameObject {
public:

	Player(Cappuccino::Shader& shader, std::vector<Cappuccino::Texture*> textures, std::vector<Cappuccino::Mesh*> meshes);
	~Player() = default;

	void childUpdate(float dt) override;

private:

	Cappuccino::CappInput _input;
	
};
#pragma once

#include <Cappuccino/GameObject.h>

class LevelPlane : public Cappuccino::GameObject {
public:

	LevelPlane(Cappuccino::Shader& shader);
	~LevelPlane() = default;

private:

	void childUpdate(float dt) override;
	
};

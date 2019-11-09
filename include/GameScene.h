#pragma once

#include <Cappuccino/SceneManager.h>
#include <Cappuccino/DirLight.h>
#include "Enemy.h"

class GameScene : Cappuccino::Scene {
public:

	GameScene(bool firstScene);
	virtual ~GameScene() = default;

	bool init() override;
	bool exit() override;
	void mouseFunction(double xpos, double ypos) override;
	void clickFunction(int button, int action, int mods) override;

private:
	Cappuccino::DirLight dirLight{ Cappuccino::DirLight(glm::vec2(1600.0f, 1200.0f), glm::vec3(0.0f, -1.0f, -1.0f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 512.0f) };
	Cappuccino::Shader* aShader;
	std::vector<Enemy*> enemies;
	Cappuccino::Camera camera;

	void childUpdate(float dt) override;

};

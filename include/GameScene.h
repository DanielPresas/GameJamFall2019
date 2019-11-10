#pragma once

#include "Enemy.h"
#include "Player.h"

#include <Cappuccino/SceneManager.h>
#include <Cappuccino/DirLight.h>

class GameScene : Cappuccino::Scene {
public:

	GameScene(bool firstScene);
	virtual ~GameScene() = default;

	bool init() override;
	bool exit() override;
	void mouseFunction(double xpos, double ypos) override;
	void clickFunction(int button, int action, int mods) override;

private:

	void childUpdate(float dt) override;

	Player* player;
	std::vector<Enemy*> enemies;
	
	Cappuccino::DirLight dirLight{ Cappuccino::DirLight(glm::vec2(1600.0f, 1200.0f), glm::vec3(0.0f, -1.0f, -1.0f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 512.0f) };
	Cappuccino::Camera camera;

	static std::vector<std::string> _enemyTextures;
};

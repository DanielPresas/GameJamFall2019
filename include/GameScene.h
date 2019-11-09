#pragma once

#include <Cappuccino/SceneManager.h>
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
	std::vector<Enemy*> enemies;
	Cappuccino::Camera camera;

	void childUpdate(float dt) override;

};

#pragma once

#include <Cappuccino/SceneManager.h>

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

};

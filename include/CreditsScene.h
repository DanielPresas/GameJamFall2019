#pragma once
#include "Cappuccino/UI.h"
#include "Cappuccino/SceneManager.h"

class CreditsScene : public Cappuccino::Scene {
public:
	CreditsScene(bool yn);

	bool init() override;
	bool exit() override;

	void childUpdate(float dt) override;

	void mouseFunction(double xpos, double ypos) override;
private:
	Cappuccino::UserInterface _ui;
	unsigned sound = 0, group = 0;

};
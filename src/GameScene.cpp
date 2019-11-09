#include "GameScene.h"

GameScene::GameScene(bool firstScene): Scene(firstScene) {}

bool GameScene::init() {
	return true;
}

bool GameScene::exit() {
	return true;
}

void GameScene::childUpdate(float dt) {}

void GameScene::mouseFunction(double xpos, double ypos) {}

void GameScene::clickFunction(int button, int action, int mods) {}

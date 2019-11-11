#pragma once

#include "Enemy.h"
#include "LevelPlane.h"
#include "Player.h"

#include <Cappuccino/SceneManager.h>
#include <Cappuccino/DirLight.h>
#include <Cappuccino/UI.h>

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

	static std::vector<std::string> enemyTextures;
	static std::vector<std::string> trainTextures;
	static int KILLS;
	
	Player* player{};
	std::vector<Enemy*> enemies;
	std::vector<Projectile*> sceneParticles;

	LevelPlane* levelPlane;
	
	Cappuccino::DirLight dirLight { glm::vec2(1600.0f, 1200.0f),
	                                glm::vec3(0.0f, -1.0f, -1.0f),
	                                glm::vec3(0.5f, 0.5f, 0.5f),
	                                glm::vec3(1.0f, 1.0f, 1.0f),
	                                glm::vec3(1.0f, 1.0f, 1.0f),
	                                512.0f };
	Cappuccino::Camera camera;

	Cappuccino::UserInterface* UI;
	Cappuccino::UIText* playerHealth;

	unsigned musicHandle = 0, groupHandle = 0;
	unsigned hurt = 0;
	unsigned die = 0;
};

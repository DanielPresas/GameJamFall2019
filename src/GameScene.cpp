#include "GameScene.h"

#include <Cappuccino/Random.h>
#include <Cappuccino/SoundSystem.h>

using namespace Cappuccino;
int GameScene::KILLS = 0;
std::vector<std::string> GameScene::enemyTextures = {
	"Amtoj.png",
	"Baymax.jpg",
	"BobTheBuilder.png",
	"DarthVader.jpg",
	"Deadpool.png",
	"Doomguy.png",
	"FilthyFrank.jpg",
	"Freeman.png",
	"HarryPotter.png",
	"Josh.png",
	"Kratos.png",
	"LaraCroft.png",
	"MasterChief.png",
	"MichaelJordan.jpg",
	"Minion.png",
	"NeilArmstrong.png",
	"PostMalone.png",
	"RonaldMcdonald.png",
	"Sanic.jpg",
	"Sans.jpg",
	"ScottPilgrim.png",
	"Shrek.jpg",
	"Spiderman.png",
	"VaultBoy.jpg"
};

std::vector<std::string> GameScene::trainTextures {
	"Thomas.jpg",
	"Percy.jpg",
	"James.jpg",
	"James2.jpg"
};

GameScene::GameScene(const bool firstScene) : Scene(firstScene)
{	
	glm::mat4 p = glm::perspective(glm::radians(45.0f), 1600.0f / 1200.0f, 0.1f, 100.0f);
	camera.setPosition(glm::vec3(0.0f, 10.0f, 7.0f));
	camera.lookAt(glm::vec3(0.0f, 0.0f, 0.0f));

	// Player instantiation
	player = new Player(dirLight._dirLightShader, std::vector<Texture*>{ new Texture("Jenko.png", TextureType::DiffuseMap) }, std::vector<Mesh*>{ new Mesh("humanoid2.obj") }, new Rapid(&dirLight._dirLightShader));
	player->_transform.rotate(glm::vec3(0.0f, 1.0f, 0.0f), 180);

	// Enemy instantiation
	for(const auto& texture : enemyTextures) {
		enemies.push_back(new Enemy(dirLight._dirLightShader, std::vector<Texture*>{ new Texture(texture, TextureType::DiffuseMap)}, std::vector<Mesh*>{ new Mesh("humanoid2.obj") }, new Pistol(&dirLight._dirLightShader)));

		if(texture == "Josh.png") {
			enemies.back()->_transform.scale(glm::vec3(1.0f), 0.8f);
		}
	}

	for(const auto& texture : trainTextures) {
		enemies.push_back(new Enemy(dirLight._dirLightShader, std::vector<Texture*>{ new Texture(texture, TextureType::DiffuseMap)}, std::vector<Mesh*>{ new Mesh("train.obj") }, new Pistol(&dirLight._dirLightShader)));
	}
	
	enemies.push_back(new Enemy(dirLight._dirLightShader, std::vector<Texture*>{ new Texture("Pacman.png", TextureType::DiffuseMap)}, std::vector<Mesh*>{ new Mesh("pacman.obj") }, new Pistol(&dirLight._dirLightShader)));

	
	for(const auto& enemy : enemies) {
		enemy->_rigidBody._position = glm::vec3(randomFloat(-20.0f, 20.0f), 0.0f, randomFloat(-20.0f, -10.0f));
		enemy->_rigidBody.setViewProjMat(camera.whereAreWeLooking(), p);
	}

	for (unsigned i = 0; i < 100; i++) {
		sceneParticles.push_back(new Projectile(&dirLight._dirLightShader, std::vector<Texture*>{ new Texture("Pacman.png", TextureType::DiffuseMap) }, std::vector<Mesh*>{new Mesh("projectile.obj")}));
		sceneParticles.back()->_transform.scale(glm::vec3(1.0f, 1.0f, 1.0f), 0.25f);
	}

	// Level instantiation
	levelPlane = new LevelPlane(dirLight._dirLightShader);
	levelPlane->_transform.scale(glm::vec3(1.0f, 0.0f, 1.0f), 3.0f);
	levelPlane->_rigidBody._position = glm::vec3(-15.0f, 0.0f, 20.0f);

	// UI creation
	UI = new UserInterface;
	
	playerHealth = new UIText("Health: " + std::to_string(player->health),
	                          glm::vec2(1600.0f, 1200.0f),
	                          glm::vec2(-100.0f, -200.0f),
	                          glm::vec3(1.0f, 1.0f, 1.0f),
	                          1.0f);

	UI->_uiComponents.push_back(playerHealth);
	UI->_uiComponents.push_back(new  UIText("Kills: " + std::to_string(KILLS),
		glm::vec2(1600.0f, 1200.0f),
		glm::vec2(-100.0f, -400.0f),
		glm::vec3(1.0f, 1.0f, 1.0f),
		1.0f));


	// Sound manager
	musicHandle = SoundSystem::load2DSound("FightSong.wav");
	groupHandle = SoundSystem::createChannelGroup("backgroundMusic");
	hurt = SoundSystem::load2DSound("pain.mp3");
	die = SoundSystem::load2DSound("die.mp3");

}

bool GameScene::init() {
	_initialized = true;
	_shouldExit = false;
	
	levelPlane->setActive(true);
	player->setActive(true);
	for (auto x : enemies)
		x->setActive(true);

	SoundSystem::playSound2D(musicHandle, groupHandle, SoundSystem::ChannelType::SoundEffect);

	return true;
}

bool GameScene::exit() {

	levelPlane->setActive(false);
	player->setActive(false);
	for (auto x : enemies)
		x->setActive(false);

	SoundSystem::getChannels()[0]->stop();

	_initialized = false;
	_shouldExit = true;
	
	return true;
}

void GameScene::childUpdate(float dt) {

	const glm::vec3 offset(0.0f, 10.0f, 7.0f);
	camera.setPosition(glm::vec3(player->_rigidBody._position) + offset);
	camera.lookAt(player->_rigidBody._position);
	
	for(auto e1 : enemies) {

		for(auto bullet : player->gun->getProjectiles()) {
			if(bullet->isActive() && bullet->_rigidBody.checkCollision(e1->_rigidBody)) {
				e1->health -= 5;
				bullet->setActive(false);
				SoundSystem::playSound2D(hurt, groupHandle, SoundSystem::ChannelType::SoundEffect);
				break;
			}
		}

		if(e1->health <= 0) {
			for (unsigned i = 0; i < sceneParticles.size(); i++) {
				sceneParticles[i]->setActive(true);
				sceneParticles[i]->_rigidBody._position = e1->_rigidBody._position;
				sceneParticles[i]->_rigidBody.setVelocity(glm::vec3(cosf(i) * (1.0f + i), 0.0f, -sinf(i) * (1.0f + i)));
			}
			KILLS++;
			e1->_rigidBody._position = player->_rigidBody._position + glm::vec3(randomFloat(-25.0f, 25.0f), 0.0f, randomFloat(-25.0f, -15.0f));
			e1->health = 10;


		}

		for(auto bullet : e1->gun->getProjectiles()) {
			if(bullet->isActive() && bullet->_rigidBody.checkCollision(player->_rigidBody)) {
				player->health--;
				bullet->setActive(false);
				break;
			}
		}

		if(player->health <= 0) {
			player->_rigidBody._position = glm::vec3(0.0f);
			player->health = 3;

			SoundSystem::playSound2D(die, groupHandle, SoundSystem::ChannelType::SoundEffect);
			KILLS = 0;

			for(const auto& enemy : enemies) {
				enemy->_rigidBody._position = glm::vec3(randomFloat(-15.0f, 15.0f), 0.0f, randomFloat(-15.0f, -8.0f));
			}
		}
		
		enum Direction : unsigned int {
			FORWARD = 1,
			BACKWARD,
			LEFT,
			RIGHT
		};

		std::vector<glm::vec3> directions = {
			glm::vec3( 0.0, 0.0f,  1.0f),	// forward
			glm::vec3( 0.0, 0.0f, -1.0f),	// backward
			glm::vec3(-1.0, 0.0f,  0.0f),	// left
			glm::vec3( 1.0, 0.0f,  0.0f),	// right
		};
		
		glm::vec3 displacement;
		unsigned bestMatch = 0;

		for(auto e2 : enemies) {

			if(glm::distance(e1->_rigidBody._position, e2->_rigidBody._position) < 5.0f) {
				const glm::vec3 temp = glm::vec3(0.1f, 0.0f, 0.1f);

				e1->_rigidBody._position += temp;
				e2->_rigidBody._position -= temp;
			}
			
			if(e1->checkCollision(*e2)) {
				displacement = e1->_rigidBody._position - e2->_rigidBody._position;

				float max = 0.0f;
				for(unsigned i = 0; i < 4; ++i) {
					const float dotProduct = glm::dot(glm::normalize(displacement), directions[i]);

					if(dotProduct > max) {
						max = dotProduct;
						bestMatch = i + 1;
					}
				}

				const Direction dir = static_cast<Direction>(bestMatch);

				if(dir == LEFT) {
					e1->_rigidBody._position.x -= 0.05f;
				}
				else if(dir == RIGHT) {
					e1->_rigidBody._position.x += 0.05f;
				}
				else if(dir == FORWARD) {
					e1->_rigidBody._position.z += 0.05f;
				}
				else if(dir == BACKWARD) {
					e1->_rigidBody._position.z -= 0.05f;
				}
			}
		}

		if(e1->checkCollision(*player)) {
			displacement = e1->_rigidBody._position - player->_rigidBody._position;

			float max = 0.0f;
			for(unsigned i = 0; i < 4; ++i) {
				const float dotProduct = glm::dot(glm::normalize(displacement), directions[i]);

				if(dotProduct > max) {
					max = dotProduct;
					bestMatch = i + 1;
				}
			}

			const Direction dir = static_cast<Direction>(bestMatch);

			if(dir == LEFT) {
				e1->_rigidBody._position.x -= 0.05f;
			}
			else if(dir == RIGHT) {
				e1->_rigidBody._position.x += 0.05f;
			}
			else if(dir == FORWARD) {
				e1->_rigidBody._position.z += 0.05f;
			}
			else if(dir == BACKWARD) {
				e1->_rigidBody._position.z -= 0.05f;
			}
		}

		
	}

	dirLight._dirLightShader.loadViewMatrix(camera);
	dirLight.updateViewPos(camera.getPosition());

	glm::mat4 p = glm::perspective(glm::radians(45.0f), (float)1600.0f / (float)1200.0f, 0.1f, 100.0f);

	player->_rigidBody.setViewProjMat(camera.whereAreWeLooking(), p);
	
	for(auto x : enemies) {
		x->seek(player, dt);
		x->_rigidBody.setViewProjMat(camera.whereAreWeLooking(), p);
	}


	playerHealth->setText("Health: " + std::to_string(player->health));
	dynamic_cast<UIText*>(UI->_uiComponents.back())->setText("Kills: " + std::to_string(KILLS));
	UI->update(dt);
}

void GameScene::mouseFunction(double xpos, double ypos) {

}

void GameScene::clickFunction(int button, int action, int mods) {

}

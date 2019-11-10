#include "GameScene.h"

#include "Cappuccino/Random.h"

using namespace Cappuccino;

std::vector<std::string> GameScene::_enemyTextures = {
	"Baymax.jpg",
	"BobTheBuilder.png",
	"Deadpool.png",
	"Doomguy.png",
	"FilthyFrank.jpg",
	"Kratos.png",
	"MasterChief.png",
	"PostMalone.png",
	"Sanic.jpg",
	"Sans.jpg",
	"Shrek.jpg",
	"Spiderman.png",
	"VaultBoy.jpg"
};

GameScene::GameScene(bool firstScene) : Scene(firstScene)
{
	glm::mat4 p = glm::perspective(glm::radians(45.0f), (float)1600.0f / (float)1200.0f, 0.1f, 100.0f);
	camera.setPosition(glm::vec3(0.0f, 10.0f, 7.0f));
	camera.lookAt(glm::vec3(0.0f, 0.0f, 0.0f));
	
	player = new Player(dirLight._dirLightShader, std::vector<Texture*>{ new Texture("Jenko.png", TextureType::DiffuseMap) }, std::vector<Mesh*>{ new Mesh("humanoid2.obj") }, new Rapid(&dirLight._dirLightShader));
	player->_transform.rotate(glm::vec3(0.0f, 1.0f, 0.0f), 180);

	for(const auto& texture : _enemyTextures) {
		enemies.push_back(new Enemy(dirLight._dirLightShader, std::vector<Texture*>{ new Texture(texture, TextureType::DiffuseMap)}, std::vector<Mesh*>{ new Mesh("humanoid2.obj") }, new Pistol(&dirLight._dirLightShader)));
	}

	enemies.push_back(new Enemy(dirLight._dirLightShader, std::vector<Texture*>{ new Texture("Pacman.png",      TextureType::DiffuseMap)}, std::vector<Mesh*>{ new Mesh("pacman.obj"),   }, new Pistol(&dirLight._dirLightShader)));

	for (unsigned int i = 0; i < enemies.size(); ++i) {
		enemies[i]->_rigidBody._position = glm::vec3(randomFloat(-15.0f, 15.0f), 0.0f, randomFloat(-15.0f, -8.0f));
		enemies[i]->_rigidBody.setViewProjMat(camera.whereAreWeLooking(), p);
	}

}

bool GameScene::init() {
	player->setActive(true);
	for (auto x : enemies)
		x->setActive(true);

	return true;
}

bool GameScene::exit() {

	player->setActive(false);
	for (auto x : enemies)
		x->setActive(false);
	return true;
}

void GameScene::childUpdate(float dt) {

	glm::vec3 offset(0.0f, 10.0f, 7.0f);
	camera.setPosition(glm::vec3(player->_rigidBody._position) + offset);
	camera.lookAt(player->_rigidBody._position/* + glm::vec3(0.0f, 0.0f, -7.0f)*/);
	
	for(auto e1 : enemies) {
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

}

void GameScene::mouseFunction(double xpos, double ypos) {

}

void GameScene::clickFunction(int button, int action, int mods) {

}

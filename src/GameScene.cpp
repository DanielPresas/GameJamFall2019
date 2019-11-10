#include "GameScene.h"
using namespace Cappuccino;
GameScene::GameScene(bool firstScene) : Scene(firstScene)
{
	player = new Player(dirLight._dirLightShader, std::vector<Texture*>{ new Texture("Jenko.png", TextureType::DiffuseMap) }, std::vector<Mesh*>{ new Mesh("humanoid2.obj") });
	player->_transform.rotate(glm::vec3(0.0f, 1.0f, 0.0f), 180);
	player->_rigidBody._position = glm::vec3(0.0f, 0.0f, 3.0f);

	//enemies.push_back(new Enemy(dirLight._dirLightShader, std::vector<Texture*>{ new Texture("gunDiffuse.png", TextureType::DiffuseMap), new Texture("gunDiffuse.png", TextureType::SpecularMap)  }, std::vector<Mesh*>{ new Mesh("gun3.obj") }
	//));
	enemies.push_back(new Enemy(dirLight._dirLightShader, std::vector<Texture*>{ new Texture("Kratos.png", TextureType::DiffuseMap)}, std::vector<Mesh*>{ new Mesh("humanoid2.obj") }, new Pistol(&dirLight._dirLightShader)));
	enemies.push_back(new Enemy(dirLight._dirLightShader, std::vector<Texture*>{ new Texture("MasterChief.png", TextureType::DiffuseMap)}, std::vector<Mesh*>{ new Mesh("humanoid2.obj") }, new Rapid(&dirLight._dirLightShader)));
	enemies.push_back(new Enemy(dirLight._dirLightShader, std::vector<Texture*>{ new Texture("Schmidt.png", TextureType::DiffuseMap)}, std::vector<Mesh*>{ new Mesh("humanoid2.obj") }, new Pistol(&dirLight._dirLightShader)));
	enemies.push_back(new Enemy(dirLight._dirLightShader, std::vector<Texture*>{ new Texture("VaultBoy.jpg", TextureType::DiffuseMap)}, std::vector<Mesh*>{ new Mesh("humanoid2.obj") }, new Pistol(&dirLight._dirLightShader)));
	enemies.push_back(new Enemy(dirLight._dirLightShader, std::vector<Texture*>{ new Texture("Deadpool.png", TextureType::DiffuseMap)}, std::vector<Mesh*>{ new Mesh("humanoid2.obj") }, new Rapid(&dirLight._dirLightShader)));
	enemies.push_back(new Enemy(dirLight._dirLightShader, std::vector<Texture*>{ new Texture("Baymax.jpg", TextureType::DiffuseMap)}, std::vector<Mesh*>{ new Mesh("humanoid2.obj") }, new Pistol(&dirLight._dirLightShader)));
	enemies.push_back(new Enemy(dirLight._dirLightShader, std::vector<Texture*>{ new Texture("Pacman.png", TextureType::DiffuseMap)}, std::vector<Mesh*>{ new Mesh("pacman.obj"), }, new Pistol(&dirLight._dirLightShader)));

	glm::mat4 p = glm::mat4(1.0f);
	p = glm::perspective(glm::radians(45.0f), (float)1600.0f / (float)1200.0f, 0.1f, 100.0f);
	camera.setPosition(glm::vec3(0.0f, 10.0f, 7.0f));
	camera.lookAt(glm::vec3(0.0f, 0.0f, 0.0f));
	for (int i = 0; i < enemies.size(); ++i) {
		enemies[i]->_rigidBody._position = glm::vec3((i - 1) * 1.0f, 0.0f, -3.0f) * 2.0f;
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

	for (auto x : enemies)
		x->seek(player, dt);

}

void GameScene::mouseFunction(double xpos, double ypos) {

}

void GameScene::clickFunction(int button, int action, int mods) {

}

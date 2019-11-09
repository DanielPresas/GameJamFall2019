#include "GameScene.h"
using namespace Cappuccino;
GameScene::GameScene(bool firstScene) : Scene(firstScene)
{

	enemies.push_back(new Enemy(&dirLight._dirLightShader, std::vector<Texture*>{new Cappuccino::Texture(std::string("nut.png"), Cappuccino::TextureType::DiffuseMap) }, std::vector<Mesh*>{new Mesh("gun.obj")}));
	enemies.back()->_transform.scale(glm::vec3(1.0f, 1.0f, 1.0f), 0.05f);
	camera.lookAt(glm::vec3(0.0f, 0.0f, -3.0f));

}

bool GameScene::init() {

	for (auto x : enemies)
		x->setActive(true);
	return true;
}

bool GameScene::exit() {

	for (auto x : enemies)
		x->setActive(false);
	return true;
}

void GameScene::childUpdate(float dt) {
	dirLight._dirLightShader.loadViewMatrix(camera);
	dirLight.updateViewPos(camera.getPosition());


}

void GameScene::mouseFunction(double xpos, double ypos) {

}

void GameScene::clickFunction(int button, int action, int mods) {

}

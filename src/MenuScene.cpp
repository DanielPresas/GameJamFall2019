#include "MenuScene.h"

#include <Cappuccino/SoundSystem.h>
#include <Cappuccino/CappMacros.h>

using namespace Cappuccino;

MenuScene::MenuScene(bool isActive)
	: Scene(isActive), _in(true, std::nullopt), cursorBox(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(100.0f, 100.0f, 100.0f)), startBox(glm::vec3(0.0f, -75.0f, 0.0f), glm::vec3(200.0f, 100.0f, 200.0f)),
	creditsBox(glm::vec3(0.0f, 30.0f, 0.0f), glm::vec3(200.0f, 100.0f, 200.0f))
{
	menuShader = new Shader("screenSpaceModel.vert", "screenSpace.frag");
	ui._uiComponents.push_back(new UIText("Start", glm::vec2(1600.0f, 1200.0f), glm::vec2(-100.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.5f));
	ui._uiComponents.push_back(new UIText("Credits", glm::vec2(1600.0f, 1200.0f), glm::vec2(-100.0f, -200.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.5f));
	ui._uiComponents.push_back(new UIText("T O O  M A N Y  C H A R A C T E R S", glm::vec2(1600.0f, 1200.0f), glm::vec2(-400.0f, 600.0f), glm::vec3(1.0f, 1.0f, 1.0f), 2.5f));
	menuShader->use();
	menuShader->loadOrthoProjectionMatrix(1600.0f / 20.0f, 1200.0f / 20.0f);
	menuShader->loadViewMatrix(camera);

	musicHandle = SoundSystem::load2DSound("TitleTheme.mp3");
	groupHandle = SoundSystem::createChannelGroup("backgroundMusic");
}

bool MenuScene::init()
{
	_initialized = true;
	_shouldExit = false;

	SoundSystem::playSound2D(musicHandle, groupHandle, SoundSystem::ChannelType::SoundEffect);
	
	return true;
}

bool MenuScene::exit()
{
	_initialized = false;
	_shouldExit = true;

	SoundSystem::getChannels()[0]->stop();
	
	return true;
}

void MenuScene::childUpdate(float dt)
{

	cursorBox._position = glm::vec3(cursorPos.x, cursorPos.y, 0.0f);

	if (cursorBox.checkCollision(startBox, startBox._position, cursorBox._position)) {
		dynamic_cast<UIText*>(ui._uiComponents[0])->setTextColour(glm::vec3(1.0f, 0.0f, 0.0f));

		if (_in.clickListener.leftClicked())
			SceneManager::changeScene(0);
	}
	else
		dynamic_cast<UIText*>(ui._uiComponents[0])->setTextColour(glm::vec3(1.0f, 1.0f, 1.0f));

	if (cursorBox.checkCollision(creditsBox, creditsBox._position, cursorBox._position)) {
		dynamic_cast<UIText*>(ui._uiComponents[1])->setTextColour(glm::vec3(1.0f, 0.0f, 0.0f));

		if (_in.clickListener.leftClicked())
			SceneManager::changeScene(1);
	}
	else
		dynamic_cast<UIText*>(ui._uiComponents[1])->setTextColour(glm::vec3(1.0f, 1.0f, 1.0f));


	static float meme = 0.0f;

	meme += dt;

	dynamic_cast<UIText*>(ui._uiComponents.back())->setTextColour(glm::vec3(cosf(static_cast<float>(glfwGetTime())), sinf(static_cast<float>(glfwGetTime())), meme));

	ui.update(dt);
}

void MenuScene::mouseFunction(double xpos, double ypos)
{
	cursorPos = glm::vec2(xpos, ypos);
	cursorPos -= glm::vec2(800.0f, 600.0f);
}

void MenuScene::clickFunction(int button, int action, int mods)
{
	_in.clickListener.checkClick(button, action, mods);
}

#include "CreditsScene.h"
#include "Cappuccino/SoundSystem.h"

using namespace Cappuccino;

CreditsScene::CreditsScene(bool yn)
	:Scene(yn)
{

	_ui._uiComponents.push_back(new UIText("T O O  M A N Y  C H A R A C T E R S",			glm::vec2(1600.0f, 1200.0f), glm::vec2(-400.0f, 600.0f), glm::vec3(1.0f, 1.0f, 1.0f), 2.5f));
	_ui._uiComponents.push_back(new UIText("By SUGMA GAMES, THE ULTIMATE CROSSOVER",		 glm::vec2(1600.0f, 1200.0f), glm::vec2(-400.0f, 400.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("C A S T", glm::vec2(1600.0f, 1200.0f),			glm::vec2(-400.0f, 200.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Amtoj", glm::vec2(1600.0f, 1200.0f),			glm::vec2(-400.0f, -200.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Ash Ketchum", glm::vec2(1600.0f, 1200.0f),			glm::vec2(-400.0f, -200.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Baymax", glm::vec2(1600.0f, 1200.0f),			glm::vec2(-400.0f, -400.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Bob the Builder", glm::vec2(1600.0f, 1200.0f), glm::vec2(-400.0f, -600.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Darth Vader", glm::vec2(1600.0f, 1200.0f),			glm::vec2(-400.0f, -800.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Deadpool", glm::vec2(1600.0f, 1200.0f),			glm::vec2(-400.0f, -800.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Doomguy", glm::vec2(1600.0f, 1200.0f),			glm::vec2(-400.0f, -1000.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Filthy Frank", glm::vec2(1600.0f, 1200.0f),		glm::vec2(-400.0f, -1200.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Morgan and Gordon Freeman", glm::vec2(1600.0f, 1200.0f),			glm::vec2(-400.0f, -1400.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Jenko (my name jeff)", glm::vec2(1600.0f, 1200.0f),				glm::vec2(-400.0f, -1600.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Josh", glm::vec2(1600.0f, 1200.0f),				glm::vec2(-400.0f, -1600.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Kermit", glm::vec2(1600.0f, 1200.0f),			glm::vec2(-400.0f, -1800.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Kratos", glm::vec2(1600.0f, 1200.0f),			glm::vec2(-400.0f, -1800.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Lara Croft", glm::vec2(1600.0f, 1200.0f),			glm::vec2(-400.0f, -1800.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Luigi", glm::vec2(1600.0f, 1200.0f),			glm::vec2(-400.0f, -1800.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Mario", glm::vec2(1600.0f, 1200.0f),		glm::vec2(-400.0f, -2000.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Master Chief", glm::vec2(1600.0f, 1200.0f),		glm::vec2(-400.0f, -2000.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Neil Armstrong", glm::vec2(1600.0f, 1200.0f),	glm::vec2(-400.0f, -2200.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Pacman", glm::vec2(1600.0f, 1200.0f),			glm::vec2(-400.0f, -2600.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Post Malone", glm::vec2(1600.0f, 1200.0f),		glm::vec2(-400.0f, -2400.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("The Power Rangers", glm::vec2(1600.0f, 1200.0f),		glm::vec2(-400.0f, -2400.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Ronald Mcdonald", glm::vec2(1600.0f, 1200.0f),	glm::vec2(-400.0f, -2800.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Saitama the One Punch Man", glm::vec2(1600.0f, 1200.0f),			glm::vec2(-400.0f, -3000.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Sanic", glm::vec2(1600.0f, 1200.0f),			glm::vec2(-400.0f, -3000.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Sans", glm::vec2(1600.0f, 1200.0f),				glm::vec2(-400.0f, -3200.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Scott Pilgrim", glm::vec2(1600.0f, 1200.0f),	glm::vec2(-400.0f, -3400.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Shrek", glm::vec2(1600.0f, 1200.0f),			glm::vec2(-400.0f, -3600.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Shmidtt>D?!?E!@", glm::vec2(1600.0f, 1200.0f),			glm::vec2(-400.0f, -3600.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Spiderman", glm::vec2(1600.0f, 1200.0f),		glm::vec2(-400.0f, -3800.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Thomas the Tank Engine", glm::vec2(1600.0f, 1200.0f),glm::vec2(-400.0f, -4000.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Percy the Tank Engine", glm::vec2(1600.0f, 1200.0f),glm::vec2(-400.0f, -4000.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("James the Tank Engine", glm::vec2(1600.0f, 1200.0f),glm::vec2(-400.0f, -4000.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));
	_ui._uiComponents.push_back(new UIText("Vault Boy", glm::vec2(1600.0f, 1200.0f),		glm::vec2(-400.0f, -4200.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f));

	_ui._uiComponents.push_back(new UIText("The RIP List", glm::vec2(1600.0f, 1200.0f),		glm::vec2(-400.0f, -4200.0f), glm::vec3(1.0f, 1.0f, 1.0f), 2.5f));
	_ui._uiComponents.push_back(new UIText("RIP:", glm::vec2(1600.0f, 1200.0f),		glm::vec2(-400.0f, -4200.0f), glm::vec3(1.0f, 1.0f, 1.0f), 2.5f));
	_ui._uiComponents.push_back(new UIText("Danny Devito", glm::vec2(1600.0f, 1200.0f),		glm::vec2(-400.0f, -4200.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.f));
	_ui._uiComponents.push_back(new UIText("Jack Black", glm::vec2(1600.0f, 1200.0f),		glm::vec2(-400.0f, -4200.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.f));
	_ui._uiComponents.push_back(new UIText("Jack White", glm::vec2(1600.0f, 1200.0f),		glm::vec2(-400.0f, -4200.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.f));
	_ui._uiComponents.push_back(new UIText("Jack Gray", glm::vec2(1600.0f, 1200.0f),		glm::vec2(-400.0f, -4200.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.f));
	_ui._uiComponents.push_back(new UIText("Hamraj", glm::vec2(1600.0f, 1200.0f),		glm::vec2(-400.0f, -4200.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.f));
	_ui._uiComponents.push_back(new UIText("", glm::vec2(1600.0f, 1200.0f),		glm::vec2(-400.0f, -4200.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.f));
	
	for (unsigned i = 0; i < _ui._uiComponents.size();i++) {
		if (i == 0 || i == 1 || i == 2)
			continue;
		dynamic_cast<UIText*>(_ui._uiComponents[i])->setTextPosition(glm::vec2(-400.0f, -(float)i * 200.0f));
	}

	sound = SoundSystem::load2DSound("credits.mp3");
	group = SoundSystem::createChannelGroup("group222");

}

bool CreditsScene::init()
{
	SoundSystem::playSound2D(sound, group, SoundSystem::ChannelType::SoundEffect);
	return false;
}

bool CreditsScene::exit()
{
	SoundSystem::getChannels()[0]->stop();
	return false;
}

void CreditsScene::childUpdate(float dt)
{

	for (auto x : _ui._uiComponents) {
		dynamic_cast<UIText*>(x)->setTextPosition(dynamic_cast<UIText*>(x)->getPosition() + glm::vec2(0.0f, dt*200.f));
	}

	_ui.update(dt);
}

void CreditsScene::mouseFunction(double xpos, double ypos)
{
}

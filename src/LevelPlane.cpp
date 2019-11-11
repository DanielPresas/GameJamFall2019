#include "LevelPlane.h"

using namespace Cappuccino;

LevelPlane::LevelPlane(Shader& shader) :
	GameObject(shader, std::vector<Texture*>{ new Texture("levelPlane.jpg", TextureType::DiffuseMap) }, std::vector<Mesh*>{ new Mesh("levelPlane.obj") })
{
	
}

void LevelPlane::childUpdate(float dt) {}

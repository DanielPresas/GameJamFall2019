#pragma once
#include "Cappuccino/FontManager.h"
#include "Cappuccino/Transform.h"
#include <vector>

namespace Cappuccino {

	class Mesh;

	/*
	base class for your UI elements
	*/
	class UIComponent {
	public:
		/*
		Purp: base class function with no definition, some components may not need an update function
		*/
		virtual void updateComponent(float dt);

		/*
		Purp: base class draw function, has no definition
		*/
		virtual void drawComponent();

	};

	class UserInterface {
	public:

		void update(float dt);

		std::vector<UIComponent*> _uiComponents;
	};

	//UI components

	class UIText : public UIComponent, public Text {
	public:
		UIText(const std::string& text, const glm::vec2& windowSize, const glm::vec2& defaultPosition, const glm::vec3& defaultColour, float defaultScale);

		void drawComponent() override;

	private:

		Shader _textShader { "font.vert", "font.frag" };

	};

	class UIBar : public UIComponent {
	public:

		enum class OriginPoint {
			Middle = 0,
			BottomRight,
			BottomLeft,
		};


		UIBar(const glm::vec2& defaultPosition, const glm::vec4& defaultColour, const glm::vec3& barDimensions, OriginPoint point);

		void updateComponent(float dt) override;
		void drawComponent() override;

		void setShader(const Shader& newShader) { _barShader = newShader; }
		void setScaleFromRight(bool yn) { _scaleFromRight = yn; }
		void setPosition(const glm::vec2& newPosition) { _position = newPosition; }
		Transform _transform;

		glm::vec3& getBarDimensions() { return _barDimensions; }
	private:
		glm::vec3 _barDimensions;
		glm::vec2 _position;
		glm::vec4 _colour;
		Shader _barShader{ "screenSpaceModel.vert","screenSpace.frag" };
		bool _scaleFromRight;
		Mesh* _barMesh;
	};
}
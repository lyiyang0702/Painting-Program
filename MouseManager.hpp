#pragma once
using namespace sf;


class MouseManager {
public:
	Vector2i GetMousePosition(RenderWindow& window);
	Vector2f GetMouseCoordination(RenderWindow& window);
};
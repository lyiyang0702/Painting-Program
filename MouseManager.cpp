#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include "MouseManager.hpp"

Vector2i MouseManager::GetMousePosition(RenderWindow& window) {
	return Mouse::getPosition(window);
}

Vector2f MouseManager::GetMouseCoordination(RenderWindow& window) {
	return window.mapPixelToCoords(Mouse::getPosition(window));
}


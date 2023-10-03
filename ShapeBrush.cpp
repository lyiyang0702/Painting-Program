#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include "ShapeBrush.hpp";
#include "MouseManager.hpp"
#include <iostream>

void ShapeBrush::DrawShape(RenderWindow& window, Shapes shape, Vector2f size) {
	MouseManager mouse;
	shapeType = shape;
	switch (shape)
	{
	case Circle:
	{
		CircleShape circle(50.0f);
		circle.setPosition(mouse.GetMouseCoordination(window));
		window.draw(circle);
	}
	break;
	case Rectan:
	{
		RectangleShape rectangle(size);
		rectangle.setPosition(mouse.GetMouseCoordination(window));
		window.draw(rectangle);
	}
	break;
	case Triangle: {
		CircleShape triangle(50.0f, 3);
		triangle.setPosition(mouse.GetMouseCoordination(window));
		window.draw(triangle);
	}
	break;
	default:
		break;
	}

}


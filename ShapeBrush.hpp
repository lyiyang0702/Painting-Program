#pragma once
using namespace sf;
enum Shapes
{
	Circle,
	Rectan,
	Triangle
};

class ShapeBrush {

public:
	Shapes shapeType;
	void DrawShape(RenderWindow& window,Shapes shape, Vector2f size = Vector2f(0.f, 0.f));
};
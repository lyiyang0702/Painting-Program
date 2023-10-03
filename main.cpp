#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "MouseManager.hpp"
#include <iostream>
#include <vector>
using namespace std;
using namespace sf;
int main()
{
    MouseManager mouse;
    int brushIndex = 0;
    int colorIndex = 0;
    int leftIsDown = false;
    PrimitiveType brushes[3] = { LinesStrip, TriangleStrip, Lines };
    Color colors[3] = { Color::White, Color::Green, Color::Red };
    PrimitiveType brushType = brushes[0];
    Color currCol = colors[0];
    vector<VertexArray> lines;
    Vector2i lastMousePos(0, 0);

    RenderWindow window(VideoMode(800,600), "Painting program");
    window.setFramerateLimit(30);

    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {

            if (event.type == Event::Closed) 
                window.close();
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Key::Escape) {

                    lines.clear();
                }
                if (event.key.code == Keyboard::Key::Right) {
                    if (colorIndex < 2) {
                        colorIndex++;
                    }
                    else {
                        colorIndex = 0;
                    }

                    currCol = colors[colorIndex];
                }

            }
            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left) {

                    lines.push_back(VertexArray());
                    lines.back().setPrimitiveType(brushType);

                    
                    leftIsDown = true;
                }

            }

            if (event.type == Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == Mouse::Left) {
                leftIsDown = false;
            }

                if (event.mouseButton.button == Mouse::Right) {
                    if (brushIndex < 2) {
                        brushIndex++;
                    }
                    else {
                        brushIndex = 0;
                    }
                    brushType = brushes[brushIndex];

                }
            }

            if (event.type == Event::MouseWheelMoved) {

                if (event.mouseWheel.delta < 0) {
     
                }

                if (event.mouseWheel.delta > 0) {

                }

            }
        }

        if (leftIsDown)
        {
            if (lastMousePos != Mouse::getPosition())
            {
                Vector2f mouseCoord = mouse.GetMouseCoordination(window);
                //cout << "vertices in line " << lines.size() << endl;
                // add vertex
               lines.back().append(Vertex(mouseCoord, currCol));
                lastMousePos = Mouse::getPosition();
            }
        }

        window.clear(Color::Black);

        for (int i = 0; i < lines.size(); i++)
        {
            window.draw(lines[i]);
       }
        window.display();
    }


    return 0;
}
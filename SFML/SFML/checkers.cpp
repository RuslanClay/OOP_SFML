#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<Windows.h>
#include "Game.h"
#include"settings.h"
#include<thread>
using namespace sf;
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	ContextSettings settings;
	settings.antialiasingLevel = 20;//сглаживание

	RenderWindow window(VideoMode(500, 500), "Checker", sf::Style::Close | sf::Style::Titlebar, settings);
	Image icon;
	if (!icon.loadFromFile("Images/icon.png"))
		exit(1);
	window.setIcon(32, 32, icon.getPixelsPtr());

	Game game;
	bool start = 0;
	int NumberImage = 1;
	Button PvP("", { 268,50 }, 40, Color::Cyan, Color::Black, 3, Color::Black);
	Button PvE("", { 268,50 }, 40, Color::Cyan, Color::Black, 3, Color::Black);
	Button Settings("", { 268,50 }, 40, Color::Cyan, Color::Black, 3, Color::Black);

	PvP.setPosition({ 116,87.5 });
	PvE.setPosition({ 116,225 });
	Settings.setPosition({ 116,362.5 });

	Font font;
	font.loadFromFile("Font//bahnschrift.ttf");

	PvP.setFont(font);
	PvE.setFont(font);
	Settings.setFont(font);

	Text textPvP, textPvE, textSettings;
	textPvP = Text(L"Игра с другом", font, 40);
	textPvP.setPosition(116, 87.5);
	textPvP.setStyle(Text::Bold);
	textPvP.setFillColor(Color::Black);

	textPvE = Text(L"Игра с ИИ", font, 40);
	textPvE.setPosition(156, 225);
	textPvE.setStyle(Text::Bold);
	textPvE.setFillColor(Color::Black);

	textSettings = Text(L"Настройки", font, 40);
	textSettings.setPosition(146, 362.5);
	textSettings.setStyle(Text::Bold);
	textSettings.setFillColor(Color::Black);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			switch (event.type)
			{
			case Event::Closed:
				window.close();
			case Event::MouseMoved:
				if (PvP.isMouseOver(window))
					PvP.setBackColor(Color(247, 255, 0));
				else
					PvP.setBackColor(Color::Cyan);

				if (PvE.isMouseOver(window))
					PvE.setBackColor(Color(247, 255, 0));
				else
					PvE.setBackColor(Color::Cyan);

				if (Settings.isMouseOver(window))
					Settings.setBackColor(Color(247, 255, 0));
				else
					Settings.setBackColor(Color::Cyan);
				break;
			case Event::MouseButtonPressed:
				if (PvP.isMouseOver(window))
				{	
					PvEGame(settings, 0);
				}

				if (Settings.isMouseOver(window))//открытие окна настроек
				{	
					CheckerSettings(settings);
				}
				if (PvE.isMouseOver(window))//открытие окна настроек
				{
					PvEGame(settings, 1);	
				}
				break;

			default:
				break;
			}
		}

		window.clear(Color(245, 210, 175));
		PvP.DrawTo(window);
		PvE.DrawTo(window);
		Settings.DrawTo(window);
		window.draw(textPvP);
		window.draw(textPvE);
		window.draw(textSettings);
		window.display();
	}
	return 0;
}
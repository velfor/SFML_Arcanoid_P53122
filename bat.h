#pragma once
#include "settings.h"
#include "SFML/Graphics.hpp"

struct Bat {
	sf::RectangleShape shape;
	float speedX = 0.f;
};

void batInit(Bat& bat) {
	bat.shape.setSize(BAT_SIZE);
	bat.shape.setFillColor(BAT_COLOR);
	bat.shape.setPosition(BAT_START_POS);
}

void batUpdate(Bat& bat) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
		bat.speedX = -BAT_SPEED;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
		bat.speedX = BAT_SPEED;
	bat.shape.move(bat.speedX, 0);
	bat.speedX = 0;
	if (bat.shape.getPosition().x <= 0) 
		bat.shape.setPosition(0, BAT_START_POS.y);
	if (bat.shape.getPosition().x >= WINDOW_WIDTH - BAT_WIDTH) 
		bat.shape.setPosition(WINDOW_WIDTH - BAT_WIDTH, BAT_START_POS.y);
}

void batDraw(sf::RenderWindow& window, Bat bat) {
	window.draw(bat.shape);
}
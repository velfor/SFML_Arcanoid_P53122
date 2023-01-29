#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
#include "ball.h"
#include "bat.h"
#include "brick.h"
#include "brickRow.h"

void initBat(sf::RectangleShape& bat, const sf::Color batColor, const sf::Vector2f batPosition)
{
	bat.setSize(BAT_SIZE);
	bat.setFillColor(BAT_COLOR);
	bat.setPosition(BAT_START_POS);
}

bool pointInRect(sf::RectangleShape bat, sf::Vector2f point) {
	float batX = bat.getPosition().x;
	float batY = bat.getPosition().y;
	return (point.x >= batX && point.x <= batX + bat.getSize().x) 
		&& (point.y >= batY && point.y <= batY + bat.getSize().y);
}

void checkCollisions(Ball& ball, const Bat& bat, BrickField& field) {
	float ballX = ball.shape.getPosition().x;
	float ballY = ball.shape.getPosition().y;
	sf::Vector2f midTop{ ballX + BALL_RADIUS, ballY };
	sf::Vector2f midLeft{ ballX , ballY + BALL_RADIUS };
	sf::Vector2f midBottom{ ballX + BALL_RADIUS, ballY + 2 * BALL_RADIUS };
	sf::Vector2f midRight{ ballX + 2 * BALL_RADIUS, ballY + BALL_RADIUS };
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			//нижний край кирпича
			if (pointInRect(field.arr[i][j].shape, midTop)) {
				field.arr[i][j].shape.setPosition(900, 0);
				ball.speedy = -ball.speedy;
				break;
			}
			//верхний край кирпича
			if (pointInRect(field.arr[i][j].shape, midBottom)) {
				field.arr[i][j].shape.setPosition(900, 0);
				ball.speedy = -ball.speedy;
				break;
			}
			//левый край кирпича
			if (pointInRect(field.arr[i][j].shape, midRight)) {
				field.arr[i][j].shape.setPosition(900, 0);
				ball.speedx = -ball.speedx;
				break;
			}
			//правый край кирпича
			if (pointInRect(field.arr[i][j].shape, midLeft)) {
				field.arr[i][j].shape.setPosition(900, 0);
				ball.speedx = -ball.speedx;
				break;
			}
		}
	}
}
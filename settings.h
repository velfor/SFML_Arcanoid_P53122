#pragma once
#include <SFML/Graphics.hpp>

const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 600;
const std::string WINDOW_TITLE = "SFML Lesson2";
const float FPS = 60.f;

const float BAT_WIDTH = 20.f;
const float BAT_HEIGHT = 80.f;
const float BAT_OFFSET = 50.f;
const sf::Vector2f batSize(20.f, 80.f);
const sf::Color leftBatColor{ 158,20,37 };
const sf::Color rightBatColor{ 20,158,49 };
const float batSpeed = 5.f;
const sf::Vector2f leftBatStartPos{ BAT_OFFSET, (WINDOW_HEIGHT - BAT_HEIGHT) / 2 };
const sf::Vector2f rightBatStartPos{ WINDOW_WIDTH - BAT_OFFSET, (WINDOW_HEIGHT - BAT_HEIGHT) / 2 };

const float BALL_RADIUS = 25.f;
const sf::Color BALL_COLOR{ sf::Color::Yellow };
const sf::Vector2f BALL_START_POS{ 
	(WINDOW_WIDTH - 2 * BALL_RADIUS) / 2, 
	(WINDOW_HEIGHT - 2 * BALL_RADIUS) / 2 
};

const int CHAR_SIZE = 64;
const sf::Vector2f TEXT_START_POS{ 10.f, 10.f };

const float BRICK_WIDTH = 40.f;
const float BRICK_HEIGHT = 20.f;
#include "settings.h"
#include "functions.h"
#include "ball.h"
#include <ctime>
#include "textobj.h"

using namespace sf;


int main()
{
	srand(time(nullptr));
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	//создание объектов игры
	//ракетки
	RectangleShape leftBat, rightBat;
	initBat(leftBat, leftBatColor, leftBatStartPos);
	initBat(rightBat, rightBatColor, rightBatStartPos);
	float leftBatSpeedY = 0.f;
	float rightBatSpeedY = 0.f;

	//шарик
	Ball ball;
	ballInit(ball);
	//текст для счета
	TextObj scoreText;
	textInit(scoreText, ball.score);
	
	
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		//1 Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}

		//2 Обновление объектов

		ballUpdate(ball);
		textUpdate(scoreText, ball.score);

		//Проверка нажатий клавиш
		//если клавиша W нажата - лева ракетка вниз
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			leftBatSpeedY = -batSpeed;
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			leftBatSpeedY = batSpeed;
		}
		//двигаем ракетку		
		leftBat.move(0, leftBatSpeedY);
		//и сразу обнуляем скорость
		leftBatSpeedY = 0;
		//правая ракетка
		if (Keyboard::isKeyPressed(Keyboard::Up)) 
			rightBatSpeedY = -batSpeed;
		if (Keyboard::isKeyPressed(Keyboard::Down)) 
			rightBatSpeedY = batSpeed;
		//двигаем ракетку		
		rightBat.move(0, rightBatSpeedY);
		//и сразу обнуляем скорость
		rightBatSpeedY = 0;

		//Отбивание мяча от ракетки
		//вычисляем точки-середины сторон описанного вокруг мяча квадрата
		float ballX = ball.shape.getPosition().x;
		float ballY = ball.shape.getPosition().y;
		Vector2f midTop{ ballX + BALL_RADIUS, ballY };
		Vector2f midLeft{ ballX , ballY + BALL_RADIUS };
		Vector2f midBottom{ ballX + BALL_RADIUS, ballY + 2 * BALL_RADIUS };
		Vector2f midRight{ ballX + 2 * BALL_RADIUS, ballY + BALL_RADIUS };
		//ударился об левую ракетку
		if (pointInRect(leftBat, midLeft)) ball.speedx = -ball.speedx;
		if (pointInRect(leftBat,midBottom) || pointInRect(leftBat, midTop))
			ball.speedy = -ball.speedy;
		//ударился об правую ракетку
		if (pointInRect(rightBat, midRight)) ball.speedx = -ball.speedx;
		if (pointInRect(rightBat, midBottom) || 
			pointInRect(rightBat, midTop))
			ball.speedy = -ball.speedy;

		//3 Отрисовка окна
		//3.1 Очистка окна
		window.clear();
		//3.2 Отрисовка объектов (В ПАМЯТИ!)
		ballDraw(window, ball);
		window.draw(leftBat);
		window.draw(rightBat);
		textDraw(window, scoreText);
		//3.3 вывод на экран
		window.display();
	}
	return 0;
}
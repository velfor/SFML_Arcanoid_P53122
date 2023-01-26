#include "settings.h"
#include "functions.h"
#include "ball.h"
#include <ctime>
#include "textobj.h"
#include "bat.h"
#include "brickRow.h"

using namespace sf;


int main()
{
	srand(time(nullptr));
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	//создание объектов игры
	
	//шарик
	Ball ball;
	ballInit(ball);
	Bat bat;
	batInit(bat);
	//текст для счета
	TextObj scoreText;
	textInit(scoreText, ball.score);
	BrickField field;
	brickFieldInint(field);
	
	
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

		

		//Отбивание мяча от ракетки
		//вычисляем точки-середины сторон описанного вокруг мяча квадрата
		float ballX = ball.shape.getPosition().x;
		float ballY = ball.shape.getPosition().y;
		Vector2f midTop{ ballX + BALL_RADIUS, ballY };
		Vector2f midLeft{ ballX , ballY + BALL_RADIUS };
		Vector2f midBottom{ ballX + BALL_RADIUS, ballY + 2 * BALL_RADIUS };
		Vector2f midRight{ ballX + 2 * BALL_RADIUS, ballY + BALL_RADIUS };
		

		//3 Отрисовка окна
		//3.1 Очистка окна
		window.clear();
		//3.2 Отрисовка объектов (В ПАМЯТИ!)
		ballDraw(window, ball);
		batDraw(window, bat);
		textDraw(window, scoreText);
		brickFieldDraw(window, field);
		//3.3 вывод на экран
		window.display();
	}
	return 0;
}
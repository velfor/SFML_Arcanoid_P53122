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
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	//�������� �������� ����
	
	//�����
	Ball ball;
	ballInit(ball);
	Bat bat;
	batInit(bat);
	//����� ��� �����
	TextObj scoreText;
	textInit(scoreText, ball.score);
	BrickField field;
	brickFieldInint(field);
	
	
	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		//1 ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}

		//2 ���������� ��������

		ballUpdate(ball);
		textUpdate(scoreText, ball.score);
		
		checkCollisions(ball, bat, field);

		//3 ��������� ����
		//3.1 ������� ����
		window.clear();
		//3.2 ��������� �������� (� ������!)
		ballDraw(window, ball);
		batDraw(window, bat);
		textDraw(window, scoreText);
		brickFieldDraw(window, field);
		//3.3 ����� �� �����
		window.display();
	}
	return 0;
}
#include "settings.h"
#include "functions.h"
#include "game.h"
#include <ctime>
using namespace sf;

int main()
{
	RenderWindow window(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, Style::Titlebar | Style::Close);
	window.setPosition(Vector2i{ (1920 - (int)WINDOW_WIDTH) / 2, 0 });
	window.setFramerateLimit(FPS);

	int timer = 0, n = 0, index, minut = 0, el = 0;
	all_text text;
	all_text font;
	all_text hp;
	all_text point;
	textInit(text, font);
	PText1(text, timer, hp, point, minut);

	RoadLayer grass, sand, road, grass1, sand1, road1, car1, car2[3], fence, box;
	initRoadL(grass, Vector2f{ 0.f,0.f }, "grass.jpg");
	initRoadL(sand, Vector2f{ 75.f,0.f }, "sand.jpg");
	initRoadL(road, Vector2f{ 100.f,0.f }, "road.jpg");
	initRoadL(grass1, Vector2f{ 0.f,-1000.f }, "grass.jpg");
	initRoadL(sand1, Vector2f{ 75.f,-1000.f }, "sand.jpg");
	initRoadL(road1, Vector2f{ 100.f,-1000.f }, "road.jpg");
	initRoadL(car1, Vector2f{ 400.f,450.f }, "car1.png");
	initRoadL(fence, Vector2f{ 200.f,-150.f }, "fence.png");
	initRoadL(box, Vector2f{ 200.f,-150.f }, "box1.jpg");
	for (int i = 0; i < 3; i++)
	{
		initRoadL(car2[i], Vector2f{ 150.f,-250.f }, "car2.png");
	}
	float speed = 10, car_speedx = 0, car_speedy = 0, car2_speedy = 0, speedF = 0, speedB = 0;

	while (window.isOpen())
	{
		srand(time(nullptr));
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		if (hp.hp != 0) {
			n++;
			if (n >= 45)
			{
				timer++;
				n = 0;
			}
			text.text[0].setString(std::to_string(timer));

			grass.sprite.move(0, speed);
			grass1.sprite.move(0, speed);
			sand.sprite.move(0, speed);
			sand1.sprite.move(0, speed);
			road.sprite.move(0, speed);
			road1.sprite.move(0, speed);
			if (grass.sprite.getPosition().y >= WINDOW_HEIGHT)
				grass.sprite.setPosition(0, -1000);
			if (grass1.sprite.getPosition().y >= WINDOW_HEIGHT)
				grass1.sprite.setPosition(0, -1000);
			if (sand.sprite.getPosition().y >= WINDOW_HEIGHT)
				sand.sprite.setPosition(75, -1000);
			if (sand1.sprite.getPosition().y >= WINDOW_HEIGHT)
				sand1.sprite.setPosition(75, -1000);
			if (road.sprite.getPosition().y >= WINDOW_HEIGHT)
				road.sprite.setPosition(100, -1000);
			if (road1.sprite.getPosition().y >= WINDOW_HEIGHT)
				road1.sprite.setPosition(100, -1000);

			if (timer >= 20)
			{
				timer = 0;
				minut++;
				text.text[4].setString(std::to_string(minut));
				speed++;
			}

			if (minut >= 5)speed = 0;

			car2[0].sprite.move(0, car2_speedy);
			if (timer % 10 == 0 && timer != 0)
			{
				index = rand() % 2;
				if (index == 0)
				{
					car2[0].sprite.setPosition(150.f, -250.f);
					car2_speedy = speed - 4;
				}
				if (index == 1)
				{
					car2[0].sprite.setPosition(350.f, -250.f);
					car2_speedy = speed - 4;
				}
			}

			if (box.sprite.getPosition().y <= -100 && fence.sprite.getPosition().y <= -100) el = 0;
			fence.sprite.move(0, speedF);
			box.sprite.move(0, speedB);
			srand(time(nullptr));
			if (timer % 4 == 0 && el == 0)
			{
				index = rand() % 8;
				if (index == 0)
				{
					fence.sprite.setPosition(100.f, -250.f);
					speedF = speed;
				}
				else if (index == 1)
				{
					fence.sprite.setPosition(200.f, -250.f);
					speedF = speed;
				}
				else if (index == 2)
				{
					fence.sprite.setPosition(300.f, -250.f);
					speedF = speed;
				}
				else if (index == 3)
				{
					fence.sprite.setPosition(400.f, -250.f);
					speedF = speed;
				}
				else if (index == 4)
				{
					box.sprite.setPosition(100.f, -250.f);
					speedB = speed;
				}
				else if (index == 5)
				{
					box.sprite.setPosition(200.f, -250.f);
					speedB = speed;
				}
				else if (index == 6)
				{
					box.sprite.setPosition(300.f, -250.f);
					speedB = speed;
				}
				else if (index == 7)
				{
					box.sprite.setPosition(400.f, -250.f);
					speedB = speed;
				}
				el++;
				/*int x, y;
				int s = rand() % 4;
				y = rand() % 951 - 800;
				if (s == 0) x = 100;
				else if (s == 1)x = 200;
				else if (s == 2)x = 300;
				else if (s == 3)x = 400;
				box.sprite.setPosition(x, y);*/
			}

			if (Keyboard::isKeyPressed(Keyboard::W)) car_speedy = -7;
			if (Keyboard::isKeyPressed(Keyboard::A)) car_speedx = -7;
			if (Keyboard::isKeyPressed(Keyboard::S)) car_speedy = 7;
			if (Keyboard::isKeyPressed(Keyboard::D)) car_speedx = 7;

			car1.sprite.move(car_speedx, car_speedy);
			car_speedx = 0.f;
			car_speedy = 0.f;
			if (car1.sprite.getPosition().y <= 0 || car1.sprite.getPosition().y >= WINDOW_HEIGHT)
				car1.sprite.setPosition(car1.sprite.getPosition().x, 0);
			if (car1.sprite.getPosition().y + 200 >= WINDOW_HEIGHT || car1.sprite.getPosition().y >= WINDOW_WIDTH)
				car1.sprite.setPosition(car1.sprite.getPosition().x, WINDOW_HEIGHT - 200);
			if (car1.sprite.getPosition().x <= 100 || car1.sprite.getPosition().x >= WINDOW_HEIGHT)
				car1.sprite.setPosition(100, car1.sprite.getPosition().y);
			if (car1.sprite.getPosition().x + 100 >= WINDOW_WIDTH - 300 || car1.sprite.getPosition().x >= WINDOW_WIDTH - 300)
				car1.sprite.setPosition(WINDOW_WIDTH - 300 - 100, car1.sprite.getPosition().y);


			if ((car2[0].sprite.getPosition().x + 100 >= car1.sprite.getPosition().x && car1.sprite.getPosition().x + 100 >= car2[0].sprite.getPosition().x)
				&& (car2[0].sprite.getPosition().y <= car1.sprite.getPosition().y + 200 && car1.sprite.getPosition().y <= car2[0].sprite.getPosition().y + 200))
			{
				hp.hp--;
				text.text[2].setString(std::to_string(hp.hp));
				car2[0].sprite.setPosition(150.f, -250.f);
				car2_speedy = 0;
			}
			if ((fence.sprite.getPosition().x + 90 >= car1.sprite.getPosition().x && car1.sprite.getPosition().x + 90 >= fence.sprite.getPosition().x)
				&& (fence.sprite.getPosition().y <= car1.sprite.getPosition().y + 200 && car1.sprite.getPosition().y <= fence.sprite.getPosition().y + 40))
			{
				hp.hp--;
				text.text[2].setString(std::to_string(hp.hp));
				fence.sprite.setPosition(150.f, -250.f);
				speedF = 0;
			}
			if ((box.sprite.getPosition().x + 90 >= car1.sprite.getPosition().x && car1.sprite.getPosition().x + 90 >= box.sprite.getPosition().x)
				&& (box.sprite.getPosition().y <= car1.sprite.getPosition().y + 200 && car1.sprite.getPosition().y <= box.sprite.getPosition().y + 40))
			{
				hp.hp--;
				text.text[2].setString(std::to_string(hp.hp));
				box.sprite.setPosition(150.f, -250.f);
				speedB = 0;
			}
			if (car2[0].sprite.getPosition().y >= 1000)
			{
				car2[0].sprite.setPosition(-150.f, -250.f);
				point.point += 2;
			}
			if (fence.sprite.getPosition().y >= 1000)
			{
				fence.sprite.setPosition(-100.f, -250.f);
				point.point++;
			}
			if (box.sprite.getPosition().y >= 1000)
			{
				box.sprite.setPosition(-100.f, -650.f);
				point.point++;
			}
			text.text[3].setString(std::to_string(point.point));
		}

		window.clear();
		window.draw(grass.sprite);
		window.draw(sand.sprite);
		window.draw(road.sprite);
		window.draw(grass1.sprite);
		window.draw(sand1.sprite);
		window.draw(road1.sprite);
		window.draw(fence.sprite);
		window.draw(box.sprite);
		for (int i = 0; i < 5; i++)
			window.draw(text.text[i]);
		for (int i = 0; i < 3; i++)
			window.draw(car2[i].sprite);
		window.draw(car1.sprite);
		if (minut >= 5) window.draw(text.text[5]);
		window.display();
	}
	return 0;
}
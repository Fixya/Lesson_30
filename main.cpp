#include "settings.h"
#include "functoins.h"
#include "game.h"
#include <ctime>
using namespace sf;

int main()
{
	RenderWindow window(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, Style::Titlebar | Style::Close);
	window.setPosition(Vector2i{ (1920 - (int)WINDOW_WIDTH) / 2, 0 });
	window.setFramerateLimit(FPS);

	RoadLayer grass, sand, road, grass1, sand1, road1, car1, car2[3];
	initRoadL(grass, Vector2f{ 0.f,0.f }, "grass.jpg");
	initRoadL(sand, Vector2f{ 75.f,0.f }, "sand.jpg");
	initRoadL(road, Vector2f{ 100.f,0.f }, "road.jpg");
	initRoadL(grass1, Vector2f{ 0.f,-1000.f }, "grass.jpg");
	initRoadL(sand1, Vector2f{ 75.f,-1000.f }, "sand.jpg");
	initRoadL(road1, Vector2f{ 100.f,-1000.f }, "road.jpg");
	initRoadL(car1, Vector2f{ 400.f,450.f }, "car1.jpg");
	for (int i = 0; i < 3; i++)
	{
		initRoadL(car2[i], Vector2f{ -150.f,-250.f }, "car2.jpg");
	}
	float speed = 5, car_speedx=0, car_speedy=0, car1_speedx = 0, car1_speedy = 0;


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		grass.sprite.move(0, speed);
		grass1.sprite.move(0, speed);
		sand.sprite.move(0, speed);
		sand1.sprite.move(0, speed);
		road.sprite.move(0, speed);
		road1.sprite.move(0, speed);
		if (grass.sprite.getPosition().y >= WINDOW_HEIGHT)
		{
			grass.sprite.setPosition(0, -1000);
		}
		if (grass1.sprite.getPosition().y >= WINDOW_HEIGHT)
		{
			grass1.sprite.setPosition(0, -1000);
		}
		if (sand.sprite.getPosition().y >= WINDOW_HEIGHT)
		{
			sand.sprite.setPosition(75, -1000);
		}
		if (sand1.sprite.getPosition().y >= WINDOW_HEIGHT)
		{
			sand1.sprite.setPosition(75, -1000);
		}
		if (road.sprite.getPosition().y >= WINDOW_HEIGHT)
		{
			road.sprite.setPosition(100, -1000);
		}
		if (road1.sprite.getPosition().y >= WINDOW_HEIGHT)
		{
			road1.sprite.setPosition(100, -1000);
		}

		int index = rand() % 2;
		if (index == 0)
		{
			car2[0].sprite.setPosition(350, -200);
			car2[0].sprite.move(0, speed);
		}

		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			car_speedy = -7;
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			car_speedx = -7;
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			car_speedy = 7;
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			car_speedx = 7;
		}
		car1.sprite.move(car_speedx, car_speedy);
		car_speedx = 0.f;
		car_speedy = 0.f;
		if (car1.sprite.getPosition().y <= 0 || car1.sprite.getPosition().y >= WINDOW_HEIGHT)
		{
			car1.sprite.setPosition(car1.sprite.getPosition().x, 0);
		}
		if (car1.sprite.getPosition().y + 200 >= WINDOW_HEIGHT || car1.sprite.getPosition().y >= WINDOW_WIDTH)
		{
			car1.sprite.setPosition(car1.sprite.getPosition().x, WINDOW_HEIGHT - 200);
		}
		if (car1.sprite.getPosition().x <= 0 || car1.sprite.getPosition().x >= WINDOW_HEIGHT)
		{
			car1.sprite.setPosition(0, car1.sprite.getPosition().y);
		}
		if (car1.sprite.getPosition().x + 100 >= WINDOW_WIDTH - 200 || car1.sprite.getPosition().x >= WINDOW_WIDTH - 200)
		{
			car1.sprite.setPosition(WINDOW_WIDTH - 200 - 100, car1.sprite.getPosition().y);
		}

		/*float midleftx = car1.sprite.getPosition().x;
		float midlefty = car1.sprite.getPosition().y + 100;
		float midrightx = car1.sprite.getPosition().x + 100;
		float midrighty = car1.sprite.getPosition().y + 100;
		float midupx = car1.sprite.getPosition().x + 50;
		float midupy = car1.sprite.getPosition().y;
		float middownx = car1.sprite.getPosition().x + 50;
		float middowny = car1.sprite.getPosition().y + 200;*/

		window.clear();
		window.draw(grass.sprite);
		window.draw(sand.sprite);
		window.draw(road.sprite);
		window.draw(grass1.sprite);
		window.draw(sand1.sprite);
		window.draw(road1.sprite);
		for (int i = 0; i < 3; i++)
		{
			window.draw(car2[i].sprite);
		}
		window.draw(car1.sprite);
		window.display();
	}

	return 0;
}

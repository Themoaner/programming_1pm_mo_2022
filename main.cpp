#include <SFML/Graphics.hpp>
#include "Header.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 600), "test");

	sf::Image mapImage;
	mapImage.loadFromFile("images/map.png");
	sf::Texture map;
	map.loadFromImage(mapImage);
	sf::Sprite s_map;
	s_map.setTexture(map);

	float CurrentFrame = 0;
	sf::Clock clock;

	sk::Player me("end.png", 250, 250, 120, 133);
	sk::Boat boat("boat1.png", 0, 520, 100, 80);

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A))))
		{
			me.direction = 1;
			me.speed = 0.1;
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 3)
			{
				CurrentFrame -= 3;
			}
			me.sprite.setTextureRect(sf::IntRect(120 * int(CurrentFrame), 266, 120, 133));
		}

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D))))
		{
			me.direction = 0;
			me.speed = 0.1;
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 3)
			{
				CurrentFrame -= 3;
			}
			me.sprite.setTextureRect(sf::IntRect(120 * int(CurrentFrame), 399, 120, 133));
		}

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W))))
		{
			me.direction = 3;
			me.speed = 0.1;
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 3)
			{
				CurrentFrame -= 3;
			}
			me.sprite.setTextureRect(sf::IntRect(120 * int(CurrentFrame), 133, 120, 133));
		}

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S))))
		{
			me.direction = 2;
			me.speed = 0.1;
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 3)
			{
				CurrentFrame -= 3;
			}
			me.sprite.setTextureRect(sf::IntRect(120 * int(CurrentFrame), 0, 120, 133));
		}

		me.update(time);
		boat.update(time);

		window.clear();

		for (int i = 0; i < HEIGHT_MAP; i++)
		{
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == 'g')
					s_map.setTextureRect(sf::IntRect(0, 0, 100, 100));
				if (TileMap[i][j] == '1')
					s_map.setTextureRect(sf::IntRect(200, 0, 100, 100));
				if (TileMap[i][j] == '0')
					s_map.setTextureRect(sf::IntRect(100, 0, 100, 100));
				if (TileMap[i][j] == 's')
					s_map.setTextureRect(sf::IntRect(401, 0, 100, 100));
				if (TileMap[i][j] == 'w')
					s_map.setTextureRect(sf::IntRect(301, 0, 100, 100));
				if (TileMap[i][j] == '+')
					s_map.setTextureRect(sf::IntRect(502, 0, 100, 100));
				s_map.setPosition(j * 100, i * 100);
				window.draw(s_map);
			}
		}

		window.draw(boat.sprite);
		window.draw(me.sprite);
		window.display();
	}
	return 0;
}
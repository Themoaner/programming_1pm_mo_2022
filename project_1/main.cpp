#include <SFML/Graphics.hpp>
#include "Header.h"

class Player 
{
	public:
		float x, y, w, h, dx, dy, speed = 0;
		int direction = 0;
		sf::String File;
		sf::Image image;
		sf::Texture texture;
		sf::Sprite sprite;

		Player(sf::String F, float X, float Y, float W, float H)
		{
			File = F;
			w = W;
			h = H;
			image.loadFromFile("images/" + File);
			texture.loadFromImage(image);
			sprite.setTexture(texture);
			x = X;
			y = Y;
			sprite.setTextureRect(sf::IntRect(0, 0, w, h));
		}

		void update(float time)
		{
			switch (direction)
			{
			case 0: dx = speed; dy = 0; break;
			case 1: dx = -speed; dy = 0; break;
			case 2: dx = 0; dy = speed; break;
			case 3: dx = 0; dy = -speed; break;
			}

			x += dx * time;
			y += dy * time;

			speed = 0;
			sprite.setPosition(x, y);
			interactionWithMap();
		}

		void interactionWithMap()
		{
			for (int i = y / 100; i < (y + h) / 100; i++)
			{
				for (int j = x / 100; j < (x + w) / 100; j++)
				{
					if (TileMap[i][j] == '1' || TileMap[i][j] == 's' || TileMap[i][j] == 'w')
					{
						if (dy > 0)
							y = i * 100 - h;
						if (dy < 0)
							y = i * 100 + 100;
						if (dx > 0)
							x = j * 100 - w;
						if (dx < 0)
							x = j * 100 + 100;
					}
				}
			}
		}
};


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

	Player me("end.png", 250, 250, 120, 133);

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

		

		window.draw(me.sprite);
		window.display();
	}
	return 0;
}

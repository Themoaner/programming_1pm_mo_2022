#pragma once
#include <SFML\Graphics.hpp>

const int HEIGHT_MAP = 6;
const int WIDTH_MAP = 10;


sf::String const TileMap[HEIGHT_MAP] = {
	"0+00000000",
	"1111111111",
	"sggggggggs",
	"sggggggggs",
	"sggggggggs",
	"wwwwwwwwww",
};

namespace sk
{
	class Player
	{
	private:
		float x, y, w, h, dx, dy = 0;
		sf::String File;
		sf::Image image;
		sf::Texture texture;
	public:
		float speed = 0;
		int direction = 0;
		sf::Sprite sprite;
		Player(sf::String F, float X, float Y, float W, float H);
		void SetPlayer(float X, float Y, float W, float H);
		void update(float time);
		void interactionWithMap();
	};

	class Boat
	{
	private:
		float x, y, w, h, dx, dy, speed, moveTimer = 0;
		sf::String File;
		sf::Image image;
		sf::Texture texture;
	public:
		sf::Sprite sprite;

		Boat(sf::String F, float X, float Y, float W, float H);
		void SetBoat(float X, float Y, float W, float H);
		void update(float time);
	};
}

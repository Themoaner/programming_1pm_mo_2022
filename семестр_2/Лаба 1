#include <iostream>
#include <SFML/Graphics.hpp>

class AnimatedText
{
private:
	std::string m_text;
	std::string tmp_text;
	double m_duration;
	double m_currentDuration;
	sf::Font font;
	sf::Text text;
	sf::Clock clock;
	int k = 0;

	void initSFML(std::string str)
	{
		font.loadFromFile("C:\\Users\\KISidorenko\\Documents\\Visual Studio 2015\\Projects\\лаба1\\лаба1\\caviar-dreams.ttf");
		text.setFont(font);
		text.setCharacterSize(24);
		text.setFillColor(sf::Color::Green);
		text.setPosition(50, 50);
		//text.setString(str);
	}

	void sfmlSet()
	{
		text.setString(tmp_text);
	}

	void timer()
	{
		float time = clock.getElapsedTime().asSeconds();
		if (time > m_duration)
		{
			if (k < m_text.length())
			{
				tmp_text += m_text[k];
				k += 1;
				sfmlSet();
				clock.restart();
			}

		}
	}

public:

	AnimatedText()
	{
		m_text = "default string";
		m_duration = 28;
	}

	AnimatedText(std::string text, double duration)
	{
		m_text = text;
		m_duration = duration / text.length();

	}

	void start() 
	{
		initSFML(m_text);
		sf::RenderWindow window(sf::VideoMode(1000, 500), "test");

		while (window.isOpen())
		{
			sf::Event event;
			timer();

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
			}
			window.clear();
			window.draw(text);
			window.display();
		}
	}
};


int main()
{
	std::string str = "Helloworld";

	AnimatedText at = AnimatedText(str, 5);
	at.start();

	return 0;
}

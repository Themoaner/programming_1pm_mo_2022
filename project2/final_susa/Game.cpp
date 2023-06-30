#include <string>
#include <list>
#include "Game.h"

namespace mt {

    Game::~Game() {
        if (m_window != nullptr)
            delete m_window;
    }

    void Game::SetCaption(const std::string& caption) {
        m_caption = caption;
    }

    void Game::SetResolution(int width, int height) {
        m_width = width;
        m_height = height;
    }

    void Game::Setup() {
        m_window = new sf::RenderWindow(sf::VideoMode(m_width, m_height), m_caption);
    }

    void Game::Run() {
        m::Map map("files\\Map.txt");
        map.SetMassive();
        map.SetImage();

        sf::View view(sf::FloatRect(0.f, 0.f, m_width, m_height));
        view.zoom(0.3f);

        sf::Image Susa;
        Susa.loadFromFile("files/susa4.png");
        //Player susa(Susa, 300 - 16, 500, 32, 32, "susa");
        Player susa(Susa, 88*32 , 8*32, 32, 32,"susa");
        susa.SetMap(map.GetMassive());

        sf::Image Clip;
        Clip.loadFromFile("files/clip.png");
        sf::Image Puddle;
        Puddle.loadFromFile("files/Texturs.png");
        //Enemy clip1(Clip, 2464, 416, 32, 32, "clip");
        //Enemy clip2(Clip, 138 * 32, 4 * 32, 32, 32, "clip");

        float CurrentFrame = 0;
        sf::Clock clock;

        ///////////////////////// СПИСОК ВРАГОВ /////////////////////////

        std::list<Enemy*>  L;           //список
        std::list<Enemy*>::iterator ii; //итератор чтобы проходить по эл-там списка

        L.push_back(new Enemy(Clip, 2464, 416, 32, 32, "clip"));
        L.push_back(new Enemy(Clip, 138 * 32, 4 * 32, 32, 32, "clip"));
        L.push_back(new Enemy(Puddle, 92 * 32, 9 * 32 - 10, 14, 10, "puddle"));
        L.push_back(new Enemy(Puddle, 98 * 32, 9 * 32 - 10, 14, 10, "puddle"));
        L.push_back(new Enemy(Puddle, 103 * 32, 9 * 32 - 10, 14, 10, "puddle"));
        L.push_back(new Enemy(Puddle, 110 * 32, 3 * 32 - 10, 14, 10, "puddle"));
        L.push_back(new Enemy(Puddle, 115 * 32, 3 * 32 - 10, 14, 10, "puddle"));
        L.push_back(new Enemy(Puddle, 120 * 32, 3 * 32 - 10, 14, 10, "puddle"));
        ///////////////////////// СПИСОК ВРАГОВ /////////////////////////

        while (m_window->isOpen()) {
            sf::Event event;
            float time = clock.getElapsedTime().asMicroseconds();
            clock.restart();
            time = time / 800;
            while (m_window->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    m_window->close();
            }

            //////////////////// СТОЛКНОВЕНИЕ С ВРАГОМ ////////////////////
            for (ii = L.begin(); ii != L.end(); ii++)
            {
                if ((**ii).getRect().intersects(susa.getRect())) //если враг пересекается с игроком
                {
                    susa.life = false; //персонаж умирает
                }
            }
            //////////////////// СТОЛКНОВЕНИЕ С ВРАГОМ ////////////////////
            //sf::Time dt = timer.restart();
            susa.update(time, &CurrentFrame, time, &view);
            for (ii = L.begin(); ii != L.end(); ii++)
            {
                (*ii)->update(time); //для всех элементов списка активируем ф-цию update
            }
            //clip1.update(time);
            //clip2.update(time);

            m_window->clear(sf::Color (255, 182, 193));
            m_window->setView(view);

            //Рисуем карту
            for (int i = 0; i < map.GetHEIGHT(); i++)
                for (int j = 0; j < map.GetWIDTH(); j++)
                    m_window->draw((*map.SetTexture(i, j)));//рисуем квадратики на экран

            //m_window->draw(ball1);
            m_window->draw(*susa.GetSprite());
            for (ii = L.begin(); ii != L.end(); ii++) {
                m_window->draw(*(*ii)->GetSprite()); //рисуем объекты списка L
            }
            //m_window->draw(*clip1.GetSprite());
            //m_window->draw(*clip2.GetSprite());
            m_window->display();
        }

    }
}

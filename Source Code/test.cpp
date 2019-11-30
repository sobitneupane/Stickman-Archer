
//menu
#include<SFML/Graphics.hpp>
#include<iostream>
#include "Menu.h"
#include "singlePlayer.h"
#include "doublePlayer.h"
void mainMenu();
int main()
{
    mainMenu();

};

void mainMenu()
{
    sf::RenderWindow window(sf::VideoMode(1000,600),"GAME");

    sf::Texture texture;
    texture.loadFromFile("b.jpg");
    sf::Sprite bg(texture);

    Menu m1(window.getSize().x,window.getSize().y);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                case sf::Keyboard::Up:
                    m1.MoveUp();
                    break;
                case sf::Keyboard::Down:
                    m1.MoveDown();
                    break;
                case sf::Keyboard::Return:
                     switch(m1.GetPressedItem())
                     {
                        case 0:
                            window.close();
                            single();
                            break;
                        case 1:
                            window.close();
                            doublePlay();
                            break;
                        case 2:
                            window.close();
                            break;
                     }
                     break;
                }
                break;
            case sf::Event::Closed:
                window.close();
                break;
            }
        }
    window.clear();
    window.draw(bg);
    m1.draw(window);
    window.display();
    }
}


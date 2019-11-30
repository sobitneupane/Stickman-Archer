#include "Menu.h"

    Menu::Menu(float width, float height){
        if(font.loadFromFile("solo5.ttf"))
        {
            //handle error
        }
        menu[0].setFont(font);
        menu[0].setColor(sf::Color(93,200,200));
        menu[0].setString("Single PLAYER");
        menu[0].setPosition(sf::Vector2f( 350 ,600/4*1));

        menu[1].setFont(font);
        menu[1].setColor(sf::Color(0,134,134));
        menu[1].setString("Double PLAYER");
        menu[1].setPosition(sf::Vector2f(350,600/4 *2));

        menu[2].setFont(font);
        menu[2].setColor(sf::Color(0,134,134));
        menu[2].setString("EXIT");
        menu[2].setPosition(sf::Vector2f(450,600/4 *3));

        selectedItemIndex=0;
    }
    void Menu::draw(sf::RenderWindow &window)
    {
        for(int i =0;i<MAX_NUMBER_OF_ITEMS;i++)
        {
            window.draw(menu[i]);
        }
    }
    void Menu::MoveUp()
    {
        if(selectedItemIndex-1>=0)
        {
            menu[selectedItemIndex].setColor(sf::Color(0,134,134));
            selectedItemIndex--;
            menu[selectedItemIndex].setColor(sf::Color(93,200,200));
        }
    }
    void Menu::MoveDown()
    {
        if(selectedItemIndex+1<MAX_NUMBER_OF_ITEMS)
        {
            menu[selectedItemIndex].setColor(sf::Color(0,134,134));
            selectedItemIndex++;
            menu[selectedItemIndex].setColor(sf::Color(93,200,200));
        }
    }




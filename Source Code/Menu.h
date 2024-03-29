#include<SFML/Graphics.hpp>
const int MAX_NUMBER_OF_ITEMS = 3;
class Menu
{
public:
    Menu(float width, float height);

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem(){return selectedItemIndex;}

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
};

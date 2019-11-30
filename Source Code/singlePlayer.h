
#include <SFML/Graphics.hpp>
#include<iostream>
#include <string>
#include<sstream>
#include <cmath>
#include "Animation.h"

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

int newarrow=0;
int nom=1;
int upnum=0;
int score=0;
const int WINSIZEx = 900;
const int WINSIZEy = 400;
const int TARSIZEx = 6;
const int TARSIZEy = 40;
const int ARROWX=25;
const int ARROWY=10;
float Rot=345;
float RotA=Rot;
float initialVelocityY=2.2;
float initialVelocity=6.0;
float n=0.1;
float xComp;
float yComp;
float ang;
float ang1;
int movenum=0;
float numberUntilHmax;
float centerX=3;
float blueX=3;
float greenX=3;
float centerY=10;
float blueY=6;
float greenY=9;

//
const float TarX=4;
const float TarY=10;
const float TarCenY=350;
const float TarCenX= WINSIZEx-100;
float moveTar=0.7;
bool checkLogic(sf::RectangleShape,sf::RectangleShape);
bool checkCollision(sf::RectangleShape,sf::RectangleShape);

//for powerselector
int PowerFactor=0;
float temp = initialVelocity/510.f;
int aa=0;
float bb=255;
const float PowerSelectorInitPosX=10;

const float PowerSelectorInitPosY=10;
class p1
{

private:
    bool isPressed=false;
    bool isLeftPressed=false;
    bool isKeyBoardPressed=false;
    bool hasArrowTouchTarget=false;
public:

    p1(){
    int num=1;
    float a;
    sf::RenderWindow window(sf::VideoMode(WINSIZEx,WINSIZEy), "Single Player");
    window.setFramerateLimit(300);
    //the following is for the movable target

    sf::RectangleShape TarCentre(sf::Vector2f(TarX,TarY));
    TarCentre.setOrigin(TarX/2,TarY/2);
    TarCentre.setFillColor(sf::Color(0,0,0));
    TarCentre.setPosition(TarCenX,TarCenY);

    sf::RectangleShape TarMed(sf::Vector2f(TarX,TarY));
    TarMed.setOrigin(TarX/2,TarY/2);
    TarMed.setFillColor(sf::Color(255,255,255));
    TarMed.setPosition(TarCenX,TarCenY+TarY);

    sf::RectangleShape TarMedu(TarMed);
    TarMedu.setPosition(TarCenX,TarCenY-TarY);

    sf::RectangleShape TarEx(sf::Vector2f(TarX,TarY));
    TarEx.setOrigin(TarX/2,TarY/2);
    TarEx.setFillColor(sf::Color(0,0,0));
    TarEx.setPosition(TarCenX,TarMed.getPosition().y+TarY);

    sf::RectangleShape TarExu(TarEx);
    TarExu.setPosition(TarCenX,TarMedu.getPosition().y-TarY);

    sf::RectangleShape base(sf::Vector2f(40,5));
    base.setPosition(65,320);
    base.setFillColor(sf::Color::Blue);

    //
    // moveable target over
    //
    sf::RectangleShape leg1(sf::Vector2f(6,40));
    leg1.setPosition(82,283);
    leg1.setRotation(10);
    leg1.setFillColor(sf::Color::Blue);

    sf::RectangleShape leg2(sf::Vector2f(6,40));
    leg2.setPosition(82,283);
    leg2.setRotation(-10);
    leg2.setFillColor(sf::Color::Blue);

    sf::RectangleShape body(sf::Vector2f(10,40));
    body.setPosition(80,250);
    body.setFillColor(sf::Color::Blue);

    sf::CircleShape head(10.f);
    head.setPosition(75,230);
    head.setFillColor(sf::Color::Blue);

    sf::RectangleShape hand1(sf::Vector2f(25,4));
    hand1.setPosition(85,250);
    hand1.setOrigin(0,0);
    hand1.setRotation(-15);
    hand1.setFillColor(sf::Color::Blue);

    sf::RectangleShape hand2(sf::Vector2f(25,4));
    hand2.setPosition(80,250);
    hand2.setRotation(-15);
    hand2.setFillColor(sf::Color::Blue);

    sf::CircleShape hand2c(2.0f);
    hand2c.setPosition(80,250);
    hand2c.setOrigin(2,0);
    hand2c.setRotation(-15);
    hand2c.setFillColor(sf::Color::Blue);

    sf::RectangleShape player(sf::Vector2f(25.0f,50.0f));
    player.setPosition(85,250);
    player.setOrigin(-10,25);
    player.setRotation(-15);
    sf::Texture playerTexture;
    playerTexture.loadFromFile("bow_0.png");
    player.setTexture(&playerTexture);

    Animation animation(playerTexture, sf::Vector2u(6,4),0.1f);

    float deltaTime = 0.0f;
    sf::Clock clock;

    sf::RectangleShape arrow(sf::Vector2f(ARROWX,ARROWY));
    arrow.setPosition(hand2.getPosition().x-2,hand2.getPosition().y+2);
    arrow.setOrigin(-25,ARROWY/2);
    arrow.setRotation(-15);
    sf::Texture arrowTexture;
    arrowTexture.loadFromFile("arrow2.png");
    arrow.setTexture(&arrowTexture);

    sf::RectangleShape powerSelector(sf::Vector2f(30,20));

    powerSelector.setPosition(PowerSelectorInitPosX,PowerSelectorInitPosY);


    sf::Font font;
    sf::Text sc;

    sf::Text powerBar;
    powerBar.setCharacterSize(20);
    powerBar.setString("MAX POWER");

    font.loadFromFile("arial.ttf");
    sc.setFont(font);
    sc.setString("SCORE:");
    sc.setCharacterSize(20);
    sc.setPosition(sf::Vector2f(10 ,PowerSelectorInitPosY+5+30));

    powerBar.setFont(font);
    powerBar.setPosition(190,8);
    while (window.isOpen())
    {
        static bool R=false;



            if(!R)

            {

                PowerFactor++;

                 powerSelector.move(0.2,0);

                bb-=0.5;

                if(bb<0)

                    R=true;

            }

            if(R)

            {

                PowerFactor--;

                powerSelector.move(-0.2,0);

                bb+=0.5;

                if(bb>255)

                    R=false;

            }


          powerSelector.setFillColor(sf::Color(255,bb,bb));

        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        player.setTextureRect(animation.uvRect);
        window.sf::RenderWindow::clear(sf::Color(0,168,168));

        window.draw(base);
        window.draw(leg1);
        window.draw(leg2);
        window.draw(body);
        window.draw(powerBar);
        window.draw(TarCentre);
        window.draw(TarMed);
        window.draw(TarMedu);
        window.draw(TarEx);
        window.draw(TarExu);

        window.draw(head);
        window.draw(hand1);
        window.draw(player);
        window.draw(arrow);
        window.draw(hand2c);
        window.draw(hand2);
        window.draw(sc);
        window.draw(powerSelector);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isKeyBoardPressed)
    {
        initialVelocity=temp*PowerFactor;
        isKeyBoardPressed=true;
        arrow.setOrigin(ARROWX-1,ARROWY/2);
        float angleInDeg=arrow.getRotation();
        float angleInRad= (M_PI*angleInDeg)/(180.f);
       xComp = initialVelocity*fabs(cos(angleInRad));
        yComp = initialVelocityY*fabs(sin(angleInRad));
        ang = arrow.getRotation();
         numberUntilHmax = 2*yComp/(0.009);
    }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            isLeftPressed=true;
            animation.Update(2, deltaTime,true);

            if(movenum<70)
            {
            arrow.move(-0.06+0.001*(1-cos(360-arrow.getRotation())),0.001*(1-cos(360-arrow.getRotation())));
            hand2.move(-0.06+0.001*(1-cos(360-arrow.getRotation())),0.001*(1-cos(360-arrow.getRotation())));
            hand2c.move(-0.06+0.001*(1-cos(360-arrow.getRotation())),0.001*(1-cos(360-arrow.getRotation())));
            movenum++;
            }
        }
if(isKeyBoardPressed)
{
    ang1 = arrow.getRotation()+(2*(360-ang)/(numberUntilHmax));
    arrow.setRotation(ang1);
    arrow.move(xComp,-yComp+0.009*n);
    n++;
}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !isKeyBoardPressed)
        {
            if(Rot>300)
            Rot-=0.2;
            arrow.setRotation(Rot);
            hand1.setRotation(Rot);
            hand2.setRotation(Rot);
            hand2c.setRotation(Rot);
            if(!isLeftPressed)
            arrow.setPosition(hand2.getPosition().x-2,hand2.getPosition().y+2);
            player.setRotation(Rot);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !isKeyBoardPressed)
        {
            if(Rot<345)
            Rot+=0.2;
            hand1.setRotation(Rot);
            hand2.setRotation(Rot);
            hand2c.setRotation(Rot);
            arrow.setRotation(Rot);
            if(!isLeftPressed)
                arrow.setPosition(hand2.getPosition().x-2,hand2.getPosition().y+2);
            player.setRotation(Rot);

        }
        if(TarEx.getPosition().y>WINSIZEy)
            moveTar=-moveTar;
        if(TarExu.getPosition().y<0)
            moveTar=-moveTar;

            TarCentre.move(0,moveTar);
            TarMed.move(0,moveTar);
            TarMedu.move(0,moveTar);
            TarEx.move(0,moveTar);
            TarExu.move(0,moveTar);
 if(checkCollision(arrow,TarCentre)||checkCollision(arrow,TarEx)||checkCollision(arrow,TarExu)||checkCollision(arrow,TarMed)||checkCollision(arrow,TarMedu))
    {
        newarrow=1;
        isKeyBoardPressed=false;
        arrow.move(0,moveTar);
        hasArrowTouchTarget=true;
    }

        if(checkCollision(arrow,TarCentre))
            score+=10;
        if(checkCollision(arrow,TarEx)||checkCollision(arrow,TarExu))
            score+=2;
        if(checkCollision(arrow,TarMed)||checkCollision(arrow,TarMedu))
            score+=5;
        sc.setString("SCORE:" +patch::to_string(score) );
        sc.setColor(sf::Color::Red);

            if(arrow.getPosition().x>WINSIZEx || arrow.getPosition().y>WINSIZEy)
            {
                newarrow=1;
            }
            if(newarrow==1)
            {
                n=0;
                isKeyBoardPressed=false;
                animation.Update(0,deltaTime,false);
                hand2.setPosition(80,250);
                hand1.setPosition(85,250);
                hand2c.setPosition(80,250);
                hand2c.setOrigin(2,0);
                arrow.setRotation(hand2.getRotation());
                arrow.setPosition(hand2.getPosition().x-2,hand2.getPosition().y+2);
                arrow.setOrigin(-25,ARROWY/2);
                movenum=0;
                newarrow++;
            }
        window.display();

    }}
};

bool checkCollision(sf::RectangleShape ARROW, sf::RectangleShape B)
{

if((ARROW.getPosition().x>(TarCenX-TarX/2))&& (ARROW.getPosition().x<(TarCenX+TarX/2))&& ((ARROW.getPosition().y)>(B.getPosition().y-(B.getSize().y)/2))&&(ARROW.getPosition().y<(B.getPosition().y+(B.getSize().y)/2)))
    {
        n=0;
        return true;
    }
else return false;
}


void single(){
    using namespace std;
    p1 p;
}

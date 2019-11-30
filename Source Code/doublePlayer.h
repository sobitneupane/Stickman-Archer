
#include<iostream>
#include <string>
#include<sstream>
#include <cmath>
int i=0;
int j=0;
int health=5;
int lifeCall=0;
 void lP(sf::RenderWindow&);
void mainMenu();

int health_1=5;
int lifeCall_1=0;
 void lP_1(sf::RenderWindow&);

     sf::Texture lifeTexture;
     sf::Texture lifeTexture_1;


class p2
{
private:
    float initialVelocityY=2.2;
    float initialVelocity=3.5;
    bool isPressed=false;
    bool isLeftPressed=false;
    bool isAPressed=false;
    bool isKeyBoardPressed=false;
    bool isKey0Pressed = false;
    float n_2=0.1;
    float n=0.1;
    int newarrow_2=0;
int upnum_2=0;
int score_2=0;
int lifePlayer2=0;
int lifePlayer1=0;
int l=0;
int l_1=0;
float Rot_2=195;
float xComp_2;
float yComp_2;
float ang_2;
float ang1_2;
int movenum_2=0;
float numberUntilHmax_2;

public:
    p2()
     {
    sf::RenderWindow window(sf::VideoMode(WINSIZEx,WINSIZEy),"Double Player");
    window.setFramerateLimit(300);
//player1
    sf::RectangleShape leg1(sf::Vector2f(6,40));
    leg1.setPosition(82,283);
    leg1.setRotation(10);
    leg1.setFillColor(sf::Color::Black);
lifeTexture.loadFromFile("h.png");
lifeTexture_1.loadFromFile("h.png");
    sf::RectangleShape leg2(sf::Vector2f(6,40));
    leg2.setPosition(82,283);
    leg2.setRotation(-10);
    leg2.setFillColor(sf::Color::Black);

    sf::RectangleShape body(sf::Vector2f(10,40));
    body.setPosition(80,250);
    body.setFillColor(sf::Color::Black);

    sf::CircleShape head(10.f);
    head.setPosition(75,230);
    head.setFillColor(sf::Color::Black);

    sf::RectangleShape hand1(sf::Vector2f(25,4));
    hand1.setPosition(85,250);
    hand1.setOrigin(0,0);
    hand1.setRotation(-15);
    hand1.setFillColor(sf::Color::Black);

    sf::RectangleShape hand2(sf::Vector2f(25,4));
    hand2.setPosition(80,250);
    hand2.setRotation(-15);
    hand2.setFillColor(sf::Color::Black);

    sf::CircleShape hand2c(2.0f);
    hand2c.setPosition(80,250);
    hand2c.setOrigin(2,0);
    hand2c.setRotation(-15);
    hand2c.setFillColor(sf::Color::Black);

        sf::RectangleShape base(sf::Vector2f(40,5));
    base.setPosition(65,320);
    base.setFillColor(sf::Color::Black);

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




//player1 finished

//player2 start
    sf::RectangleShape leg1_2(sf::Vector2f(6,40));
    leg1_2.setPosition(WINSIZEx-82,283);
    leg1_2.setRotation(10);
    leg1_2.setFillColor(sf::Color::Blue);

    sf::RectangleShape leg2_2(sf::Vector2f(6,40));
    leg2_2.setPosition(WINSIZEx-82,283);
    leg2_2.setRotation(-10);
    leg2_2.setFillColor(sf::Color::Blue);

    sf::RectangleShape body_2(sf::Vector2f(10,40));
    body_2.setPosition(WINSIZEx-84,250);
    body_2.setFillColor(sf::Color::Blue);

    sf::CircleShape head_2(10.f);
    head_2.setPosition(WINSIZEx-89,230);
    head_2.setFillColor(sf::Color::Blue);

    sf::RectangleShape hand1_2(sf::Vector2f(25,4));
    hand1_2.setPosition(body_2.getPosition().x+2,body_2.getPosition().y+4);
    hand1_2.setOrigin(0,0);
    hand1_2.setRotation(180-15+30);
    hand1_2.setFillColor(sf::Color::Blue);

    sf::RectangleShape hand2_2(sf::Vector2f(25,4));
    hand2_2.setPosition(body_2.getPosition().x-4+10,body_2.getPosition().y+4);
    hand2_2.setRotation(180-15+30);
    hand2_2.setFillColor(sf::Color::Blue);


    sf::RectangleShape base_2(sf::Vector2f(40,5));
    base_2.setPosition(WINSIZEx-65-34,320);
    base_2.setFillColor(sf::Color::Blue);

    sf::RectangleShape player_2(sf::Vector2f(25.0f,50.0f));
    player_2.setPosition(body_2.getPosition().x,body_2.getPosition().y);
    player_2.setOrigin(-10,25);
    player_2.setRotation(180-15+30);
    sf::Texture playerTexture_2;
    playerTexture_2.loadFromFile("bow_0.png");
    player_2.setTexture(&playerTexture_2);

    Animation animation_2(playerTexture_2, sf::Vector2u(6,4),0.1f);

    sf::RectangleShape arrow_2(sf::Vector2f(ARROWX,ARROWY));
    arrow_2.setPosition(hand2_2.getPosition().x+2,hand2_2.getPosition().y+2);
    arrow_2.setOrigin(-25,ARROWY/2);
    arrow_2.setRotation(180-15+30);
    sf::Texture arrowTexture_2;
    arrowTexture_2.loadFromFile("arrow2.png");
    arrow_2.setTexture(&arrowTexture_2);
//player2 finish


    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
        switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {

                case sf::Keyboard::Escape:
                    window.close();
                    mainMenu();
                    break;

                }
                break;
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

//player1
        player.setTextureRect(animation.uvRect);
        window.sf::RenderWindow::clear(sf::Color(0,168,168));

        window.draw(base);
        window.draw(leg1);
        window.draw(leg2);
        window.draw(body);

        window.draw(head);
        window.draw(hand1);
        window.draw(player);
        window.draw(arrow);
        window.draw(hand2c);
        window.draw(hand2);
//player2
        player_2.setTextureRect(animation_2.uvRect);

        window.draw(base_2);
        window.draw(leg1_2);
        window.draw(leg2_2);
        window.draw(hand2_2);
        window.draw(body_2);

        window.draw(head_2);
        window.draw(player_2);
        window.draw(arrow_2);
        window.draw(hand1_2);

        lP_1(window);
        lP(window);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isKeyBoardPressed)
    {
        isKeyBoardPressed=true;
        arrow.setOrigin(ARROWX-1,ARROWY/2);
        float angleInDeg=arrow.getRotation();
        float angleInRad= (M_PI*angleInDeg)/(180.f);
       xComp = initialVelocity*fabs(cos(angleInRad));
        yComp = initialVelocityY*fabs(sin(angleInRad));
        ang = arrow.getRotation();
         numberUntilHmax = 2*yComp/(0.009);
    }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            isAPressed=true;
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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !isKeyBoardPressed)
        {
            if(Rot>300)
            Rot-=0.2;

            arrow.setRotation(Rot);
            hand1.setRotation(Rot);
            hand2.setRotation(Rot);
            hand2c.setRotation(Rot);
            if(!isAPressed)
            arrow.setPosition(hand2.getPosition().x-2,hand2.getPosition().y+2);
            player.setRotation(Rot);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !isKeyBoardPressed)
        {
            if(Rot<345)
            Rot+=0.2;
            hand1.setRotation(Rot);
            hand2.setRotation(Rot);
            hand2c.setRotation(Rot);
            arrow.setRotation(Rot);
            if(!isAPressed)
                arrow.setPosition(hand2.getPosition().x-2,hand2.getPosition().y+2);
            player.setRotation(Rot);

        }
        //player2 rotation algorithm

        //
// if enter is pressed
//

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0) && !isKey0Pressed)
    {
        isKey0Pressed=true;
        float tempA= initialVelocity;
        float mulCon = tempA/(100.0);
      //  initialVelocity=mulCon*powerSelector.getPosition().x;
        arrow_2.setOrigin(ARROWX-1,ARROWY/2);
        float angleInDeg=arrow_2.getRotation();
        float angleInRad= (M_PI*angleInDeg)/(180.f);
       xComp_2 = initialVelocity*fabs(cos(angleInRad));
        yComp_2 = initialVelocityY*fabs(sin(angleInRad));
        ang_2 = arrow_2.getRotation();
         numberUntilHmax_2 = 2*yComp_2/(0.009);// analogous to calculating time from Hmax
        }

if(isKey0Pressed)
{
    ang1_2 = arrow_2.getRotation()-(2*(ang_2-180)/(numberUntilHmax_2));
   arrow_2.setRotation(ang1_2);
   arrow_2.move(-xComp_2,-yComp_2+0.009*n_2);
    n_2++;
   }
/*
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0) && !isKey0Pressed)
    {
        isKey0Pressed=true;
        arrow_2.setOrigin(ARROWX-1,ARROWY/2);
        float angleInDeg=2*(180-arrow_2.getRotation())+180;
        float angleInRad= (M_PI*angleInDeg)/(180.f);
       xComp_2 = initialVelocity*fabs(cos(angleInRad));
        yComp_2 = initialVelocityY*fabs(sin(angleInRad));
        ang_2 = arrow_2.getRotation();
         numberUntilHmax_2 = 2*yComp_2/(0.009);
    }

if(isKey0Pressed)
{
    ang1_2 = arrow_2.getRotation()-(2*(ang_2-180)/(numberUntilHmax_2));
    arrow_2.setRotation(ang1_2);
    arrow_2.move(-xComp_2,-yComp_2+0.009*n_2);
    n_2++;
}*/
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            isLeftPressed=true;
            animation_2.Update(2, deltaTime,true);

            if(movenum_2<70)
            {
            arrow_2.move(+0.06-0.001*(1-cos(360-arrow_2.getRotation())),-0.001*(1-cos(180+arrow_2.getRotation())));
            hand2_2.move(+0.06-0.001*(1-cos(360-arrow_2.getRotation())),-0.001*(1-cos(360-arrow_2.getRotation())));

            movenum_2++;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !isKey0Pressed)
        {
            if(Rot_2<240)
            Rot_2+=0.2;

            arrow_2.setRotation(Rot_2);
            hand1_2.setRotation(Rot_2);
            hand2_2.setRotation(Rot_2);
            if(!isLeftPressed)
            arrow_2.setPosition(hand2_2.getPosition().x-2,hand2_2.getPosition().y+2);
            player_2.setRotation(Rot_2);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !isKey0Pressed)
        {
            if(Rot_2>=195)
            Rot_2-=0.2;
            hand1_2.setRotation(Rot_2);
            hand2_2.setRotation(Rot_2);
            arrow_2.setRotation(Rot_2);
            if(!isLeftPressed)
                arrow_2.setPosition(hand2_2.getPosition().x-2,hand2_2.getPosition().y+2);
            player_2.setRotation(Rot_2);
        }
        //lifePlayer2 lifeCalculation
        if((arrow.getPosition().x>body_2.getPosition().x) && (arrow.getPosition().x<body_2.getPosition().x+body_2.getSize().x) && (arrow.getPosition().y>body_2.getPosition().y) && (arrow.getPosition().y<body_2.getPosition().y+body_2.getSize().y+leg1.getSize().y))
            {
                n=0;
                newarrow=1;
                isKeyBoardPressed=false;
                body_2.setFillColor(sf::Color(0,0,255,50));
                if(l==0){lifePlayer2+=50;}
                l++;
            }
        if((arrow.getPosition().x>head_2.getPosition().x) && (arrow.getPosition().x<head_2.getPosition().x+20) && (arrow.getPosition().y>head_2.getPosition().y) && (arrow.getPosition().y<head_2.getPosition().y+20))
        {
            n=0;
            newarrow=1;
            isKeyBoardPressed= false;
            head_2.setFillColor(sf::Color(0,0,255,50));
            if(l==0){lifePlayer2+=100;}
            l++;

        }
        if(lifePlayer2>=100)
        {
            i=0;
            n=0;
            lifePlayer2=0;
            lifeCall=0;
            head_2.setFillColor(sf::Color::Blue);
            body_2.setFillColor(sf::Color::Blue);
        }
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
                l=0;
            }
        if(health<1)
        {
            window.close();
            std::cout<<"player1 wins"<<std::endl;
            health=4;
            mainMenu();
        }

        //player1 lifeCalculation

        if((arrow_2.getPosition().x>body.getPosition().x) && (arrow_2.getPosition().x<body.getPosition().x+body.getSize().x) && (arrow_2.getPosition().y>body.getPosition().y) && (arrow_2.getPosition().y<body.getPosition().y+body.getSize().y+leg1.getSize().y))
            {
                n_2=0;
                newarrow_2=1;
                isKey0Pressed=false;
                body.setFillColor(sf::Color(0,0,0,100));
                if(l_1==0){lifePlayer1+=50;}
                    l_1++;
            }
        if((arrow_2.getPosition().x>head.getPosition().x) && (arrow_2.getPosition().x<head.getPosition().x+20) && (arrow_2.getPosition().y>head.getPosition().y) && (arrow_2.getPosition().y<head.getPosition().y+20))
        {
                n_2=0;
                newarrow_2=1;
                isKey0Pressed=false;
                head.setFillColor(sf::Color(0,0,0,100));
                if(l_1==0){lifePlayer1+=100;}
                    l_1++;
        }
        if(lifePlayer1>=100)
        {
            n_2=0;
            lifePlayer1=0;
            lifeCall_1=0;
            j=0;
            head.setFillColor(sf::Color::Black);
            body.setFillColor(sf::Color::Black);
        }
        if(arrow_2.getPosition().x<0 || arrow_2.getPosition().y>WINSIZEy)
            {
                newarrow_2=1;
            }

            if(newarrow_2==1)
            {
                n_2=0;
                isKey0Pressed=false;
                animation_2.Update(0,deltaTime,false);//
                hand2_2.setPosition(body_2.getPosition().x+10-4,body_2.getPosition().y+4);
                hand1_2.setPosition(body_2.getPosition().x+2,body_2.getPosition().y+4);
                arrow_2.setRotation(hand2_2.getRotation());
                arrow_2.setPosition(hand2_2.getPosition().x+2,hand2_2.getPosition().y+2);
                arrow_2.setOrigin(-25,ARROWY/2);
                movenum_2=0;
                newarrow_2++;
                l_1=0;
            }
        if(health_1<1)
        {
            window.close();
            std::cout<<"player2 wins";
            health_1=4;
            mainMenu();
        }


        window.display();
    }
    }

};

 void lP(sf::RenderWindow& window)
{
    sf::RectangleShape lRect(sf::Vector2f(30*health,30));
    lRect.setPosition(WINSIZEx-150,50);

    lRect.setTexture(&lifeTexture);

    sf::Vector2u texSize = lifeTexture.getSize();

    texSize.x /=8;
    texSize.y/=2;

    lRect.setTextureRect(sf::IntRect(0,0,texSize.x*health,texSize.y));
    window.draw(lRect);
    if(i==0)
        health--;
    i++;

}

 void lP_1(sf::RenderWindow& window)
{
    sf::RectangleShape lRect_1(sf::Vector2f(30*health_1,30));
    lRect_1.setPosition(50,50);

    lRect_1.setTexture(&lifeTexture_1);

    sf::Vector2u texSize_1 = lifeTexture_1.getSize();

    texSize_1.x /=8;
    texSize_1.y/=2;

    lRect_1.setTextureRect(sf::IntRect(0,0,texSize_1.x*health_1,texSize_1.y));
    window.draw(lRect_1);
    if(j==0)
        health_1--;
    j++;

}


void doublePlay()
{
    class p2 d;
}

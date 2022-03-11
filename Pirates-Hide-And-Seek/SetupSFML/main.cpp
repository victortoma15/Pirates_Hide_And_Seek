#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Button.h"
#include "Matrix.h"
#include "Tilemap.cpp"
#include "tilemaps.h"
#include <time.h>

int main()
{
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(600, 600), "- Pirates Hide And Seek -");

    //vars
    sf::Text text;
    sf::Text lgd;
    sf::Font font;
    tilemaps tm;
    matrix mtx;
    sf::Clock clock;
    sf::Music music;
    sf::Texture fundal;
            fundal.loadFromFile("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/SetupSFML/fundal.png");
        sf::Sprite backg(fundal);
    sf::Texture fundaljoc;
            fundaljoc.loadFromFile("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/SetupSFML/fundaljoc.png");
        sf::Sprite bck(fundaljoc);
    
    sf::Texture winner;
            winner.loadFromFile("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/SetupSFML/win.png");
        sf::Sprite win(winner);


    
    int legend[4];
    int level[4][9];
    int solt[4][9];
    int matched[4];
 
    int isGameStarted = 0;
    int isGameFinished = 0;
    int minute = 0;
    
    bool isLongPressActiv = false, sq1 = false, sq2 = false, sq3 = false, sq4 = false;

    
    
    // Load font from file
    if(!font.loadFromFile("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/SetupSFML/arial.ttf"))
        return -1;
    if (!music.openFromFile("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/SetupSFML/mel.wav"))
        return -1;
    fundal.loadFromFile("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/SetupSFML/fundal.png");
           

    // Load the enviroment
        // Text
    text.setFont(font);
    text.setCharacterSize(24); // character size
    text.setFillColor(sf::Color::Red);
    text.setPosition(220, 70);
        // Text 2
    lgd.setFont(font);
    lgd.setString("Legenda");
    lgd.setCharacterSize(24);
    lgd.setFillColor(sf::Color::Red);
    lgd.setPosition(60, 175);
        // Music
    music.play();
        // Buttons
    // Create start game button
    Button btn1("START", { 100, 50 }, 30, sf::Color::Green, sf::Color::Black);
    btn1.setFont(font);
    btn1.setPosition({ 250, 200 });
    btn1.setSize(25);
            // Exit button
    Button btn2("EXIT", { 100, 50 }, 30, sf::Color::Green, sf::Color::Black);
    btn2.setFont(font);
    btn2.setPosition({ 250, 270 });
    btn2.setSize(25);
    
    Button btn3("Main Menu", { 125,50 }, 30, sf::Color::Green, sf::Color::Black);
    btn3.setFont(font);
    btn3.setPosition({ 250, 500 });
    btn3.setSize(25);


    // Generate matrix
   for(int i = 0; i<4; i++)
    {
     mtx.pickElements(level[i]);
    
        //cout << "DEBUG " << mtx.pickLegend(level[i], legend, i); << endl;
        mtx.generateSolutions(level[i], mtx.pickLegend(level[i], i), solt[i], legend, i);
    }
    cout << endl;
    for(int i = 0; i<4; i++)
     {
         cout << legend[i] << " ";
     }
    cout << endl;
    
   
    while (window.isOpen())
    {
        // handle events

        //
        sf::Event event;
        while (window.pollEvent(event))
        {
            sf::Vector2i mousePos;
            mousePos = sf::Mouse::getPosition(window);
            switch (event.type)
            {

            case sf::Event::Closed:
                window.close();

                break;

            case sf::Event::MouseButtonPressed:
            {
                sf::RectangleShape pt;
                pt.setSize({96, 96});
                pt.setPosition(450, 100);
                if(pt.getGlobalBounds().contains(sf::Vector2f(mousePos)))
                    sq1 = true;
                else
                {
                    pt.setPosition({450, 200});
                    if(pt.getGlobalBounds().contains(sf::Vector2f(mousePos)))
                        sq2 = true;
                    else
                    {
                        pt.setPosition({450, 300});
                        if(pt.getGlobalBounds().contains(sf::Vector2f(mousePos)))
                            sq3 = true;
                        else
                        {
                            pt.setPosition({450, 400});
                            if(pt.getGlobalBounds().contains(sf::Vector2f(mousePos)))
                                sq4 = true;
                            else
                            {
                                pt.setPosition({450, 500});

                            }

                        }
                    }
                }

                isLongPressActiv = true;
                if (btn1.isMouseOver(window))
                {
                    tm.StartGame(level, solt, legend);
                    isGameStarted = true;
                    clock.restart();
                    minute = 0;
                }
                if (btn3.isMouseOver(window))
                {
                    //tm.StartGame(level, solt, legend);
                    isGameStarted = false;
                    isGameFinished = false;
                    tm.resetGame(matched);
                    //clock.restart();
                    //minute = 0;
                }
                if (btn2.isMouseOver(window))
                {
                    window.close();
                }
                break;

            }

            case sf::Event::MouseMoved:
                if(isLongPressActiv == true)
                {
                    if(sq1 == true)
                        tm.sol1.setPosition({float(mousePos.x), float(mousePos.y)});
                    if(sq2 == true)
                        tm.sol2.setPosition({float(mousePos.x), float(mousePos.y)});
                    if(sq3 == true)
                        tm.sol3.setPosition({float(mousePos.x), float(mousePos.y)});
                    if(sq4 == true)
                        tm.sol4.setPosition({float(mousePos.x), float(mousePos.y)});
                }
                if (btn1.isMouseOver(window))
                {
                    btn1.setBackColor(sf::Color::Magenta);
                }
                else
                {
                    btn1.setBackColor(sf::Color::Green);
                }
                if (btn2.isMouseOver(window))
                {
                    btn2.setBackColor(sf::Color::Magenta);
                }
                else
                {
                    btn2.setBackColor(sf::Color::Green);
                }
                if (btn3.isMouseOver(window))
                {
                    btn3.setBackColor(sf::Color::Magenta);
                }
                else
                {
                    btn3.setBackColor(sf::Color::Green);
                }
                break;

            // verif daca coord is peste 1 din cele 4 matr
            case sf::Event::MouseButtonReleased:
                isLongPressActiv = false;
                sq1 = false;
                sq2 = false;
                sq3 = false;
                sq4 = false;
                    if(tm.sol1.getPosition() == tm.map.getPosition()){
                        cout << "matched 1";
                        tm.sol1.setPosition(tm.map.getPosition());
                        matched[0] = 0;
                        if(tm.champion(matched))
                            isGameFinished = 1;
                    }
                    if(tm.sol2.getPosition() == tm.map2.getPosition()){
                        cout << "matched 2";
                        tm.sol2.setPosition(tm.map2.getPosition());
                        matched[1] = 0;
                        if(tm.champion(matched))
                            isGameFinished = 1;
                    }
                    if(tm.sol3.getPosition() == tm.map3.getPosition()){
                        cout << "matched 3";
                        tm.sol3.setPosition(tm.map3.getPosition());
                        matched[2] = 0;
                        if(tm.champion(matched))
                            isGameFinished = 1;
                    }
                    if(tm.sol4.getPosition() == tm.map4.getPosition()){
                        cout << "matched 4";
                        tm.sol4.setPosition(tm.map4.getPosition());
                        matched[3] = 0;
                        if(tm.champion(matched))
                            isGameFinished = 1;
                    }
                    
            }
        }

        sf::Time elapsed = clock.getElapsedTime();
        if(int(elapsed.asSeconds()) == 60)
        {
            clock.restart();
            minute++;
        }
        if(!isGameFinished)
        text.setString("Timp Scurs: " + to_string(minute) + ":" + to_string(int(elapsed.asSeconds())));
        // draw the map
        window.clear();
        if(isGameStarted)
        {
            window.draw(bck);
            btn3.drawTo(window);
            window.draw(tm.map);
            window.draw(tm.map2);
            window.draw(tm.map3);
            window.draw(tm.map4);
            window.draw(text);
            window.draw(tm.sol1);
            window.draw(tm.sol2);
            window.draw(tm.sol3);
            window.draw(tm.sol4);
            window.draw(tm.legenda);
            window.draw(lgd);
            

            
        }
        else{
            window.draw(backg);
            btn1.drawTo(window);
            btn2.drawTo(window);
            
        }
        
        if(isGameFinished){
            window.draw(win);
            btn3.drawTo(window);
        }
            
           
        window.display();
    }


}

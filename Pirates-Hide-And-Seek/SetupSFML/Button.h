#pragma once
#include <SFML/Graphics.hpp>

class Button {
public:
    // Constructor
    Button(std::string btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color textColor) {
        button.setSize(buttonSize);
        button.setFillColor(bgColor);


        btnWidth = buttonSize.x;
        btnHeight = buttonSize.y;

        text.setString(btnText);
        text.setCharacterSize(charSize);
        text.setFillColor(textColor);
    }

    // Button find
    void setFont(sf::Font &fonts) {
        text.setFont(fonts);
    }
    
    void setSize(int size){
        text.setCharacterSize(size);
    }
    
    // Fill color
    void setBackColor(sf::Color color) {
        button.setFillColor(color);
    }
    // Outbounded function
    void setTextColor(sf::Color color) {
        text.setFillColor(color);
    }

    void setPosition(sf::Vector2f point) {
        button.setPosition(point);

        // Center text on button:
        float xPos = (point.x + btnWidth / 2) - (text.getLocalBounds().width / 2);
        float yPos = (point.y + btnHeight / 2.2) - (text.getLocalBounds().height / 2);
        text.setPosition(xPos, yPos);
    }

    void drawTo(sf::RenderWindow &window) {
        window.draw(button);
        window.draw(text);
    }
    

    bool isMouseOver(sf::RenderWindow &window) {
        int mouseX = sf::Mouse::getPosition(window).x;
        int mouseY = sf::Mouse::getPosition(window).y;

        int btnPosX = button.getPosition().x;
        int btnPosY = button.getPosition().y;

        int btnxPosWidth = button.getPosition().x + btnWidth;
        int btnyPosHeight = button.getPosition().y + btnHeight;

        if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
            return true;
        }
        return false;
    }
private:
    sf::RectangleShape button;
    sf::Text text;

    int btnWidth;
    int btnHeight;
};

#ifndef SNAKE_HPP
#define SNAKE_HPP
//---------------------------------------------------
#include "BaseGame.hpp"

class Snake : public BaseGame {
public:
    void Start(Adafruit_SSD1306* _display) override {
        _display->clearDisplay();
        _display->setCursor(0,0);
        _display->println("SNAKE GAME");
        _display->display();
    }

    void Loop(Adafruit_SSD1306* _display) override {
        
    }
};


//---------------------------------------------------
#endif
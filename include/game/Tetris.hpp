#ifndef TETRIS_HPP
#define TETRIS_HPP
//---------------------------------------------------
#include "BaseGame.hpp"

class Tetris : public BaseGame {
public:
    void Start(Adafruit_SSD1306* _display) override {
        _display->clearDisplay();
        _display->setCursor(0,0);
        _display->println("TETRIS GAME");
        _display->display();
    }

    void Loop(Adafruit_SSD1306* _display) override {
        
    }
};


//---------------------------------------------------
#endif
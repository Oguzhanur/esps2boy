#ifndef GUI_HPP
#define GUI_HPP
//---------------------------------------------------
#include "Settings.hpp"
#include "Engine.hpp"

class GUI{
private:
    Adafruit_SSD1306* _display;
public:
    GUI(Adafruit_SSD1306* _display) : _display(_display) {}

    void printLoadingScreen();

    void printMenu(int _selected);
};




//---------------------------------------------------
#endif
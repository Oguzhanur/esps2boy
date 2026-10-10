#ifndef ENGINE_HPP
#define ENGINE_HPP
//---------------------------------------------------
#include <Arduino.h>
#include "Settings.hpp"
#include <string>
#include <vector>


class Engine{
private:
    Adafruit_SSD1306* _display;
    
public:
    Engine(Adafruit_SSD1306* _display) : _display(_display) {} // Engine başlatma

    void StartGame(int selected);
};



//---------------------------------------------------
#endif
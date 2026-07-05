#ifndef BASE_GAME_HPP
#define BASE_GAME_HPP
//---------------------------------------------------

// Hareketler
#define BUTTON_LEFT  17
#define BUTTON_UP    15
#define BUTTON_DOWN  16
#define BUTTON_RIGHT 14
// O,X butonu
#define BUTTON_O 13
#define BUTTON_X 12
// Buzzer
#define BUZZER 20


// Oyun
struct vector2f{
    float x;
    float y;
};


//---------------------------------------------------
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Settings.hpp"

class BaseGame {
public:
    virtual ~BaseGame() {} // Silici fonksiyon
    // Zorunlu fonksiyonlar
    virtual void Start(Adafruit_SSD1306* _display) = 0; // 1 kere çalışacak
    virtual void Loop(Adafruit_SSD1306* _display) = 0;  // Sürekli çalışaca
};

//---------------------------------------------------
#endif
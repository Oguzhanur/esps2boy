#ifndef TEST_HPP
#define TEST_HPP
//---------------------------------------------------
#include "BaseGame.hpp"

const unsigned char PlayerImage [] PROGMEM = {
	0x3f, 0xff, 0xc0, 0x40, 0x00, 0x20, 0x80, 0x00, 0x10, 0x9f, 0x0f, 0x90, 0x9d, 0x0e, 0x90, 0x9d, 
	0x0e, 0x90, 0x91, 0x08, 0x90, 0x9f, 0x0f, 0x90, 0x80, 0x00, 0x10, 0x80, 0x00, 0x10, 0x80, 0x00, 
	0x10, 0x98, 0x01, 0x90, 0x98, 0x01, 0x90, 0x84, 0x02, 0x10, 0x83, 0xfc, 0x10, 0x80, 0x00, 0x10, 
	0x80, 0x00, 0x10, 0x80, 0x00, 0x10, 0x40, 0x00, 0x20, 0x3f, 0xff, 0xc0
};

class Test : public BaseGame {
private:
    vector2f playerPos;
    float playerSpeed = 0.5;
public:
    void Start(Adafruit_SSD1306* _display) override {
        _display->clearDisplay();
        _display->setCursor(0,0);
        _display->println("TEST GAME LOADING...");
        _display->display();

        tone(BUZZER, 880);
        delay(1000);
        noTone(BUZZER);
    }

    void Loop(Adafruit_SSD1306* _display) override {
        // Oyuncu hareketleri
        if (!digitalRead(BUTTON_LEFT)){
            playerPos.x -= playerSpeed;
        } else if (!digitalRead(BUTTON_RIGHT)){
            playerPos.x += playerSpeed;
        }
        if (!digitalRead(BUTTON_UP)){
            playerPos.y -= playerSpeed;
        } else if (!digitalRead(BUTTON_DOWN)){
            playerPos.y += playerSpeed;
        }
        // Ekrana çizme işlemi
        _display->clearDisplay();

        _display->drawBitmap(round(playerPos.x+10.0), round(playerPos.y+10.0), PlayerImage, 20, 20, 1);

        _display->display();

        delay(50);
    }
};


//---------------------------------------------------
#endif
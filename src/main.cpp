#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "Settings.hpp"
#include "Engine.hpp"
#include "GUI.hpp"

// Display ayarları
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Değişkenler
int selectedGame=0;

// Oyun motoru
Engine gameEngine(&display);
GUI guiEngine(&display);

// Inıt
void setup() {
  // Seri ekranı başlat
  Serial.begin(115200);
  Serial.println("Start");

  // Butonlar
  pinMode(BUTTON_RIGHT, INPUT_PULLUP);
  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
  pinMode(BUTTON_LEFT, INPUT_PULLUP);

  pinMode(BUTTON_O, INPUT_PULLUP);
  pinMode(BUTTON_X, INPUT_PULLUP);

  // Buzzer
  pinMode(BUZZER, OUTPUT);

  // İ2C için wire begin
  Wire.begin(DISPLAY_SDA, DISPLAY_SCL);

  // Ekranı başlat
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("Screen Error"));
    for (;;); // Don't proceed, loop forever
  }
  Serial.println("Screen Start");

  guiEngine.printLoadingScreen();

  // Arayüzü başlat
  guiEngine.printMenu(selectedGame);
}

void loop() {
  // GUI

  if (!digitalRead(BUTTON_LEFT)){
    if (selectedGame!=0){
      selectedGame--;
    } else {
      selectedGame = GameList.size()-1;
    }
    guiEngine.printMenu(selectedGame);
  }
    
  if (!digitalRead(BUTTON_RIGHT)){
    if (selectedGame!=GameList.size()-1){
      selectedGame++;
    } else {
      selectedGame = 0;
    }
    guiEngine.printMenu(selectedGame);
  }

  if (!digitalRead(BUTTON_O)){
    gameEngine.StartGame(selectedGame);
    guiEngine.printMenu(selectedGame);
  }

  delay(50); // this speeds up the simulation
}

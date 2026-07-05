#include "Engine.hpp"

void Engine::StartGame(int selected){
    int running = 1;
    GameList[selected].gameClass->Start(_display);

    while (running){
        if (!digitalRead(BUTTON_X)){
            running=0;
        }

        // Oyun seçimi
        if (GameList[selected].gameClass != nullptr) {
            GameList[selected].gameClass->Loop(_display);
        }
    }
}
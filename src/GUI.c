#include "GUI.h"

void GUI::printLoadingScreen(){
    // Ekran/Yazı ayarlamaları
    _display->clearDisplay();
    _display->setTextSize(1);
    _display->setTextColor(SSD1306_WHITE);
    _display->setFont(&FreeSerifBold12pt7b);

    // ESP BOY yazısı
    _display->setCursor(10, 25);
    _display->print("ESP");
    _display->setCursor(62, 25);
    _display->print("BOY");

    // Loading yazısı
    _display->setFont();
    _display->setCursor(4, 37);
    _display->print("Loading....");
  
    // Yükleme kısımı
    _display->drawRect(4, 47, 120, 12, 1);
    _display->setCursor(4, 47 - 15);

    // Animasyon
    for (int i = 0; i <= (120 - 4); i++) {
        _display->fillRect(4 + 2, 47 + 2, i, 12 - 4, WHITE);
        _display->display();
        delay(1);
    }
}


void GUI::printMenu(int _selected){
    // Ekranı temizleme
    _display->clearDisplay();

    // Sağ/Sol oklar
    _display->drawBitmap(4, 46, image_Pin_arrow_left_bits, 18, 14, 1);
    _display->drawBitmap(106, 46, image_Pin_arrow_right_bits, 18, 14, 1);
    
    // Oyun isimi
    _display->setCursor(37, 49);
    _display->print(GameList[_selected].name);

    // Oyun ön görünümü
    _display->display();

}

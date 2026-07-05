#ifndef GAMELIST_HPP
#define GAMELIST_HPP
//---------------------------------------------------

#include "BaseGame.hpp"
#include "game/Test.hpp"
#include "game/Tetris.hpp"
#include "game/Snake.hpp"

struct Game {
    String name;
    int id;
    BaseGame* gameClass; // class* yerine BaseGame* kullandık
};

// Vektör listemiz başlangıçta nesneleri yaratmaz, hafıza harcamaz.
inline std::vector<Game> GameList = {
    {"Test" , 786954, new Test()},
    {"Snake", 972150, new Snake()},
    {"Tetris" , 598886, new Tetris()}
};

//

//---------------------------------------------------
#endif
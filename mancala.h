/* Leo Guagenti
 * 4/29/19
 * Mancala Game header file
 * Phase III
 * The current implementation allows for a human player to play
 * a game of mancala with the computer
*/

#ifndef MANCALA
#define MANCALA

#include "game.h"
#include "colors.h"
#include <iostream>
#include <string>
#include <queue>
#include <iomanip>

namespace main_savitch_14{
    class Mancala:public main_savitch_14::game{
        public:
            //constructors
            Mancala();

            //game functions to override
            void make_move(const std::string &move);
            void restart();

            //pure virtuals
            void display_status()const;
            bool is_game_over();
            bool is_legal(const std::string &move)const;
            game::who winning()const;

            game* clone()const;
            int evaluate()const;
            void compute_moves(std::queue<std::string> &moves)const;

            //helper functions
            bool testComputer()const;
            bool testHuman()const;
            void collectComputerChips();
            void collectHumanChips();

        private:
            int board[2][7];
    };
}


#endif


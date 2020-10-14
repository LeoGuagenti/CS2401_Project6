/* Leo Guagenti
 * 4/29/19
 * Mancala Game implementation
 * Phase III
 * Implementations for functions found in mancala.h and game.h
 * The current implementation allows for a human player to play
 * a game of mancala with the computer
*/

#include "mancala.h"
#include "game.h"
#include "colors.h"
namespace main_savitch_14{
    Mancala::Mancala(){
        //setting up default board
        for(unsigned int i = 0; i < 6; i++){
            board[0][i] = 4;
        }
        for(unsigned int j = 1; j < 7; j++){
            board[1][j] = 4;
        }

        //setting default scores
        board[0][6] = 0; //human mancala
        board[1][0] = 0; // ai mancala
    }

    void Mancala::restart(){
        //reseting upper row
        for(unsigned int i = 0; i < 6; i++){
            board[0][i] = 4;
        }

        //resetting lower row
        for(unsigned int j = 1; j < 7; j++){
            board[1][j] = 4;
        }
        //setting default scores
        board[1][0] = 0;
        board[0][6] = 0;
    }

    void Mancala::display_status()const{
        std::cout << "=-------------------------------------------------------------=" << std::endl;
        std::cout << left << "|      |   " << setw(2) << board[0][0] << "  |   " << setw(2) << board[0][1] << "  |   " << setw(2) << board[0][2] << "  |   " << setw(2) << board[0][3] << "  |   " << setw(2) << board[0][4] << "  |   " << setw(2) <<  board[0][5] << "  |      |" << std::endl;
        std::cout << "|      |       |       |       |       |       |       |      |" << std::endl;
        std::cout << left  << "|  " << setw(2) << board[1][0] << "  |-----------------------------------------------|  " << setw(2) << board[0][6] << "  |" << std::endl;
        std::cout << left << "|      |   " << setw(2) << board[1][1] << "  |   " << setw(2) << board[1][2] << "  |   " << setw(2) << board[1][3] << "  |   " << setw(2) << board[1][4] << "  |   " << setw(2) << board[1][5] << "  |   " << setw(2) <<  board[1][6] << "  |      |" << std::endl;
        std::cout << "|      |   A   |   B   |   C   |   D   |   E   |   F   |      |" << std::endl;
        std::cout << "=-------------------------------------------------------------=" << std::endl;
    }

    bool Mancala::is_game_over(){
        if(testComputer()){
            collectComputerChips();
            return true;
        }else if(testHuman()){
            collectHumanChips();        
            return true;
        }else{
            return false;
        }
    }

    //adds all chips in human holes to human score
    void Mancala::collectHumanChips(){
        for(unsigned int i = 1; i < 7; i++){
            board[0][6] += board[1][i];
        }
    }

    //adds all chips in computer holes to computer score
    void Mancala::collectComputerChips(){
        for(unsigned int i = 0; i < 6; i++){
            board[1][0] += board[0][i];
        }
    }

    //helper for is_game_over 
    bool Mancala::testComputer()const{
        for(unsigned int i = 0; i < 6; i++){
            if(board[0][i] != 0){
                return false;
            }
        }
        return true;
    }

    //helper for is_game_over 
    bool Mancala::testHuman()const{
        for(unsigned int i = 1; i < 7; i++){
            if(board[1][i] != 0){
                return false;
            }
        }
        return true;
    }

    //determines if a move is legal
    bool Mancala::is_legal(const std::string &move)const{
        char userMove = tolower(move[0]);
        //loops through a index a to f for the current mover
        if(next_mover() == HUMAN){
            for(int i = 'a'; i < 'g'; i++){
                //if the user's choice index != 0 then valid
                if(userMove == i && board[1][i - 96] != 0){
                    return true;
                }
            }
            return false;
        }else{
            for(int i = 'a'; i < 'g'; i++){
                //if the user's choice index != 0 then valid
                if(userMove == i && board[0][i - 97] != 0){
                    return true;
                }
            }
            return false;
        }
    }

    void Mancala::make_move(const std::string &move){
        char playerMove = tolower(move[0]);
        int layer, index, chips;

        if(next_mover() == HUMAN){
            //Human player
            layer = 1;
            index = playerMove - 96;
            chips = board[layer][index];
            board[layer][index] = 0;

            //general movement and depositions around the board
            while(chips != 0){
                if(layer == 1 && index == 6){
                    layer = 0;
                }else if(layer == 0 && index == 0){
                    layer = 1;
                    index++;
                }else if(layer == 0){
                    index--;
                }else if(layer == 1){
                    index++;
                }

                board[layer][index] += 1;
                chips--;
            }

            //checking if last drop was on 0 pocket
            if(board[layer][index] == 1 && chips == 0 && layer == 1 && index != 0){
                board[0][6] += board[0][index - 1];
                board[0][index - 1] = 0;
            }

            //checking if last drop was in the players mancala
            if(!(layer == 0 && index == 6)){
                move_number++;
            }

        }else{
            //Computer Player
            layer = 0;
            index = playerMove - 97;
            chips = board[layer][index];
            board[layer][index] = 0;

            while(chips != 0){
                if(layer == 1 && index == 6){
                    layer = 0;
                    index--;
                }else if(layer == 0 && index == 0){
                    layer = 1;
                }else if(layer == 0){
                    index--;
                }else if(layer == 1){
                    index++;
                }

                board[layer][index] += 1;
                chips--;
            }

            //checking if last drop was on 0 pocket
            if(board[layer][index] == 1 && chips == 0 && layer == 0 && index != 6){
                board[1][0] += board[1][index + 1];
                board[1][index + 1] = 0;
            }

            //checking if last drop was in the players mancala
            if(!(layer == 1 && index == 0)){
                move_number++;
            }
        }
    }

    //pure virtual functions -- placeholders
    game* Mancala::clone()const{
        return new Mancala(*this);
    }

 game::who Mancala::winning()const{
        if(board[1][0] > board[0][6]){
            return HUMAN;
        }else if(board[1][0] < board[0][6]){
            return COMPUTER;
        }else{
            return NEUTRAL;
        }
    }


    void Mancala::compute_moves(std::queue<std::string> &moves)const{
        std::string move;
        for(unsigned int i = 'a'; i < 'g'; i++){
            move = i;
            if(board[0][i - 97] != 0){
                moves.push(move);
            }
        }
    }

    int Mancala::evaluate()const{
        return (board[1][0] - board[0][6]);
    }
}

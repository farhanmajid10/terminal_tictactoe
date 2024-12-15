#include<iostream>
#include "board.h"

int main(){
    Board board;
        board.place_item(2);
        board.printboard();
        std::cout << std::endl;
        board.place_item(8);
        board.printboard();
        std::cout << std::endl;        
        board.place_item(4);
        board.printboard();
        std::cout << std::endl;
        board.place_item(7);
        board.printboard();
        std::cout << std::endl;
        board.place_item(6);
        board.printboard();
        std::cout << std::endl;
        
        board.check();
        if(board.get_game_won() == 1){
            std::cout << "Game Won!"<< std::endl;
        }
    return 0;
}
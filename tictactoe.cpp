#include<iostream>
#include "board.h"

int main(){
    Board board;
    int player_one_input;
    int player_two_input;
        
    while(board.get_game_won() == 0){
        
    }
        board.place_item(7);
        board.printboard();
        std::cout << std::endl;
        board.place_item(0);
        board.printboard();
        std::cout << std::endl;
        board.place_item(3);
        board.printboard();
        std::cout << std::endl;        
        board.place_item(4);
        board.printboard();
        std::cout << std::endl;
        board.place_item(6);
        board.printboard();
        std::cout << std::endl;
        board.place_item(8);
        board.printboard();
        std::cout << std::endl;
        
        
        board.check();
        if(board.get_game_won() == 1){
            std::cout << "Player1 Won!"<< std::endl;
        }else if(board.get_game_won() == 2){
            std::cout << "Player2 Won!"<< std::endl;
        }
    return 0;
}
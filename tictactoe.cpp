#include<iostream>
#include "board.h"

int main(){
    Board board;
    int player_one_input;
    int player_two_input;
    int prev_turn = 10;
        
    while(board.get_game_won() == 0){
        if(board.get_turn() == 0){
            std::cout << "Player1: ";
            scanf("%d", &player_one_input);
            if(player_one_input > 8 || player_one_input < 0){
                std::cout << "Please Enter Valid Numbers." << std::endl;
                board.printboard();
                std::cout << std::endl;
                continue;
            }
            board.place_item(player_one_input);
        }else if(board.get_turn() == 1){
            std::cout << "Player2: ";
            scanf("%d", &player_two_input);
            if(player_two_input > 8 || player_two_input < 0){
                std::cout << "Please Enter Valid numbers." << std::endl;
                board.printboard();
                std::cout << std::endl;
                continue;
            }
            board.place_item(player_two_input);
        }
        if(board.get_turn()  == prev_turn){
            std::cout << "Please Enter valid numbers." << std::endl;
        }
        prev_turn = board.get_turn();
        board.printboard();
        std::cout << std::endl;
        board.check();
        if(board.get_game_won() == 1){
            std::cout << "Player1 won the game." << std::endl;
            break;
        }else if(board.get_game_won() == 2){
            std::cout << "Player2 won the game." << std::endl;
            break;
        }
    }
    return 0;
}
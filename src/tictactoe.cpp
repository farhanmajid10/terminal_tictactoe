#include<iostream>
#include "board.h"
#include<string.h>

int main(){
    Board board;
    int player_one_input;
    int player_two_input;
    std::string player_one_name;
    std::string player_two_name; 
    int prev_turn = 10;
        
    std::cout << "Enter Player1 name: ";
    std::cin >> player_one_name;
    std::cout << "Enter Player2 name: ";
    std::cin >> player_two_name;

    while(board.get_game_won() == 0){
        if(board.get_turn() == 0){
            std::cout << player_one_name << ": ";
            std::cin >> player_one_input;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                std::cout << "Please enter Valid Input" << std::endl;
                continue;
            }else if(player_one_input > 8 || player_one_input < 0){
                std::cout << "Please enter valid Input" << std::endl;
                board.printboard();
                std::cout << std::endl;
                continue;
            }            
            board.place_item(player_one_input);
        }else if(board.get_turn() == 1){
            std::cout << player_two_name << ": ";
            std::cin >> player_two_input;
            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                std::cout << "Please enter Valid Input" << std::endl;
                continue;
            }else if(player_two_input > 8 || player_two_input < 0){
                std::cout << "Please enter valid Input" << std::endl;
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
            std::cout << player_one_name << " won the game." << std::endl;
            break;
        }else if(board.get_game_won() == 2){
            std::cout << player_two_name << " won the game." << std::endl;
            break;
        }
    }
    return 0;
}
#include "board.h"
#include <iostream>

    Board::Board(){
        game = new char [9];
        //char[] game = new char[9]
        input1 = 'X';
        input2 = 'O';
        turns = 1;
        for(int i = 0; i < 9; i++){
            game[i] = '#';
        }
    }

    void Board::place_item(int index){
        if(game[index] == '#' && (turns % 2) == 1){
            game[index] = input1;
            turns++;
        }else if(game[index] == '#' && (turns % 2) == 0){
            game[index] = input2;
            turns++;
        }
    }

    void Board::printboard(void){
        std::cout<< std::endl;
        for(int i = 0; i < 9; i++){
            if(i % 3 == 0 && i != 0){
                std::cout<< std::endl;
            }
            std::cout << game[i];
            std::cout << " ";
        }
    }
    void Board::check(void){
        int count = 0;
        //rows
        for(int i = 0; i < 3; i++){
            count = 0;
            for(int j = 0; j < 3; j++){
                if(game[3*i + j] == 'O'){
                    count++;
                }
                if(count == 3){
                    gamewon = 1;
                }
            }
        }
        for(int i = 0; i < 3; i++){
            count = 0;
            for(int j = 0; j < 3; j++){
                if(game[3*i + j] == 'X'){
                    count++;
                }
                if(count == 3){
                    gamewon = 1;
                }
            }
        }

        //columns
        for(int i = 0; i < 3; i++){
            count = 0;
            for(int j = 0; j < 3; j++){
                if(game[i + 3*j] == 'X'){
                    count++;
                }
                if(count == 3){
                    gamewon = 1;
                }
            }
        }
        for(int i = 0; i < 3; i++){
            count = 0;
            for(int j = 0; j < 3; j++){
                if(game[i + 3*j] == 'O'){
                    count++;
                }
                if(count == 3){
                    gamewon = 1;
                }
            }
        }
        count = 0;
        //diagonals
        for(int i = 0, j = 0; i < 3, j < 3; i++, j++){
            if(game[3*i+j] == 'O'){
                count++;
            }
        }
        if(count == 3){
            gamewon = 1;
            count = 0;
        }
        for(int i = 0, j = 0; i < 3, j < 3; i++, j++){
            if(game[3*i+j] == 'X'){
                count++;
            }
        }
        if(count == 3){
            gamewon = 1;
        }
        count = 0;
        for(int i = 2, j = 2; j >= 0, i >= 0; j--,i--){
            if(game[3*i + j] == 'O'){
                count++;
            }
        }
        if(count == 3){
            gamewon = 1;
        }
        count = 0;
        for(int i = 2, j = 2; j >= 0, i >= 0; j--,i--){
            if(game[3*i + j] == 'X'){
                count++;
            }
        }
        if(count == 3){
            gamewon = 1;
        }
        count = 0;

        return;
    }

    int Board::get_game_won(void){
        return gamewon;
    }
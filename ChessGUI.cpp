#include "Board.h"
#include "Piece.h"
#include <string>
#include <iostream>
#include <regex>

int main()
{
    Board board;
    bool playing = true;

    while (playing) {
        system("cls");
        std::cout << " ___ ___ ___ ___ ___ ___ ___ ___\n";
        for (int row = 0; row < 8; row++) {
            std::cout << "|   |   |   |   |   |   |   |   |\n|";
            for (int col = 0; col < 8; col++) {
                std::cout << " ";
                Piece* ptr = board.getSpot(col, row).getPiece();
                if (ptr == nullptr) {
                    std::cout << " ";
                }
                else {
                    std::cout << (std::string) *ptr;
                }
                std::cout << " |";
            }
            std::cout << "\n|___|___|___|___|___|___|___|___|\n";
        }

        std::cout << "Enter a valid move in long algebraic notation, e.g. 'e2e4', 'e7e5', 'e1g1' (white short castling), 'e7e8q' (for promotion)\n";
        
        std::string move;
        std::cin >> move;
        if (std::regex_match(move, std::regex("([a-hA-H]\\d)(?!\\1)([a-hA-H]\\d)([a-hA-H])*"))) {
            std::cout << "valid move!";
        }
        else {
            std::cout << "invalid move";
        }

        std::cin.ignore();
        std::cin.get();
    }
}
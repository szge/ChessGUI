#include "TextGUI.h"
#include "ChessInterface.h"
#include <windows.h>
#include <string>
#include <iostream>
#include <regex>

TextGUI::TextGUI() {

}

void TextGUI::start()
{
	ChessInterface chessInterface;

    while (true) {
        system("cls");
        std::cout << "   ____ ____ ____ ____ ____ ____ ____ ____\n";
        for (int row = 7; row >= 0; row--) {
            std::cout << "  |    |    |    |    |    |    |    |    |\n" << row + 1 << " |";

            for (int col = 0; col < 8; col++) {
                std::cout << " ";
                // chess board prints with row 1 on the bottom so ya gotta flip it
                std::cout << chessInterface.printPiece(col, row);
                std::cout << " |";
            }
            std::cout << "\n  |____|____|____|____|____|____|____|____|\n";
        }
        std::cout << "    ";
        for (int i = 0; i < 8; i++) {
            std::cout << (char) ('A' + i) << "    ";
        }
        std::cout << "\n"; // \n is faster than endl since no buffer flush
        std::cout << "To move, enter a valid move in long algebraic notation\n\te.g. 'e2e4', 'e7e5', 'e1g1' (white short castling), 'e7e8q' (for promotion)\n";
        std::cout << "To restart, enter \"restart\"\n";

        if (chessInterface.getPlayerColor() == Color::WHITE) {
            std::cout << "White move: ";
        }
        else {
            std::cout << "Black move: ";
        }
        std::string input;
        std::cin >> input;
        std::transform(input.begin(), input.end(), input.begin(), ::tolower); // convert to lower case
        if (input == "restart") {
            std::cout << "Board resetting...";
            chessInterface.resetBoard();
        }
        else if (input == "0000" || std::regex_match(input, std::regex("([a-h][1-8])(?!\\1)([a-h][1-8])([qrbn]?)"))) {
            // valid long algebraic chess notation
            if (!chessInterface.move(input)) {
                std::cout << "Invalid move. Press any key to acknowledge.";
                std::cin.ignore();
                std::cin.get();
            }
        }
        else {
            std::cout << "Invalid input. Make sure your move is formatted correctly. Press any key to acknowledge.";
            std::cin.ignore();
            std::cin.get();
        }
    }
}
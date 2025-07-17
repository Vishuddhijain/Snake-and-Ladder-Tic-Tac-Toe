#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

class TicTacToe {
public:
    void clear_screen() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    void display_board(char board[3][3]) {
        const string RED = "\033[1;31m";
        const string BLUE = "\033[1;34m";
        const string RESET = "\033[0m";

        clear_screen();
        cout << "\n  0   1   2\n";
        for (int i = 0; i < 3; i++) {
            cout << i << " ";
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'X') {
                    cout << RED << board[i][j] << RESET;
                } else if (board[i][j] == 'O') {
                    cout << BLUE << board[i][j] << RESET;
                } else {
                    cout << board[i][j];
                }
                if (j != 2) {
                    cout << " | ";
                }
            }
            cout << endl;
            if (i != 2) {
                cout << "  ---------" << endl;
            }
        }
        cout << endl;
    }

    bool checkwin(char board[3][3], string player, char symbol) {
        // Check horizontal lines
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
                cout << player << " won!" << endl;
                return true;
            }
        }

        // Check vertical lines
        for (int i = 0; i < 3; ++i) {
            if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
                cout << player << " won!" << endl;
                return true;
            }
        }

        // Check diagonals
        if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
            cout << player << " won!" << endl;
            return true;
        }
        if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
            cout << player << " won!" << endl;
            return true;
        }
        
        return false;
    }

    bool is_board_full(char board[3][3]) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    void computer_move_difficult(char board[3][3]) {
        // Try to win
        if (try_move(board, 'O')) return;
        
        // Try to block player
        if (try_move(board, 'X')) return;
        
        // Take center if available
        if (board[1][1] == ' ') {
            board[1][1] = 'O';
            return;
        }
        
        // Take corners
        int corners[4][2] = {{0,0}, {0,2}, {2,0}, {2,2}};
        for (int i = 0; i < 4; i++) {
            if (board[corners[i][0]][corners[i][1]] == ' ') {
                board[corners[i][0]][corners[i][1]] = 'O';
                return;
            }
        }
        
        // Take any available spot
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    return;
                }
            }
        }
    }

private:
    bool try_move(char board[3][3], char symbol) {
        char opponent = (symbol == 'X') ? 'O' : 'X';
        
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (check_line(board[i][0], board[i][1], board[i][2], symbol, board, i, 0, i, 1, i, 2)) return true;
        }
        
        // Check columns
        for (int j = 0; j < 3; j++) {
            if (check_line(board[0][j], board[1][j], board[2][j], symbol, board, 0, j, 1, j, 2, j)) return true;
        }
        
        // Check diagonals
        if (check_line(board[0][0], board[1][1], board[2][2], symbol, board, 0, 0, 1, 1, 2, 2)) return true;
        if (check_line(board[0][2], board[1][1], board[2][0], symbol, board, 0, 2, 1, 1, 2, 0)) return true;
        
        return false;
    }

    bool check_line(char a, char b, char c, char symbol, char board[3][3], int r1, int c1, int r2, int c2, int r3, int c3) {
        char opponent = (symbol == 'X') ? 'O' : 'X';
        
        if (a == symbol && b == symbol && c == ' ') {
            board[r3][c3] = opponent;
            return true;
        }
        if (a == symbol && c == symbol && b == ' ') {
            board[r2][c2] = opponent;
            return true;
        }
        if (b == symbol && c == symbol && a == ' ') {
            board[r1][c1] = opponent;
            return true;
        }
        return false;
    }
};

class SnakeAndLadder {
public:
    void clear_screen() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    void display_board(string board1[10][10]) {
        cout << "-----------------------------------------------------------" << endl;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (board1[i][j] == "P1") {
                    cout << "\033[31m" << board1[i][j] << "\033[0m";
                } else if (board1[i][j] == "P2") {
                    cout << "\033[34m" << board1[i][j] << "\033[0m";
                } else {
                    cout << "\033[33m" << board1[i][j] << "\033[0m";
                }
                cout << " |";
            }
            cout << endl;
            cout << "-----------------------------------------------------------" << endl;
        }
    }

    void clear_previous_position(string board1[10][10], int pos) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (board1[i][j] == "P1" || board1[i][j] == "P2") {
                    board1[i][j] = to_string(pos);
                }
            }
        }
    }

    void checking_ladder(string board1[10][10], int &pos, string pers) {
        int ladders[][2] = {{4, 14}, {9, 31}, {21, 42}, {28, 84}, {51, 67}, {72, 91}, {80, 99}};
        
        for (int i = 0; i < 7; i++) {
            if (pos == ladders[i][0]) {
                cout << "You have reached a ladder! Climbing from " << pos << " to " << ladders[i][1] << endl;
#ifdef _WIN32
                Beep(750, 300);
#endif
                pos = ladders[i][1];
                update_position(board1, pos, pers);
                display_board(board1);
#ifdef _WIN32
                Sleep(2000);
#else
                sleep(2);
#endif
                clear_screen();
                return;
            }
        }
    }

    void checking_snake(string board1[10][10], int &pos, string pers) {
        int snakes[][2] = {{17, 7}, {62, 19}, {54, 34}, {87, 36}, {64, 60}, {93, 73}, {95, 75}, {98, 79}};
        
        for (int i = 0; i < 8; i++) {
            if (pos == snakes[i][0]) {
                cout << "OOPS! You have reached a snake! Sliding from " << pos << " to " << snakes[i][1] << endl;
#ifdef _WIN32
                Beep(750, 300);
#endif
                pos = snakes[i][1];
                update_position(board1, pos, pers);
                display_board(board1);
#ifdef _WIN32
                Sleep(2000);
#else
                sleep(2);
#endif
                clear_screen();
                return;
            }
        }
    }

    void checking_position(string board1[10][10], int pos, string pers) {
        cout << "You are at position " << pos << endl;
        update_position(board1, pos, pers);
        display_board(board1);
#ifdef _WIN32
        Sleep(2000);
#else
        sleep(2);
#endif
        clear_screen();
    }

private:
    void update_position(string board1[10][10], int pos, string pers) {
        if (pos <= 0 || pos > 100) return;
        
        int row = 9 - (pos - 1) / 10;
        int col;
        
        if (row % 2 == 1) {
            col = (pos - 1) % 10;
        } else {
            col = 9 - ((pos - 1) % 10);
        }
        
        board1[row][col] = pers;
    }
};

int main() {
    srand(time(0));
    
    cout << "\033[33m";
    cout << "WELCOME PLAYER\n\n";
    cout << "THIS IS A TWO GAME PORTAL WHICH INCLUDES THE FOLLOWING GAMES:\n";
    cout << "1- TIC TAC TOE\n";
    cout << "2- SNAKE AND LADDER\n\n";
    cout << "\033[0m";
    cout << "CHOOSE WHICH GAME YOU WANT TO PLAY (1 or 2): ";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "\n=== Welcome to TIC-TAC-TOE ===\n\n";
        cout << "Rules:\n";
        cout << "1. Get three symbols in a row, column, or diagonal to win\n";
        cout << "2. Enter row and column (0-2) when prompted\n";
        cout << "3. Player X goes first\n\n";

        TicTacToe game;
        char board[3][3] = {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}
        };

        cout << "Choose game mode:\n";
        cout << "1. Player vs Player\n";
        cout << "2. Player vs Computer (Easy)\n";
        cout << "3. Player vs Computer (Hard)\n";
        cout << "Enter choice: ";
        
        int mode;
        cin >> mode;

        if (mode == 1) {
            string player1, player2;
            cout << "Enter name for Player 1 (X): ";
            cin >> player1;
            cout << "Enter name for Player 2 (O): ";
            cin >> player2;

            game.display_board(board);
            
            for (int moves = 0; moves < 9; moves++) {
                int row, col;
                string current_player = (moves % 2 == 0) ? player1 : player2;
                char symbol = (moves % 2 == 0) ? 'X' : 'O';

                cout << current_player << "'s turn. Enter row and column (0-2): ";
                cin >> row >> col;

                if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                    cout << "Invalid move! Try again.\n";
                    moves--;
                    continue;
                }

                board[row][col] = symbol;
                game.display_board(board);

                if (game.checkwin(board, current_player, symbol)) {
                    return 0;
                }
            }
            cout << "It's a draw!\n";
        }
        else if (mode == 2) {
            string player;
            cout << "Enter your name: ";
            cin >> player;
            
            game.display_board(board);
            
            for (int moves = 0; moves < 9; moves++) {
                if (moves % 2 == 0) {
                    int row, col;
                    cout << player << "'s turn. Enter row and column (0-2): ";
                    cin >> row >> col;

                    if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                        cout << "Invalid move! Try again.\n";
                        moves--;
                        continue;
                    }

                    board[row][col] = 'X';
                    game.display_board(board);

                    if (game.checkwin(board, player, 'X')) {
                        return 0;
                    }
                } else {
                    // Computer's turn (random)
                    int row, col;
                    do {
                        row = rand() % 3;
                        col = rand() % 3;
                    } while (board[row][col] != ' ');

                    board[row][col] = 'O';
                    cout << "Computer played at (" << row << ", " << col << ")\n";
                    game.display_board(board);

                    if (game.checkwin(board, "Computer", 'O')) {
                        return 0;
                    }
                }
            }
            cout << "It's a draw!\n";
        }
        else if (mode == 3) {
            string player;
            cout << "Enter your name: ";
            cin >> player;
            
            game.display_board(board);
            
            for (int moves = 0; moves < 9; moves++) {
                if (moves % 2 == 0) {
                    int row, col;
                    cout << player << "'s turn. Enter row and column (0-2): ";
                    cin >> row >> col;

                    if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                        cout << "Invalid move! Try again.\n";
                        moves--;
                        continue;
                    }

                    board[row][col] = 'X';
                    game.display_board(board);

                    if (game.checkwin(board, player, 'X')) {
                        return 0;
                    }
                } else {
                    // Computer's turn (strategic)
                    game.computer_move_difficult(board);
                    cout << "Computer made its move.\n";
                    game.display_board(board);

                    if (game.checkwin(board, "Computer", 'O')) {
                        return 0;
                    }
                }
            }
            cout << "It's a draw!\n";
        }
    }
    else if (choice == 2) {
        SnakeAndLadder game;
        string board1[10][10] = {
            {"100", "99", "98", "97", "96", "95", "94", "93", "92", "91"},
            {"81", "82", "83", "84", "85", "86", "87", "88", "89", "90"},
            {"80", "79", "78", "77", "76", "75", "74", "73", "72", "71"},
            {"61", "62", "63", "64", "65", "66", "67", "68", "69", "70"},
            {"60", "59", "58", "57", "56", "55", "54", "53", "52", "51"},
            {"41", "42", "43", "44", "45", "46", "47", "48", "49", "50"},
            {"40", "39", "38", "37", "36", "35", "34", "33", "32", "31"},
            {"21", "22", "23", "24", "25", "26", "27", "28", "29", "30"},
            {"20", "19", "18", "17", "16", "15", "14", "13", "12", "11"},
            {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"}
        };

        cout << "\n=== SNAKE AND LADDER ===\n\n";
        cout << "Ladders: 4→14, 9→31, 21→42, 28→84, 51→67, 72→91, 80→99\n";
        cout << "Snakes: 17→7, 62→19, 54→34, 87→36, 64→60, 93→73, 95→75, 98→79\n\n";

        game.display_board(board1);

        string player1, player2;
        cout << "Enter name for Player 1: ";
        cin >> player1;
        cout << "Enter name for Player 2: ";
        cin >> player2;

        int pos1 = 0, pos2 = 0;
        int turn = 0;

        while (pos1 < 100 && pos2 < 100) {
            if (turn % 2 == 0) {
                cout << player1 << ", press Enter to roll the dice...";
                cin.ignore();
                cin.get();
                
                int dice = (rand() % 6) + 1;
                cout << player1 << " rolled a " << dice << endl;
                
                if (pos1 + dice <= 100) {
                    pos1 += dice;
                    
                    game.checking_ladder(board1, pos1, "P1");
                    game.checking_snake(board1, pos1, "P1");
                    game.checking_position(board1, pos1, "P1");
                    
                    if (pos1 == 100) {
                        cout << "\n🎉 " << player1 << " WINS! 🎉\n";
                        return 0;
                    }
                } else {
                    cout << "Cannot move - would exceed 100!\n";
                }
            } else {
                cout << player2 << ", press Enter to roll the dice...";
                cin.get();
                
                int dice = (rand() % 6) + 1;
                cout << player2 << " rolled a " << dice << endl;
                
                if (pos2 + dice <= 100) {
                    pos2 += dice;
                    
                    game.checking_ladder(board1, pos2, "P2");
                    game.checking_snake(board1, pos2, "P2");
                    game.checking_position(board1, pos2, "P2");
                    
                    if (pos2 == 100) {
                        cout << "\n🎉 " << player2 << " WINS! 🎉\n";
                        return 0;
                    }
                } else {
                    cout << "Cannot move - would exceed 100!\n";
                }
            }
            turn++;
        }
    }
    else {
        cout << "Invalid choice! Please run the program again.\n";
    }

    return 0;
}
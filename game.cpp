#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <bits/stdc++.h>
using namespace std;
 class tictactoe{
     public:
void clear_screen()
{
  system("cls");
}

void display_board(char board[3][3])
{
  const string RED = "\033[1;31m";  // Red color for 'X'
  const string BLUE = "\033[1;34m"; // Blue color for '0'
  const string RESET = "\033[0m";   // Reset color to default

  clear_screen();
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      // Apply color to 'X'
      if (board[i][j] == 'X')
      {
        cout << RED << board[i][j] << RESET;
      }
      // Apply color to '0'
      else if (board[i][j] == '0')
      {
        cout << BLUE << board[i][j] << RESET;
      }
      // No color for empty cells
      else
      {
        cout << board[i][j];
      }
      if (j != 2)
      {
        cout << " |";
      }
    }
    cout << endl;
    if (i != 2)
    {
      cout << "--------" << endl;
    }
  }
}
void checkwin(char board[3][3], string str, char symbol)
{

  // CHECKING HORIZONTAL LINES
  for (int i = 0; i < 3; ++i)
  {
    if ((board[i][0] == symbol) && (board[i][1] == symbol) && (board[i][2] == symbol))
    {
      cout << str << " won" << endl;
      exit(0);
    }
  }

  // CHECKING VERTICAL LINES
  for (int i = 0; i < 3; ++i)
  {
    if ((board[0][i] == symbol) && (board[1][i] == symbol) && (board[2][i] == symbol))
    {
      cout << str << " won" << endl;
      exit(0);
    }
  }

  // CHECKING DIAGONALS
  if ((board[0][0] == symbol) && (board[1][1] == symbol) && (board[2][2] == symbol))
  {
    cout << str << " won" << endl;
    exit(0);
  }
  if ((board[0][2] == symbol) && (board[1][1] == symbol) && (board[2][0] == symbol))
  {
    cout << str << " won" << endl;
    exit(0);
  }
}
 };
 class snakeandladder{
 public:

/*void display_board(string board1[10][10]);
void clear_previous_position(string board1[10][10], int pos);
void checking_ladder(string board1[10][10], int &pos, string pers);
void checking_snake(string board1[10][10], int &pos, string pers);
void checking_position(string board1[10][10], int pos, string pers);*/

void clear_screen()
{
  system("cls");
}
void display_board(string board1[10][10])
{
  cout << "--------------------------------------------------" << endl;
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      if (board1[i][j] == "P1")
      {
        cout << "\x1B[31m"; // Set red color for P1
      }
      else if (board1[i][j] == "P2")
      {
        cout << "\x1B[34m"; // Set blue color for P2
      }
      else
      {
        cout << "\x1B[33m"; // Set default color to green for the rest of the board
      }
      cout << board1[i][j] << " \x1B[32m |";
    }
    cout << endl;
    cout << "\x1B[37m--------------------------------------------------" << endl;
  }
}

// Function to clear the previous position of a player on the board
void clear_previous_position(string board1[10][10], int pos)
{
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      if (board1[i][j] == "P1" || board1[i][j] == "P2")
      {
        board1[i][j] = to_string(pos);
      }
    }
  }
}

// Function to check if a player has reached a ladder
void checking_ladder(string board1[10][10], int &pos, string pers)
{

  if (pos == 4)
  {
    cout << "You have reached a ladder!" << endl;
    Beep(750, 300);
    cout << "Your position is now at 14" << endl;
    pos = 14;
    board1[8][6] = pers;
    display_board(board1);
    Sleep(2000);
    clear_screen();
  }
  else if (pos == 9)
  {
    cout << "You have reached a ladder!" << endl;
    Beep(750, 300);
    cout << "Your position is now at 31" << endl;
    pos = 31;
    board1[6][9] = pers;
    display_board(board1);
    Sleep(2000);
    clear_screen();
  }
  else if (pos == 21)
  {
    cout << "You have reached a ladder!" << endl;
    Beep(750, 300);
    cout << "Your position is now at 42" << endl;
    pos = 42;
    board1[5][1] = pers;
    display_board(board1);
    Sleep(2000);
    clear_screen();
  }
  else if (pos == 28)
  {
    cout << "You have reached a ladder!" << endl;
    Beep(750, 300);
    cout << "Your position is now at 84" << endl;
    pos = 84;
    board1[2][3] = pers;
    display_board(board1);
    Sleep(2000);
    clear_screen();
  }
  else if (pos == 51)
  {
    cout << "You have reached a ladder!" << endl;
    Beep(750, 300);
    cout << "Your position is now at 67" << endl;
    pos = 67;
    board1[3][6] = pers;
    display_board(board1);
    Sleep(2000);
    clear_screen();
  }
  else if (pos == 72)
  {
    cout << "You have reached a ladder!" << endl;
    Beep(750, 300);
    cout << "Your position is now at 91" << endl;
    pos = 91;
    board1[0][9] = pers;
    display_board(board1);
    Sleep(2000);
    clear_screen();
  }
  else if (pos == 80)
  {
    cout << "You have reached a ladder!" << endl;
    Beep(750, 300);
    cout << "Your position is now at 99" << endl;
    pos = 99;
    board1[0][2] = pers;
    display_board(board1);
    Sleep(2000);
    clear_screen();
  }
}

// Function to check if a player has reached a snake
void checking_snake(string board1[10][10], int &pos, string pers)
{

  if (pos == 17)
  {
    cout << "OOPS!!You have reached at the mouth of a snake!" << endl;
    Beep(750, 300);
    cout << "Your position is now at 7" << endl;
    pos = 7;
    board1[9][6] = pers;
    display_board(board1);
    Sleep(2000);
    clear_screen();
  }
  else if (pos == 62)
  {
    cout << "OOPS!!You have reached at the mouth of a snake!" << endl;
    Beep(750, 300);
    cout << "Your position is now at 19" << endl;
    pos = 19;
    board1[8][1] = pers;
    display_board(board1);
    Sleep(2000);
    clear_screen();
  }
  else if (pos == 54)
  {
    cout << "OOPS!!You have reached at the mouth of a snake!" << endl;
    Beep(750, 300);
    cout << "Your position is now at 34" << endl;
    pos = 34;
    board1[6][6] = pers;
    display_board(board1);
    Sleep(2000);
    clear_screen();
  }
  else if (pos == 87)
  {
    cout << "OOPS!!You have reached at the mouth of a snake!" << endl;
    Beep(750, 300);
    cout << "Your position is now at 36" << endl;
    pos = 36;
    board1[6][4] = pers;
    display_board(board1);
    Sleep(2000);
    clear_screen();
  }
  else if (pos == 64)
  {
    cout << "OOPS!!You have reached at the mouth of a snake!" << endl;
    Beep(750, 300);
    cout << "Your position is now at 60" << endl;
    pos = 60;
    board1[4][0] = pers;
    display_board(board1);
    Sleep(2000);
    clear_screen();
  }
  else if (pos == 93)
  {
    cout << "OOPS!!You have reached at the mouth of a snake!" << endl;
    Beep(750, 300);
    cout << "Your position is now at 73" << endl;
    pos = 73;
    board1[2][7] = pers;
    display_board(board1);
    Sleep(2000);
    clear_screen();
  }
  else if (pos == 95)
  {
    cout << "OOPS!!You have reached at the mouth of a snake!" << endl;
    Beep(750, 300);
    cout << "Your position is now at 75" << endl;
    pos = 75;
    board1[2][5] = pers;
    display_board(board1);
    Sleep(2000);
    clear_screen();
  }
  else if (pos == 98)
  {
    cout << "OOPS!!You have reached at the mouth of a snake!" << endl;
    Beep(750, 300);
    cout << "Your position is now at 79" << endl;
    pos = 79;
    board1[2][1] = pers;
    display_board(board1);
    Sleep(2000);
    clear_screen();
  }
}

// Function to check and update the position of a player on the board
void checking_position(string board1[10][10], int pos, string pers)
{

  if ((pos != 4) && (pos != 9) && (pos != 21) && (pos != 28) && (pos != 51) && (pos != 72) && (pos != 80) && (pos != 17) && (pos != 62) && (pos != 54) && (pos != 87) && (pos != 64) && (pos != 93) && (pos != 95) && (pos != 98) && (pos != 20) && (pos != 40) && (pos != 60) && (pos != 80))
  {
    cout << "You are at position" << pos << endl;
    int row, col;
    row = 9 - (pos - 1) / 10;
    if (row % 2 != 0)
    {
      col = (pos - 1) % 10;
    }
    else
    {
      col = (9 - (pos % 10)) + 1;
    }
    board1[row][col] = pers;
  }
  else if (pos == 20)
  {
    cout << "You are at position" << pos << endl;
    board1[8][0] = pers;
  }
  else if (pos == 40)
  {
    cout << "You are at position" << pos << endl;
    board1[6][0] = pers;
  }
  else if (pos == 60)
  {
    cout << "You are at position" << pos << endl;
    board1[4][0] = pers;
  }
  else if (pos == 80)
  {
    cout << "You are at position" << pos << endl;
    board1[2][0] = pers;
  }
  display_board(board1);
  Sleep(2000);
  clear_screen();
  cout << endl;
}
 };

int main()
{
  cout << "\x1b[33m";
  cout << "WELCOME PLAYER                             " << endl
       << endl;
  cout << "THIS IS A TWO GAME PORTAL WHICH INCLUDES THE FOLLOWING TWO GAMES:" << endl;
  cout << "1- TIC TAC TOE" << endl;
  cout << "2- SNAKE AND LADDER" << endl
       << endl;
  cout << "\x1b[0m";
  cout << "CHOOSE WHICH GAME U WANT TO PLAY" << endl;

  int a;
  cin >> a;
  if (a == 1)
  {

    cout << "                                                             Welcome to TIC-TAC-TOE" << endl
         << endl;
    cout << "Here are the rules:" << endl;
    cout << "1)Objective: The game is played on a 3x3 grid. The objective is to be the first player to get three of their symbols (traditionally X or O) in a row, column, or diagonal." << endl;
    cout << "2)Players: The game is typically played by two players." << endl;
    cout << "3)Board: The board consists of a 3x3 grid. Players take turns placing their symbol (X or O) in an empty cell of the grid." << endl;
    cout << "4)Turns: Players take turns to make their moves. Player X makes the first move, followed by Player O, and so on." << endl;
    cout << "5)Winning: A player wins the game if they have three of their symbols in a row, column, or diagonal. The game ends immediately when a player achieves this, and they are declared the winner." << endl;
    cout << "6)Draw: If all cells of the grid are filled with symbols and neither player has achieved a winning combination, the game is a draw." << endl;
    cout << "7)Strategy: While Tic Tac Toe is a simple game, it still involves some strategy. Players aim to either create their own winning combinations or block their opponent from achieving theirs." << endl;
    cout << "8)Fairness: If both players play optimally, the game should end in a draw. However, mistakes or suboptimal play can lead to one player winning or a draw." << endl
         << endl
         << endl;
    cout << "Here is your Tic Tac Toe board" << endl;
    tictactoe t;
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        if (j != 2)
        {
          cout << "  |";
        }
      }
      cout << endl;
      if (i != 2)
      {
        cout << "---------" << endl;
      }
    }
    cout << endl;
    cout << "Choose an option:" << endl;
    cout << "1. Player vs player" << endl;
    cout << "2. Player vs computer (Easy)" << endl;
    cout << "3. Player vs computer (Difficult)" << endl;
    int choice;
    cin >> choice;

    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};
    string u, v;
    if (choice == 1)
    {
      cout << "Enter the name of the first player: ";
      cin >> u;
      cout << "Welcome " << u << ", your symbol is 'X'" << endl;
      cout << "Enter the name of the second player: ";
      cin >> v;
      cout << "Welcome " << v << ", your symbol is 'O'" << endl;

      for (int moves = 1; moves <= 9; moves++)
      {
        if ((moves % 2) != 0)
        {
          int x, y;
        label_player1:
          cout << u << " enter the position";
          cin >> x >> y;
          try
          {
            if ((x > 2) || (y > 2) || (x < 0) || (y < 0) || (board[x][y] != ' '))
              throw 5;
          }
          catch (int a)
          {
            cout << "You have entered Invalid position.Please enter the correct one" << endl;
            goto label_player1;
          }
          board[x][y] = 'X';
          t.display_board(board);
          t.checkwin(board, u, 'X');
        }
        else
        {
          int p, q;
        label_player2:
          cout << v << " enter the position";
          cin >> p >> q;
          try
          {
            if ((p > 2) || (q > 2) || (p < 0) || (q < 0) || (board[p][q] != ' '))
              throw 2;
          }
          catch (int b)
          {
            cout << "You have entered Invalid position.Please enter the correct one" << endl;
            goto label_player2;
          }
          board[p][q] = '0';
          t.display_board(board);
          t.checkwin(board, v, '0');
        }
      }

      cout << "It's a draw" << endl;
    }
    else if (choice == 2)
    {
      string u;
      cout << "enter name of the player";
      cin >> u;
      cout << "Welcome " << u << " your symbol is X" << endl;
      cout << "Computer is the second player with symbol 0" << endl;

      for (int moves = 1; moves <= 9; moves++)
      {
        if ((moves % 2) != 0)
        {
          int x, y;
        label_player1_easy:
          cout << u << " enter the position";
          cin >> x >> y;
          try
          {
            if ((x > 2) || (y > 2) || (x < 0) || (y < 0) || (board[x][y] != ' '))
              throw 5;
          }
          catch (int a)
          {
            cout << "You have entered Invalid position.Please enter the correct one" << endl;
            goto label_player1_easy;
          }
          board[x][y] = 'X';
          t.display_board(board);
          cout << endl;
          t.checkwin(board, u, 'X');
        }
        else
        {
          int p, q;
        label_computer_easy:
          p = rand() % 3;
          q = rand() % 3;
          try
          {
            if ((p > 2) || (q > 2) || (p < 0) || (q < 0) || (board[p][q] != ' '))
              throw 2;
          }
          catch (int b)
          {
            cout << "You have entered Invalid position.Please enter the correct one" << endl;
            goto label_computer_easy;
          }
          board[p][q] = '0';
          t.display_board(board);
          t.checkwin(board, "Computer", '0');
        }
      }
      cout << "It's a draw" << endl;
    }
    else if (choice == 3)
    {
      string u;
      cout << "enter name of the player";
      cin >> u;
      cout << "Welcome " << u << " your symbol is X" << endl;
      cout << "Computer is the second player with symbol 0" << endl;

      for (int moves = 1; moves <= 9; moves++)
      {
        if ((moves % 2) != 0)
        {
          // Computer's turn for difficult level
          // Winning moves for computer
          for (int i = 0; i < 3; i++)
          {
            if (board[i][0] == '0' && board[i][1] == '0' && board[i][2] == ' ')
            {
              board[i][2] = '0';
            }
            else if (board[i][0] == '0' && board[i][2] == '0' && board[i][1] == ' ')
            {
              board[i][1] = '0';
            }
            else if (board[i][1] == '0' && board[i][2] == '0' && board[i][0] == ' ')
            {
              board[i][0] = '0';
            }
          }

          for (int i = 0; i < 3; i++)
          {
            if (board[0][i] == '0' && board[1][i] == '0' && board[2][i] == ' ')
            {
              board[2][i] = '0';
            }
            else if (board[0][i] == '0' && board[2][i] == '0' && board[1][i] == ' ')
            {
              board[1][i] = '0';
            }
            else if (board[1][i] == '0' && board[2][i] == '0' && board[0][i] == ' ')
            {
              board[0][i] = '0';
            }
          }

          if (board[0][0] == '0' && board[1][1] == '0' && board[2][2] == ' ')
          {
            board[2][2] = '0';
          }
          else if (board[0][0] == '0' && board[2][2] == '0' && board[1][1] == ' ')
          {
            board[1][1] = '0';
          }
          else if (board[1][1] == '0' && board[2][2] == '0' && board[0][0] == ' ')
          {
            board[0][0] = '0';
          }

          if (board[0][2] == '0' && board[1][1] == '0' && board[2][0] == ' ')
          {
            board[2][0] = '0';
          }
          else if (board[0][2] == '0' && board[2][0] == '0' && board[1][1] == ' ')
          {
            board[1][1] = '0';
          }
          else if (board[1][1] == '0' && board[2][0] == '0' && board[0][2] == ' ')
          {
            board[0][2] = '0';
          }

          // Blocking moves for player
          for (int i = 0; i < 3; i++)
          {
            if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == ' ')
            {
              board[i][2] = '0';
            }
            else if (board[i][0] == 'X' && board[i][2] == 'X' && board[i][1] == ' ')
            {
              board[i][1] = '0';
            }
            else if (board[i][1] == 'X' && board[i][2] == 'X' && board[i][0] == ' ')
            {
              board[i][0] = '0';
            }
          }

          for (int i = 0; i < 3; i++)
          {
            if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == ' ')
            {
              board[2][i] = '0';
            }
            else if (board[0][i] == 'X' && board[2][i] == 'X' && board[1][i] == ' ')
            {
              board[1][i] = '0';
            }
            else if (board[1][i] == 'X' && board[2][i] == 'X' && board[0][i] == ' ')
            {
              board[0][i] = '0';
            }
          }

          if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == ' ')
          {
            board[2][2] = '0';
          }
          else if (board[0][0] == 'X' && board[2][2] == 'X' && board[1][1] == ' ')
          {
            board[1][1] = '0';
          }
          else if (board[1][1] == 'X' && board[2][2] == 'X' && board[0][0] == ' ')
          {
            board[0][0] = '0';
          }

          if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == ' ')
          {
            board[2][0] = '0';
          }
          else if (board[0][2] == 'X' && board[2][0] == 'X' && board[1][1] == ' ')
          {
            board[1][1] = '0';
          }
          else if (board[1][1] == 'X' && board[2][0] == 'X' && board[0][2] == ' ')
          {
            board[0][2] = '0';
          }
          else if (board[1][1] == ' ')
          {
            board[1][1] = '0';
          }
          else if (board[0][0] == ' ')
          {
            board[0][0] = '0';
          }
          else if (board[0][2] == ' ')
          {
            board[0][2] = '0';
          }
          else if (board[2][0] == ' ')
          {
            board[2][0] = '0';
          }
          else if (board[2][2] == ' ')
          {
            board[2][2] = '0';
          }

          else
          {
            for (int i = 0; i < 3; ++i)
            {
              for (int j = 0; j < 3; ++j)
              {
                if (board[i][j] == ' ')
                {
                  board[i][j] = '0';
                  i = j = 3; // Break out of the loops
                }
              }
            }
          }

          t.display_board(board);
          t.checkwin(board, "Computer", '0');
        }
        else
        {
          int x, y;
        label_player1_difficult:
          cout << u << " enter the position";
          cin >> x >> y;
          try
          {
            if ((x > 2) || (y > 2) || (x < 0) || (y < 0) || (board[x][y] != ' '))
              throw 5;
          }
          catch (int a)
          {
            cout << "You have entered Invalid position.Please enter the correct one" << endl;
            goto label_player1_difficult;
          }
          board[x][y] = 'X';
          t.display_board(board);
          cout << endl;
          t.checkwin(board, u, 'X');
        }
      }
      cout << "It's a draw" << endl;
    }
  }
  else if (a == 2)
  {
snakeandladder s;
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
        {" 1", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10"}};
    cout << "                                                   SNAKE AND LADDER" << endl
         << endl;
    cout << "Here are the rules:" << endl;
    cout << "1)Objective: The objective of the game is to be the first player to reach the final square on the game board, traditionally marked as 100." << endl
         << "2)Game Board: The game is played on a square board divided into a grid of cells. Each cell is numbered sequentially from 1 to 100." << endl
         << "3)Players: The game is typically played by two or more players. Each player takes turns to roll a die and move their token (representing their position) on the board." << endl
         << "4)Rolling the Die: On their turn, a player rolls a standard six-sided die. The number rolled determines the number of squares the player advances on the board." << endl
         << "5)Ladders: Some squares on the board have a ladder symbol connecting them to a higher-numbered square. If a player lands on a square at the bottom of a ladder, they immediately move their token to the square at the top of the ladder." << endl
         << "6)Snakes: Similarly, some squares on the board have a snake symbol connecting them to a lower-numbered square. If a player lands on a square at the head of a snake, they immediately move their token to the square at the tail of the snake." << endl
         << "7)Winning: The first player to reach or exceed the final square (100) on the board is declared the winner." << endl
         << "8)Extra Rolls: If a player rolls a number that would move them beyond square 100, they do not move forward on that turn. However, if they roll the exact number needed to reach square 100, they win the game." << endl
         << "9)Turns: Players take turns rolling the die and moving their tokens in a clockwise manner around the board until one player wins." << endl
         << "10)Optional Rules: Some variations of the game may include additional rules or features, such as penalties for landing on certain squares or special rules for landing on the first and last squares." << endl
         << endl;

    cout << "Here is your snake and ladder board(ladder is at 4-14, 9-31, 21-42, 28-84, 51-67, 72-91, 80-99 and snake is at 17-7, 62-19, 54-34, 87-36, 64-60,93-73, 95-75,98-79)" << endl
         << endl;

    s.display_board(board1);

    string p1, p2;
    cout << "Enter the name of 1st player";
    cin >> p1;
    cout << "Enter the name of 2nd player";
    cin >> p2;
    getchar();
    cout << endl;

    int posp1 = 0, posp2 = 0;
    int moves = 1;

    while ((posp1 <= 100) && (posp2 <= 100))
    {
      if (moves % 2 != 0)
      {
        cout << p1 << " press enter to roll a die" << endl;
        getchar();
        int p;
        p = rand() % 7;
        cout << p1 << " you rolled a " << p << endl;
        if (posp1 + p <= 100)
        {
          posp1 = posp1 + p;
        }
        else if (posp1 + p > 100)
        {
          cout << "Better luck in next chance" << endl;
        }

        s.checking_ladder(board1, posp1, "P1");

        s.checking_snake(board1, posp1, "P1");

        s.checking_position(board1, posp1, "P1");

        s.clear_previous_position(board1, posp1);

        if (posp1 == 100)
        {
          cout << p1 << " you have won the game" << endl;
          exit(0);
        }
      }

      else
      {
        cout << p2 << " press enter to roll a die" << endl;
        getchar();
        int q;
        q = rand() % 7;
        cout << p2 << " you rolled a " << q << endl;
        if (posp2 + q <= 100)
        {
          posp2 = posp2 + q;
        }
        else if (posp2 + q > 100)
        {
          cout << "Better luck in next chance" << endl;
        }

        s.checking_ladder(board1, posp2, "P2");

        s.checking_snake(board1, posp2, "P2");

        s.checking_position(board1, posp2, "P2");

        s.clear_previous_position(board1, posp2);

        if (posp2 == 100)
        {
          cout << p2 << " you have won the game" << endl;
          exit(0);
        }
      }

      moves++;
    }
  }
  else
  {
    cout << " THE USER HAS NOT CHOOSE ANY GAME TO PLAY " << endl;
  }
  return 0;
}
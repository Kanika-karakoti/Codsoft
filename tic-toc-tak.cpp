#include <iostream>
#include <vector>

using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(vector<vector<char>>& board) {
  cout << "\n   |   |   " << endl;
  cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
  cout << "   |   |   " << endl;
  cout << "---+---+---" << endl;
  cout << "   |   |   " << endl;
  cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
  cout << "   |   |   " << endl;
  cout << "---+---+---" << endl;
  cout << "   |   |   " << endl;
  cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
  cout << "   |   |   " << endl << endl;
}

// Function to check if a player has won
bool checkWin(vector<vector<char>>& board, char player) {
  // Check rows
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return true;
    }
  }

  // Check columns
  for (int j = 0; j < 3; j++) {
    if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
      return true;
    }
  }

  // Check diagonals
  if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
      (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
    return true;
  }

  return false;
}

// Function to check if the game is a draw
bool checkDraw(vector<vector<char>>& board) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        return false; // Game is not a draw yet
      }
    }
  }
  return true; // All cells are filled, it's a draw
}

int main() {
  // Initialize the game board
  vector<vector<char>> board(3, vector<char>(3, ' '));

  // Assign players
  char player1 = 'X';
  char player2 = 'O';

  // Game loop
  bool gameRunning = true;
  char currentPlayer = player1;
  while (gameRunning) {
    // Display the board
    displayBoard(board);

    // Get player input
    int row, col;
    cout << "Player " << currentPlayer << ", enter your move (row, col): ";
    cin >> row >> col;

    // Validate input
    if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
      cout << "Invalid move. Please try again." << endl;
      continue;
    }

    // Update the board
    board[row - 1][col - 1] = currentPlayer;

    // Check for win
    if (checkWin(board, currentPlayer)) {
      displayBoard(board);
      cout << "Player " << currentPlayer << " wins!" << endl;
      gameRunning = false;
    }

    // Check for draw
    if (checkDraw(board)) {
      displayBoard(board);
      cout << "It's a draw!" << endl;
      gameRunning = false;
    }

    // Switch players
    currentPlayer = (currentPlayer == player1) ? player2 : player1;
  }

  // Play again?
  char playAgain;
  cout << "Play again? (y/n): ";
  cin >> playAgain;
  if (playAgain == 'y') {
    main(); // Restart the game
  }

  return 0;
}

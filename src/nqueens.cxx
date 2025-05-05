module;
#include <print>
#include <string>
#include <vector>

export module nqueens;

using board_t = std::vector<std::vector<char>>;
constexpr char default_cell = '.';
constexpr char queen_cell = 'Q';

board_t createBoard(int size) {
  board_t board(size, std::vector<char>(size, default_cell));
  return board;
}

void printBoard(const board_t& board) {
  for (const auto& row : board) {
    for (const auto& cell : row) {
      std::print("{}\t", cell);
    }
    std::println();
  }
}

bool solveCrossWord(std::string word, board_t& board, int row, int col) {

  // Place on the left
  auto placeOnLeft = [&board, &word](int r, int c) {
    for (int i = 0; i < word.size(); ++i) {
      if (c - i < 0 || board[r][c - i] != default_cell && board[r][c - i] != word[i]) {
        return false;
      }
    }
    return true;
  };

  // Place on the right
  auto placeOnRight = [&board, &word](int r, int c) {
    for (int i = 0; i < word.size(); ++i) {
      if (c + i >= board.size() || board[r][c + i] != default_cell && board[r][c + i] != word[i]) {
        return false;
      }
    }
    return true;
  };
  
  // Place on the top
  auto placeOnTop = [&board, &word](int r, int c) {
    for (int i = 0; i < word.size(); ++i) {
      if (r - i < 0 || board[r - i][c] != default_cell && board[r - i][c] != word[i]) {
        return false;
      }
    }
    return true;
  };
  
  // Place on the bottom
  auto placeOnBottom = [&board, &word](int r, int c) {
    for (int i = 0; i < word.size(); ++i) {
      if (r + i >= board.size() || board[r + i][c] != default_cell && board[r + i][c] != word[i]) {
        return false;
      }
    }
    return true;
  };
  
  // Place on the top-left diagonal
  auto placeOnTopLeft = [&board, &word](int r, int c) {
    for (int i = 0; i < word.size(); ++i) {
      if (r - i < 0 || c - i < 0 || board[r - i][c - i] != default_cell && board[r - i][c - i] != word[i]) {
        return false;
      }
    }
    return true;
  };
  
  // Place on the top-right diagonal
  auto placeOnTopRight = [&board, &word](int r, int c) {
    for (int i = 0; i < word.size(); ++i) {
      if (r - i < 0 || c + i >= board.size() || board[r - i][c + i] != default_cell && board[r - i][c + i] != word[i]) {
        return false;
      }
    }
    return true;
  };
  
  // Place on the bottom-left diagonal
  auto placeOnBottomLeft = [&board, &word](int r, int c) {
    for (int i = 0; i < word.size(); ++i) {
      if (r + i >= board.size() || c - i < 0 || board[r + i][c - i] != default_cell && board[r + i][c - i] != word[i]) {
        return false;
      }
    }
    return true;
  };
  
  // Place on the bottom-right diagonal
  auto placeOnBottomRight = [&board, &word](int r, int c) {
    for (int i = 0; i < word.size(); ++i) {
      if (r + i >= board.size() || c + i >= board.size() || board[r + i][c + i] != default_cell && board[r + i][c + i] != word[i]) {
        return false;
      }
    }
    return true;
  };
  
  if (placeOnLeft(row, col)) {
    for (int i = 0; i < word.size(); ++i) {
      board[row][col - i] = word[i];
    }
    return true;
  }
  if (placeOnRight(row, col)) {
    for (int i = 0; i < word.size(); ++i) {
      board[row][col + i] = word[i];
    }
    return true;
  }
  if (placeOnTop(row, col)) {
    for (int i = 0; i < word.size(); ++i) {
      board[row - i][col] = word[i];
    }
    return true;
  }
  if (placeOnBottom(row, col)) {
    for (int i = 0; i < word.size(); ++i) {
      board[row + i][col] = word[i];
    }
    return true;
  }
  if (placeOnTopLeft(row, col)) {
    for (int i = 0; i < word.size(); ++i) {
      board[row - i][col - i] = word[i];
    }
    return true;
  }
  if (placeOnTopRight(row, col)) {
    for (int i = 0; i < word.size(); ++i) {
      board[row - i][col + i] = word[i];
    }
    return true;
  }
  if (placeOnBottomLeft(row, col)) {
    for (int i = 0; i < word.size(); ++i) {
      board[row + i][col - i] = word[i];
    }
    return true;
  }
  if (placeOnBottomRight(row, col)) {
    for (int i = 0; i < word.size(); ++i) {
      board[row + i][col + i] = word[i];
    }
    return true;
  }
  // If no valid placement found,
  return false;
}

bool solveNQueens(int column, board_t& board) {
  // Placeholder implementation for solveNQueens  
  auto placeQueens = [&board](int row, int col) {
    // Check if placing a queen is valid

    for (int i = 0; i < board.size(); ++i) {
      if (board[row][i] == queen_cell) {
        return false; // Check row
      }
    }

    for (int i = 0; i < board.size(); ++i) {
      if (board[i][col] == queen_cell) {
        return false; // Check column
      }
    }

    for(int r = row, c = col; r >= 0 && c >= 0; --r, --c) {
      if (board[r][c] == queen_cell) {
        return false; // Check diagonal
      }
    }
    for(int r = row, c = col, count = board.size(); r < count && c < count; ++r, ++c) {
      if (board[r][c] == queen_cell) {
        return false; // Check diagonal
      }
    }
    for(int r = row, c = col; r >= 0 && c < board.size(); --r, ++c) {
      if (board[r][c] == queen_cell) {
        return false; // Check anti-diagonal
      }
    }
    for(int r = row, c = col, count = board.size(); r < count && c >= 0; ++r, --c) {
      if (board[r][c] == queen_cell) {
        return false; // Check anti-diagonal
      }
    }
    // Check if the position is already occupied by another queen
    return true;
  };

  if (column == board.size()) {
    // All queens are placed successfully
    return true;
  }

  // Example logic to place queens on the board
  for (int i = 0, count = board.size(); i < count; ++i) {
    if (placeQueens(i, column)) {
      board[i][column] = queen_cell;
      if (solveNQueens(column + 1, board)) {
        // If placing the queen leads to a solution, return true
        return true;
      }        
      else {
        board[i][column] = default_cell; // backtrack
      }
    }    
  }
  
  return false;
}

export namespace nq {  
  
  void testSolveNQueens() {    
    int count = 8;
    board_t board = createBoard(count);
    
    std::println("N-queens problem with {} queens", count);
    if (solveNQueens(0, board)) {
      printBoard(board);
    }    
  }

  void testSolveCrossWords() {
    std::vector<std::string> input = {"hello", "world", "crossword"};
    const int size = input.empty() ? 0 : std::max_element(input.begin(), input.end(), [](const auto& a, const auto& b) {
      return a.size() < b.size();
    })->size();

    board_t board = createBoard(size);
    
    std::println("Crossword puzzle");
    
    std::sort(input.begin(), input.end(), [](const auto& a, const auto& b) {
      return a.size() > b.size();
    });

    auto crossWord = [&board, &input]() {
      for (int i = 0; i < board.size(); ++i) {      
        for (int j = 0; j < board.size(); ++j) {
          std::vector<std::pair<int, int>> affectedCells;
          auto word_it = input.begin();
          auto word = *word_it;
          if (solveCrossWord(word, board, i, j)) {
            // Track affected cells
            for (int k = 0; k < word.size(); ++k) {
              affectedCells.emplace_back(i, j + k);
            }
            // If the word is placed successfully, remove it from the list
            input.erase(word_it);
          } 
          else {
            // backtrack - revert only affected cells
            for (const auto& [r, c] : affectedCells) {
              board[r][c] = default_cell;
            }
          }                     
          if (input.empty()) {
            // If all words are placed successfully, return true
            return true;
          }          
        }
      }    
      return false;
    };

    
    
    // Removed redundant "Crossword puzzle:" message
    if (crossWord()) {
      std::println("All words placed successfully");
    } else {
      std::println("Failed to place all words");
    } 
    printBoard(board);   
  }
} // namespace ns
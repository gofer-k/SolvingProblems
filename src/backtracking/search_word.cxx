module;
#include <print>
#include <string>
#include <vector>

export module search_word;

bool in_board(size_t row, size_t col, size_t row_count, size_t col_count)
{
  auto is_range = [](size_t idx, size_t count)
  { return idx >= 0 && idx < count; };
  return is_range(row, row_count) && is_range(col, col_count);
}

bool lookup_word(std::vector<std::vector<char>> &board, size_t row, size_t col, size_t word_pos, const std::string &input_word)
{
  if (not in_board(row, col, board.size(), board.front().size()))
  {
    return false;
  }
  else if (board[row][col] == '\0')
  {
    return false;
  }

  if (board[row][col] != input_word[word_pos])
  {
    return false;
  }
  
  if (word_pos == input_word.length() - 1)
  {
    return true;
  }
  
  auto tmp = board[row][col];
  board[row][col] = '\0';
  auto result = lookup_word(board, row, col + 1, word_pos + 1, input_word)
                || lookup_word(board, row + 1, col, word_pos + 1, input_word)
                || lookup_word(board, row, col - 1, word_pos + 1, input_word)
                 || lookup_word(board, row - 1, col, word_pos + 1, input_word);
  board[row][col] = tmp;
  return result;
}

bool exist(std::vector<std::vector<char>> &board, std::string word)
{
  if (board.empty() || word.empty() || word.length() > 15)
  {
    return false;
  }

  for (size_t row = 0; row < board.size(); ++row)
  {
    for (size_t col = 0; col < board[row].size(); ++col)
    {
      if (lookup_word(board, row, col, 0, word))
      {
        return true;
      }
    }
  }
  return false;
}

export namespace sw
{

  void test_search_word()
  {
    {
      std::vector<std::vector<char>> board = {
          {'C', 'A', 'A'},
          {'A', 'A', 'A'},
          {'B', 'C', 'D'}};

      std::string word = "AAB";
      std::println("Word: {} exist: {}", word, exist(board, word));
    }

    // word = "SEE";
    // std::cout << "Word: " << word << " exist: " << exist(board, word) << std::endl;
    // word = "ABCB";
    // std::cout << "Word: " << word << " exist: " << exist(board, word) << std::endl;
  }

} // namespace sw
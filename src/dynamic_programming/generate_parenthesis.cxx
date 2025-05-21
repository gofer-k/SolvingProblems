module;
#include <vector>
#include <string>
#include <print>
#include <algorithm>
#include <cassert>
#include <stack>

export module gen_parenthesis;

const char close_parenthesis = ')';
const char open_parenthesis =  '(';
std::vector<std::string> result;

void generatorParenthesis(int pairs_count, int opened, int closed, std::string str) {
  std::println("Opened: {}, Closed: {}, str: {}", opened, closed, str);
  if (opened == pairs_count && closed == pairs_count) { 
    result.push_back(str);
    return;
  }
  if (opened < pairs_count) {
    str += open_parenthesis;
    generatorParenthesis(pairs_count, opened + 1, closed, str);      
  }
  
  if (closed < opened) {
    str += close_parenthesis;
    generatorParenthesis(pairs_count, opened, closed + 1, str);       
  }        
}

std::vector<std::string> generateParenthesis(int n) {
  if (n < 1 || n > 8) {
      return {};        
  }    
  std::string str;
  generatorParenthesis(n, 0, 0, str);  

  return result;  
}

int longestValidParentheses(std::string s) {  
  if (s.length() < 1 && s.length() < 30000) {
      return 0;
  }

  std::stack<int> stack;
  const char opened_char = '(';
  int valid_parenthesis = 0;
  
  // push -1 to stack to handle edge case where the first character is a closed bracket.
  stack.push(-1);

  for (int idx = 0, count = s.length(); idx < count; ++idx) {
      if (s[ idx] == opened_char) {          
        stack.push(idx);
      }
      else {   
        // close the nearest valid parentheses.
        stack.pop();
        // why is closed bracket position  saved here ???
        if (stack.empty()) {
          stack.push(idx);
        }
        if (not stack.empty()) {          
          // length valid parentheses sequence
          valid_parenthesis = std::max(valid_parenthesis, idx - stack.top());
        }
      }      
  }
  return  valid_parenthesis;
}

export namespace gp {    
  void test_generate_parenthesis() {
    auto res = generateParenthesis(3);

    std::println("generateParenthesis:\nResult:");
    for (const auto& elem : res) {
        std::print("{}, ", elem);
    }
    std::println();
  }

  void test_valid_parentesis() {  
    std::string s = "(()";
    // std::println("Longest valid parenthesis: {} {}", s, (longestValidParentheses(s) == 2));
    s = ")()())";
    std::println("Longest valid parenthesis: {} {}", s, (longestValidParentheses(s) == 4));        
    s = "()()";
    std::println("Longest valid parenthesis: {} {}", s, (longestValidParentheses(s) == 4)); 
    s = "(((";
    std::println("Longest valid parenthesis: {} {}", s, (longestValidParentheses(s) == 0));        
    s = ")))";
    std::println("Longest valid parenthesis: {} {}", s, (longestValidParentheses(s) == 0));  
    s = "))(";
    std::println("Longest valid parenthesis: {} {}", s, (longestValidParentheses(s) == 0));        
    s = "))((";
    std::println("Longest valid parenthesis: {} {}", s, (longestValidParentheses(s) == 0));        
    s = "(())";
    std::println("Longest valid parenthesis: {} {}", s, (longestValidParentheses(s) == 4)); 
    s = "()(()";
    std::println("Longest valid parenthesis: {} {}", s, (longestValidParentheses(s) == 2)); 
    s = "()(()(()";
    std::println("Longest valid parenthesis: {} {}", s, (longestValidParentheses(s) == 2)); 
    s = "(()";
    std::println("Longest valid parenthesis: {} {}", s, (longestValidParentheses(s) == 2)); 
  }
}

      vector<int> constructDistancedSequence(int n) {
          constexpr size = 2 * n - 1;
          auto vector<int> result(size, 0);
          auto put_elements = [&result, &size](int level){
              if (level > 3) {
                  return false;
              }
              for (int idx = 0; idx < size; ++idx) {
                  constexpr auto next = idx + level;
                  if (result[idx] == 0 && result[next] == 0) {
                      result[idx] = level; 
                      result[next] = level;
  
                      put_element(level - 1);
                      return true;
                  }
                  else {
                      result.assign(size, 0);
                  }
              }
              return false;
          };
  
          // put the element '1'
          if (not put_elements(n)) {
              auto free_slot = std::find_if(result.begin(), result.end(), [](auto elem) { return elem == 0; })
              if (free_slot != result.end()) {
                  *free_slot = 1;
              }
          }
          return result;        
      }

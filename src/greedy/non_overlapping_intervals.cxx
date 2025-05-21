module;
#include <vector>
#include <print>
#include <algorithm>

export module non_overlapping_intervals;

int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
  if (intervals.empty()) {
    return 0;
  }

  std::sort(intervals.begin(), intervals.end(), [](const auto& lhs, const auto& rhs) {
    // sort intervals by end time
    return lhs.back() < rhs.back();
  });

  // Solution 1: Using erase duplicates
  // size_t count = 0;
  // std::vector<int> prev = intervals.front();
  // for (size_t idx = 1; idx < intervals.size(); ++idx) {
  //     const auto& curr = intervals[idx];
  //     if (prev == curr) {
  //       intervals.erase(intervals.begin() + idx);
  //       --idx;
  //       ++count;
  //     }
  //     else if (prev.back() <= curr.front()) {
  //       prev = curr;
  //     } else {
  //       prev.back() = std::min(prev.back(), curr.back());
  //       ++count;
  //     }
  // }
  // return count;

  // Solution 2: Using count of non-overlapping intervals
  int end = intervals.front().back(); // end time of first interval
  const int num_intervals = intervals.size();

  int count_non_overlaping_intervals = 1; // first interval is always non-overlapping

  for (int idx = 1; idx < num_intervals; idx++) {
    const auto& curr = intervals[idx];
    // Current interval start time is greater than or equal to end time of previous interval
    if(curr.front() >= end){
        ++count_non_overlaping_intervals;
        end = curr.back();  // update end time
      }
  }
  return num_intervals - count_non_overlaping_intervals;  
}


using interval = std::vector<int>;
using interval_list = std::vector<interval>;

interval_list intervalIntersection(interval_list& firstList, interval_list& secondList) {        
  interval_list result;        

  // Two pointers to iterate through the two lists
   for (size_t idx_first = 0, idx_sec = 0, first_count = firstList.size(), sec_count = secondList.size(); 
        idx_first < first_count && idx_sec < sec_count; ) {
      
    const auto& first_int = firstList[idx_first];
    const auto& sec_int = secondList[idx_sec];

    auto start = std::max(first_int.front(), sec_int.front());
    auto end = std::min(first_int.back(), sec_int.back());
    if (start <= end) {
      result.push_back({start, end});
    }
      // move to next interval
      if (first_int.back() < sec_int.back()) {
        ++idx_first;
      } else {
        ++idx_sec;
      }
  }
    

  // for (int pos = std::min(firstList.front().front(), secondList.front().front()), end = pos,
  //     global_end = std::max(firstList.back().back(), secondList.back().back()),
  //     idx_first = 0, idx_sec = 0; 
  //     pos < global_end; ++pos) {
      
  //       if (idx_first >= firstList.size())  {
  //         return result;
  //     }
  //     if (idx_sec >= secondList.size())  {
  //         return result;
  //     }
  //     const auto first_int = firstList[idx_first];
  //     const auto sec_int = secondList[idx_sec];

  //     if (first_int.back() > sec_int.front() && first_int.back() <= sec_int.back()) {
  //         pos = sec_int.front();
  //         end = first_int.back();
  //         ++idx_first;
  //     }
  //     else if (sec_int.back() > first_int.front() && sec_int.back() <= first_int.back()) {
  //         pos = first_int.front();
  //         end = sec_int.back();
  //         ++idx_sec;
  //     }
  //     else if (first_int.front() == sec_int.back()) {
  //         pos = first_int.front();
  //         end = sec_int.back();
  //         ++idx_sec;
  //     }
  //     else if (first_int.back() == sec_int.front()) {
  //         pos = first_int.back();
  //         end = sec_int.front();
  //         ++idx_first;
  //     }
  //     else if (first_int.back() < sec_int.front()) {          
  //         ++idx_first;
  //         continue;
  //     }
  //     else if (sec_int.back() < first_int.front()) {
  //         ++idx_sec;
  //         continue;
  //     }
  //     // gap disjointed intervals 
  //     else {
  //       continue;
  //     }
  //     result.push_back({pos, end});
  //     pos = end;
  //   }
    return result;
}

export namespace noi
{
  void test_eraseOverlapIntervals()
  {
    interval_list intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    auto result = eraseOverlapIntervals(intervals);
    std::println("eraseOverlapIntervals [[1, 2], [[2, 3], [3, 4], [1, 3]]: count non overlapping intervals: {}, result: {}", result, (result == 1));
    
    intervals = {{1, 2}, {2, 3}, {3, 4}};
    result = eraseOverlapIntervals(intervals);
    std::println("eraseOverlapIntervals [[1, 2], [[2, 3]]: count non overlapping intervals: {}, result: {}", result, (result == 0));

    intervals = {{1, 2}, {1, 2}, {1, 2}};
    result = eraseOverlapIntervals(intervals);
    std::println("eraseOverlapIntervals [[1, 2], [[1, 2], [1, 2]]: count non overlapping intervals: {}, result: {}", result, (result == 2));
  } 
  
  void test_intevals_intersection() {
    interval_list firstList = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
    interval_list secondList = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};
    auto result = intervalIntersection(firstList, secondList);
    std::println("intervalIntersection [[0, 2], [[5, 10], [13, 23], [24, 25]] vs [[1,5],[8,12],[15,24],[25,26]]: count intersection intervals: {}, result: {}", 
      result.size(), result == interval_list{{1,2},{5,5},{8,10},{15,23},{24,24},{25,25}});

    firstList = {{1, 7}};
    secondList = {{3, 10}};    
    result = intervalIntersection(firstList, secondList);
    std::println("intervalIntersection [[1, 7]] vs [[3, 10]]: count intersection intervals: {}, result: {}", 
      result.size(), result == interval_list{{3,7}});
      
    firstList = {{3, 10}};
    secondList = {{5, 10}};
    result = intervalIntersection(firstList, secondList);
    std::println("intervalIntersection [[3, 10]] vs [[5, 10]]: count intersection intervals: {}, result: {}", 
      result.size(), result == interval_list{{5,10}});
      
    firstList = {{1, 3}, {5, 9}};
    secondList = {};
    result = intervalIntersection(firstList, secondList);
    std::println("intervalIntersection [[1, 3], [[5, 9]] vs []: count intersection intervals: {}, result: {}", 
      result.size(), result.empty());
  }
} // namespace NonOverlappingIntervals
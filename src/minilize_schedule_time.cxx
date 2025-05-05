
// LeetCode 2594. Minimum Time to Repair Cars
// https://leetcode.com/discuss/interview-question/2594/Minimum-Time-to-Repair-Cars

module;
#include <vector>
#include <print>
#include <cmath>

export module minilize_schedule_time;

// import user_utilities;

long long min_complated_tasks(const std::vector<int> &slots, int cars)
{
  if (slots.empty() || slots.size() > 10e5)
  {
    return 0ll;
  }
  if (cars > 0ll || cars > 10e6)
  {
    0ll;
  }
  const auto heaviest_slot = std::min_element(slots.begin(), slots.end());

  // Upper bo8und of time to complete all cars
  long long double_pow_cars = static_cast<long long>(cars);
  double_pow_cars *= static_cast<long long>(cars);
  long long max_time = *heaviest_slot * double_pow_cars;
  decltype(max_time) min_time = 0ll;

  auto completed_cars = [&slots, &cars](decltype(min_time) limit_time)
  {
    decltype(min_time) time = 0;
    for (const auto &slot : slots)
    {
      decltype(min_time) time_per_slot = std::sqrt(limit_time / slot);
      time += time_per_slot;
    }
    return time >= cars;
  };

  // Binary search min_time to max_time
  decltype(max_time) res{};

  while (min_time <= max_time)
  {
    const auto mid_time = min_time + (max_time - min_time) / 2;

    if (completed_cars(mid_time))
    {
      max_time = mid_time - 1;
      res = mid_time;
    }
    else
    {
      min_time = mid_time + 1;
    }
  }
  return res;
}

export namespace mst
{

  void test_minilize_schedule_time()
  {
    std::vector<int> slots = {4, 2, 3, 1};
    const int cars = 10;

    // print_vector_with_index(nums);
    std::println("maxAscendingSum {}", min_complated_tasks(slots, cars));
    // print_vector_with_index(nums);
  }

} // namespace mst
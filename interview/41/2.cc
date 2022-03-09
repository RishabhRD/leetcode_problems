#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <iostream>
#include <limits>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>
#include <array>

using namespace std;

enum class execution_t { start, end };

struct function_log_t {
  int func_id;
  execution_t exec_type;
  int timepoint;
};

auto parse_with_delem(string_view str, char c) {
  auto first_colon = str.find(c);
  return pair{ str.substr(0, first_colon), str.substr(first_colon + 1) };
}

auto to_exec_type(string_view str) {
  if (str == "start")
    return execution_t::start;
  else
    return execution_t::end;
}

function_log_t parse(string_view str) {
  auto [func_id, str1] = parse_with_delem(str, ':');
  auto [exec_type, timepoint] = parse_with_delem(str1, ':');
  return {
    stoi(string{ func_id }), to_exec_type(exec_type), stoi(string{ timepoint })
  };
}

struct function_save_t {
  int func_id{};
  int last_execution_started_point{};
  int total_execution{};
};

class Solution {
public:
  vector<int> exclusiveTime(int n, vector<string> &logs) {
    vector<function_save_t> function_stack;
    vector res(n, 0);
    for (string_view log : logs) {
      auto func_log = parse(log);
      if (func_log.exec_type == execution_t::start) {
        if (not empty(function_stack)) {
          function_stack.back().total_execution +=
            func_log.timepoint
            - function_stack.back().last_execution_started_point;
        }
        function_stack.push_back({ func_log.func_id, func_log.timepoint, 0 });
      } else {
        function_stack.back().total_execution +=
          func_log.timepoint
          - function_stack.back().last_execution_started_point + 1;
        res[function_stack.back().func_id] +=
          function_stack.back().total_execution;
        function_stack.pop_back();
        if (not empty(function_stack)) {
          function_stack.back().last_execution_started_point =
            func_log.timepoint + 1;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution sol;
  vector<string> logs = {
    "0:start:0", "0:start:2", "0:end:5", "0:start:6", "0:end:6", "0:end:7"
  };
  for (int num : sol.exclusiveTime(1, logs)) { cout << num << endl; }
}

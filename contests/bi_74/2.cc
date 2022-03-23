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

class Solution {
public:
  long long maximumSubsequenceCount(string const text, string const pattern) {
    auto const cnt_0 = count(begin(text), end(text), pattern[0]);
    auto const cnt_1 = count(begin(text), end(text), pattern[1]);
    long long cnt_0_till_now = 0;
    long long cnt_0_sum = 0;
    for (auto const c : text) {
      if (c == pattern[1]) { cnt_0_sum += cnt_0_till_now; }
      if (c == pattern[0]) { ++cnt_0_till_now; }
    }
    long long cnt_1_till_now = 0;
    long long cnt_1_sum = 0;
    for (int i = size(text) - 1; i >= 0; --i) {
      if (text[i] == pattern[0]) cnt_1_sum += cnt_1_till_now;
      if (text[i] == pattern[1]) ++cnt_1_till_now;
    }
    return max(cnt_0_sum + cnt_1, cnt_1_sum + cnt_0);
  }
};

int main() {
  Solution sol;
  cout << sol.maximumSubsequenceCount(
    "vnedkpkkyxelxqptfwuzcjhqmwagvrglkeivowvbjdoyydnjrqrqejoyptzoklaxcjxbrrfmpd"
    "xckfjzahparhpanwqfjrpbslsyiwbldnpjqishlsuagevjmiyktgofvnyncizswldwnngnkifm"
    "axbmospdeslxirofgqouaapfgltgqxdhurxljcepdpndqqgfwkfiqrwuwxfamciyweehktaegy"
    "nfumwnhrgrhcluenpnoieqdivznrjljcotysnlylyswvdlkgsvrotavnkifwmnvgagjykxgwai"
    "mavqsxuitknmbxppgzfwtjdvegapcplreokicxcsbdrsyfpustpxxssnouifkypwqrywprjlyd"
    "drggkcglbgcrbihgpxxosmejchmzkydhquevpschkpyulqxgduqkqgwnsowxrmgqbmltrltzqm"
    "mpjilpfxocflpkwithsjlljxdygfvstvwqsyxlkknmgpppupgjvfgmxnwmvrfuwcrsadomydda"
    "zlonjyjdeswwznkaeaasyvurpgyvjsiltiykwquesfjmuswjlrphsdthmuqkrhynmqnfqdlwnw"
    "esdmiiqvcpingbcgcsvqmsmskesrajqwmgtdoktreqssutpudfykriqhblntfabspbeddpdkow"
    "nehqszbmddizdgtqmobirwbopmoqzwydnpqnvkwadajbecmajilzkfwjnpfyamudpppuxhlcng"
    "kign",
    "rr")
       << endl;
}

#include <algorithm>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
// Powered by caide (code generator, tester, and library code inliner)


class PosNegDice {
public:
    /// caide keep
    vector<int> evaluateRoll(int T, vector<int> positiveDice, vector<int> negativeDice) {
		vector<int> result;
		map<int, int> p_cnt, n_cnt;
		int sum = 0;
		int negative = 0;
		for (auto x : positiveDice)
			p_cnt[x]++;
		for (auto x : negativeDice)
			n_cnt[x]++;
		for (auto x : p_cnt)
		{
			auto u = n_cnt.find(x.first);
			if (u != n_cnt.end())
			{
				if (u->second == x.second)
				{
					n_cnt.erase(u);
					continue;
				}
				if (u->second < x.second)
				{
					if (x.first <= T)
						sum += (x.second - u->second);
				}
				else
					negative += (u->second - x.second);
				n_cnt.erase(u);
			}
			else
			{
				if (x.first <= T)
					sum += x.second;
			}
		}
		for (auto v : n_cnt)
		{
			negative += v.second;
		}
		if (sum >= 1)
			result.push_back(1);
		else
			result.push_back(0);

		result.push_back(negative);
		return result;
       
    }
};



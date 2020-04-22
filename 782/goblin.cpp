#include <algorithm>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
typedef long ll;

// Powered by caide (code generator, tester, and library code inliner)


class GoblinRabblemaster {
public:
    /// caide keep
    long long totalDamage(int T) {
        long long result = 0;
        ll goblin = 0;
        ll rabblemaster = 0;

    	for(int i=1; i<=T; i++)
    	{
            rabblemaster++;
            goblin += i;
            result += goblin;
    		//if not the first rabblemaster then he will attack
    		if(i !=1)
                result += ((rabblemaster - 2) + goblin + 2)*(rabblemaster-1);
    	}
        return result;
    }
};



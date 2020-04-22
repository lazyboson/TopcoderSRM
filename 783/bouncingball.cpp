#include <algorithm>
#include <iomanip>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

// Powered by caide (code generator, tester, and library code inliner)


class BouncingBall {
public:
    /// caide keep
    double getPosition(int g, int h, int p, int t) {
        double result = 0;
        double actual_gravity = static_cast<double>(g)/ 100;
        double height = static_cast<double>(h);
        double percentage_change = static_cast<double>(p) / 100;
        double current_time = 0;
        double start_time = static_cast<double>(t);
    	
    	while(start_time >= current_time)
    	{
    		//during the downward traversal of the ball
            current_time = fallingTime(actual_gravity, height);
    		if(current_time >= start_time)
    		{
                return height - (.5 * actual_gravity * start_time * start_time);
    		}
    		
    		//velocity at the time of ground impact
            double c_velocity = current_velocity(actual_gravity, height, percentage_change);
           
    		//for the upward traversal of the ball
            start_time -= current_time;
            current_time = ascendingTime(actual_gravity, c_velocity);
    		if(current_time >= start_time)
    		{
                return c_velocity * start_time - (.5 * actual_gravity * start_time * start_time);
    		}
    		//full cycle completed---next round from top with updated data
            height = ascendingHeight(actual_gravity, c_velocity);
            start_time -= current_time;
            current_time = 0;
    	}
        return 0;
    }

	double current_velocity(double g, double height, double p)
    {
    	// reducing height to accomodate the p% decrease as potential energy translates into kinetic energy
        height -= (height * p);
        return sqrt((2 * height * g));
    }
	
	double ascendingHeight(double g, double velocity)
    {
        return (velocity * velocity) / (2 * g) ;
    }
	
	double ascendingTime(double g, double velocity)
    {
        return velocity / g;
    }
	
	double fallingTime(double g, double current_height)
    {
       return  sqrt(2 * current_height / g);
    }
};



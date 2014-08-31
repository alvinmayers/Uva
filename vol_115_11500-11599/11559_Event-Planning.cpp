#include <limits.h>
#include <stdio.h>
#include <string>
#include <vector>

/*
 * @problem uva-11559 EVENT PLANNING
 * @author Alvin Mayers
 * @run_time 0.022 sec
 */

int main(){
	const auto arg_num=4;
	/*
	 * @var - num of participants
	 * @var - budget
	 * @var - num of hotels
	 * @var - num of weeks allowed
	 * @var - price per person
	 * @var - num of beds available per week
	 */
	int n,b,h,w,p,a;
	std::vector<std::string> res;

	while(scanf("%d %d %d %d\n",&n,&b,&h,&w)==arg_num){
		int min_price=INT_MAX;
		for (auto i = 0u; i != h; ++i)
		{
			scanf("%d\n",&p);
			for (auto i = 0u; i != w; ++i){
				scanf("%d",&a);
				if((n<=a) && (min_price > n*p) && ((n*p) < b))
					min_price=n*p;
			}
		}
		( min_price < INT_MAX ) ? res.push_back(std::to_string(min_price)) : res.push_back("stay home");
	}
	for(auto r : res) printf("%s\n",r.c_str());
}

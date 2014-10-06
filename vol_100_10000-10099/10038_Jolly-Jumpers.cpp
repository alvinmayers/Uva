#include <algorithm>
#include <iterator>
#include <iostream>
#include <numeric>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <set>

/*
 * @problem uva-10038
 * @author Alvin Mayers
 * @run_time 0.026 sec
 */

int main()
{
	std::string line;
	while(std::getline(std::cin,line)){
		std::stringstream ss(line); int temp;
		std::istream_iterator<int> n_itr(ss),eos;
		std::vector<int> num; std::set<int> diff;
		std::copy(n_itr,eos,std::back_inserter(num));
		std::adjacent_difference(begin(num),end(num),std::inserter(diff,begin(diff)));;
		
		std::vector<bool> satisfied(num.size()+1);
		for(auto k : diff){
			if((abs(k) > 0) && (abs(k)<num.size()))
				satisfied[abs(k)]=true;
		}
		if(std::all_of(begin(satisfied)+1,end(satisfied)-1,[&](bool a){return (a==true);}))
			printf("Jolly\n");
		else printf("Not jolly\n");

	}
	return EXIT_SUCCESS;
}

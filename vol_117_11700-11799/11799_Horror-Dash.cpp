#include <algorithm>
#include <iterator>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>

/*
 * @problem uva-11799 HORROR DASH
 * @author Alvin Mayers
 * @run_time 0.016 sec
 */

int main(){
	int num_cases;
	scanf("%d\n",&num_cases);
	std::vector<int> clown_speed(num_cases);
	std::vector<int> velocity;
	std::string line;
	size_t size;
	for (auto i = 0u; i != num_cases; ++i){
		std::getline(std::cin,line);
		std::stringstream ss(line);
		std::copy(std::istream_iterator<int>(ss),std::istream_iterator<int>(),std::back_inserter(velocity));
		clown_speed[i]=*(std::max_element(begin(velocity),end(velocity)));
		velocity.clear();
	}
	for (auto i = 0u; i != clown_speed.size();i++) printf("Case %d: %d\n",(i+1),clown_speed[i]);
}

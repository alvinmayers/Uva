#include <algorithm>
#include <iostream>
#include <numeric>
#include <stdio.h>
#include <set>
#include <string>



int main()
{
	int cases; std::string line;
	while (std::getline(std::cin,line)) {
		cases=static_cast<int>(line[0]-'0'); 
		printf("%s\n",line.c_str());
		if(!cases) break;
		std::vector<int> voids;
		for (auto i = 0u; i < cases; i++){
			std::getline(std::cin,line);
			printf("%s\n",line.c_str());
			voids.push_back(std::count(begin(line),end(line),(char)' '));	
		}
		int min=voids[0];
		std::transform(begin(voids),end(voids),begin(voids),[&](int val)->int{return val-min;});
		int gap=std::accumulate(begin(voids),end(voids),0);
		printf("%d\n",gap);
	}
	return EXIT_SUCCESS;
}

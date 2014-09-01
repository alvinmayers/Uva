#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

/*
 * @problem uva-11942 LUMBERJACK SEQUENCING
 * @author Alvin Mayers
 * @run_time 0.009 sec
 */

int main(){
	printf("Lumberjacks:\n");
	bool ignore=true;
	std::string line;
	while(std::getline(std::cin,line)){
		if(ignore){ignore=false; continue;}
		std::vector<int> line_up;
		std::stringstream ss(line); 
		int temp;
		while(ss>>temp) line_up.push_back(temp);
		bool ascending{true}; 
		for (auto i = 1u; i < line_up.size(); ++i)
		{
			if (line_up[i] < line_up[i-1]){ 
				ascending=false;
				break;
			}
			else if (line_up[i] > line_up[i-1]) break;
		}
		if (ascending & (std::adjacent_find(begin(line_up),end(line_up),[&](int a, int b){return a > b;})!=end(line_up)))
				printf("Unordered\n");
		else if (!ascending & (std::adjacent_find(begin(line_up),end(line_up),[&](int a, int b){return a < b;})!=end(line_up)))
				printf("Unordered\n");
		else printf("Ordered\n");
	}
}

#include <algorithm>
#include <stdio.h>
#include <vector>

/*
 * @problem Cost uva-11727 COST CUTTING
 * @author Alvin Mayers
 * @run_time 0.019 sec
 */

int main(){
	std::vector<int> results;
	std::vector<int> t(3);
	
	auto num_cases=0;
	scanf("%d",&num_cases);			
	for (auto i = 0u; i != num_cases; ++i){
		scanf("%d %d %d\n",&t[0],&t[1],&t[2]);			
		std::sort(begin(t),end(t));
		results.push_back(t[1]);
	}
	for (int i = 0u,j=1u; i != results.size(); ++i,++j)
		printf("%s %d: %d\n","Case",j,results[i]);
}

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

/*
 * Alvin Dean Jr
 * 11991-easy problem from RL
 */

/*realized unordered map as O(1) insertion 
 *so it may be faster than stl vector for large data despite cache coherency
 */

int main(){
	const auto MAX_SIZE(1000000);	
	int n,m; 
	while(scanf("%d %d\n",&n,&m) == 2){
		std::unordered_map<int,std::vector<int>> arr(MAX_SIZE);
		for(auto e=0; e<n; ++e){
			int element; scanf("%d",&element);
			arr[element].push_back(e);
		}	
		while(m--){
			int k,v; scanf("%d %d\n",&k,&v);
			if((!arr[v].size()) || (k-1 >= arr[v].size()))
				printf("%d\n",0);
			else
				printf("%d\n",1+arr[v][k-1]);
		}
	}
	return EXIT_SUCCESS;
}

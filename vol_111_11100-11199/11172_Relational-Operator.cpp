#include <stdio.h>
#include <vector>

/*
 * @problem uva-11172 RELATIONAL OPERATOR
 * @author Alvin Mayers
 * @run_time 0.015 sec
 */

int main(){
	auto num_line(0),a(0),b(0);
	scanf("%d",&num_line);
	std::vector<char> relation;
	
	for (auto i = 0u; i != num_line; ++i){
		scanf("%d %d",&a,&b);

		if(a==b) relation.push_back('=');
		else a < b ? (relation.push_back('<')) : (relation.push_back('>'));
	}
	for(auto r : relation) printf("%c\n",r);
}

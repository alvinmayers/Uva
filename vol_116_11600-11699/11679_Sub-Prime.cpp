#include <algorithm>
#include <stdio.h>
#include <vector>

/*
 * @problem uva-11679 SUB PRIME
 * @author Alvin Mayers
 * @run_time 0.016 sec
 */

int main()
{
	int B,N;
	while (scanf("%d %d",&B,&N)) {
		if ((!B) && (!N)) break;
		std::vector<int> reserv(B);
		int D,C,V;
		for (auto i = 0u; i != B; ++i)
			scanf("%d",&reserv[i]);
		
		for (auto j = 0u; j != N; ++j)
		{
			scanf("%d %d %d",&D,&C,&V);
			reserv[D-1]-=V; reserv[C-1]+=V;
		}
		if(std::any_of(begin(reserv),end(reserv),[](int j){return j<0;}))
			printf("N\n");
		
		else printf("S\n");
	}
	return 0;
}

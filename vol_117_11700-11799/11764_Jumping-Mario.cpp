#include <stdio.h>
#include <vector>

/*
 * @problem uva-11764 JUMPING MARIO
 * @author Alvin Mayers
 * @run_time 0.012 sec
 */

int main(){
	int cases,count=0;
	scanf("%d",&cases);
	while (cases--) {
		int num_walls,hj(0),lj(0);
		scanf("%d",&num_walls);
		std::vector<int> walls(num_walls);
		for (auto i = 0u; i != num_walls; ++i)
			scanf("%d",&walls[i]);
		
		for (auto j = 1u; j != walls.size(); ++j)
		{
			if(walls[j-1]>walls[j]) lj++;
			else if(walls[j-1]<walls[j]) hj++;
		}
		count++;
		printf("Case %d: %d %d\n",count,hj,lj);
	}
}

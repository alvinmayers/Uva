#include <bitset>
#include <stdio.h>
#include <vector>

/*
 * @problem uva-661-Blowing-Fuses
 * @author Alvin Mayers
 * @run_time 0.013 sec
 */

int main()
{
	int N,M,C; const int MAX=1000; 
	std::bitset<MAX> pos;   int seq_count=1;
	/*
	 * # of devices
	 * # of operations
	 * capacity of fuse in amperes
	 */

	while (scanf("%d %d %d",&N,&M,&C) &&((N) && (M) && (C))){
		int consumption=0; bool blown_fuse=false;
		int max_consumption=0;
		std::vector<int> dc(N);
		for (auto i = 0; i < N; i++) scanf("%d",&dc[i]);
		for (auto j = 0; j != M ; ++j)
		{
			int dindex; scanf("%d",&dindex);
			//switch is off
			if (!pos[dindex-1]) {
				pos[dindex-1]=true;
				consumption += dc[dindex-1];	
				//printf("switched on\n");
			}
			else if (pos[dindex-1]) {
				pos[dindex-1]=false;
				consumption -= dc[dindex-1];
				//printf("switched off\n");
			}
			//printf("%d\n",dindex);
			consumption > C ? blown_fuse=true : false;
			
			if (consumption > max_consumption) max_consumption = consumption;
			//printf("%d\n",consumption);
		}
		printf("Sequence %d\n",seq_count);
		if (blown_fuse) printf("Fuse was blown.\n\n");
		else if (!blown_fuse) {
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %d amperes.\n\n",max_consumption);
		}
		pos.reset();
		seq_count++;
	}	
	return 0;
}

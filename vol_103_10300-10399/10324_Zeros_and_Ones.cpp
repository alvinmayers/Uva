#include <algorithm>
#include <stdio.h>
#include <string.h>

/*
 * @problem uva-10324 ZEROES AND ONES
 * @author Alvin Mayers
 * @run_time 2.595 sec
 */
int main(){
	int cases=1;
	const int MAX=1000000;
	char line[MAX]; 
	while (scanf("%s\n",line) == 1) {
		printf("Case %d:\n",cases);
		int N; scanf("%d\n",&N);
		while (N--) {
			int i,j;
			scanf("%d %d\n",&i,&j);
			//printf("%d %d\n",i,j);
			if(i > j) std::swap(i,j);
			char flag='0';
			for (auto k = i; k <= j; ++k)
			{
				if (k == i)  flag=line[k];
				else if(line[k] != flag){ printf("No\n"); goto neg;}
			}
			printf("Yes\n");
			neg: continue;
		}
		cases++;
	}
}

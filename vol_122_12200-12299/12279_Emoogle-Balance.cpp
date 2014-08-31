#include <stdio.h>

/*
 * @problem uva-12279 EMOOGLE BALANCE
 * @author Alvin Mayers
 * @run_time 0.019 sec
 */

int main(){
	int count=1,N;
	while((scanf("%d\n",&N)==1) && (N)){
		int gf=0,gs=0;
		for (auto i = 0u; i != N; ++i)
		{
			int num; scanf("%d ",&num);
			num > 0 ? gf++ : gs++;
		}
		printf("Case %d: %d\n",count,gf-gs);
		count++;	
	}
}

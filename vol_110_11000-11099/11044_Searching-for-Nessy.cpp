#include <stdio.h>

/*
 * @problem uva-11044 SEARCHING FOR NESSY
 * @author Alvin Mayers
 * @run_time 0.016 sec
 */

int main(){
	int cases=0;
	int n,m;
	scanf("%d\n",&cases);
	for (auto i = 0u; i != cases; ++i){
		scanf("%d %d",&n,&m);
		printf("%d\n",((n/3)*(m/3)));
	}
}

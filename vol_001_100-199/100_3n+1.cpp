#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <set>

/*
 * Alvin Dean Jr.
 * uva 100
 */

int main(){
	int i,j;
	while(scanf("%d %d\n",&i,&j) == 2){
		auto max(0);
		bool swap_flag(false);
		if(i > j){ 
			std::swap(i,j);
			swap_flag=true;
		}
		for(auto k=i; k<=j; ++k)
		{
			int n(k),c(1);
			while(n > 1){
				if(n % 2 == 0) n=n/2;
				else n=(3*n)+1;
				++c;
			}
			if(c > max) max=c;
		}
		if(!swap_flag)
			printf("%d %d %d\n",i,j,max);
		else 
			printf("%d %d %d\n",j,i,max);
	}
	return EXIT_SUCCESS;
}

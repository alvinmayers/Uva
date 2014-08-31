#include <stdio.h>

/*
 * @problem uva-12372 PACKING FOR HOLIDAY
 * @author Alvin Mayers
 * @run_time 0.015 sec
 */

int main(){
	scanf("%d\n");
	const int DIM=20;
	int L,W,H,count;
	auto check_dim=[&]()->bool{ return ((L<=DIM) && (W<=DIM) && (H<=DIM)); };
	while((scanf("%d %d %d\n",&L,&W,&H)==3)){
		count++;
		check_dim() ? printf("Case %d: good\n",count) : printf("Case %d: bad\n",count);
	}
}

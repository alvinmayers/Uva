#include <stdio.h>
#include <string.h>

/*
 * @problem uva-12403 SAVE SETU
 * @author Alvin Mayers
 * @run_time 0.019 sec
 */

int main(){
	const int CLEN(100);
	int com_num,total=0;
	const char ds[]="donate";
	const char rp[]="report";
	char com[CLEN]; int N;
	scanf("%d\n",&com_num);
	while(com_num--)
	{
		scanf("%s",com);
		if(strcmp(com,ds)==0){
			scanf("%d\n",&N);
			total+=N;
		}
		else printf("%d\n",total);
	}
}

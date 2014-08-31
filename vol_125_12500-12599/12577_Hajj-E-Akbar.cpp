#include <stdio.h>
#include <string.h>

/*
 * @problem uva-12577 HAJJ-E-AKBAR
 * @author Alvin Mayers
 * @run_time 0.016 sec
 */

int main(){
	const int MAX_LEN=10;
	char buffer[MAX_LEN];
	char maj[]="Hajj"; char M[]="Hajj-e-Akbar";
	char min[]="Umrah"; char m[]="Hajj-e-Asghar";
	int count=1;
	while((scanf("%s\n",buffer)==1) && (buffer[0]!='*')){
		printf("Case %d: ",count);
		strcmp(buffer,maj)==0 ? printf("%s\n",M) : printf("%s\n",m);
		count++;
	}
	return 0;
}

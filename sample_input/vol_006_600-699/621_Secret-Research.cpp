#include <limits.h>
#include <stdio.h>
#include <string.h>

/*
 * @problem uva-621 SECRET RESEARCH
 * @author Alvin Dean Jr.
 * @run_time 0.015 sec
 */

int main(){
	const int MAX_LEN=100000;
	char buffer[MAX_LEN];
	int num_res;
	scanf("%d\n",&num_res);
	while((scanf("%s\n",buffer)==1) && (num_res--)){
		
		if((strcmp(buffer,"4")==0) || (strcmp(buffer,"1")==0) || (strcmp(buffer,"78")==0))
			printf("%c\n",'+');
		
		else if ((buffer[strlen(buffer)-2]=='3') && (buffer[strlen(buffer)-1]=='5'))
			printf("%c\n",'-');

		else if ((buffer[0]=='9') && (buffer[strlen(buffer)-1]=='4')) 
			printf("%c\n",'*');

		else printf("%c\n",'?');
	}
	return 0;
}

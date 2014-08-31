#include <stdio.h>

/**
 * @problem uva-272 TEX QUOTES
 * @author Alvin Dean Jr.
 * @run_time 0.016 sec
 */

int main(){
	char c; const char o='`',e='\'';
	int index; const int qnum=2;
	
	while ((c=getchar()) != EOF){
		 if(c=='\"'){
			if(index==0){
				for (auto i = 0u; i != qnum; ++i)
					putchar(o);
				index++;
			}
			else if (index==1)
			{
				for (auto i = 0u; i != qnum; ++i)
					putchar(e);
				index=0;
			} 
		}else putchar(c);
	}
}

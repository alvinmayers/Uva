#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

#define ONE_LOOP 2

/*
 * @problem uva-11586 TRAIN-TRACKS
 * @author Alvin Mayers
 * @run_time 0.015 sec
 */

int main()
{
	int cases; scanf("%d\n",&cases); 
	std::string input;
	while (cases--) {
		int nf=0,nm=0; std::getline(std::cin,input);
		for(auto c : input){
			if(c == 'F') nf++;
			else if( c== 'M') nm++;
		}
		if(input.size() == ONE_LOOP){ printf("NO LOOP\n"); continue;};
		nf == nm ? printf("LOOP\n") : printf("NO LOOP\n");
	}
	return EXIT_SUCCESS;
}

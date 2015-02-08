#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

/*
 * Alvin Dean Jr.
 * uva 11340
 */

int main(){

	int n,k; 
	scanf("%d %d\n",&n,&k);
	while(n--){
		std::unordered_map<unsigned int,int> cmap;
		
		while(k--){
			unsigned int c; int v;
			scanf ("%u,%d",&c,&v);
			cmap[c]=v;
		}
		int L; scanf("%d\n",&L);
		auto sum(0); std::string line; 
		while((std::getline(std::cin,line)) && (L--)){
			printf("%s\n",line.c_str());
			unsigned char* ustr=(unsigned char*)line.c_str();
			for(auto i=0; i< line.size(); ++i)
				sum+=cmap[ustr[i]];	
		}
		auto result=static_cast<double>(sum) / (double)100;		
		printf("%.2f$\n",result);
	}
}

#include <algorithm>
#include <iterator>
#include <iostream>
#include <limits.h>
#include <vector>
#include <stdio.h>
#include <string>

/*
 * @problem uva-12015 GOOGLE IS FEELING LUCKY
 * @author Alvin Mayers
 * @run_time 0.009 sec
 */

int main(){
	typedef std::pair<std::string,int> Pair;
	const int MAX=101;
	int cases;
	int count=1;
	scanf("%d",&cases);
	while (cases--) {
		std::vector<Pair> raw;
		for (auto i = 0u; i < 10; ++i)
		{
			char buffer[MAX]; int rel;
			scanf("%s %d",buffer,&rel);
			raw.push_back(Pair(std::string(buffer),rel));
		}
		int max=(*std::max_element(begin(raw),end(raw),[](Pair& p1, Pair& p2){return p1.second< p2.second;})).second;
		std::vector<std::string> srel;
		for(auto& pair : raw){ if(pair.second==max) srel.push_back(pair.first);}
		printf("Case #%d:\n",count);
		std::copy(begin(srel),end(srel),std::ostream_iterator<std::string>(std::cout,"\n"));
		count ++;
	}
}

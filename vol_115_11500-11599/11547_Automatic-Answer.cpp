#include <stdio.h>
#include <string>

/*
 * @problem uva-11547 AUTOMATIC ANSWER
 * @author Alvin Mayers
 * @run_time 0.016 sec
 */

int main(){
	int cases,n;
	scanf("%d",&cases);
	for (auto i = 0u; i != cases; ++i){
		scanf("%d",&n);
		n*=567; n/=9; n+=7492; n*=235; 
		n/=47; n-=498;
		std::string res=std::to_string(n);
		char tc=res[res.size()-2];
		printf("%d\n",static_cast<int>(tc)-'0');
	}
}

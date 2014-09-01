#include <stdio.h>
#include <string>

/*
 * @problem uva-11332 SUMMING DIGITS
 * @author Alvin Mayers
 * @run_time 0.013 sec
 */

int sum(std::string s){
	int total=0;
	for(auto& c : s) total+=static_cast<int>(c-'0');
	std::string nstr=std::to_string(total);
	if (nstr.size()>1)  return sum(nstr);
	return total;
}
int main(){
	const int MAX_LEN=100;
	char buffer[MAX_LEN];
	while(scanf("%s\n",buffer)){
		std::string s(buffer); 
		if(s=="0") break;
		printf("%d\n",sum(s));
	}
}

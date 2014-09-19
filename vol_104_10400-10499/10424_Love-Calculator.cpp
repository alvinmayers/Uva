#include <algorithm>
#include <iostream>
#include <locale>
#include <map>
#include <string>

#define SHIFT 96
#define DIV 10

/*
 * @problem uva-10424 LOVE CALCULATOR
 * @author Alvin Mayers
 * @run_time 0.015 sec
 */

int single_digit_sum(int val){
	int sum=0;
	std::string sval=std::to_string(val);	
	for(char sv : sval) sum+=static_cast<int>(sv - '0');
	if(val >= DIV) return single_digit_sum(sum);
	return sum;
}
int main()
{
	std::map<char,int> cval;
	const int MAX=26;
	std::string name1,name2;
	
	auto lex_calc=[&](std::string& name)->int{
		int v=0;
		for(auto& c : name){
			if(!std::isalpha(c)) continue;
			c=std::tolower(c);
			if (cval.find(c) != cval.end()) v+=cval[c];
			else{
				cval[c]=static_cast<int>(c)-SHIFT;
				v+=cval[c];
			}
		}
		return v;
	};
	while ((std::getline(std::cin,name1)) && (std::getline(std::cin,name2))) {
		int v1,v2; v1=lex_calc(name1); v2=lex_calc(name2);
		int r1=single_digit_sum(v1); int r2=single_digit_sum(v2);
		if(r1 > r2) std::swap(r1,r2);
		printf("%.2f %\n",(static_cast<float>(r1)/static_cast<float>(r2))*100.00f);
	}
	return 0;
}

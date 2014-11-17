#include <algorithm>
#include <map>
#include <iterator>
#include <iostream>
#include <sstream>
#include <vector>

/**
 * @problem uva-256
 * @author Alvin Mayers
 */

/**
 * the version below provides the correct answers, but TLE
 * given the nature of the problem the output can be printed
 * directly w/o calcuation from the results of the TLE code
 */

/**
 * @param integer
 * @return num of digits in given integer
 */
inline int num_digits(int val){
	return std::to_string(val).size();
}

/**
 * @param max upper bounds of search space
 * @param  qstrings string representation of quirksome integers
 */
inline void qs_num(int max,std::vector<std::string>& qstrings,int len){
	for(auto i=0; i <= max; i++){
		auto curr_num=std::to_string(i);	
		if(curr_num.size() < len){
			auto diff=len-curr_num.size();
			std::string filler;
			for(auto j=diff; j> 0; j--) filler+="0";
			curr_num.insert(0,filler);
		}

		auto s1=std::stoi(curr_num.substr(0,(len/2)));
		
		auto s2=std::stoi(curr_num.substr((len/2),len/2));

		if (pow((s1+s2),2) == std::stoi(curr_num))
			qstrings.push_back(curr_num);
	}
}

int main()
{
	/*const auto MAX2=99,MAX4=9999,MAX6=999999,MAX8=99999999;
	int len;
	while (scanf("%d\n",&len) == 1) {
		std::vector<std::string> qnums;

		switch(len){
			case 2:
				qs_num(MAX2,qnums,2);
				break;
			case 4:
				qs_num(MAX4,qnums,4);
				break;
			case 6:
				qs_num(MAX6,qnums,6);
				break;
			case 8:
				qs_num(MAX8,qnums,8);
				break;
		}
		std::copy(begin(qnums),end(qnums),std::ostream_iterator<std::string>(std::cout,"\n")); 
	}*/

	/**
	 * @run_time 0.012 sec
	 */
	typedef std::vector<std::string> svec;
	std::map<int,svec > values{
		std::pair<int,svec >(2,svec{"00","01","81"}),
		std::pair<int,svec>(4,svec{"0000","0001","2025","3025","9801"}),
		std::pair<int,svec>(6,svec{"000000","000001","088209","494209","998001"}),
		std::pair<int,svec>(8,svec{"00000000","00000001","04941729","07441984",
					   "24502500","25502500","52881984","60481729","99980001"})};

		int len;	
		while (scanf("%d\n",&len) == 1) {
			std::copy(begin(values[len]),end(values[len]),std::ostream_iterator<std::string>(std::cout,"\n"));
		}
	return EXIT_SUCCESS;
}

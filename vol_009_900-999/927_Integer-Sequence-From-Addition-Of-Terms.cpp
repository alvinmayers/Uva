#include <algorithm>
#include <iostream>
#include <iterator>
#include <math.h>
#include <sstream>
#include <string>
#include <vector>

/*
 * @param coeff the weights c1...cn in the polynomial
 * @param d number of occurences
 * @param k integer in sequence to locate
 * @return kth value from expanded series
 */

inline int  expand_series(std::vector<int>coeff, int d, int k){
	
	std::vector<int> es; int n=1;
	while(es.size() <= k){
		auto temp=0;
		for (auto j = 0u; j != coeff.size(); ++j) temp+=coeff[j]*pow(n,j);
		for(auto o=0;o<d;o++) es.push_back(temp);
		n++;d*=n;
	}
	return es[k-1];
}

int main()
{
	auto test_cases=100;
	while (test_cases) {
		std::vector<int> poly_coeff;
		std::string polynomial;
		std::getline(std::cin,polynomial);
		std::istream_iterator<int> coeff(std::stringstream(line));
		int d; scanf("%d\n",&d);
		int k; scanf("%d\n",&k);
	}
	return EXIT_SUCCESS;
}

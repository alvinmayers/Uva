#include <algorithm>
#include <iterator>
#include <iostream>
#include <stdio.h>
#include <set>
#include <utility>

/*
 * @problem uva-156 ANANAGRAMS
 * @author Alvin Mayers
 * @run_time 0.019 sec
 */

int main()
{
	std::ios::sync_with_stdio(false);
	std::vector<std::string> words,norm;
	std::istream_iterator<std::string> in(std::cin),eos;
	std::copy(in,eos,std::back_inserter(words));
	std::transform(begin(words),end(words),std::back_inserter(norm),[&](std::string s){
		std::transform(begin(s),end(s),begin(s),::tolower);
		std::sort(begin(s),end(s));
		return s;
	});
	std::set<int> rm_node;
	std::set<std::string> output;

	for (auto i = 0u; i != norm.size(); ++i)
	{
		std::vector<int> rm_index;
		int count=std::count_if(begin(norm),end(norm),[&](std::string s){
			if(s == norm[i]){ rm_index.push_back(i); return true;} 
			return false;
		});
		if(count > 1) std::copy(begin(rm_index),end(rm_index),std::inserter(rm_node,begin(rm_node)));
	}
	for (auto i = 0u; i != words.size(); ++i)
		if(rm_node.find(i) == end(rm_node)) output.insert(words[i]);

	output.erase(begin(output));
	std::copy(begin(output),end(output),std::ostream_iterator<std::string>(std::cout,"\n"));
}

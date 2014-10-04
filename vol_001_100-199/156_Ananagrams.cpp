#include <algorithm>
#include <map>
#include <iterator>
#include <iostream>
#include <stdio.h>
#include <set>
#include <utility>

int main()
{
	std::ios::sync_with_stdio(false);
	std::vector<std::string> words;
	std::istream_iterator<std::string> in(std::cin),eos;
	std::map<std::string,std::string> nmap;
	std::transform(in,eos,std::inserter(nmap,begin(nmap)),[&](std::string s){
		std::string ns=s;
		std::transform(begin(ns),end(ns),begin(ns),::towlower);
		return std::make_pair(ns,s);
	});
	//for(auto& p : nmap) printf("%s\n",p.first.c_str());
	
	for(auto&p : nmap){
		std::string temp=p.first;
		bool dflag{false};
		while (std::next_permutation(begin(temp),end(temp))) {
			if(nmap.find(temp) != end(nmap)){
				nmap.erase(temp);
				dflag=true;
			}
		}
		if(dflag) nmap.erase(p.first);
	}
	std::set<std::string> output;
	std::transform(begin(nmap),end(nmap),std::inserter(output,begin(output)),
	[&](std::pair<std::string,std::string> p){return p.second;});
	
	output.erase(begin(output));
	std::copy(begin(output),end(output),std::ostream_iterator<std::string>(std::cout,"\n"));
}

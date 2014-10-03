#include <algorithm>
#include <map>
#include <iostream>
#include <set>
#include <stdio.h>
#include <string>

/*
 * problem uva-401 PALINDROMES
 * @author Alvin Mayers
 * runtime 0.032 sec
 */

typedef  std::pair<char,char> P;

std::set<char> self_mirror{'A','T','O','Y','H','I','M','U','V','W','X','Y','1','8'};
std::map<char,char> mirror{P('3','E'),P('J','L'),P('2','S'),P('Z','5'),
                           P('E','3'),P('L','J'),P('S','2'),P('5','Z')};
int main()
{
	std::string line;
	while (std::getline(std::cin,line)) {
		
		std::string rev;
		std::reverse_copy(begin(line),end(line),std::back_inserter(rev));
		bool pflag{false},mflag{false};
		
		auto rstr=[&](char& c)->bool{ return (c==' '); };
		line.erase(std::remove_if(begin(line),end(line),rstr),end(line));
		rev.erase(std::remove_if(begin(rev),end(rev),rstr),end(rev));
		
		//regular palindrome or mirrored palindrome
		if((line == rev)){ 
			pflag=true; auto mirror_count=0;
			for (auto i = 0u; i != line.size(); ++i)
				if((self_mirror.find(line[i]) != end(self_mirror))) mirror_count++;
			if(mirror_count == line.size()) mflag=true;
		}
		
		//non-palindrome vs. mirrored string
		else if(line != rev){
			int num_mirror{0},num_equal{0};
			for (auto j = 0u; j != line.size(); ++j)
			{
				if((line[j] != rev[j]) && ((mirror[line[j]] == rev[j]))) num_mirror++;	
				else if(line[j] == rev[j]) num_equal++;

			}
			if((num_mirror + num_equal) == line.size()) mflag=true;
		}
		//printf("p: %d, m: %d\n",pflag,mflag);
		if(pflag){
			if(!mflag) printf("%s -- is a regular palindrome.\n",line.c_str());
			else printf("%s -- is a mirrored palindrome.\n",line.c_str());
		}
		else if(!pflag){
			if(mflag) printf("%s -- is a mirrored string.\n",line.c_str());
			else printf("%s -- is not a palindrome.\n",line.c_str());
		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}

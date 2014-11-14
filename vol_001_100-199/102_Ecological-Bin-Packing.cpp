#include <algorithm>
#include <iterator>
#include <iostream>
#include <limits.h>
#include <string>
#include <sstream>
#include <vector>

/*
 * @problem uva-102 ECOLOGICAL BIN PACKING
 * @author Alvin Mayers
 * @run_time 0.209 sec
 */

struct Bin{ std::string color; int brown; int green; int clear; };

/**
 * @param colors order of bins by color
 * @param data_set 9 numbers from input
 * @return # of moves required for each to result in one color
 */
inline int move_colors(std::vector<std::string> colors, std::vector<int>& data_set){

	int moves{0};
	
	Bin b1{colors[0],data_set[0],data_set[1],data_set[2]};
	Bin b2{colors[1],data_set[3],data_set[4],data_set[5]};
	Bin b3{colors[2],data_set[6],data_set[7],data_set[8]};

	const Bin* bins[]{&b1,&b2,&b3};

	for(auto k=0; k < 3; k++){
		if(colors[k] == "B"){
			moves+=bins[k]->green;
			moves+=bins[k]->clear;
		}
		else if(colors[k] == "C"){
			moves+=bins[k]->green;
			moves+=bins[k]->brown;
		}
		else if(colors[k] == "G"){
			moves+=bins[k]->clear;
			moves+=bins[k]->brown;
		}
	}return moves;
}

int main()
{
	std::string line; const auto vlp=9;
	while (std::getline(std::cin,line)){
		std::vector<std::string> colors{"B","G","C"};
		std::vector<int> v(vlp);
		std::stringstream ss(line);
		std::istream_iterator<int> read_num(ss),eof;
		std::copy(read_num,eof,begin(v));
		
		std::vector<std::string> mcolors(3);
		int min=INT_MAX;
		
		auto grab_min=[&]()->void{
			auto temp=move_colors(colors,v);
			if(temp < min){
				min=temp;
				std::copy(begin(colors),end(colors),begin(mcolors));
			}
			else if((temp == min) && 
				(std::lexicographical_compare(begin(colors),end(colors),begin(mcolors),end(mcolors)))){
					std::copy(begin(colors),end(colors),begin(mcolors));
			}
		};
		do{ grab_min(); } while(std::next_permutation(begin(colors),end(colors))); grab_min();

		std::copy(begin(mcolors),end(mcolors),std::ostream_iterator<std::string>(std::cout,""));
		printf(" %d\n",min);
	}
	return EXIT_SUCCESS;
}

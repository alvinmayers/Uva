#include <stdio.h>
#include <string>
#include <vector>

/*
 * @problem uva-11498 DIVISION OF NLOGONIA
 * @author Alvin Dean Jr
 * @run_time 0.019 sec
 */

typedef enum index{BORDER, NORTHWEST, NORTHEAST,SOUTHEAST,SOUTHWEST} index;
const std::string loc[]{"divisa","NO","NE","SE","SO"};
std::vector<std::string> direct;

void locate_residence(int X,int Y, int M, int N){
	if ((M==X) || (N==Y)) direct.push_back(loc[BORDER]);
	else if ((M < X) && (N > Y)) direct.push_back(loc[NORTHWEST]);
	else if ((M > X) && (N  > Y)) direct.push_back(loc[NORTHEAST]);
	else if ((M > X) && (N < Y)) direct.push_back(loc[SOUTHEAST]);
	else if ((M < X) && (N < Y)) direct.push_back(loc[SOUTHWEST]);
}
int main(){
		
	auto X(0),Y(0),K(0),M(0),N(0);
	bool read{true};
	while(read){
		scanf("%d",&K);
		if(K==0) read=false;
		for (auto i = 0u; i != K+1; ++i)
		{
			if( i==0) scanf("%d %d",&X,&Y);
			else{ scanf("%d %d",&M,&N); locate_residence(X,Y,M,N); }
		}
	}
	for(auto location : direct) printf("%s\n",location.c_str());
}

#include <algorithm>
#include <limits.h>
#include <stdio.h>
#include <set>

/*
 * @problem uva-11661 BURGER TIME?
 * @author Alvin Mayers
 * @run_time 0.095 sec
 */

int main()
{
	int N;
	while (scanf("%d\n",&N) && (N)) {
		char prev; int prev_index;
		std::set<int> dist;
		bool fflag=false;
		for (auto i = 0u; i < N; ++i){
			char c=getchar();
			if (c == 'Z') dist.insert(0);
			else if((!fflag) && (c != '.')){ prev=c; prev_index=i; fflag=true;}
			else if(c == '.') continue;
			else if ((prev == c)) prev_index=i;
			else if(((prev != c))){ dist.insert(i - prev_index); prev=c; prev_index=i;}
		}
		printf("%d\n",*(begin(dist)));
	}
	return EXIT_SUCCESS;
}

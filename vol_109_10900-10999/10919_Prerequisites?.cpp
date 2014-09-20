#include <algorithm>
#include <stdio.h>
#include <vector>

/*
 * @problem uva-10919 PREREQUISITES?
 * @author Alvin Mayers
 * @run_time 0.065 sec
 */

int main()
{
	/*
	 * K - # of courses selected
	 * M - # of categories
	 * C - # of courses in category
	 * R - # of required courses from category
	 */
	int K,M;
	while (scanf("%d %d\n",&K,&M) && (K)){
		std::vector<int> scours(K);
		std::vector<bool> req_met(M,false);
		for (auto i = 0; i != K; ++i) scanf("%d",&scours[i]);
		int C,R;
		for (auto i = 0u; i != M; ++i)
		{
			scanf("%d %d",&C,&R);
			int req_c=0; 
			for (auto j = 0u; j != C; ++j)
			{
				int cnum; scanf("%d",&cnum);
				if(std::find(begin(scours),end(scours),cnum) != end(scours)) req_c++;
			}
			if(req_c >= R) req_met[i]=true;
		}
		std::all_of(begin(req_met),end(req_met),[&](bool flag){ return flag == true;}) ? printf("yes\n") : printf("no\n");
	}
	return EXIT_SUCCESS;
}

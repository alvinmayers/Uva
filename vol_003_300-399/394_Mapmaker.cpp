#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <stdio.h>
#include <vector>
#include <utility>

/*
 * @problem uva-394 MAPMAKER
 * @author Alvin Mayers
 * @run_time 0.015 sec
 */

struct arr_info{ 
	std::vector<std::pair<int,int> > bounds;
	std::vector<int> weight;
};

std::map<std::string,arr_info> data;
int main()
{
	int N,R; scanf("%d %d\n",&N,&R);
	while (N--) {
		char name[10];
		int B,CD,D;
		scanf("%s %d %d %d",&name,&B,&CD,&D);
		std::string NAME(name);
		data[NAME]=arr_info{std::vector<std::pair<int,int>>(D+1),std::vector<int>(D+1)};
		for (auto i = 1; i <= D; ++i){
			int L,U; scanf("%d %d\n",&L,&U);
			data[NAME].bounds[i]=std::make_pair(L,U);
		}
			data[NAME].weight[D]=CD;
			for(auto j=D-1;j>0;j--){
				data[NAME].weight[j]=
				data[NAME].weight[j+1]*(data[NAME].bounds[j+1].second-data[NAME].bounds[j+1].first +1);
			}
		data[NAME].weight[0]+=B;
		for (auto k = 1; k < D+1; k++)
			data[NAME].weight[0]-=(data[NAME].weight[k]*data[NAME].bounds[k].first);
	}
	while(R--){
		char name[10];
		scanf("%s\n",&name); std::string NAME(name);
		std::vector<int> index(data[NAME].weight.size());
		for (auto i = 1; i < data[NAME].weight.size(); ++i) scanf("%d",&index[i]); 
		
		int sum=data[NAME].weight[0];

		for (auto i = 1u; i < data[NAME].weight.size(); ++i)
			sum+=data[NAME].weight[i]*index[i];	

		printf("%s[",name);
		for (auto i = 1; i != index.size(); ++i)
		{
			if(i+1 == index.size()){ printf("%d] = %d\n",index[i],sum); }
			else printf("%d, ",index[i]);
		}
	}
	return EXIT_SUCCESS;
}

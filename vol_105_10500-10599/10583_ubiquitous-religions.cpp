#include <algorithm>
#include <memory>
#include <numeric>
#include <stdio.h>
#include <vector>

/*
 * Alvin Mayers
 * uva 10583 ubiquitous religions
 */

typedef  std::vector<int>& Vec;

/*
 * used union find Data Structure functions
 * from pp. 54 of Competitve Programming 3 textbook
 * note: parameters modified to fit solution
 */
/*---------UNION FIND BOOK CODE--------------------------*/

inline int find_set(Vec p,int i){
	return (p[i] == i) ? i : (p[i]=find_set(p,p[i]));
}
inline bool is_same_set(Vec p,int i,int j){
	return (find_set(p,i) == find_set(p,j));
}
inline void union_set(Vec p,Vec r,int i,int j){
	if(!is_same_set(p,i,j)){
		int x(find_set(p,i)),y(find_set(p,j));
		if(r[x] > r[y])
			p[x]=p[y];
		else{
			p[x]=y;
			if(r[x] == r[y]) ++r[y];
		}
	}
}
/***********BOOK CODE ENDS HERE**************************/
int main(){
	int n,m,c(0);	
	while(scanf("%d %d\n",&n,&m)){
		if((!n) && (!m)) break;
		std::vector<int> rank(n+1,0),snode(n+1);
		int init(0);
		std::generate(begin(snode)+1,end(snode),[&]()->int{ return ++init; });
		while(m--){
			int i,j; scanf("%d %d\n",&i,&j);
			union_set(snode,rank,i,j);
		}
		auto sum(0);
		std::vector<bool> flag(n+1,false);
		for(auto k=1;k<snode.size();++k){
			int root(find_set(snode,snode[k]));
			if(!flag[root]){
				sum+=1;
				flag[root]=true;
			}
		}
		printf("Case %d: %d\n",++c,sum);	
	}
	return EXIT_SUCCESS;
}

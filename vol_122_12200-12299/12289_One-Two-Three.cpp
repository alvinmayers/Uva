#include <algorithm>
#include <stdio.h>
#include <string>

/*
 * @problem uva-12289 ONE-TWO-THREE
 * @author Alvin Mayers
 * @run_time 0.015 sec
 */

int main(){
	const int MAX_LEN=5;
	int cases;	
	std::string ot[]{"one","two"};
	while(scanf("%d\n",&cases)==1){
		for (auto k = 0u; k != cases; ++k)
		{
			char word[MAX_LEN];
			scanf("%s\n",word);
			std::string w(word);
			int index=0,match=0;
			if (w.size()==3) {
				for (auto i = 0u; i != 2; ++i){
					int w_match=0;
					for (auto j = 0u; j != ot[i].size(); ++j)
					{
						if (ot[i][j]==word[j]) w_match++;	
					}
					if (w_match > match) { index=i+1;match=w_match;}
				}
				printf("%d\n",index);
			}	
			else if (w.size()==5) printf("%d\n",3);
		}
	}
}

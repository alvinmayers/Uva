#include <algorithm>
#include <stdio.h>
#include <vector>

/*
 * @problem uva-11364 PARKING
 * @author Alvin Mayers
 * @run_time 0.015 sec
 */

int main(){
	int arr_size,cases=0;
	scanf("%d\n",&cases);
	for (auto i = 0u; i != cases; ++i)
	{
		scanf("%d",&arr_size);
		std::vector<int> stores(arr_size);
		for (auto j = 0u; j != arr_size; ++j)
			stores[scanf("%d ",&stores[j])];
		int max=*std::max_element(begin(stores),end(stores));
		int min=*std::min_element(begin(stores),end(stores));
		printf("%d\n",(2*(max-min)));
	}
}

#include <stdio.h>

/*
 * @problem uva-10300 ECOLOGICAL PREMIUM
 * @author Alvin Dean Jr.
 * @run_time 0.018 sec
 */

int main(){
	int cases;
	scanf("%d\n",&cases);
	while (cases--) {
		int num_farmers,dim,num_animals,env;
		scanf("%d\n",&num_farmers);
		int total_burden=0;
		for (auto i = 0u; i != num_farmers; ++i)
		{
			scanf("%d %d %d\n",&dim,&num_animals,&env);
			total_burden+=dim*env;
		}
		printf("%d\n",total_burden);
	}
	return 0;
}

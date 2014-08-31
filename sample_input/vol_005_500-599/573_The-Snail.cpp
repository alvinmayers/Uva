#include <math.h>
#include <stdio.h>
#include <string>

/*
 * @problem uva-573 THE SNAIL
 * @author Alvin Dean Jr
 * @run_time 0.018 sec
 */

int main(){
	const std::string fail="failure on day";
	const std::string succ="success on day";
	/*
	 * @var h-height of well
	 * @var u-distance snail can climb during the day
	 * @var d-distance snail slides down at night
	 * @var f-fatigue factor (what is the point of sleeping then? )
	 */
	double h,u,d,f;
	int day;
	double snail_loc;
	while((scanf("%lf %lf %lf %lf\n",&h,&u,&d,&f)==4) &&(h > 0)){
		snail_loc=0;	
		day=1;
		auto decr=u*(f*pow(10,-2));
		while((snail_loc >=0) && (snail_loc <= h)){
			snail_loc+=u; 
			if(snail_loc > h){ 
				printf("%s %d\n",succ.c_str(),day); 
				break;
			}
			snail_loc-=d; 
			if(snail_loc < 0){ 
				printf("%s %d\n",fail.c_str(),day); 
				break;
			}
			u-=decr; if(u < 0) u=0;
			day++;
		}		
	}
}

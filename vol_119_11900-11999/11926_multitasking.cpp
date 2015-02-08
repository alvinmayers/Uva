#include <algorithm>
#include <bitset>
#include <stdio.h>

/*
 * Alvin Mayers
 * uva 11926
 */

#define print_nc printf("NO CONFLICT\n")
#define print_c printf("CONFLICT\n")

const auto MAX_SIZE(1000000);

int main(){
	int n,m;
	while((scanf("%d %d\n",&n,&m))){
		if((!n) && (!m)) break;
		std::bitset<MAX_SIZE> sch;
		bool dn_flag(false);
		int beg,las,rep; 
		while(n--){
			scanf("%d %d\n",&beg,&las);
			if(!dn_flag){
				for(auto t=beg;t<las;++t){ 
					if(sch.test(t)){
						print_c; dn_flag=true; break;
					}
					else sch.set(t);
				}
			}
		}	
		while(m--){
			scanf("%d %d %d\n",&beg,&las,&rep);
			if(!dn_flag){
				auto t(beg);
				while((beg<=MAX_SIZE) && (!dn_flag)){
					if(las > MAX_SIZE) las=MAX_SIZE;
					for(auto t=beg;t<las;++t){ 
						if(sch.test(t)){
							print_c; dn_flag=true; break;
						}
						else sch.set(t);
					}
					beg+=rep; las+=rep;
				}	
			}
		}
		if(!dn_flag) print_nc;
	}
}

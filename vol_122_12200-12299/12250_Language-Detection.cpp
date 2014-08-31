#include <map>
#include <stdio.h>
#include <string>
#include <string.h>

/*
 * @problem uva-12250 LANGUAGE DETECTION
 * @author Alvin Mayers
 * @run_time 0.013 sec
 */

int main(){
	const int MAX_LEN=14;
	typedef std::pair<std::string,std::string>  P;
	std::map<std::string,std::string> wl{
		P("HELLO","ENGLISH"),
		P("HOLA","SPANISH"),
		P("HALLO","GERMAN"),
		P("BONJOUR","FRENCH"),
		P("CIAO","ITALIAN"),
		P("ZDRAVSTVUJTE","RUSSIAN")
	};
	char buffer[MAX_LEN];
	int n=1;
	while((scanf("%s\n",&buffer)==1) && (buffer[0]!='#')){
		if(wl.find(std::string(buffer))==wl.end()){
			printf("Case %d: UNKNOWN\n",n);
			n++; continue;
		}
		printf("Case %d: %s\n",n,wl[std::string(buffer)].c_str());
		memset(&buffer[0],0,MAX_LEN);
		n++;
	}
}

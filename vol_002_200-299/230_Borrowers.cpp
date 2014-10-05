#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>


/*
 * @problem uva-230 BORROWERS
 * @author Alvin Mayers
 * @run_time -----
 */


std::vector<std::string> shelf,return_list; //titles of books on shelf
std::map<std::string,std::string>ta_map; //mapping of title -> author
std::map<std::string,bool> borrowed; 

bool rquote(char c){return (c== '"');}

void sort_books(std::vector<std::string>& book_list){
std::sort(begin(book_list),end(book_list),
	[&](std::string s1,std::string s2){
		if (ta_map[s1] < ta_map[s2]){
			return ta_map[s1] < ta_map[s2];
		}
		else if(ta_map[s1] == ta_map[s2])
			return s1 < s2;
	});
}
void parse_input(std::string& a, std::string& l,std::string& t){
	int e1,e2;
	for (auto i = 1; i != l.size(); ++i)
		if((l[i-1] == 'b') && (l[i] == 'y')){
			e1=i-2; e2=i+1;	
			break;
		}
	t=l.substr(0,e1); 
	a=l.substr(e2,l.size()-1);

	t.erase(std::remove_if(begin(t),end(t),rquote),end(t));
	a.erase(std::remove_if(begin(a),end(a),rquote),end(a));
	shelf.push_back(t); ta_map.insert(std::make_pair(t,a));
}
int main()
{

	bool flag{false}; std::string line,author,title,com;
	std::map<std::string,bool> borrowed; 
	bool sflag{false};
	while(std::getline(std::cin,line)){
		if((line == "END") && (!flag)) flag=true;	 
		else if(!flag) parse_input(author,line,title);		
		else if(flag){
			int e1,e2;
			std::istringstream ss(line);
			ss >> com; title=line.substr(com.size(),line.size());
			title.erase(std::remove_if(begin(title),end(title),rquote),end(title));
			title.erase(0,1);
			
			if(com == "RETURN") return_list.push_back(title);
			
			else if(com == "SHELVE"){
				if(!return_list.size()){ printf("END\n"); continue; }
				if(!sflag){sort_books(shelf); sflag=true;}
				sort_books(return_list);
				for(auto bt : return_list){
					int index=std::distance(begin(shelf),std::find(begin(shelf),end(shelf),bt));
				
					if(!index) printf("put \"%s\" first\n",bt.c_str());

					else if(index > 0)
						printf("Put \"%s\" after  \"%s\"\n",bt.c_str(),shelf[index-1].c_str());
				}
				return_list.clear(); 
				printf("END\n");
			}
		}
	}
	return EXIT_SUCCESS;
}

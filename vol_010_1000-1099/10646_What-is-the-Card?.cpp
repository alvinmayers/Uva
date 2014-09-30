#include <algorithm>
#include <iostream>
#include <set>
#include <stdio.h>
#include <string.h>
#include <vector> 

/*
 * @problem uva-10646 WHAT IS THE CARD?
 * @author Alvin Mayers
 * @run_time ----------
 */

int main()
{
	typedef std::pair<char,char> Pair;
	const std::set<char> FACE_CARDS{'A','K','Q','J','T'};
	const int DECK_NUM=52,MAX_LEN=(3*DECK_NUM);
	int cases; scanf("%d\n",&cases);
	char deck[MAX_LEN]; int counter=1;
	while (std::cin.getline(deck,MAX_LEN) && (cases--)) {
		//parse values into vector
		std::vector<Pair> cards(DECK_NUM);
		std::vector<int> values(DECK_NUM);
		for (int i = 0u,j=0; i < strlen(deck); i+=3,j++){ 
			cards[j]=Pair(deck[i],deck[i+1]);	
			if(FACE_CARDS.find(deck[i]) != end(FACE_CARDS)) values[j]=10;
			else values[j]=static_cast<int>(deck[i]-'0');
		}
		int y=0,p=26,h=27;
		for (int i = 0u; i < 3; ++i){int x=values[p]; y+=x; p-=(10-x)+1;}
		std::vector<Pair> revised_deck;
		std::copy(begin(cards),begin(cards)+p,std::back_inserter(revised_deck));
		std::copy(begin(cards)+h,end(cards),std::back_inserter(revised_deck));
		printf("Case %d: %c%c\n",counter,revised_deck[y-2].first,revised_deck[y-2].second);
		counter++;
	}	
	return EXIT_SUCCESS;
}

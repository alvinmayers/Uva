#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

/*
 * @problem uva 462 BRIDGE HAND EVALUATOR
 * @author Alvin Mayers
 * @run_time 0.216 sec
 */

typedef enum card_types{NUMBER,JACK,QUEEN,KING,ACE}card_types;
typedef enum card_suit{SPADES,HEARTS,DIAMONDS,CLUBS} card_suit;


card_types ctype(char value,int& points){
	switch(value){
		case 'A': points+=ACE; return ACE;
		case 'K': points+=KING; return KING;
		case 'Q': points+=QUEEN; return QUEEN;
		case 'J': points+=JACK; return JACK;
		default: return NUMBER;
	}
}
int main()
{
	const int MAX_LEN=40; const int num_suits=4;
	const char suited[num_suits]{'S','H','D','C'};
	char hand[MAX_LEN];
	while (std::cin.getline(hand,MAX_LEN)) {
		int points(0),points_r57(0);
		std::vector<std::vector<card_types> >suits(num_suits,std::vector<card_types>());
		//calculate addition of points for royal cards
		for (auto i = 0u; i < strlen(hand); i+=3)
		{
			char kind=hand[i]; char suit=hand[i+1];
			//printf("%c,%c : %d, %d\n",kind,suit,i,i+1);
			switch(suit){
				case 'S': suits[SPADES].push_back(ctype(kind,points));break;
				case 'H': suits[HEARTS].push_back(ctype(kind,points));break;
				case 'D': suits[DIAMONDS].push_back(ctype(kind,points));break;
				case 'C': suits[CLUBS].push_back(ctype(kind,points));break;
			}
		}
		points_r57=points;
		//deduct points according to rules
		std::vector<bool>stopped(num_suits,false);  auto index=0;
		std::vector<int> suit_size(num_suits,0);
		for(auto& suit : suits){
			suit_size[index]=suit.size(); 
			if((std::find(begin(suit),end(suit),ACE) != end(suit))) stopped[index]=true;

			if ((std::find(begin(suit),end(suit),KING) != end(suit))){
				if((suit.size() ==1)){  points--; points_r57--; }
				else if (suit.size()> 1) stopped[index]=true;
			}
			if ((std::find(begin(suit),end(suit),QUEEN) != end(suit))){
				if((suit.size() < 3)){ points--; points_r57--;}
				else if(suit.size() >=3) stopped[index]=true;
			}
			if ((std::find(begin(suit),end(suit),JACK) != end(suit)) && (suit.size() < 4)){ 
				points--; points_r57--;
			}
			//rules 5 -> 7
			if ((suit.size() == 2)) points_r57++; else if (suit.size() ==1) points_r57+=2;
			else if(!suit.size()) points_r57+=2;
			index++;
		}
		//assessment
		if(points_r57 < 14) printf("PASS\n");
		else if ((points >= 16 ) && (std::all_of(begin(stopped),end(stopped),[&](bool b){return b==true;}))) 
			printf("BID NO-TRUMP\n");
		else if (points_r57 >= 14 ){
			int ssuit=std::distance(begin(suit_size),std::max_element(begin(suit_size),end(suit_size)));
			printf("BID %c\n",suited[ssuit]);
		}
		//printf("points %d ::::: r57 %d\n",points,points_r57);
	}
	return EXIT_SUCCESS;
}

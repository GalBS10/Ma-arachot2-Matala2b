#ifndef CARD
#define CARD
#include "iostream"

using namespace std;


//each card will have only a value (without sign) 1 is for Ace , 2 is for two , ... , 11 is for Jack , 12 is for Queen , 13 is for king.
enum Sign{
    null,
    Heart,
    Diamond,
    Spade,
    Clover
};
    class Card{
        public:
            string s_value;
            int i_value;
            Sign sign;

            Card();
            Card(int value, Sign _sign);
            int compare(Card card1);
            string to_string();
    };
#endif

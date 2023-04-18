#ifndef CARD
#define CARD
#include "iostream"

using namespace std;


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

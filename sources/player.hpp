#ifndef PLAYER
#define PLAYER
#include "iostream"
#include "card.hpp"
#include "stack"

using namespace std;
class Player{

    
    string name;
    bool is_playing;//a flag that indicate if the player is playing or not.
    //stats of the player
    size_t draws;
    size_t wins;
    size_t loses;

    stack<Card> card_stack;//holds the cards he get at the start of the game.
    stack<Card> cards_won;//holds the cards he won in the game.
    public:
        //constructor
        Player ();
        Player (string n);

      //  Card card_out();
      //  void add_turn(string turn);
      //  int how_many_cards();
        void set_is_playing();
        //string last_turn();
        string getName();
        bool getIs_playing();
        size_t getDraws();
        size_t getWins();
        size_t getLoses();
        stack<Card>& getCard_stack();
        stack<Card>& getCards_won();
        void increaseDraws();
        void increaseWins();
        void increaseLoses();
        int stacksize();
        int cardesTaken();
};
#endif
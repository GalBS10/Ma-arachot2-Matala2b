#include "player.hpp"
#include "card.hpp"

Player:: Player (){
    name = string("someone");
    is_playing = false;
    draws = 0;
    wins = 0;
    loses = 0;
    card_stack = stack<Card>();
    cards_won = stack<Card>();
}
Player:: Player (string n){
    name = string(n);
    is_playing = false;
    draws = 0;
    wins = 0;
    loses = 0;
    card_stack = stack<Card>();
    cards_won = stack<Card>();
}

string Player:: getName(){
    return name;
}
bool Player:: getIs_playing(){
    return is_playing;
}
size_t Player:: getDraws(){
    return draws;
}
size_t Player:: getWins(){
    return wins;
}
size_t Player:: getLoses(){
    return loses;
}
stack<Card>& Player:: getCard_stack(){
    return card_stack;
}
stack<Card>& Player:: getCards_won(){
    return cards_won;
}
void Player:: increaseDraws(){
    draws++;
}
void Player:: increaseWins(){
    wins++;
}
void Player:: increaseLoses(){
    loses++;
}


int Player:: stacksize(){//prints the amount of cards left. should be 21 but can be less if a draw was played
    return card_stack.size(); 
}
int Player:: cardesTaken(){// prints the amount of cards this player has won. 
    return cards_won.size();
}
void Player:: set_is_playing(){ //set is_playing to the his opposite.
    is_playing = !is_playing;
}
#ifndef GAME
#define GAME
#include "iostream"
#include "player.hpp"
#include "array"
using namespace std;

namespace ariel{
    constexpr int CARDS_AMOUNT = 52;
    constexpr int MAX_TURNS_POSSIBLE = 26;
}
using namespace ariel;

    class Game{

        public:
            Player& player1;
            Player& player2;
            //int pack [PACK_SIZE];
            array<Card, CARDS_AMOUNT> pack;//the main deck of cards. we split the cards to the players from this deck.
            stack<Card> cards_on_table;// this stack is used in each turn. the player who won get all the cards in this stack.
            array<string,MAX_TURNS_POSSIBLE> turns;// holds all the turn that played.
            size_t turns_index;// the index for

           // Game();
            Game(Player& player1, Player& player2);//constructor

            string getP1();
            string getP2();
            void empty_cards_on_table(Player& player);
            void playTurn();
            void printLastTurn();
            void playAll();
            void printWiner();
            void printLog();
            void printStats();
            void split_stack(array<Card,CARDS_AMOUNT> pack, Player& player_1, Player& player2_);

    };
#endif
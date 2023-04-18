#include "card.hpp"
#include <sstream>
#include "string"


Card:: Card(){ //default constructor
    s_value = "0";
    i_value =0;
    sign = null;
}

/// @brief - giving each value a name in order to print it in the turn
/// @param _value  - the int value in order to compare between the cards.
/// @param _sign  - the sign of the card.
/// @param s_value - the name of the card.
Card:: Card(int _value, Sign _sign){//constructor
    if(_value==11)
    {
        s_value = "Jack";
    }
    else if (_value == 12)
    {
        s_value ="Queen";
    }
    else if (_value == 13)
    {
        s_value ="King";
    }
    else if (_value == 1)
    {
        s_value ="Ace";
    }else{
    //------------ converting the int to string 
    std::stringstream tmp;
    tmp << _value;
    s_value = tmp.str();
    //-------------
    }
    i_value = _value;
    sign = _sign;
}

/// @brief - turnind the card info into a string in order to print it.
/// @return - the string that describe the card.
string Card:: to_string(){
    string s= "";
    if(sign == Heart){
        s = "Heart";
    }
    if(sign == Diamond){
        s = "Diamond";
    }
    if(sign == Spade){
        s = "Spade";
    }
    if(sign == Clover){
        s = "Clover";
    }

    return  s_value + " of " + s;

}

/// @brief - in order to know who won in teach round we need to compare the cards and by the rules of the game
// we return the right value.
/// @param card2 - the card we compare "this" to.
/// @return - returning an int.
/// 1 - "this" card won .
/// -1 - card2 won.
/// 0 - equal.
int Card:: compare(Card card2){

    if(i_value == 1 && card2.i_value == 2){ //Ace vs. 2 = lose
        return -1;
    }
    if(i_value == 1 && card2.i_value != 1){ //Ace vs. !2&&!Ace = win
        return 1;
    }
    if(i_value == 2 && card2.i_value == 1){ //2 vs. Ace = win
        return 1;
    }
    if(i_value != 1 && card2.i_value == 1){ //!2&&!Ace vs. Ace = lose
        return -1;
    }
    if(i_value > card2.i_value){
        return 1;
    }
    if(i_value < card2.i_value){
        return -1;
    }
    
    return 0; // Draw

}

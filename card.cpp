#include "card.hpp"
#include <sstream>
#include "string"


Card:: Card(){
    s_value = "0";
    i_value =0;
    sign = null;
}
Card:: Card(int _value, Sign _sign){
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

#include "player.hpp"
#include "game.hpp"
#include "algorithm"
#include "vector"
#include "ctime"
#include "iomanip"
#include "random"

// Game::Game(){

// }

Game::Game(Player &p1, Player &p2) : player1(p1), player2(p2)
{
    try
    {
        if (p1.getIs_playing() || p2.getIs_playing())
        {
            throw runtime_error("ERROR - one or more of the player is still playing");
        }
        cards_on_table = stack<Card>();
        player1.set_is_playing();
        player2.set_is_playing();
        turns_index = 0;

        for (size_t i = 0; i < 5; i++) // generating the turns array.
        {
            turns[i] = string("");
        }

        int val = 1;
        for (size_t i = 0; i < 52;) // generating the cards pack
        {

            pack[i] = Card(val, Heart);
            i++;
            pack[i] = Card(val, Diamond);
            i++;
            pack[i] = Card(val, Spade);
            i++;
            pack[i] = Card(val, Clover);
            i++;
            val++;
        }

        split_stack(pack, player1, player2); // giving each player half a pack(after we shuffle it).
    }
    catch (exception &e)
    {
        cout << "failed to create a Game. pls try again";
    }
}

void Game::split_stack(array<Card, 52> pack, Player &player_1, Player &player_2)
{
    vector<int> nums(52); // Initialize vector of integers from 0 to 51

    for (size_t i = 0; i < 52; ++i)
    {
        nums[i] = i;
    }
    // Shuffle vector using std::shuffle and std::default_random_engine
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(nums.begin(), nums.end(), rng);

    for (size_t i = 0; i < 52; i++) // giving the cards to the players from random places in the pack of cards.
    {
        if (i % 2 == 0)
        {
            player_1.getCard_stack().push(pack[size_t(nums[i])]);
        }
        else
        {
            player_2.getCard_stack().push(pack[size_t(nums[i])]);
        }
    }
}

string Game::getP1()
{
    return player1.getName();
}
string Game::getP2()
{
    return player2.getName();
}
void Game::empty_cards_on_table(Player &player)
{
    while (!cards_on_table.empty())
    {
        player.getCards_won().push(cards_on_table.top());
        cards_on_table.pop();
    }
}

void Game::playTurn()
{
    if (!(player1.getIs_playing() && player2.getIs_playing()))
    {
        throw runtime_error("ERROR - The players already finished the game");
    }
    bool loop = true;
    string s1 = "";
    string s2 = "";
    string ans = "";

    while (loop)
    {
        s1 = player1.getName() + " played " + player1.getCard_stack().top().to_string() + ", ";
        s2 = player2.getName() + " played " + player2.getCard_stack().top().to_string() + ". ";
        if (player1.getCard_stack().top().compare(player2.getCard_stack().top()) == 1)
        {
            player1.getCards_won().push(player1.getCard_stack().top());
            player1.getCards_won().push(player2.getCard_stack().top());
            empty_cards_on_table(player1);
            ans += s1 + s2 + player1.getName() + " wins.";
            player1.getCard_stack().pop();
            player2.getCard_stack().pop();
            player1.increaseWins();
            player2.increaseLoses();
            loop = false;
        }
        else if (player1.getCard_stack().top().compare(player2.getCard_stack().top()) == -1)
        {
            player2.getCards_won().push(player2.getCard_stack().top());
            player2.getCards_won().push(player1.getCard_stack().top());
            empty_cards_on_table(player2);
            ans += s1 + s2 + player2.getName() + " wins.";
            player1.getCard_stack().pop();
            player2.getCard_stack().pop();
            player2.increaseWins();
            player1.increaseLoses();
            loop = false;
        }
        else if (player1.getCard_stack().top().compare(player2.getCard_stack().top()) == 0)
        {
            player1.increaseDraws();
            player2.increaseDraws();
            cards_on_table.push(player1.getCard_stack().top());
            cards_on_table.push(player2.getCard_stack().top());

            ans += s1 + s2 + "Draw. ";

            player1.getCard_stack().pop();
            player2.getCard_stack().pop();

            if (player1.stacksize() == 0 || player2.stacksize() == 0)
            {
                int i = 0;
                while (!cards_on_table.empty())
                {
                    if (i % 2 == 0)
                    {
                        player1.getCards_won().push(cards_on_table.top());
                        cards_on_table.pop();
                    }
                    else
                    {
                        player2.getCards_won().push(cards_on_table.top());
                        cards_on_table.pop();
                    }
                }
                break;
            }
            cards_on_table.push(player1.getCard_stack().top());
            cards_on_table.push(player2.getCard_stack().top());

            player1.getCard_stack().pop(); // for putting a upside down card
            player2.getCard_stack().pop();
            if (player1.stacksize() == 0 || player2.stacksize() == 0)
            {
                int i = 0;
                while (!cards_on_table.empty())
                {
                    if (i % 2 == 0)
                    {
                        player1.getCards_won().push(cards_on_table.top());
                        cards_on_table.pop();
                    }
                    else
                    {
                        player2.getCards_won().push(cards_on_table.top());
                        cards_on_table.pop();
                    }
                }
                break;
            }

        }
    }
    turns[turns_index] = ans;
    turns_index++;
}

void Game::printLastTurn()
{
    // print the last turn stats. For example:
    // Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
    // Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw.
    // Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
    if (turns_index == 0)
    {
        cout << "didn't play yet";
    }
    else
    {
        cout << turns[turns_index - 1];
    }
}
void Game::printWiner() // prints the name of the winning player can be used also to find who is the current winner(who has more cards at the moment)
{
    if (player1.cardesTaken() > player2.cardesTaken())
    {
        cout << player1.getName();
    }
    else if (player1.cardesTaken() < player2.cardesTaken())
    {
        cout << player2.getName();
    }
    else
    {
        throw runtime_error ("Draw");
    }
}
void Game::playAll() // playes the game untill the end
{
    while (player1.stacksize() > 0 && player2.stacksize() > 0)
    {
        playTurn();
    }
    player1.set_is_playing(); // setting is_palying to false;
    player2.set_is_playing();
}
void Game::printLog() // prints all the turns played one line per turn (same format as game.printLastTurn())
{
    for (size_t i = 0; i < turns_index; i++)
    {
        cout << turns[i] << endl;
    }
}
void Game::printStats() // for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
{
    cout << std::string(55, '-') << std::endl;

    // Table rows
    std::cout << std::left << std::setw(25) << "Win rate"
              << std::setw(15) << std::setprecision(2) << (player1.getWins() / turns_index)
              << std::setw(15) << std::setprecision(2) << (player2.getWins() / turns_index)
              << std::endl;

    std::cout << std::left << std::setw(25) << "Wins"
              << std::setw(15) << std::setprecision(2) << player1.getWins()
              << std::setw(15) << std::setprecision(2) << player2.getWins()
              << std::endl;

    std::cout << std::left << std::setw(25) << "Loses"
              << std::setw(15) << std::setprecision(2) << player1.getLoses()
              << std::setw(15) << std::setprecision(2) << player2.getLoses()
              << std::endl;

    std::cout << std::left << std::setw(25) << "Amount of draw"
              << std::setw(15) << player1.getDraws()
              << std::setw(15) << player2.getDraws()
              << std::endl;

    std::cout << std::left << std::setw(25) << "Cards won"
              << std::setw(15) << player1.cardesTaken()
              << std::setw(15) << player2.cardesTaken()
              << std::endl;

    std::cout << std::left << std::setw(25) << "Cards remaining"
              << std::setw(15) << player1.stacksize()
              << std::setw(15) << player2.stacksize()
              << std::endl;
}

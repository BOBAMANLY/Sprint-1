#include <iostream>
using namespace std;

class Dealer
{

    public:

    // public variables
    int _current_card;
    int _next_card;
    string _user_input;
    int _points;
    bool _can_deal;
    int card;
    int random_int;

    // Methods
    void can_deal()
    {
        // Checks to see if the dealer can deal
        if (_points > 0 && _user_input != "q")
        {
            _can_deal = true;
        }
    }

    bool get_can_deal()
    {
        // Returns the value of _can_deal
        can_deal();
        return _can_deal;
    }

    void update_points(int score)
    {
        // Updates the points
        if (_user_input == "h" && _next_card > _current_card)
        {
            _points = score + 100;
        }
        else if (_user_input == "l" && _next_card < _current_card)
        {
            _points = score + 100;
        }
        else
        {
            _points = score - 75;
        }
    }

    int draw_card()
    {
        // Draws a card
        card = rand() % 13 + 1;
        return card;
    }

    void draw_next_card()
    {
        // Draws thecard for the variable  next card
        random_int = draw_card();
        while (random_int == _current_card)
        {
            random_int = draw_card();
        }
        _next_card = random_int;

    }

    void draw_current_card()
    {
        // Draws the card for the variable current card
        _current_card = draw_card();
    }

    void get_user_input()
    {
        // Gets the user input on what the next card value will be
        cout << "Is the next card higher or lower? (h/l) " << endl;
        cin >> _user_input;
    }

    void set_score(int score)
    {
        // Sets the score
        _points = score;
    }

};

class Director
{

    private:

    // private variables
    Dealer _dealer;
    bool _keep_playing;

    public:

    void set_keep_playing(bool torf)
    {
        // Sets the value of _keep_playing based on input
        _keep_playing = torf;
    }

    void start_game()
    {
        // Starts the game
        _dealer.set_score(0);
        _dealer.draw_current_card();
        set_keep_playing(true);

        // While loop that keeps the game going
        while (_keep_playing == true)
        {
            Director::get_inputs();
            Director::do_updates();
            Director::do_outputs();
        }
    }

    void get_inputs()
    {
        // Function to get game inputs
        cout << "The current card is "<< _dealer._current_card << endl;
        _dealer.get_user_input();
        _dealer.draw_next_card();
    }

    void do_updates()
    {
        // Function to update the game
        _dealer.update_points(_dealer._points);
    }

    void do_outputs()
    {
        // Function to do game outputs
        cout << "The card was: " << _dealer._next_card << endl;
        cout << "Your score is: " << _dealer._points << endl;
        if (_dealer.get_can_deal() == true)
        {
            // Checks to see if the player wants to play again
            string choice;
            cout << "Do you want to play again? (y/n) ";
            cin >> choice;
            if (choice == "y")
            {
                _keep_playing = true;
                _dealer._current_card = _dealer._next_card;
            }
            else
            {
                _keep_playing = false;
            }
        }
    }

};

int main()
{
    // Main function
    Director director;
    director.start_game();
    return 0;
}
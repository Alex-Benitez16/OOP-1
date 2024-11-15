#ifndef DECK
#define DECK

#include <iostream>
#include <array>
#include "card.h"
using std::cout;

using std::array;

class Deck{
    private: 
        array<Card, 4>deck;
        int number_of_cards;
    public: 
        Deck() : number_of_cards(0){};
        void add_card(Card c);
        Card get_card(int n);

        void to_string();
    
};

void Deck::add_card(Card c) {
    if(number_of_cards > 3) {
        throw std::invalid_argument("Deck is already full.");
    }
    deck.at(number_of_cards) = c;
    number_of_cards++;
}

Card Deck::get_card(int n) {
    return deck.at(n);
}

void Deck::to_string() {
    cout << "Your current deck has: ";
    for(int i = 0; i < number_of_cards; i++) {
        cout << deck.at(i).get_name() << ", ";
    }
    cout << "\n";
}

#endif
/*
*   Clase Deck, contiene un arreglo de cuatro cartas (agregación) y un contador
*/
#ifndef DECK
#define DECK

#include <iostream>
#include <array>
#include "card.h"
using std::cout;

using std::array;

// Definición de la clase
class Deck{
    private: 
        // Atributos privados
        array<Card, 4>deck;
        int number_of_cards;
    public: 
        // Constructor
        Deck() : number_of_cards(0){};

        // Métodos públicos
        void add_card(Card c);
        Card get_card(int n);

        void to_string();
    
};


/*
*   función para añadir cartas al arreglo
*   
*   @param Card c: carta para copiar y agregar
*   @return
*/
void Deck::add_card(Card c) {
    if(number_of_cards > 3) {
        throw std::invalid_argument("Deck is already full.");
    }
    deck.at(number_of_cards) = c;
    number_of_cards++; // Actualizar contador
}

/*
*   getter card
*   
*   @param int n: posición de la carta a acceder
*   @return Card: regresa una copia de la carta elegida
*/
Card Deck::get_card(int n) {
    return deck.at(n);
}

/*
*   to string. imprime los nombres de las cartas en el mazo
*   
*   @param
*   @return 
*/
void Deck::to_string() {
    cout << "Your current deck has: ";
    for(int i = 0; i < number_of_cards; i++) {
        cout << deck.at(i).get_name() << ", ";
    }
    cout << "\n";
}

#endif
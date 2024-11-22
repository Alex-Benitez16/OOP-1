/*
*   clase heredada de character, añade métodos y atributos
*/
#ifndef PLAYER
#define PLAYER

#include "character.h"
#include "deck.h"
#include <sstream>
#include "bot.h"
#include "action.h"
using std::string;

// Definición de la clase player
class Player: public Character {
    private: 
        // Atributos privados
        Deck deck;
        int defense;
    public:
        // Constructores
        Player(): Character(), deck(), defense(100){};
        Player(string n): Character(n), deck(), defense(100){};

        // Métodos públicos
        Deck get_deck();
        void add_card(Card c);
        void play_card(int n, Bot &bot);
        void take_damage(int damage);
        void stats();
};

/*
*   getter deck
*   
*   @param
*   @return Deck: regresa el mazo del jugador
*/
Deck Player::get_deck() {
    return deck;
}

/*
*   agrega una carta al mazo del jugador
*   
*   @param Card c: carta para agregar
*   @return
*/
void Player::add_card(Card c) {
    deck.add_card(c);
}

/*
*   recibe daño. reduce el daño recibido por un porcentaje dictado
*   por la defensa del jugador
*   
*   @param int damage: daño
*   @return 
*/
void Player::take_damage(int damage) {
    health -= damage * (static_cast<double>(defense) / 100);
}

/*
*   juega la carta seleccionada. la función revisa el tipo de la carta
*   (atacar, defender, curar), y aplica el efecto deseado. de ser ataque, 
*   se aplica el daño al bot pasado en los parámetros
*   
*   @param int n: número de la carta, Bot &bot: enemigo al que atacar
*   @return 
*/
void Player::play_card(int n, Bot &bot) {

    if(deck.get_card(n).get_action() == Action::attack) {
        bot.take_damage(deck.get_card(n).get_effect());
    }
    else if(deck.get_card(n).get_action() == Action::heal) {
        heal(deck.get_card(n).get_effect());
    }
    else {
        defense -= deck.get_card(n).get_effect();
    }
}

/*
*   to string. imprime los stats del jugador
*   
*   @param
*   @return
*/
void Player::stats() {
    std::cout << name << " stats: ";
    std::cout << health << "hp";
    std::cout << 100 - defense << "%";
    std::cout << "\n";
}

#endif
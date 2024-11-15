#ifndef CHARACTER
#define CHARACTER

#include <string>
#include "deck.h"
#include "card.h"

using std::string;

class Character{
    private: 
        string name;
        int health;
        int energy;
        Deck default_deck;
    public:
        Character(): name(""), health(100), energy(100){};
        Character(string n): name(n), health(100), energy(100){};

        string get_name();
        int get_health();
        int get_energy();
        Deck& get_default_deck();

        void set_name(string n);
        void set_health(int h);
        void set_energy(int e);


};

string Character::get_name() { return name; }
int Character::get_health() { return health; }
int Character::get_energy() { return energy; }
Deck& Character::get_default_deck() { return default_deck; }

void Character::set_name(string n) { name = n; }
void Character::set_health(int h) { health = h; }
void Character::set_energy(int e) { energy = e; }

#endif
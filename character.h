/*
*   clase abstracta de personaje de la cual player y bot heredarán
*/
#ifndef CHARACTER
#define CHARACTER

#include <string>
#include "deck.h"
#include "card.h"

using std::string;

// Definición de la clase
class Character{
    protected: 
        // Atributos protegidos para heredar
        string name;
        int health;
    public:
        // Constructores
        Character(): name(""), health(100){};
        Character(string n): name(n), health(100){};
        Character(string n, int num): name(n), health(num){};

        // Getters
        string get_name();
        int get_health();

        // No se incluyen setters porque los valores se designan en el
        // constructor y no se vuelven a modificar

        // Métodos públicos
        void take_damage(int damage);
        void heal(int amount);
        void stats();

};

/*
*   getter name
*   
*   @param
*   @return string: name
*/
string Character::get_name() { return name; }

/*
*   getter health
*   
*   @param
*   @return int: health
*/
int Character::get_health() { return health; }

/*
*   aplica daño a la vida del jugador
*   
*   @param int damage: daño
*   @return
*/
void Character::take_damage(int damage) {
    health -= damage;
}

/*
*   cura, incrementa la vida
*   
*   @param int amount: cantidad de vida a aumentar
*   @return
*/
void Character::heal(int amount) {
    health += amount;
}

/*
*   to string. imprime los atributos de la clase
*   
*   @param
*   @return
*/
void Character::stats() {
    std::cout << name << " stats: ";
    std::cout << health << "hp";
}

#endif
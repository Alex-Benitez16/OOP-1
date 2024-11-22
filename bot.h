/*
*   clase heredada de character. añade algunos atributos y sobreescribe 
*   algunas funciones
*/
#ifndef BOT
#define BOT

#include "character.h"
#include <sstream>

// Definición de clase bot
class Bot: public Character {
    private:
        // Atributos privados
        int power;
    public:
        // Constructores
        Bot(): Character(){};
        Bot(string n, int he, int pow): Character(n, he), power(pow){};

        // Métodos públicos
        int attack();
        void stats();
};

/*
*   getter de power
*   
*   @param
*   @return int: power
*/
int Bot::attack() {
    return power;
}

/*
*   to string. imprime los atributos del bot
*   
*   @param
*   @return
*/
void Bot::stats() {
    std::cout << name << " stats: ";
    std::cout << health << "hp ";
    std::cout << power << " attack power ";
    std::cout << "\n";
}

#endif 
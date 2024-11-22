/*
*   Clase Card contiene las características de una carta en el juego:
*   nombre, acción, efecto, y descripción. Cuenta con sus accessors y 
*   mutators, y una funcón tostring (display)
*/

#ifndef CARD
#define CARD

#include <string>
#include <iostream>
#include "action.h" 
#include <sstream>
using std::cout;

using std::string;

// Declaración de la clase
class Card{
    private: 
        // Atributos privados
        string name;
        Action action;
        int effect;
        string description;
    public:
        // Constructores
        Card() : name(""), action(Action::attack), 
        effect(0), description("No description available"){};
        Card(string n, Action b, int e, string descrip): 
        name(n), action(b), effect(e), description(descrip){};       

        // Métodos públicos
        string get_name();
        Action get_action();
        int get_effect();
        string get_description();

        void set_name(string n);
        void set_action(Action b);
        void set_effect(int e);
        void set_description(string d);

        int play();
        string display(bool set = true);

};

// Getters

/*
*   getter name
*   
*   @param
*   @return string: name
*/
string Card::get_name() { return name; }

/*
*   getter action
*   
*   @param
*   @return Action: action
*/
Action Card::get_action() { return action; }

/*
*   getter effect
*   
*   @param
*   @return int: effect
*/
int Card::get_effect() { return effect; }

/*
*   getter description
*   
*   @param
*   @return string: description
*/
string Card::get_description() { return description; }

/*
*   setter name
*   
*   @param string n: nombre 
*   @return
*/
void Card::set_name(string n) { name = n; }

/*
*   setter action
*   
*   @param Action b: tipo de acción 
*   @return
*/
void Card::set_action(Action b) { action = b; }

/*
*   setter effect
*   
*   @param int e: efecto
*   @return
*/
void Card::set_effect(int e) { effect = e;}

/*
*   setter description
*   
*   @param string d: descripción 
*   @return
*/
void Card::set_description(string d) { description = d; }

/*
*   función para utilizar una carta, simplemente regresa el efecto
*   
*   @param
*   @return int: efecto de la carta
*/
int Card::play() { return get_effect();}

/*
*   función to string
*   
*   @param bool set: booleano para determinar si usar saltos de línea o no
*   @return string: atributos hechos string
*/
string Card::display(bool set) {
    std::stringstream aux;
    aux << "Card name: " << name << " |";
    if(set) aux << "\n";
    aux << "Card description: " << description << " |";
    if(set) aux << "\n";
    if(action == Action::attack) aux << "Attack damage: ";
    else if(action == Action::defend) aux << "Damage protection: ";
    else aux << "Health recovered: ";
    aux << effect << " |";
    if(set) aux << "\n";

    return aux.str();
}

#endif
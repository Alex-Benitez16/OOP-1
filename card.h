#ifndef CARD
#define CARD

#include <string>
#include <iostream>
using std::cout;

using std::string;

class Card{
    public:  enum class Action {attack, heal, defend,};
    private: 
        string name;
        int cost;
        Action action;
        int effect;
        string description;
    public:
        Card() : name(""), cost(0), action(Action::attack), 
        effect(0), description("No description available"){};
        Card(string n, int c, Action b, int e) : 
        name(n), cost(c), action(b), effect(e), 
        description("No description available"){};       

        string get_name();
        int get_cost();
        Action get_action();
        int get_effect();
        string get_description();

        void set_name(string n);
        void set_cost(int c);
        void set_action(Action b);
        void set_effect(int e);
        void set_description(string d);

        int play();
        void display();
};

string Card::get_name() { return name; }
int Card::get_cost() { return cost; }
Card::Action Card::get_action() { return action; }
int Card::get_effect() { return effect; }
string Card::get_description() { return description; }

void Card::set_name(string n) { name = n; }
void Card::set_cost(int c) { cost = c;}
void Card::set_action(Card::Action b) { action = b; }
void Card::set_effect(int e) { effect = e;}
void Card::set_description(string d) { description = d; }

int Card::play() { return get_effect();}
void Card::display() {
    cout << "Card name: " << name << "\n";
    cout << "Card description: " << description << "\n";
    if(action == Card::Action::attack) cout << "Attack damage: ";
    else if(action == Card::Action::defend) cout << "Damage defended: ";
    else cout << "Health recovered: ";
    cout << effect << "\n";
    cout << "Card cost: " << cost << "\n";
}

#endif
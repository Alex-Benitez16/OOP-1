#include "card.h"
#include <thread>
#include <chrono>
#include "bot.h"
#include <iostream>
#include "character.h"
#include "deck.h"
#include "action.h"
#include "player.h"
#include <random>
#include <cstdlib>

using std::string;

/*
*   función para imprimir progresivamente
*   
*   @param string str: string a imprimir, bool has_newline: añadir line break
*   al final de la impresión (verdadero o falso)
*   @return string: name
*/
void print_cool(string str, bool has_newline = true) {
    for(int i = 0; i < str.size(); i++) {
        std::cout << str.at(i) << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(30)); 
    }

    if(has_newline) ::cout << "\n";
}

/*
*   pregunta al usuario por un nombre y lo regresa
*   
*   @param
*   @return string: name
*/
string ask_for_players_name() {
    print_cool("Enter your name: ", false);
    string name;
    getline(std::cin, name);
    return name;
}

/*
*   imprime instrucciones
*   
*   @param
*   @return
*/
void print_instructions() {
    print_cool("This game is pretty simple to play.");
    print_cool("You will be given four random cards.");
    print_cool("Your goal is to defeat four enemies using those cards.");
    print_cool("Good luck!");
}

/*
*   presionar enter (cualquier tecla) para continuar
*   
*   @param
*   @return
*/
void press_enter_to_continue() {
    string input;
    print_cool("Press enter to continue.");
    getline(std::cin, input);
}

/*
*   limpiar consola
*   
*   @param
*   @return
*/
void clear_scr() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}

/*
*   asigna una carta al jugador
*   
*   @param Player &player: jugador al que se le asigna la carta, 
*   Card card_pool[15]: arreglo de todas las cartas
*   int n: posición de la carta en el arreglo para agregarla al jugador
*   @return
*/
void assign_card(Player &player, Card card_pool[15], int n) {
    player.add_card(card_pool[n]);
}

/*
*   pedir un input al jugador para elegir la carta que jugar. revisa que la
*   selección sea válida
*   
*   @param Player player: jugador 
*   @return int: elección del usuario
*/
int select_card(Player player) {
    print_cool("Select an action:");
    std::cout << "\t1. " + player.get_deck().get_card(0).display(false) << "\n";
    std::cout << "\t2. " + player.get_deck().get_card(1).display(false) << "\n";
    std::cout << "\t3. " + player.get_deck().get_card(2).display(false) << "\n";
    std::cout << "\t4. " + player.get_deck().get_card(3).display(false) << "\n";

    while(true){
    string input;
    getline(std::cin, input);
    if(input.size() == 1 && input[0] >= '1' && input[0] <= '4') {
        return static_cast<int>(input[0]) - '0' - 1;
    }
    std::cout << "Please select a valid option: ";
    }
}

int main() {
    // Arreglo del banco de cartas
    Card card_pool[15] = {
        Card("Fireball", Action::attack, 30, "Fire a powerful ball"),
        Card("Quickslash", Action::attack, 20, 
        "Like a normal slash, but quicker"),
        Card("Falcon Punch", Action::attack, 50, "Falcon punch!!!"),
        Card("Energy Sword", Action::attack, 1000, "One shot"),
        Card("Railgun", Action::attack, 40, "Pium, pium"),
        Card("Guard", Action::defend, 5, "Block, block"),
        Card("Normal block", Action::defend, 2, "Just a normal block"), 
        Card("Diamond armor", Action::defend, 10, "The toughest of armors"),
        Card("Energy barrier", Action::defend, 8, "Buzzzz"),
        Card("Armor Lock", Action::defend, 6, "Activate armor lock!"),
        Card("Estus flask", Action::heal, 20, "Illusory wall ahead"), 
        Card("Heal", Action::heal, 10, "Heals"),
        Card("Golden apple", Action::heal, 15, "Munch munch munch"), 
        Card("A Good Night of Sleep", Action::heal, 30, "Zzzzz"), 
        Card("Regen", Action::heal, 5, "Regeneration")
    };

    clear_scr();

    Player player(ask_for_players_name());

    print_instructions();

    press_enter_to_continue();
    clear_scr();

    // Generación de números aleatorios
    std::mt19937 gen;
    std::random_device rd;
    gen.seed(rd());
    std::uniform_int_distribution<> intDist(0, 14);

    // Asignar aleatoriamente cartas del banco de cartas al jugador
    assign_card(player, card_pool, intDist(gen));
    assign_card(player, card_pool, intDist(gen));
    assign_card(player, card_pool, intDist(gen));
    assign_card(player, card_pool, intDist(gen));

    // Mostrar al jugador su mazo 
    print_cool("Your deck is as follows: ");
    for(int i = 0; i < 4; i++) {
        std::cout << "----------------------------------------------\n\n";
        std::cout << player.get_deck().get_card(i).display();
        std::cout << "\n";
    }

    std::cout << "----------------------------------------------\n";

    press_enter_to_continue();
    clear_scr();

    // Primer enfrentamiento
    Bot bot1("Sephiroth", 150, 20);

    print_cool("Your first opponent is " + bot1.get_name());

    press_enter_to_continue();

    while(bot1.get_health() > 0) {
        clear_scr();
        bot1.stats();
        player.stats();
        int input = select_card(player);
        player.play_card(input, bot1);
        if(bot1.get_health() > 0) {
        player.take_damage(bot1.attack());
        }
        if(player.get_health() <= 0) {
            print_cool("\nGAME OVER");
            return 0;
        }
    }

    print_cool("CONGRATULATIONS. You defeated " + bot1.get_name());

    Bot bot2("GLaDOS", 10, 250);

    while(bot2.get_health() > 0) {
        clear_scr();
        bot2.stats();
        player.stats();
        int input = select_card(player);
        player.play_card(input, bot2);
        if(bot2.get_health() > 0) {
            player.take_damage(bot2.attack());
        }
        if(player.get_health() <= 0) {
            print_cool("\n GAME OVER");
            return 0;
        }
    }

    print_cool("CONGRATULATIONS. You defeated " + bot2.get_name());

    Bot bot3("Ornstein and Smough", 50, 300);

    while(bot3.get_health() > 0) {
        clear_scr();
        bot3.stats();
        player.stats();
        int input = select_card(player);
        player.play_card(input, bot3);
        if(bot2.get_health() > 0) {
            player.take_damage(bot3.attack());
        }
        if(player.get_health() <= 0) {
            print_cool("\n GAME OVER");
            return 0;
        }
    }


    print_cool("CONGRATULATIONS. You defeated " + bot3.get_name());

    Bot bot4("Sans", 50, 1);

    while(bot4.get_health() > 0) {
        clear_scr();
        bot4.stats();
        player.stats();
        int input = select_card(player);
        player.play_card(input, bot4);
        if(bot2.get_health() > 0) {
            player.take_damage(bot4.attack());
        }
        if(player.get_health() <= 0) {
            print_cool("\n GAME OVER");
            return 0;
        }
    }

    print_cool("CONGRATULATIONS. You defeated " + bot4.get_name());

    print_cool("VICTORY");
    return 0;
}
#include <iostream>
#include <string>
#include "character.h"
#include "hero.h"
#include "attack.h"
#include "enemy.h"
using std::cout;
using std::cin;

void print_stats(Hero player) {
    cout << player.get_name() << " stats: \n";
    cout << "Health: " << player.get_max_hp() << std::endl;
    cout << "Stamina: " << player.get_max_stamina() << std::endl;
    cout << "Damage Multiplier: " << player.get_damage_mult() << std::endl;
    cout << "Unlocked Attacks: " <<  player.get_total_attacks_quantity() 
    << std::endl;
    cout << "Gold: " << player.get_gold() << std::endl;
}

void print_enemy_stats(Enemy enemy) {
    cout << "Health: " << enemy.get_max_hp() << std::endl;
    cout << "Damage: " << enemy.get_damage() << std::endl;
}

std::string ask_for_name() {
    std::string player_name;
    cout << "Choose your character name: ";
    cin >> player_name;
    return player_name;
}

int main() {
    Hero player(ask_for_name());
    print_stats(player);

    Enemy ogre(100, 20);
    Enemy mage(60, 35);
    Enemy skeleton(40, 22);

    cout << "\nOgre stats:\n";
    print_enemy_stats(ogre);
    cout << "\nMage stast:\n";
    print_enemy_stats(mage);
    cout << "\nSkeleton stats:\n";
    print_enemy_stats(skeleton);
}
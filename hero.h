#pragma once

#include "character.h"
#include <string>
#include "attack.h"
#include <vector>
using std::string;

class Hero : public Character {
    private:
        string name;
        std::vector<Attack> attacks;
        // std::vector<Item> items;
        int max_stamina;
        int current_stamina;
        int gold;
        double mult_damage;

    public:
        Hero();
        Hero(string n);
        void set_name(string s);
        string get_name();
        void add_attack(Attack a);
        Attack get_attack(int n);
        int get_total_attacks_quantity();
        // void add_item(Item);
        // Item get_item(int n);
        void set_max_stamina(int n);
        int get_max_stamina();
        void set_current_stamina(int n);
        int get_current_stamina();
        void increase_max_stamina(int n);
        void decrease_current_stamina(int n);
        void set_gold(int n);
        int get_gold();
        void add_gold(int n);
        void set_damage_mult(double d);
        void increase_damage_mult(double d);
        double get_damage_mult();
        int deal_damage();
};

Hero::Hero() {
    name = "";
    max_stamina = 20;
    current_stamina = 20;
    gold = 0;
    mult_damage = 1.0;
    set_max_hp(20);
    set_current_hp(20);
    set_level(1);
}

Hero::Hero(string n) {
    name = n;
    max_stamina = 20;
    current_stamina = 20;
    gold = 0;
    mult_damage = 1.0;
    set_max_hp(20);
    set_current_hp(20);
    set_level(1);
}

void Hero::set_name(string s) {
    name = s;
}

string Hero::get_name() {
    return name;
}

void Hero::add_attack(Attack a) {
    attacks.push_back(a);
}

Attack Hero::get_attack(int n) {
    return attacks[n];
}

int Hero::get_total_attacks_quantity() {
    return static_cast<int>(attacks.size());
}

void Hero::set_max_stamina(int n) {
    max_stamina = n;
}

int Hero::get_max_stamina() {
    return max_stamina;
}

void Hero::set_current_stamina(int n) {
    current_stamina = n;
}

int Hero::get_current_stamina() {
    return current_stamina;
}

void Hero::increase_max_stamina(int n) {
    max_stamina += n;
}

void Hero::decrease_current_stamina(int n) {
    current_stamina -= n;
}

void Hero::set_gold(int n) {
    gold = n;
}

int Hero::get_gold() {
    return gold;
}

void Hero::add_gold(int n) {
    gold += n;
}

void Hero::set_damage_mult(double d) {
    mult_damage = d;
}

void Hero::increase_damage_mult(double d) {
    mult_damage += d;
}

double Hero::get_damage_mult() {
    return mult_damage;
}


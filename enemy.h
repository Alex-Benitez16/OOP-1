#pragma once

#include "character.h"

class Enemy : public Character {
    private:
        int damage;
    
    public:
        Enemy();
        Enemy(int hp, int d);
        void set_damage(int n);
        int get_damage();
};

Enemy::Enemy() {
    damage = 0;
    set_max_hp(100);
    set_current_hp(100);
}

Enemy::Enemy(int hp, int d) {
    damage = d;
    set_max_hp(hp);
    set_current_hp(hp);
}

void Enemy::set_damage(int n) {
    damage = n;
}

int Enemy::get_damage() {
    return damage;
}
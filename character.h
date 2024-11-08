#pragma once

class Character {
    private:
        int max_hp;
        int current_hp;
        int level;
    public:
        Character() : max_hp(0), current_hp(0), level(1){};
        void set_max_hp(int n);
        int get_max_hp();
        void set_current_hp(int n);
        int get_current_hp();
        void set_level(int n);
        int get_level();
};

void Character::set_max_hp(int n) {
    max_hp = n;
}

int Character::get_max_hp() {
    return max_hp;
}

void Character::set_current_hp(int n) {
    current_hp = n;
}

int Character::get_current_hp() {
    return current_hp;
}

void Character::set_level(int n) {
    level = n;
}

int Character::get_level() {
    return level;
}
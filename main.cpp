#include "card.h"
#include "character.h"
#include "deck.h"

int main() {
    Character player("Player_1");
    Card fireball("Fireball", 20, Card::Action::attack, 10);
    Card greatheal("Great Heal", 40, Card::Action::heal, 50);
    Card shield("Shield", 10, Card::Action::defend, 15);
    Card quickslash("Quick Slash", 0, Card::Action::attack, 5);

    player.get_default_deck().add_card(fireball);
    player.get_default_deck().add_card(greatheal);
    player.get_default_deck().add_card(shield);
    player.get_default_deck().add_card(quickslash);

    player.get_default_deck().to_string();

    player.get_default_deck().get_card(0).display();
    player.get_default_deck().get_card(1).display();
    player.get_default_deck().get_card(2).display();
    player.get_default_deck().get_card(3).display();
}
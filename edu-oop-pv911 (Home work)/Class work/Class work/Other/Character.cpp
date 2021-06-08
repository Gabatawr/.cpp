#include "Character.h"

gab::Character* gab::Character::get(int hp, int damage, Type T)
{
	if (T == warrior) return new Warrior(hp, damage);
	if (T == archer)  return new Arch(hp, damage);
	if (T == wizard)  return new Wizard(hp, damage);
	if (T == skull)   return new Skull(hp, damage);
	if (T == ork)     return new Ork(hp, damage);
					  return new Troll(hp, damage);
}

int  gab::Character::make_damage()           { return damage_; }
void gab::Character::take_damage(int damage) { hp_ -= damage; }

int  gab::Character::death()                 { return gold_; }

int  gab::Character::get_hp()                { return hp_; }
bool gab::Character::get_side()              { return side_; }


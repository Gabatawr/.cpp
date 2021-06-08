#pragma once
namespace gab
{

	enum Type { warrior, archer, wizard, skull, ork, troll };

	class Character
	{
	protected:
		int hp_;
		int damage_;
		int gold_;
		bool side_;
		
		Character(int hp, int damage, int gold, bool side) : hp_(hp), damage_(damage), gold_(gold), side_(side) {}
		
	public:
		static Character* get(int hp, int damage, Type T);
		
		virtual int  make_damage();
		virtual void take_damage(int);
		
		virtual int  death();
		
		virtual int  get_hp();
		virtual bool get_side();
		
		virtual ~Character() = default;
	};

	class Warrior : public Character
	{
	public:
		Warrior(int hp, int damage) : Character(hp, damage, hp + damage / 2 , 1) {}
	};
	class Arch : public Character
	{
	public:
		Arch(int hp, int damage) : Character(hp, damage, hp + damage / 2, 1) {}
	};
	class Wizard : public Character
	{
	public:
		Wizard(int hp, int damage) : Character(hp, damage, hp + damage / 2, 1) {}
	};

	class Skull : public Character
	{
	public:
		Skull(int hp, int damage) : Character(hp, damage, hp + damage / 2, 0) {}
	};
	class Ork : public Character
	{
	public:
		Ork(int hp, int damage) : Character(hp, damage, hp + damage / 2, 0) {}
	};
	class Troll : public Character
	{
	public:
		Troll(int hp, int damage) : Character(hp, damage, hp + damage / 2, 0) {}
	};

}
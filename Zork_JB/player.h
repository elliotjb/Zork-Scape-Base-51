#ifndef _Player_
#define _Player_

#include "Criature.h"
#include "Room.h"
#include "Item.h"

class Player:public Criature
{
public:
	Player(const char* name, const char* description, int hp, int attack, int coins);
	~Player();

	TYPE type;
	Room* position;
	Vector<Item*>inv;

	void Move(Vector<ClString> &);
	void Look() const;
	void Look_inventory() const;
	void Look_item(Vector<ClString> &) const;
	void Open();
	void Close();
	void Pick_item(Vector<ClString> &);
	void Drop_item(Vector<ClString> &);
	void Equip(Vector<ClString> &);
	void UnEquip(Vector<ClString> &);
	void Put_into(Vector<ClString> &);
	void Get_from(Vector<ClString> &);
	void Stats()const;
	void Attack(Vector<ClString> &);
	void Buy_list();
	void Sell_to(Vector<ClString> &);
	void Buy_from(Vector<ClString> &);
	void Shoot_attack();
	//void Look_Specify_Position() const;
};

#endif


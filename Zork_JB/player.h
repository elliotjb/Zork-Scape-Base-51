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
	int hp = 1;
	int attack=0;
	int coins=0;

	void Move(const Vector<ClString> &);
	void Look() const;
	void Look_inventory() const;
	void Look_item(Vector<ClString> &) const;
	void Open();
	void Close();
	void Pick_item(Vector<ClString> &);
	void Drop_item(Vector<ClString> &);
	/*void Look_Specify_Position() const;
	void Move();
	void Open();
	void Close();

	void Equip(Vector<ClString> &);
	void UnEquip(Vector<ClString> &);
	void Stats()const;
	void Put_into(Vector<ClString> &);
	void Get_from(Vector<ClString> &);*/
};

#endif


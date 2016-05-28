#ifndef _ALIEN_H_
#define _ALIEN_H_

#include "Criature.h"
#include "Room.h"
#include "Item.h"

class Alien:public Criature
{
public:
	Alien(const char* name, const char* description, int hp, int attack, int coins);
	~Alien();

	TYPE type;
	Room* position;
	Vector<Item*>inv;

	void Move(const int dir);
	void Attack();
	void Dead();
	void Update();
	void Revive();

	/*void Look() const;
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
	void Stats()const;*/
	//void Look_Specify_Position() const;

};

#endif


#ifndef _CRIATURE_H_
#define _CRIATURE_H_

#include "Entity.h"
#include "Room.h"
#include "Item.h"

class Criature :public Entity
{
public:
	Criature();
	Criature(const char* name, const char* description, int hp, int attack, int coins);
	~Criature();


	Item* haveitem;
	Room* position;
	
	int hp;
	int attack;
	int coins;

	virtual void Move(const Vector<ClString> &){};
	virtual void Look() const{};
	virtual void Look_inventory() const{};
	virtual void Look_item(Vector<ClString> &) const{};
	virtual void Open(){};
	virtual void Close(){};
	virtual void Pick_item(Vector<ClString> &){};
	virtual void Drop_item(Vector<ClString> &){};
	virtual void Equip(Vector<ClString> &){};
	virtual void UnEquip(Vector<ClString> &){};
	virtual void Stats()const{};
	virtual void Put_into(Vector<ClString> &){};
	virtual void Get_from(Vector<ClString> &){};
	virtual void Attack(Vector<ClString> &){};
};




#endif
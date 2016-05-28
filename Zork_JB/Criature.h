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
	virtual void Move(const Vector<ClString> &) = 0;
	virtual void Look() const = 0;
	virtual void Look_inventory() const = 0;
	virtual void Look_item(Vector<ClString> &) const = 0;
	virtual void Open() = 0;
	virtual void Close() = 0;
	virtual void Pick_item(Vector<ClString> &) = 0;
	virtual void Drop_item(Vector<ClString> &) = 0;
	virtual void Equip(Vector<ClString> &) = 0;
	virtual void UnEquip(Vector<ClString> &) = 0;
	virtual void Stats()const = 0;
	virtual void Put_into(Vector<ClString> &) = 0;
	virtual void Get_from(Vector<ClString> &) = 0;
	//virtual void Look_Specify_Position() const = 0;



};




#endif
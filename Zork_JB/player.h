#ifndef _Player_
#define _Player_

#include "Entity.h"
#include "Room.h"
#include "Item.h"


class Criature:public Entity
{
public:
	Criature();
	Criature(const char* name, const char* description, TYPE type, int hp, int attack, int coins);
	~Criature();

	TYPE type;
	Item* haveitem;
	Room* position;

	int hp;
	int attack;
	int coins;

	/*virtual void Look_item(Vector<ClString> &) const = 0;
	virtual void Look() const = 0;
	virtual void Look_inventory() const = 0;
	virtual void Look_Specify_Position() const = 0;
	virtual void Move() = 0;
	virtual void Open() = 0;
	virtual void Close() = 0;
	virtual void Pick_item(Vector<ClString> &) = 0;
	virtual void Drop_item(Vector<ClString> &) = 0;
	virtual void Equip(Vector<ClString> &) = 0;
	virtual void UnEquip(Vector<ClString> &) = 0;
	virtual void Stats()const = 0;
	virtual void Put_into(Vector<ClString> &) = 0;
	virtual void Get_from(Vector<ClString> &) = 0;*/


};


class Player:public Criature
{
public:
	Player();
	Player(const char* name, const char* description, TYPE type, int hp, int attack, int coins);
	~Player();

	TYPE type;
	Room* position;
	int hp;
	int attack;
	int coins;

	/*void Look_item(Vector<ClString> &) const;
	void Look() const;
	void Look_inventory() const;
	void Look_Specify_Position() const;
	void Move();
	void Open();
	void Close();
	void Pick_item(Vector<ClString> &);
	void Drop_item(Vector<ClString> &);
	void Equip(Vector<ClString> &);
	void UnEquip(Vector<ClString> &);
	void Stats()const;
	void Put_into(Vector<ClString> &);
	void Get_from(Vector<ClString> &);*/
};

#endif


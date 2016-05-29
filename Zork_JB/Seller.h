#ifndef _SELLER_H_
#define _SELLER_H_

#include "Criature.h"
#include "Room.h"
#include "Item.h"

class Seller :public Criature
{
public:
	Seller(const char* name, const char* description, int hp, int attack, int coins);
	~Seller();

	TYPE type;
	Room* position;
	Vector<Item*>inv;

	void Update();

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


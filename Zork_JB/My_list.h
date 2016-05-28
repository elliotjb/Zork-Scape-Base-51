#ifndef _DLIST_H_
#define _DLIST_H_

typedef unsigned int uint;
template <class TYPE>
class DList
{
public:
	struct Node
	{
	public:
		TYPE data;
		Node* next = nullptr;
		Node* prev = nullptr;

	public:
		Node(const TYPE &data) : data(data)
		{}
		~Node(){}
	};
	Node* first = nullptr;

public:

	DList(){}
	~DList(){}

	uint size()
	{
		uint con = 0;
		Node* temp = first;
		while (temp != nullptr)
		{
			con++;
			temp = temp->next;
		}
		return con;
	}

	bool empty() const
	{
		return first == nullptr;
	}

	Node* end()
	{
		Node* temp = first;
		if (temp != nullptr)
		{
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
		}
		return temp;
	}

	void push_back(const TYPE &data)
	{
		Node* last = first;
		Node* temp = new Node(data);
		if (last == nullptr)
		{
			first = temp;
		}
		else
		{
			while (last->next != nullptr)
			{
				last = last->next;
			}
			last->next = temp;
			temp->prev = last;
		}
	}

	void push_front(const TYPE &data)
	{
		Node* temp = first;
		Node* new_node = new Node(data);
		if (temp != nullptr)
		{
			new_node->next = first;
			first->prev = new_node;
		}
		first_data = new_node;
	}

	void pop_back()
	{
		if (first != nullptr)
		{
			if (first->next != nullptr)
			{
				Node* temp = first;
				Node* other_temp = first;
				while (temp->next != nullptr)
				{
					temp = temp->next;
				}
				while (other_temp->next != temp)
				{
					other_temp = other_temp->next;
				}
				other_temp->next = nullptr;
				delete temp;
			}
			else
			{
				Node* temp = first;
				first = nullptr;
				delete temp;
			}
		}
	}


	void pop_front()
	{
		if (temp != nullptr)
		{
			Node* temp = first;
			first = temp->next;
			first->prev = nullptr;
			delete temp;
		}
	}

	void erase(Node* data)
	{
		if (size() > 1)
		{
			if (data->prev == nullptr)
			{
				first = data->next;
				first->prev = nullptr;
			}

			else if (data->next == nullptr)
			{
				data->prev->next = nullptr;
			}

			else
			{
				data->prev->next = data->next;
				data->next->prev = data->prev;
			}
			delete data;
		}
		else
		{
			first = nullptr;
			delete data;
		}
	}

	void insert(Node* pos, const TYPE &data)
	{
		Node* temp = pos;
		Node* new_node = new Node(data);
		if (temp != nullptr)
		{
			new_node->next = temp;
			new_node->prev = temp->prev;
			temp->prev->next = new_node;
		}
		else
		{
			first = new_node;
		}
	}
};


#endif //_DLIST_H_
#pragma once
using namespace std;

struct Node
{
	int key;
	char* value;
};

class HashTable
{
private:
	Node* m_Node;

public:
	HashTable();
	HashTable(const HashTable& ht);
	~HashTable();
};


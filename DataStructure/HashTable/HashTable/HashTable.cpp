#include "HashTable.h"

HashTable::HashTable() : m_Node(nullptr)
{

}

HashTable::HashTable(const HashTable& ht)
{
	int nodeLen = 0;

	while (m_Node != nullptr)
	{
		m_Node++;
		nodeLen++;
	}

	m_Node = new Node[nodeLen];
}

HashTable::~HashTable()
{
	delete[] m_Node;
}

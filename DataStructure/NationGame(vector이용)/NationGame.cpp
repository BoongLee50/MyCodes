#include"NationGame.h"
#include<process.h>


NationGame::NationGame()
{
	Nation country[] = { Nation("�ѱ�","����"), Nation("�̱�","������DC"),Nation("�߱�","����¡"),Nation("�Ϻ�","����"),
		Nation("ĳ����","��Ÿ��"),Nation("ȣ��","ĵ����"),Nation("����","����"),Nation("���þ�","��ũ��"),Nation("����","���") };
	for (int i = 0; i < 9; i++)
	{
		v.push_back(country[i]);
	}
}

void NationGame::run()
{
	cout << "**** ������ ���� ���߱� ������ �����մϴ�. ****" << endl;
	while (true)
	{
		cout << "���� �Է�:1, ����:2, ����:3 >>";
		int num;
		cin >> num;
		switch (num)
		{
		case 1: input(); break;
		case 2: quiz(); break;
		case 3: exit(); return;
		}
	}
}

bool NationGame::compare(string nation)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].getNation() == nation)
			return true;
	}
	return false;
}

void NationGame::input()
{
	string nation, capital;
	cout << "���� " << v.size() << "���� ���� �ԷµǾ� �ֽ��ϴ�." << endl;
	cout << "����� ������ �Է��ϼ���. (no no �� �Է� ��)" << endl;
	while (true)
	{
		cout << v.size() + 1 << ">>";
		cin >> nation >> capital;
		if (nation == "no" && capital == "no") break;

		if (compare(nation))
		{
			cout << "�̹� �Էµ� �����Դϴ�." << endl;
			cout << "�ٸ� ������ �Է��Ͽ� �ּ���." << endl;
		}

		Nation country(nation, capital);
		v.push_back(country);
	}
	return;
}

void NationGame::quiz()
{
	while (true)
	{
		int address = rand() % v.size();
		cout << v[address].getNation() << " ������?(exit�� �Է��Ͻø� ��� �����ϴ�)";
		string capital;
		cin >> capital;
		if (capital == "exit")
			return;

		if (v[address].getCapital() == capital)
			cout << "������ϴ�!!" << endl;
		else
			cout << "Ʋ���̽��ϴ�..." << endl;
	}
}

void NationGame::exit()
{
	return;
}
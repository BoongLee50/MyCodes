#include"NationGame.h"
#include<process.h>


NationGame::NationGame()
{
	Nation country[] = { Nation("한국","서울"), Nation("미국","워싱턴DC"),Nation("중국","베이징"),Nation("일본","도쿄"),
		Nation("캐나다","오타와"),Nation("호주","캔버라"),Nation("영국","런던"),Nation("러시아","모스크바"),Nation("북한","평양") };
	for (int i = 0; i < 9; i++)
	{
		v.push_back(country[i]);
	}
}

void NationGame::run()
{
	cout << "**** 나라의 수도 맞추기 게임을 시작합니다. ****" << endl;
	while (true)
	{
		cout << "정보 입력:1, 퀴즈:2, 종료:3 >>";
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
	cout << "현재 " << v.size() << "개의 나라가 입력되어 있습니다." << endl;
	cout << "나라와 수도를 입력하세요. (no no 면 입력 끝)" << endl;
	while (true)
	{
		cout << v.size() + 1 << ">>";
		cin >> nation >> capital;
		if (nation == "no" && capital == "no") break;

		if (compare(nation))
		{
			cout << "이미 입력된 수도입니다." << endl;
			cout << "다른 수도를 입력하여 주세요." << endl;
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
		cout << v[address].getNation() << " 수도는?(exit를 입력하시면 퀴즈가 끝납니다)";
		string capital;
		cin >> capital;
		if (capital == "exit")
			return;

		if (v[address].getCapital() == capital)
			cout << "맞췄습니다!!" << endl;
		else
			cout << "틀리셨습니다..." << endl;
	}
}

void NationGame::exit()
{
	return;
}
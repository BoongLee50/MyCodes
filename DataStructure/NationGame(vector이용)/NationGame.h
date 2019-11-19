#ifndef NATIONGAME_H
#define NATIONGAME_H
#include"Nation.h"
class NationGame
{
	vector<Nation>v;
public:
	NationGame();
	void run();
	void input();
	void quiz();
	bool compare(string nation);
	void exit();
};

#endif // !NATION_H
#include"GraphicEditor.h"

static int token = 0;

GraphicEditor::GraphicEditor()
{
	
}

void GraphicEditor::run()
{
	cout << "그래픽 에디터입니다." << endl;
	while (true)
	{
		int num;
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >>";
		cin >> num;
		switch (num)
		{
		case 1: input(); break;
		case 2: remove(); break;
		case 3: list(); break;
		case 4: exit(); return;
		}
	}
}

void GraphicEditor::input()
{
	int num;
	cout << "선:1, 원:2, 사각형:3>>";
	cin >> num;
	if (token == 0)
	{
		switch (num)
		{
		case 1: pStart = new Line(); break;
		case 2: pStart = new Circle(); break;
		case 3: pStart = new Rect(); break;
		}
		pEnd = pStart;
	}
	else
	{
		switch (num)
		{
		case 1: pEnd = pEnd->add(new Line()); break;
		case 2: pEnd = pEnd->add(new Circle()); break;
		case 3: pEnd = pEnd->add(new Rect()); break;
		}
	}
	token++;
}

void GraphicEditor::remove()
{
	int index;
	cout << "삭제하고자 하는 도형의 인덱스>>";
	cin >> index;
	p = pStart;
	if (index == 0)
	{
		pStart = p->getNext();
		token--;
	}
	else if (index <= (token - 1))
	{
		Shape *prev = p;
		Shape *node = p->getNext();
		int num = index;
		while (index!=1)
		{
			prev = node;
			node = node->getNext();
			index--;
		}
		prev->setNext(node);
		token--;
		if (token == 1)
			pEnd = pStart;
		if (token == num)
			pEnd = prev;
		delete node;
	}
}

void GraphicEditor::list()
{
	p = pStart;

	for (int i = 0; p != NULL; i++)
	{
		cout << i << ":";
		p->paint();
		p = p->getNext();
	}
}

void GraphicEditor::exit()
{
	cout << "프로그램을 종료합니다." << endl;
	return;
}
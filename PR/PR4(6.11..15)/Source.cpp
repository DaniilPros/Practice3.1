#include<iostream>
#include<string>
#include<vector>
#include<conio.h>
#include<cstdlib>
using namespace std;

struct Catalogue {
	string title;
	Catalogue* prior;
	vector<Catalogue*> catalogues;
};

void Delete(vector<Catalogue*> &v,int index);
void Delete(vector<Catalogue*> &v);
Catalogue* Init(Catalogue& catalogue_prior);
void menu(vector<Catalogue*>& v, Catalogue& c);
void ShowMenu();
void ShowCatalogues(vector<Catalogue*>& v);
void ShowTree(Catalogue* c, int level);
void OutputTab(int time);
void Exit();
void Open(vector<Catalogue*>& v, Catalogue& c);
void Create(vector<Catalogue*>& v, Catalogue& c);
void ShowTree(vector<Catalogue*>& v);

int main()
{
	vector<Catalogue*> catalogues(1);
	Catalogue*c = new Catalogue;
	c->title = "home";
	c->prior =nullptr;
	catalogues[0] = c;
	menu(catalogues,*catalogues[0]);
	system("pause");
	return 0;
}

void Delete(vector<Catalogue*>& v,int j)
{
	if (v.size() == 0) return;
		for (int i = 0; i < v.at(j)->catalogues.size(); i++)
			Delete(v.at(j)->catalogues, 0);
		delete v.at(j);
}

Catalogue* Init(Catalogue& catalog)
{
	Catalogue* c=new Catalogue;
	cout << "Input title: ";
	cin >> c->title;
	c->prior = &catalog;
	return c;
}

void menu(vector<Catalogue*>& v,Catalogue& c)
{
	ShowCatalogues(v);
	ShowMenu();
	bool back = false;
	while (!back)
	{
		switch (_getch())
		{
		case '1':
			Open(v,c);
			ShowCatalogues(v);
			ShowMenu();
			break;
		case '2':
			Create(v, c);
			ShowCatalogues(v);
			ShowMenu();
			break;
		case '3':
			Delete(v);
			ShowCatalogues(v);
			ShowMenu();
			break;
		case'4':
			if(v.size()>0)
				back = v[0]->prior == nullptr ? false : true;
			back = true;
			break;
		case '5':
			ShowTree(v);
			break;
		case '6':
			Exit();
			ShowCatalogues(v);
			ShowMenu();
			break;
		default:
			break;
		}
	}
}

void ShowMenu()
{
	cout << "\n\n1.Open catalogue\n2.Create Catalogue\n3.Delete Catalogue\n4.Back\n5.Show Tree of catalogue\n6.Exit\n";
}

void ShowCatalogues(vector<Catalogue*>& v)
{
	system("cls");
	for (int i = 0; i < v.size(); i++)
	{
		cout << i+1 << "." << v[i]->title << " ";
	}
}

void ShowTree(Catalogue* c, int level)
{
	OutputTab(level);
	cout << c->title << endl;
	for (auto& i : c->catalogues)
	{
		ShowTree(i, level + 1);
	}
}

void OutputTab(int time)
{
	for (int i = 0; i <= time; i++)
	{
		cout << "\t";
	}
}

void Exit()
{
	cout << "\nAre you shure?(\"Yes\"-\"1\")\n";
	switch (_getch())
	{
	case '1':
		exit(0);
	default:
		system("cls");
	}
}

void Open(vector<Catalogue*>& v, Catalogue& c)
{
	char index;
	int i;
	cout << "Which catalogue (Press number of catalogue):\n";
	index=_getch();
	i = atoi(&index);
	if (i != NULL)
	if (i <=v.size())
		menu(v[i-1]->catalogues,c);
	else {
		cout << "Error. Try again.\nPress any keys...";
		_getch();
	}
}

void Create(vector<Catalogue*>& v, Catalogue& c)
{
	v.push_back(Init(c));
}

void Delete(vector<Catalogue*> &v)
{
	char index;
	int i;
	cout << "Which catalogue (Press number of catalogue):\n";
	index = _getch();
	i = atoi(&index);
	if(i!=NULL)
		if (i <= v.size()) {
			Delete(v, i-1);
			v.erase(v.begin()+i-1);
		}
	else {
		cout << "Error. Try again.\nPress any keys...";
		_getch();
	}
}

void ShowTree(vector<Catalogue*>& v)
{
	system("cls");
	for (auto& i : v)
	{
		ShowTree(i, 0);
	}
	cout << "\nPress any keys...";
	_getch();
	ShowCatalogues(v);
	ShowMenu();
}
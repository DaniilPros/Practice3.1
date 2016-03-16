#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<conio.h>
#include<cstdlib>
using namespace std;

struct CellPhone {
	string model, 
		producer, 
		form_factor, 
		type_of_network,
		model_year, 
		count_of_cards, 
		price;
};
vector<int> index;

void Show(vector<CellPhone> phones);
CellPhone Input();
int Search(vector <CellPhone> phones);
int Sort(vector <CellPhone> phones);
void SearchP(vector <CellPhone> phones);
void SortP(vector <CellPhone> phones);
void SearchT(vector <CellPhone> phones);
void SortT(vector <CellPhone> phones);
void SearchC(vector <CellPhone> phones);
void SortC(vector <CellPhone> phones);

vector<CellPhone> ReadFromFile();
void WriteToFile(vector<CellPhone> phones);
int menu();

int main()
{
	menu();
	return 0;
}

vector<CellPhone> ReadFromFile()
{
	string line;
	vector<CellPhone> phones;
	ifstream file;
	CellPhone phone;
	file.open("phones.txt");
	while (!file.eof())
	{
		getline(file, line);
		phone.model = line;
		getline(file, line);
		phone.producer = line;
		getline(file, line);
		phone.model_year = line;
		getline(file, line);
		phone.form_factor = line;
		getline(file, line);
		phone.type_of_network = line;
		getline(file, line);
		phone.count_of_cards = line;
		getline(file, line);
		phone.price = line;
		phones.push_back(phone);
	}
	file.close();
	if(phones[phones.size()-1].model=="")
	phones.pop_back();
	return phones;
}

void WriteToFile(vector<CellPhone> phones)
{
	ofstream file;
	file.open("phones.txt");
	for (auto& i : phones)
	{
		file << i.model << endl
			<< i.producer << endl
			<< i.model_year << endl
			<< i.form_factor << endl
			<< i.type_of_network << endl
			<< i.count_of_cards << endl
			<< i.price << endl;
	}
	file.close();
}

void Show(vector<CellPhone> phones)
{
	system("cls");
	//cout << "Model" << "\tProducer" << "\tModel_year" << "\tForm factor" << "\tType of network" << "\tCount of cards" << "\tPrice\n";
	for (auto& i : index)
	{
		cout << "Model: " << phones[i].model
			<< "\tProducer: "<< phones[i].producer
			<< "\tModel_year: "<< phones[i].model_year
			<< "\tForm factor: " << phones[i].form_factor
			<< "\tType of network: "<< phones[i].type_of_network
			<< "\tCount of cards: " << phones[i].count_of_cards
			<< "\tPrice: " << phones[i].price << "\n";
	}
}

int menu()
{
	vector <CellPhone> phones;
	cout << "1.Add phone\n2.Read from file\n3.Write to file\n4.Show catalog\n5.Exit\n";
	while (true)
	{
		switch (_getch()) {
		case '1':
			phones.push_back(Input());
			index.push_back(phones.size() - 1);
			system("cls");
			cout << "1.Add phone\n2.Read from file\n3.Write to file\n4.Show catalog\n5.Exit\n";
			break;
		case '2':
			phones=ReadFromFile();
			index.clear();
			for (int i = 0; i < phones.size(); i++)
			{
				index.push_back(i);
			}
			cout << "Read\n";
			break;
		case '3':
			
			WriteToFile(phones);
			cout << "Wrote\n";
			break;
		case '5':
			return 0;
		default:
			break;
		case '4':
			
			Show(phones);
			cout << "1.Sort\n2.Search\n3.Exit\n";
			int t = 10;
			while (t!=3)
			{
				t=_getch();
				switch (t)
				{
				case '1':
					Sort(phones);
					system("cls");
					Show(phones);
					cout << "1.Sort\n2.Search\n3.Exit\n";
					break;
				case '2':
					Search(phones);
					system("cls");
					Show(phones);
					cout << "1.Sort\n2.Search\n3.Exit\n";
					break;
				case '3':
					t = 3;
					break;
				default:
					break;
				}
			}
			system("cls");
			cout << "1.Add phone\n2.Read from file\n3.Write to file\n4.Show catalog\n5.Exit\n";
			break;
		
		}

	}
	return 0;
}

CellPhone Input()
{
	
	CellPhone phone;
	
		cout << "Input model:\n";
		cin >> phone.model;
		cout << "Input producer:\n";
		cin >> phone.producer;
		cout << "Input model_year:\n";
		cin >> phone.model_year;
		cout << "Input form factor:\n";
		cin >> phone.form_factor;
		cout << "Input type of network:\n";
		cin >> phone.type_of_network;
		cout << "Input count of cards:\n";
		cin >> phone.count_of_cards;
		cout << "Input price:\n";
		cin >> phone.price;
		return phone;
}

int Search(vector <CellPhone> phones)
{
	cout << "1.by producer\n2.by type of network\n3.by count of cards\n";
	
	while (true)
	{
		
		switch (_getch())
		{
		case '1':
			SearchP(phones);
			return 0;
			break;
		case '2':
			SearchT(phones);
			return 0;
			break;
		case '3':
			SearchC(phones);
			return 0;
			break;
		default:
			break;
		}
	}
}

int Sort(vector <CellPhone> phones)
{
	cout << "1.by producer\n2.by type of network\n3.by count of cards\n";
	
	while (true)
	{
		switch (_getch())
		{
		case '1':
			SortP(phones);
			return 0;
			break;
		case '2':
			SortT(phones);
			return 0;
			break;
		case '3':
			SortC(phones);
			return 0;
			break;
		default:
			break;
		}
	}
}

void SearchP(vector <CellPhone> phones)
{
	system("cls");
	string s;
	bool f=false;
	cout << "Input producer: ";
	cin >> s;
	for (auto& i : phones)
	{
		if (i.producer == s)
		{
			f = true;
			cout << "Model: " << i.model
				<< "\tProducer: " << i.producer
				<< "\tModel_year: " << i.model_year
				<< "\tForm factor: " << i.form_factor
				<< "\tType of network: " << i.type_of_network
				<< "\tCount of cards: " << i.count_of_cards
				<< "\tPrice: " << i.price << "\n";
		}
	}
	if (!f)
	{
		cout << "No results.\n";
	}
	system("pause");
}

void SortP(vector <CellPhone> phones)
{
	system("cls");
	index.clear();
	for (int i = 0; i < phones.size(); i++)
	{
		index.push_back(i);
	}
	for (int i = 0; i < phones.size();i++)
	{
		for (int j = 0 ; j < phones.size(); j++)
		{
			if (phones[index[i]].producer[0] <= phones[index[j]].producer[0])
			{
				swap(index[i], index[j]);
			}
		}

	}

}

void SearchT(vector <CellPhone> phones)
{
	system("cls");
	string s;
	bool f = false;
	cout << "Input type of network: ";
	cin >> s;
	for (auto& i : phones)
	{
		if (i.type_of_network == s)
		{
			f = true;
			cout << "Model: " << i.model
				<< "\tProducer: " << i.producer
				<< "\tModel_year: " << i.model_year
				<< "\tForm factor: " << i.form_factor
				<< "\tType of network: " << i.type_of_network
				<< "\tCount of cards: " << i.count_of_cards
				<< "\tPrice: " << i.price << "\n";
		}
	}
	if (!f)
	{
		cout << "No results.\n";
	}
	system("pause");
}

void SortT(vector <CellPhone> phones)
{
	system("cls");
	index.clear();
	for (int i = 0; i < phones.size(); i++)
	{
		index.push_back(i);
	}
	for (int i = 0; i < phones.size(); i++)
	{
		for (int j = 0; j < phones.size(); j++)
		{
			if (phones[index[i]].type_of_network[0] <= phones[index[j]].type_of_network[0])
			{
				swap(index[i], index[j]);
			}
		}

	}

}

void SearchC(vector <CellPhone> phones)
{
	system("cls");
	string s;
	bool f = false;
	cout << "Input count of cards: ";
	cin >> s;
	for (auto& i : phones)
	{
		if (i.count_of_cards == s)
		{
			f = true;
			cout << "Model: " << i.model
				<< "\tProducer: " << i.producer
				<< "\tModel_year: " << i.model_year
				<< "\tForm factor: " << i.form_factor
				<< "\tType of network: " << i.type_of_network
				<< "\tCount of cards: " << i.count_of_cards
				<< "\tPrice: " << i.price << "\n";
		}
	}
	if (!f)
	{
		cout << "No results.\n";
	}
	system("pause");
}

void  SortC(vector <CellPhone> phones)
{
	system("cls");
	index.clear();
	for (int i = 0; i < phones.size(); i++)
	{
		index.push_back(i);
	}
	for (int i = 0; i < phones.size(); i++)
	{
		for (int j = 0; j < phones.size(); j++)
		{
			if (phones[index[i]].count_of_cards[0] <= phones[index[j]].count_of_cards[0])
			{
				swap(index[i], index[j]);
			}
		}
	}
}


#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<conio.h>
#include<array>
using namespace std;

struct Item {
	string word;
	pair<int, int> position;
	bool error;
};
struct VItem {
	vector<Item> items;
	string description;
	bool emplace_back(VItem);
	int size();
};

bool VItem::emplace_back(VItem vi)
{
	if (this->description == vi.description|| this->description == "")
	{
		this->description = vi.description;
		//items.emplace_back(vi.items);
		items.insert(items.end(), vi.items.begin(), vi.items.end());
		return true;
	}
	return false;
}
int VItem::size()
{
	return this->items.size();
}
vector<string> ReadFromFile(string name_of_file);
void output(vector<string> vector_of_string);
array <VItem,3> ParserFile(vector<string>, vector<string>, string name_of_file);
bool check(vector<string>, string);
array <VItem,3> ParserLine(vector<string>, vector<string>, string, pair<int, int>);
array <VItem,3> ParserTagAndAttributes(vector<string>, vector<string>, string, pair<int, int>);
Item ParserTag( vector<string>, string, pair<int, int>);
Item ParserAttributes(vector<string>, string, pair<int, int>);
Item ParserAttributsValues(string, pair<int, int>);
string CreateTagsAndAttributesLine(string, int);
array <VItem,3> ParserAttributesAndValue(vector<string>, string, pair<int, int>);
string CutString(string, int, int);
void output(array <VItem,3>);

int main()
{	
	vector<string> attributes = ReadFromFile("Attributes.txt");
	vector<string> tags = ReadFromFile("Tags.txt");
	vector<string> stoper = {" ","=","/","<",">" };
	output(ParserFile(attributes, tags, "File.txt"));
	system("pause");
	return 0;
}

vector<string> ReadFromFile(string name_of_file)
{
	vector<string> s;
	string line;
	ifstream file;
	file.open(name_of_file);
	while (!file.eof())
	{
		getline(file, line);
		s.push_back(line);
	}
	file.close();
	return s;
}

void output(vector<string> vs)
{
	for (auto& i : vs)
	{
		cout << i << endl;
	}
}

array <VItem,3> ParserFile(vector<string> atts, vector<string> tags,string nf) {
	vector<string> s;
	array <VItem,3> lex,temp;
	string line;
	ifstream file;
	file.open(nf);
	int count_of_line=1;
	while (!file.eof())
	{
		getline(file, line);
		temp=ParserLine(atts, tags, line,make_pair(count_of_line,0));
		lex[0].emplace_back(temp[0]);
		lex[1].emplace_back(temp[1]);
		lex[2].emplace_back(temp[2]);
		count_of_line++;
	}
	file.close();
	return lex;
}

bool check(vector<string> vector, string item)
{
	for (auto& i : vector)
	{
		if (i == item) return true;
	}
	return false;
}

array <VItem,3> ParserLine(vector<string> atts, vector<string> tags, string ss, pair<int, int> pos)
{
	array <VItem,3> lex,temp;
	string s;
	int count=0;
	for (int i = 0; i < ss.size();i++)
	{
		if (ss[i] == '<')
		{
			s = CreateTagsAndAttributesLine(ss, i);
			temp=ParserTagAndAttributes(atts, tags, s, make_pair(pos.first,count));
			lex[0].emplace_back(temp[0]);
			lex[1].emplace_back(temp[1]);
			lex[2].emplace_back(temp[2]);
			count = lex[0].size() + lex[1].size() + lex[2].size();//Calculate count of words in tags in line
			i += s.size();
			s.clear();
		}
	}
	return lex;
}

array <VItem,3> ParserTagAndAttributes(vector<string>atts, vector<string>tags, string ss, pair<int, int> pos)
{
	bool first = false;
	string s;
	array <VItem,3> res, result_att_and_val;
	VItem tag;
	int count=0;
	for (int i = 0; i < ss.size(); i++)
	{
		if (ss[i] == ' '&&!first|| i == ss.size()-1&&!first)
		{
			if (i == ss.size() - 1) s.push_back(ss[i]);
			tag.items.emplace_back(ParserTag(tags, s, make_pair(pos.first, count)));
			tag.description="tag";
			res[0].emplace_back(tag);
			first = true;
			count++;
			s.clear();
		}
		else if (ss[i] == ' '|| i == ss.size() - 1 && first)
		{
			if (i == ss.size() - 1) s.push_back(ss[i]);
			result_att_and_val = ParserAttributesAndValue(atts, s, make_pair(pos.first, count));
			res[1].emplace_back(result_att_and_val[0]);
			res[2].emplace_back(result_att_and_val[1]);
			count += 2;
			s.clear();
		}
		else s.push_back(ss[i]);
	}
	return res;
}

Item ParserTag(vector<string>tags, string ss, pair<int, int> pos)
{
	Item item;
	item.word = ss;
	item.position = pos;
	item.error = check(tags, ss);
	return item;
}

Item ParserAttributes(vector<string> atts, string ss, pair<int, int> pos)
{
	Item item;
	item.word = ss;
	item.position = pos;
	item.error = check(atts, ss);
	return item;
}

string CreateTagsAndAttributesLine(string s, int pos)
{
	string ss;
	for (int i = pos + 1; i < s.size(); i++)
	{
		if (s[i] == '>')
			return ss;
		else 
			ss.push_back(s[i]);
	}
	return NULL;
}

Item ParserAttributsValues(string ss, pair<int, int> pos)
{
	Item item;
	item.word = ss;
	item.position = pos;
	item.error = true;
	return item;
}

array <VItem,3> ParserAttributesAndValue(vector<string> atts, string s, pair<int, int> pos)
{
	string ss;
	array <VItem,3> res;
	VItem att, val;
	int position = s.find('=');
	ss = CutString(s, 0, position);
	att.items.emplace_back(ParserAttributes(atts, ss, make_pair(pos.first, pos.second)));
	att.description = "attribute";
	ss = CutString(s, position + 1, s.size());
	val.items.emplace_back(ParserAttributsValues(ss, make_pair(pos.first, pos.second+1)));
	val.description = "value";
	res[0].emplace_back(att);
	res[1].emplace_back(val);
	return res;
}

string CutString(string s, int begin, int end)
{
	string ss = {};
	for (int i = begin; i < end; i++)
	{
		ss.push_back(s[i]);
	}
	return ss;
}

void output(array <VItem,3> v)
{
	for (auto& i : v)
	{
		cout << i.description << endl;
		for (auto& j : i.items)
		{
			cout << j.word << " "
				<< j.position.first << " "
				<< j.position.second<<" "
				<< j.error << endl;
		}
	}
}
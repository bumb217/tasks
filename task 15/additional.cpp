#include "additional.h"
#include "Builder.h"

int check(const string &str)
{
	int res = 0;
	for (int i = 0; i < str.size(); i++)
		res += int(str[i]);
	return res;
}

void toXml(string txt)
{
	string line;
	ifstream in(txt + ".txt");
	getline(in, line);
	auto article = Element::create("article").add("title", line);
	getline(in, line);
	article.add("author", line);
	string body;
	while (getline(in, line))
	{
		body += line + '\n';
	}
	body.resize(body.length() - 1);
	line.erase(line.begin(), line.begin() + 3);
	article.add("body", body).add("hash", line);
	in.close();
	int hash;
	stringstream(line) >> hash;
	if (hash != check(body)) 
	{ 
		cout << "Incorrect hash"; return; 
	}
	ofstream out(txt + ".xml");
	out << article.toStr();
	out.close();
};

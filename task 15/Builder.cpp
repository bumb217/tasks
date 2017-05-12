#include "Builder.h"

Builder& Builder::add(const string &name, const string &text)
{
	elem.elements.emplace_back(name, text);
	return *this;
};

string Element::toString(int indent) const
{
	ostringstream oss;
	string i(indent_size * indent, ' ');
	oss << i << "<" << name << ">" << std::endl;
	if (text.size() > 0)
	{
		oss << string(indent_size *(indent + 1), ' ') << text << endl;
	}
	for (int i = 0; i < elements.size();i++)
	{
		oss << elements[i].toString(indent + 1);
	}
	oss << i << "</" << name << ">" << endl;
	return oss.str();
}

Builder Element::create(const string &name)
{
	return Builder{name};
}

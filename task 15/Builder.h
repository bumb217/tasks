#ifndef BUILDER_HEADER
#define BUILDER_HEADER

#pragma once

#include <bits/stdc++.h>

using namespace std;

class Builder;

class Element
{
	friend class Builder;
	string name;
	string text;
	vector<Element> elements;
	const static int indent_size = 4;
public:
	Element() {}
	Element(const string &name, const string &text = "") : name(name), text(text) {}
	virtual ~Element() {};
	string toString(int indent = 0) const;
	static Builder create(const string &name);
};

class Builder
{
	typedef Builder& build;

	Element elem;

public:
	Builder(const string &name) : elem(name){};

	build add(const string &name, const string &text);
	
	string toStr() const
	{
		return elem.toString();
	}
	
	operator Element()
	{
		return elem;
	}
};

#endif BUILDER_HEADER

#include <iosfwd>
#include <stdexcept>
#include <string>
#include <map>
#include <iostream>
#include "Variable_Table.h"
using namespace std;

void Variable_Table::insert(string name, double value)
{
	variableMap.insert(pair<string,double>(name,value));
}

void Variable_Table::remove(string name)
{
	variableMap.erase(name);
}

bool Variable_Table::find(string name) const
{
	return variableMap.count(name);
}

void Variable_Table::set_value(string name, double value)
{
	map<string,double>::iterator it = variableMap.find(name);
	it->second = value;
}

double Variable_Table::get_value(string name)
{
	map<string,double>::iterator it = variableMap.find(name);
	return it->second;
}

void Variable_Table::list(ostream& os)
{
	if(empty())
	{
		os << "Det finns inga variabler definierade" << endl;
	}
	else
	{
		map<string,double>::iterator it;
		for( it=variableMap.begin() ; it != variableMap.end(); it++ )
		{
			os << (*it).first << " = " << (*it).second << endl;	
		}
	}
}

void Variable_Table::clear()
{
	variableMap.clear();
}

bool Variable_Table::empty() const
{
	return variableMap.empty();
}

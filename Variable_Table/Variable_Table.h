/*
 * Variable_Table.h
 */
#ifndef VARIABLE_TABLE_H
#define VARIABLE_TABLE_H
#include <iosfwd>
#include <iostream>
#include <stdexcept>
#include <string>
#include <map>

/*
 * Variable_Table: Tabell där alla använda variabler sparas
 */
class Variable_Table
{
public:
	void insert(std::string name, double value);
	void remove(std::string);	
	bool find(std::string) const;
	void set_value(std::string name, double value);
	double get_value(std::string name);
	void list(std::ostream& os);
	void clear();
	bool empty() const;
private:
	std::map<std::string,double> variableMap;
};



#endif

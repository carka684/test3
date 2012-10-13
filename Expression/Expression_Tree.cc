/*
 * Expression_Tree.cc    2012-10-05
 */
#include "Expression_Tree.h"
#include "Expression_error.h"
#include <string>
#include <sstream>
#include <cctype>
#include <iomanip>
#include <typeinfo>
#include <iostream>
#include <cmath>


// INKLUDERA FÖR DET SOM KOMMER ATT ANVÄNDAS I DENNA FIL!
using namespace std;

// SEPARATA DEFINITIONER FÖR FÖR EXPRESSION_TREE-KLASSERNA DEFINIERAS HÄR.



// ----------------- Binary_Operator ------------------

Binary_Operator::Binary_Operator(Expression_Tree* newLeftNode, Expression_Tree* newRightNode)
{
	leftNode = newLeftNode;
	rightNode = newRightNode;
}

Binary_Operator::~Binary_Operator()
{
	delete leftNode;
	delete rightNode;
	leftNode = nullptr;
	rightNode = nullptr;
}

void Binary_Operator::print(ostream& os, int depth) const
{	
	rightNode->print(os, depth+2);
	os << setw(depth+2) << "/" << endl << setw(depth+1) << str() << endl << setw(depth+2)<< "\\" << endl;
	leftNode->print(os,depth+2);
}

string Binary_Operator::get_infix() const
{
	string infix = "(";
	infix = infix + leftNode->get_infix();	
	infix = infix + str();
	infix = infix + rightNode->get_infix();
	infix = infix + ")";
	return infix; 
}



string Binary_Operator::get_postfix() const
{
	return (leftNode->get_postfix() + " " + rightNode->get_postfix() + " " + str());
}

// ----------------- Operand ------------------

void Operand::print(ostream& os, int depth) const
{
	string valueString = str();
	os << setw(depth+1+valueString.size()) << valueString << endl;
}
string Operand::get_infix() const
{
	return str();
}


string Operand::get_postfix() const
{
	return str();
}


// ----------------- Plus ------------------

Plus::Plus(Expression_Tree* newLeftNode, Expression_Tree* newRightNode)
	: Binary_Operator(newLeftNode, newRightNode)
{
}

Expression_Tree* Plus::clone() const
{
	return new Plus(*this);
}
double Plus::evaluate()
{ 
	return (leftNode->evaluate() + rightNode->evaluate());
}

string Plus::str() const
{
	return "+";
}

// ----------------- Minus ------------------

Minus::Minus(Expression_Tree* newLeftNode, Expression_Tree* newRightNode)
	: Binary_Operator(newLeftNode, newRightNode)
{	
}

Expression_Tree* Minus::clone() const
{
	return new Minus(*this);
}

double Minus::evaluate()
{ 
	return (leftNode->evaluate() - rightNode->evaluate());
}

string Minus::str() const
{
	return "-";
}

// ----------------- Times ------------------

Times::Times(Expression_Tree* newLeftNode, Expression_Tree* newRightNode)
	: Binary_Operator(newLeftNode, newRightNode)
{
}

Expression_Tree* Times::clone() const
{
	return new Times(*this);
}
double Times::evaluate()
{ 
	return (leftNode->evaluate() * rightNode->evaluate());
}

string Times::str() const
{
	return "*";
}

// ----------------- Divide ------------------

Divide::Divide(Expression_Tree* newLeftNode, Expression_Tree* newRightNode)
	: Binary_Operator(newLeftNode, newRightNode)
{
}

Expression_Tree* Divide::clone() const
{
	return new Divide(*this);
}
double Divide::evaluate()
{ 
	return (leftNode->evaluate() / rightNode->evaluate());
}

string Divide::str() const
{
	return "/";
}

// ----------------- Power ------------------

Power::Power(Expression_Tree* newLeftNode, Expression_Tree* newRightNode)
	: Binary_Operator(newLeftNode, newRightNode)
{
}

Expression_Tree* Power::clone() const
{
	return new Power(*this);
}
double Power::evaluate()
{ 
	return pow(leftNode->evaluate(), rightNode->evaluate());
}

string Power::str() const
{
	return "^";
}


// ----------------- Assign ------------------

Assign::Assign(Expression_Tree* newLeftNode, Expression_Tree* newRightNode)
	: Binary_Operator(newLeftNode, newRightNode)
{
	if(not (isalpha(leftNode->str()[0]) and leftNode->str().size()==1 ))
	{
		throw expression_error("Måste vara en variabel (ett tecken) till vänster om =");
	}

}



Expression_Tree* Assign::clone() const
{
	return new Assign(*this);
}
double Assign::evaluate()
{
	Variable* leftVariable = dynamic_cast<Variable*>(leftNode);
	double rightNodeValue = rightNode->evaluate(); 
	leftVariable->set_value(rightNodeValue);
	
	return rightNodeValue;
}

string Assign::str() const
{
	return "=";
}


// ----------------- Integer ------------------

Integer::Integer(int newValue)
{
	value = newValue;
}

Expression_Tree* Integer::clone() const
{
	return new Integer(*this);
}
		
double Integer::evaluate()
{
	return value;
}

string Integer::str() const
{
	stringstream ss;
	ss << value;
	string str = ss.str();
	return str;
}

// ----------------- Real ------------------

Real::Real(double newValue)
{
	value = newValue;
}

Expression_Tree* Real::clone() const
{
	return new Real(*this);
}
		
double Real::evaluate()
{
	return value;
}

string Real::str() const
{
	stringstream ss;
	ss << value;
	string str = ss.str();
	return str;
}

// ----------------- Variable ------------------

Variable::Variable(string newVariableName, Variable_Table* variable_table, int newValue)
{
	variable_table_ref = variable_table;
	value = newValue;
	variableName = newVariableName;
}

Expression_Tree* Variable::clone() const
{
	return new Variable(*this);
}

// CHECK BORDE LIGGA I VARIABLE_TABLE: FRÅGA JONAS		
double Variable::evaluate()
{
	if(variable_table_ref->find(variableName))
	{
		return variable_table_ref->get_value(variableName);
	}
	else 
	{
		throw expression_error("Variabel i högerledet är ej definierad");
	}
	
}

string Variable::str() const
{
	return variableName;
}

double Variable::get_value() const
{
	return value;
}

// CHECK BORDE LIGGA I VARIABLE_TABLE: FRÅGA JONAS
void Variable::set_value(double newValue)
{
	value = newValue;
	
	if(variable_table_ref->find(variableName))
	{
		variable_table_ref->set_value(variableName,value);
	}
	else 
	{
		variable_table_ref->insert(variableName,value);
	}
}

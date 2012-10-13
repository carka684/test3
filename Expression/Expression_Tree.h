/*
 * Expression_Tree.h    2012-08-06
 */
#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H
#include <iosfwd>
#include <string>
#include <stdexcept>
#include "../Variable_Table/Variable_Table.h"

/*
 * expression_tree_error: Kastas om fel uppstår i en Expression_Tree-operation.
 * Ett diagnostiskt meddelande ska skickas med.
 */
 
// ATT GÖRA!


// OBSERVERA: NEDANSTÅENDE ÄR ENDAST KODSKELETT - MODIFIERA OCH KOMPLETTERA!

/*
 * Expression_Tree: Abstrakt, polymorf basklass för alla trädnodklasser.
 */
class Expression_Tree
{

public:
   virtual ~Expression_Tree() {}
   virtual double           evaluate() = 0;
   
   /**
    * Returnerar trädets infix ostädat från onödiga paranteser.
    */
   virtual std::string	    get_infix() const = 0;
   virtual std::string      get_postfix() const = 0;
   virtual void             print(std::ostream&, int depth=0) const = 0;
   virtual Expression_Tree* clone() const = 0;
   virtual std::string      str() const = 0;
  
};

/* 
 * Binary_Operator
 */
class Binary_Operator : public Expression_Tree
{
	public:
	Binary_Operator(Expression_Tree* newLeftNode, Expression_Tree* newRightNode);
	~Binary_Operator();
	
	Expression_Tree* leftNode;
	Expression_Tree* rightNode;
	
	void print(std::ostream& os, int depth=0) const;
	std::string get_infix() const;
	std::string get_postfix() const;
};

/*
 * Operand
 */
class Operand : public Expression_Tree
{
	void print(std::ostream& os, int depth) const;
	std::string get_infix() const;
	std::string get_postfix() const;
};


/*
 * Plus
 */
class Plus : public Binary_Operator
{ 
	public:
	Plus(Expression_Tree* newLeftNode, Expression_Tree* newRightNode);
	~Plus() = default;
	Expression_Tree* clone() const;
	double evaluate();
	
	private:
	std::string str() const;
};

/*
 * Minus
 */
class Minus : public Binary_Operator 
{
	public:
	Minus(Expression_Tree* newLeftNode, Expression_Tree* newRightNode);
	~Minus() = default;
	Expression_Tree* clone() const;
	double evaluate();
	
	private:
	std::string str() const;

};


/*
 * Times
 */
class Times : public Binary_Operator
{
	public:
	Times(Expression_Tree* newLeftNode, Expression_Tree* newRightNode);
	~Times() = default;
	Expression_Tree* clone() const;
	double evaluate();
	
	private:
	std::string str() const;
};

/*
 * Devide
 */
class Divide : public Binary_Operator
{
	public:
	Divide(Expression_Tree* newLeftNode, Expression_Tree* newRightNode);
	~Divide() = default;
	Expression_Tree* clone() const;
	double evaluate();
	
	private:
	std::string str() const;

};

/*
 * Power
 */
class Power: public Binary_Operator
{
	public:
	Power(Expression_Tree* newLeftNode, Expression_Tree* newRightNode);
	~Power() = default;
	Expression_Tree* clone() const;
	double evaluate();
	
	private:
	std::string str() const;
};

/*
 * Assign
 */
class Assign : public Binary_Operator
{ 
	public:
	Assign(Expression_Tree* newLeftNode, Expression_Tree* newRightNode);
	~Assign() = default;
	Expression_Tree* clone() const;
	double evaluate();
	
	private:
	std::string str() const;
};


/*
 * Integer
 */
class Integer : public Operand
{
	public:
	Integer(int Value);
	~Integer() = default;
	Expression_Tree* clone() const;
	double evaluate();
	
	private:
	std::string str() const;
	int value;
};

/*
 * Real
 */
class Real : public Operand
{
	public:
	Real(double Value);
	~Real() = default;
	Expression_Tree* clone() const;
	double evaluate();
	
	private:
	std::string str() const;
	double value;
};

/*
 * Variable
 */

class Variable : public Operand
{
	public:
	Variable(std::string newVariableName,Variable_Table* variable_table, int newValue = 0);
	~Variable() = default;
	Expression_Tree* clone() const;
	double evaluate();
	double get_value() const;
	void set_value(double newValue);
	
	private:
	std::string str() const;
	
	private:
	double value;
	std::string variableName;
	Variable_Table* variable_table_ref;
};

#endif

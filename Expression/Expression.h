/*
 * Expression.h
 */
#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "../Variable_Table/Variable_Table.h"
#include <iosfwd>
#include <stdexcept>
#include <string>

/**
 * expression_error: undantag som kastas om ett fel intr�ffar i en Expression-
 * operation, ett diagnostiskt meddelande ska skickas med.
 */

// ATT G�RA!

/**
 * Expression: Klass f�r att representera ett enkelt aritmetiskt uttryck.
 */
class Expression
{
public:
   // OBSERVERA: DETTA �R ENDAST KODSKELETT - MODIFIERA OCH KOMPLETTERA!

   Expression(class Expression_Tree* newTree = 0);

   double      evaluate() const;
   std::string get_infix() const;
   std::string get_postfix() const;
   bool        empty() const;
   void        print_tree(std::ostream&) const;
   Expression_Tree* get_topNode() const;
   void	       set_topNode(Expression_Tree* newTopNode);
   void        swap(Expression&);
   
   
   private:
   Expression_Tree* topNode;
};

/**
 * swap: Byter inneh�ll p� tv� Expression-objekt.
 */
void swap(Expression&, Expression&);

/**
 * make_expression: Hj�lpfunktion f�r att skapa ett Expression-objekt, givet
 * ett infixuttryck i form av en str�ng.
 */
Expression make_expression(const std::string& infix,Variable_Table* variable_table);

#endif

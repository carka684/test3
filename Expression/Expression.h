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
 * expression_error: undantag som kastas om ett fel inträffar i en Expression-
 * operation, ett diagnostiskt meddelande ska skickas med.
 */

// ATT GÖRA!

/**
 * Expression: Klass för att representera ett enkelt aritmetiskt uttryck.
 */
class Expression
{
public:
   // OBSERVERA: DETTA ÄR ENDAST KODSKELETT - MODIFIERA OCH KOMPLETTERA!

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
 * swap: Byter innehåll på två Expression-objekt.
 */
void swap(Expression&, Expression&);

/**
 * make_expression: Hjälpfunktion för att skapa ett Expression-objekt, givet
 * ett infixuttryck i form av en sträng.
 */
Expression make_expression(const std::string& infix,Variable_Table* variable_table);

#endif

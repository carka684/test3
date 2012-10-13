/*
 * Calculator.h
 */
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "../Expression/Expression.h"
#include "../Variable_Table/Variable_Table.h"
#include <iosfwd>
#include <vector>

/**
 * Calculator: klass för att läsa in, lagra och bearbeta enkla aritmetiska
 * uttryck. För att använda kalylatorn - skapa ett Calculator-objekt och 
 * anropa run().
 *
 * Anm: flyttkonstruktorn och flyttilldelningsoperatorn genereras inte om
 * en destruktor, kopieringskonstruktor eller kopieringstilldelnings-
 * operator deklareras ("deletea" aldrig dessa två!).
 */
class Calculator
{
public:
   Calculator();
   Calculator(const Calculator&) = delete;
   ~Calculator();
   Calculator& operator=(const Calculator&) = delete;
   // Flyttkonstruktor och flyttilldening genereras inte.

   void run();

private:
   static const std::string valid_command_;

   Expression current_expression_;

   char command_;

   static void print_help();

   void get_command();
   bool valid_command() const;
   void execute_command();

   void read_expression(std::istream&);
   std::vector<Expression> expression_vector;
   Variable_Table* variable_table = new Variable_Table;
   int position = 0;
   int current_position_ = 0;
   
   void print_variables() const;
   void erase_expression();
   void erase_expression(int pos);
};

#endif

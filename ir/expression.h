/*****************************************************************************

 This file is part of QSS Solver.

 QSS Solver is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 QSS Solver is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with QSS Solver.  If not, see <http://www.gnu.org/licenses/>.

 ******************************************************************************/

#ifndef MMO_EXPRESSION_H_
#define MMO_EXPRESSION_H_

#include <string>
#include "../ast/ast_types.h"
#include "../util/symbol_table.h"

namespace MicroModelica {
  namespace IR {

    /**
     *
     */
    class Expression
    {
      public:
        /**
         *
         */
        Expression();
        /**
         *
         * @param exp
         */
        Expression(AST_Expression exp, const Util::VarSymbolTable& symbols);
        /**
         *
         */
        ~Expression() {};
        std::string
        print() const;
        inline AST_Expression 
        expression() { return _exp; };
        bool 
        isReference() const;
        bool 
        isEmpty() const { return _exp == nullptr; };
        bool 
        isValid() const { return _exp != nullptr; };
        friend std::ostream& operator<<(std::ostream& out, const Expression& s);
      private:
        AST_Expression       _exp;
        Util::VarSymbolTable _symbols;
    };

    typedef list<Expression> ExpressionList;
  }
}
#endif /* EXPRESSION_H_ */

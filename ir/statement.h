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

#ifndef MMO_STATEMENT_H_
#define MMO_STATEMENT_H_

#include "../ast/ast_types.h"
#include "../util/table.h"

namespace MicroModelica {
  namespace IR {

    /**
     *
     */
    class Statement
    {
      public:
        /**
         *
         * @param stm
         */
        Statement(AST_Statement stm, bool initial = false);
        /**
         *
         */
        Statement();
        /**
         *
         */
        ~Statement();
        friend std::ostream& operator<<(std::ostream& out, const Statement& s);
    };

    typedef ModelTable<int, Statement> StatementTable;
  }
}
#endif  /* MMO_STATEMENT_H_ */

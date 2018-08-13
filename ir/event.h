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

#ifndef MMO_EVENT_H_
#define MMO_EVENT_H_

#include "../ast/ast_types.h"
#include "../util/table.h"

namespace MicroModelica {
  namespace IR {


    /**
     *
     */
    class Event
    {
      public:
        /**
         *
         * @param cond
         * @param data
         */
        Event(AST_Expression cond);
        /**
         *
         */
        ~Event();
        /**
         *
         */
        typedef enum
        {
          POSITIVE, //!< HND_POSITIVE
          NEGATIVE, //!< HND_NEGATIVE
          ZERO      //!< HND_ZERO
        } Type;

        /**
         * Define the original relation type of the zero-crossing function
         * needed by the initial algorithm.
         */
        typedef enum
        {
          LT,    //!< ZC_LT
          LE,    //!< ZC_LE
          GT,    //!< ZC_GT
          GE     //!< ZC_GE
        } Relation;
        
        friend std::ostream& operator<<(std::ostream& out, const Event& e);
    };

    typedef ModelTable<int,Event> EventTable;
  }
}

#endif  /*  MMO_EVENT_H_ */

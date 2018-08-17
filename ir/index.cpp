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

#include "index.h"

#include "helpers.h"
#include "../ast/expression.h"
#include "../ast/equation.h"
#include "../ast/statement.h"
#include "../util/error.h"

namespace MicroModelica {
  using namespace Util;
  namespace IR {


    IndexDefinition::IndexDefinition()
    {
    }
     
    IndexDefinition::~IndexDefinition()
    {
    }
    
    std::ostream& operator<<(std::ostream& out, const IndexDefinition& id)
    {
      return out;
    }

    Index::Index()
    {
    }
     
    Index::~Index()
    {
    }
     
    string
    Index::print() const 
    {
      return "";
    }
     
    void
    Index::setMap(Expression exp)
    {
    }
     
    bool
    Index::hasMap() const 
    {
      return false;
    }
     
    bool
    Index::operator==(const Index &other) const 
    {
      return false;
    }
     
    void
    Index::addIndex(IndexDefinition id)
    {
    }

    int
    Index::dimension()
    {
      return 0;
    }
    
    std::ostream& operator<<(std::ostream& out, const Index& i)
    {
      return out;
    }

    RangeDefinition::RangeDefinition(int begin, int end, int step) :
      _begin(begin),
      _end(end),
      _step(step)
    {
    }

    RangeDefinition::~RangeDefinition()
    {
    }

    std::ostream& operator<<(std::ostream& out, const RangeDefinition& rd)
    {
      return out;
    }

    Range::Range() :
      _ranges()
    {
    }
    
    Range::Range(AST_Equation_For eqf, VarSymbolTable symbols) :
      _ranges()
    {
      AST_ForIndexList fil = eqf->forIndexList();
      setRangeDefinition(fil, symbols);
    }

    Range::Range(AST_Statement_For stf, VarSymbolTable symbols) :
      _ranges()
    {
      AST_ForIndexList fil = stf->forIndexList();
      setRangeDefinition(fil, symbols);
    }
    void 
    Range::setRangeDefinition(AST_ForIndexList fil, VarSymbolTable symbols)
    {
      AST_ForIndexListIterator filit;
      foreach (filit, fil)
      {
        AST_ForIndex fi = current_element(filit);
        AST_Expression in = fi->in_exp();
        AST_ExpressionList el = in->getAsRange()->expressionList();
        AST_ExpressionListIterator eli;
        EvalInitExp eval(symbols);
        int size = el->size();
        int begin = eval.apply(AST_ListFirst(el));
        int end = eval.apply(AST_ListAt(el, size - 1));
        if(end < begin)
        {
          Error::instance().add(AST_ListFirst(el)->lineNum(), EM_IR | EM_UNKNOWN_ODE, ER_Error, "Wrong equation range.");
        }
        string index = fi->variable()->c_str();
        _ranges[index] = (size == 2 ? RangeDefinition(begin,end) : RangeDefinition(begin, end, eval.apply(AST_ListAt(el, 1))));
      }
    }

    Range::~Range() 
    {
    }
    
    std::ostream& operator<<(std::ostream& out, const Range& r)
    {
      return out;
    }

    VariableInterval::VariableInterval()
    {
    }
     
    VariableInterval::~VariableInterval()
    {
    }
  }
}

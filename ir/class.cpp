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

#include "class.h"

#include <iterator>
#include <sstream>
#include <utility>

#include "../ast/ast_builder.h"
#include "../ast/composition.h"
#include "../ast/equation.h"
#include "../ast/expression.h"
#include "../ast/modification.h"
#include "../ast/statement.h"
#include "../util/error.h"
#include "helpers.h"


using namespace MicroModelica::Util;

namespace MicroModelica {
  namespace IR
  {
    /* Function Class Implementation*/

    Function::Function(string name) :
      _imports(),
      _name(name),
      _symbols(),
      _localSymbols(),
      _statements(),
      _types(),
      _packages(),
      _arguments(),
      _outputNbr(0),
      _externalFunctionId(0),
      _statementId(0),
      _externalFunctions()
    {
    }

    Function::~Function()
    {
    }

    VarSymbolTable
    Function::symbols() const
    {
      return _symbols;
    }

    void
    Function::insert(string n)
    {
      _imports[n] = n;
      if(!Utils::instance().readPackage(n, _packages))
      {
        Error::instance().add(0, EM_IR | EM_CANT_OPEN_FILE, ER_Error, "%s.moo", n.c_str());
      }
    }

    void
    Function::insert(AST_Equation eq)  
    {
      return;
    }

    void
    Function::insert(AST_Statement stm) 
    {
      _statements[++_statementId] = Statement(stm);
    }

    void
    Function::insert(AST_Statement stm, bool initial) 
    {
      insert(stm);
    }

    void
    Function::insert(AST_External_Function_Call efc)   
    {
      string lvalue;
      VariableLookup vl(_symbols, _localSymbols);
      if(efc->hasComponentReference())
      {
        AST_Expression_ComponentReference cr = efc->componentReference();
        if(!vl.foldTraverse(cr))
        {
          Error::instance().add(efc->lineNum(), EM_IR | EM_VARIABLE_NOT_FOUND, ER_Error, "%s", cr->name().c_str());
          return;
        }
        lvalue = cr->name();
      }
      AST_ExpressionListIterator eli;
      if(efc->args() != NULL)
      {
        foreach(eli,efc->args())
        {
          if(!vl.foldTraverse(current_element(eli)))
          {
            Error::instance().add(efc->lineNum(), EM_IR | EM_VARIABLE_NOT_FOUND, ER_Error, "External function call.");
            return;
          }
        }
      }
      _externalFunctions.insert(++_externalFunctionId, ExternalFunction(lvalue, efc->name(),efc->args()));
    }

    void
    Function::insert(VarName n, Variable vi, DEC_Type type)  
    {
      EvalInitExp eval(_symbols);
      vi.setName(n);
      if(vi.typePrefix() & TP_CONSTANT)
      {
        vi.setValue(eval.foldTraverse(vi.modification()->getAsEqual()->exp()));
      }
      _symbols.insert(n, vi);
      if(type == DEC_PUBLIC)
      {
        if(vi.isOutput())
        {
          _outputNbr++;
        }
        _arguments.insert(n,vi);
      }
      else
      {
        _localSymbols.insert(n, vi);
      }
    }

    void
    Function::insert(VarName n, Variable vi)  
    {
      insert(n, vi, DEC_PUBLIC);
    }

    void
    Function::insert(AST_Argument_Modification x)  
    { 
      if(!_annotations.insert(x))
      {
        Error::instance().add(x->lineNum(), EM_IR | EM_ANNOTATION_NOT_FOUND, ER_Error, "%s", x->name()->c_str());
      }
    }

    string
    Function::name() const
    {
      return _name; 
    }

    ImportTable 
    Function::imports() const
    {
      return _imports;
    }

    StatementTable 
    Function::statements() const 
    {
      return _statements;
    }
    
    ExternalFunctionTable 
    Function::externalFunctions() const 
    {
      return _externalFunctions;
    }

    CompiledPackageTable 
    Function::packages() const 
    {
      return _packages;
    }
    
    unsigned int 
    Function::outputNbr() const
    {
      return _outputNbr;
    }
      
    FunctionAnnotation 
    Function::annotations() const
    {
      return _annotations;
    }
     
    Util::VarSymbolTable 
    Function::localSymbols() const
    {
      return _localSymbols;
    }
 
    Util::VarSymbolTable 
    Function::arguments() const
    {
      return _arguments;
    }

    /* Package Class Implementation */

    
    Package::Package(string name) :
      _imports(),
      _name(),
      _functions()
    {
    }

    Package::~Package()
    {
    }

    VarSymbolTable
    Package::symbols() const 
    {
      return VarSymbolTable();
    }

    void
    Package::insert(string n) 
    {
      _imports[n] = n;
    }

    void
    Package::insert(AST_Equation eq)  
    {
      return;
    }

    void
    Package::insert(AST_Statement stm)  
    {
      return;
    }

    void
    Package::insert(AST_Statement stm, bool initial) 
    {
      return;
    }

    void
    Package::insert(Function &f)  
    {
      _functions[f.name()] = f;
    }

    void
    Package::insert(AST_External_Function_Call efc)  
    {
      return;
    }

    void
    Package::insert(VarName n, Variable vi, DEC_Type type)  
    {
      return;
    }

    void
    Package::insert(VarName n, Variable vi)  
    {
      return;
    }

    void
    Package::insert(AST_Argument_Modification x) 
    {
    }

    string
    Package::name() const
    {
      return _name;
    }

    ImportTable 
    Package::imports() const
    {
      return _imports;
    }
    
    FunctionTable
    Package::definitions()
    {
      return _functions;
    }

    string
    Package::fileName() 
    {
      return Utils::instance().packageName(_name);
    }

    string
    Package::prefix()
    {
      return "__" + _name + "__";
    }

    /* Model Class Implementation */
    
    Model::Model() :
      _name(),
      _imports(),
      _symbols(),
      _annotations(_symbols),
      _externalFunctions()
    {
    }

    Model::Model(string name) :
      _name(name),
      _imports(),
      _symbols(),
      _annotations(_symbols),
      _externalFunctions()
    {
    }

    Model::~Model()
    {
    }

    void
    Model::insert(VarName n, Variable vi, DEC_Type type)  
    {
    }

    void
    Model::insert(VarName n, Variable vi) 
    {
    }

    void
    Model::insert(AST_Equation eq)  
    {
    }

    void
    Model::insert(AST_Statement stm)  
    {
    }

    void
    Model::insert(AST_External_Function_Call efc) 
    {
      return;
    }

    void
    Model::insert(AST_Statement stm, bool initial) 
    {
    }

    void
    Model::insert(Function &f) 
    {
    }

    void
    Model::insert(AST_Argument_Modification x) 
    {
      if(!_annotations.insert(x))
      {
        Error::instance().add(x->lineNum(), EM_IR | EM_ANNOTATION_NOT_FOUND, ER_Error, "%s", x->name()->c_str());
      }
    }

    VarSymbolTable
    Model::symbols() const
    {
      return _symbols;
    }

    void
    Model::insert(string n) 
    {
    }

    string
    Model::name() const
    {
      return "";
    }

    ImportTable
    Model::imports() const
    {
      return _imports;
    }

    ModelAnnotation 
    Model::annotations()
    {
      return _annotations;        
    }
    
    ExternalFunctionTable 
    Model::externalFunctions() const 
    {
      return _externalFunctions;
    }

  }
}

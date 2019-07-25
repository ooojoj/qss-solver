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

#ifndef MMO_CLASS_H_
#define MMO_CLASS_H_

#include <list>
#include <map>
#include <string>
#include <vector>
#include <boost/variant/variant.hpp>

#include "../ast/ast_types.h"
#include "../deps/model_dependencies.h"
#include "../util/util_types.h"
#include "../util/util.h"

#include "annotation.h"
#include "statement.h"
#include "equation.h"
#include "event.h"
#include "helpers.h"

namespace MicroModelica {
namespace IR {
/**
 *
 */
typedef enum {
  DEC_PUBLIC,  //!< DEC_PUBLIC
  DEC_LOCAL    //!< DEC_LOCAL
} DEC_Type;

/**
 *
 */
class Class {
  public:
  ~Class(){};
  /**
   *
   * @return
   */
  virtual string name() const = 0;
  /**
   *
   * @param n
   */
  virtual void insert(string n) = 0;
  /**
   *
   * @param eq
   */
  virtual void insert(AST_Equation eq) = 0;
  /**
   *
   * @param stm
   * @param initial
   */
  virtual void insert(AST_Statement stm, bool initial) = 0;
  /**
   *
   * @param stm
   */
  virtual void insert(AST_Statement stm) = 0;
  /**
   *
   * @param efc
   */
  virtual void insert(AST_External_Function_Call efc) = 0;
  /**
   *
   * @param n
   * @param vi
   * @param type
   */
  virtual void insert(VarName n, Util::Variable& vi, DEC_Type type) = 0;
  /**
   *
   * @param n
   * @param vi
   */
  virtual void insert(VarName n, Util::Variable& vi) = 0;
  /**
   *
   * @param x
   */
  virtual void insert(AST_Argument_Modification x) = 0;
  /**
   *
   * @return
   */
  virtual Util::VarSymbolTable symbols() const = 0;
  /**
   *
   * @return
   */
  virtual Util::ImportTable imports() const = 0;
};

/**
 *
 */
class Function : public Class {
  public:
  /**
   *
   */
  Function(){};
  /**
   *
   * @param name
   */
  Function(string name);
  /**
   *
   */
  ~Function();
  /**
   *
   * @return
   */
  string name() const;
  /**
   *
   * @param efc
   */
  void insert(AST_External_Function_Call efc);
  /**
   *
   * @param n
   * @param vi
   * @param type
   */
  void insert(VarName n, Util::Variable& vi, DEC_Type type);
  /**
   *
   * @param n
   * @param vi
   */
  void insert(VarName n, Util::Variable& vi);
  /**
   *
   * @param eq
   */
  void insert(AST_Equation eq);
  /**
   *
   * @param stm
   * @param initial
   */
  void insert(AST_Statement stm, bool initial);
  /**
   *
   * @param stm
   */
  void insert(AST_Statement stm);
  /**
   *
   * @param n
   */
  void insert(string n);
  /**
   *
   * @param x
   */
  void insert(AST_Argument_Modification x);
  /**
   *
   * @return
   */
  Util::VarSymbolTable symbols() const;
  /**
   *
   * @return
   */
  Util::ImportTable imports() const;
  StatementTable statements() const;
  ExternalFunctionTable externalFunctions() const;
  CompiledPackageTable packages() const;
  unsigned int outputNbr() const;
  FunctionAnnotation annotations() const;
  Util::VarSymbolTable localSymbols() const;
  Util::VarSymbolTable arguments() const;

  private:
  Util::ImportTable _imports;
  std::string _name;
  Util::VarSymbolTable _symbols;
  Util::VarSymbolTable _localSymbols;
  FunctionAnnotation _annotations;
  StatementTable _statements;
  Util::TypeSymbolTable _types;
  CompiledPackageTable _packages;
  Util::VarSymbolTable _arguments;
  unsigned int _outputNbr;
  unsigned int _externalFunctionId;
  unsigned int _statementId;
  ExternalFunctionTable _externalFunctions;
};

typedef ModelTable<std::string, Function> FunctionTable;

/**
 *
 */
class Package : public Class {
  public:
  /**
   *
   */
  Package(){};
  /**
   *
   * @param name
   */
  Package(string name);
  /**
   *
   */
  ~Package(){};
  /**
   *
   * @return
   */
  Util::VarSymbolTable symbols() const;
  /**
   *
   * @return
   */
  string name() const;
  /**
   *
   * @param n
   */
  void insert(string n);
  /**
   *
   * @param eq
   */
  void insert(AST_Equation eq);
  /**
   *
   * @param stm
   * @param initial
   */
  void insert(AST_Statement stm, bool initial);
  /**
   *
   * @param stm
   */
  void insert(AST_Statement stm);
  /**
   *
   * @param f
   */
  void setFunctions(FunctionTable& fs);
  /**
   *
   * @param efc
   */
  void insert(AST_External_Function_Call efc);
  /**
   *
   * @param n
   * @param vi
   * @param type
   */
  void insert(VarName n, Util::Variable& vi, DEC_Type type);
  /**
   *
   * @param n
   * @param vi
   */
  void insert(VarName n, Util::Variable& vi);
  /**
   *
   * @param x
   */
  void insert(AST_Argument_Modification x);
  /**
   *
   * @return
   */
  Util::ImportTable imports() const;
  /**
   *
   * @return
   */
  FunctionTable definitions();
  /*
   *
   * @return
   */
  std::string fileName();
  /*
   *
   * @return
   */
  std::string prefix();

  private:
  Util::ImportTable _imports;
  std::string _name;
  FunctionTable _functions;
};

/**
 *
 */
class Model : public Class {
  public:
  /**
   *
   * @param name
   */
  Model();
  /**
   *
   * @param name
   */
  Model(string name);
  /**
   *
   */
  ~Model(){};
  /**
   *
   * @return
   */
  inline string name() const { return _name; };
  /**
   *
   * @param n
   */
  void insert(string n);
  /**
   *
   * @param n
   * @param vi
   * @param type
   */
  void insert(VarName n, Util::Variable& vi, DEC_Type type);
  /**
   *
   * @param n
   * @param vi
   */
  void insert(VarName n, Util::Variable& vi);
  /**
   *
   * @param eq
   */
  void insert(AST_Equation eq);
  /**
   *
   * @param stm
   * @param initial
   */
  void insert(AST_Statement stm, bool initial);
  /**
   *
   * @param stm
   */
  void insert(AST_Statement stm);
  /**
   *
   * @param f
   */
  void setCalledFunctions(FunctionTable& fs);
  /**
   *
   * @param efc
   */
  void insert(AST_External_Function_Call efc);
  /**
   *
   * @param x
   */
  void insert(AST_Argument_Modification x);
  /**
   *
   * @return
   */
  inline Util::VarSymbolTable symbols() const { return _symbols; };
  /**
   *
   * @return
   */
  inline Util::ImportTable imports() const { return _imports; };
  inline ModelAnnotation annotations() const { return _annotations; };
  inline FunctionTable calledFunctions() const { return _calledFunctions; };
  inline int algebraicNbr() { return _algebraicNbr; };
  inline int stateNbr() const { return _stateNbr; };
  inline int discreteNbr() const { return _discreteNbr; };
  inline int inputNbr() const { return _inputNbr; };
  inline int outputNbr() const { return _outputNbr; };
  inline int eventNbr() const { return _eventNbr; };
  inline Util::SymbolTable linkLibraries() const { return _linkLibraries; };
  inline Util::SymbolTable includeDirectories() const { return _includeDirectories; };
  inline Util::SymbolTable libraryDirectories() const { return _libraryDirectories; };
  inline EquationTable derivatives() { return _derivatives; };
  inline EquationTable algebraics() { return _algebraics; };
  inline Deps::ModelDependencies dependencies() { return _dependencies; };
  inline EquationTable outputs() { return _outputs; };
  inline EventTable events() { return _events; };
  inline bool externalFunctions() { return _externalFunctions; };
  inline InputTable inputs() { return _inputs; };
  void setEquations();
  void setEvents();
  void setOutputs();
  void setInputs();
  inline StatementTable initialCode() { return _initialCode; };
  void computeDependencies();
  void setModelConfig();

  private:
  /**
   * @brief      Adds a new variable for events and output equations that
   *             doesn't have associated variables in the model.
   *
   * @param[in]  id    The identifier
   * @param[in]  size  The size
   * @param[in]  type  The type
   */
  void addVariable(int id, int size, EQUATION::Type type);
  Option<Util::Variable> variable(AST_Expression exp);
  void setRealVariableOffset(AST_Expression, Util::Variable::RealType type, unsigned int& offset);
  void setRealVariables(AST_Equation eq);
  void addEquation(AST_Equation eq, Option<Range> range);
  void addEvent(AST_Statement stm, Option<Range> range);
  void addFunction(Util::SymbolTable symbols, FunctionTable& fs);
  void addInput(Equation eq);
  std::string _name;
  Util::ImportTable _imports;
  Util::VarSymbolTable _symbols;
  Util::TypeSymbolTable _types;
  ModelAnnotation _annotations;
  FunctionTable _calledFunctions;
  EquationTable _derivatives;
  EquationTable _algebraics;
  EquationTable _outputs;
  EventTable _events;
  InputTable _inputs;
  Deps::ModelDependencies _dependencies;
  CompiledPackageTable _packages;
  StatementTable _initialCode;
  Util::SymbolTable _libraryDirectories;
  Util::SymbolTable _linkLibraries;
  Util::SymbolTable _includeDirectories;
  std::list<AST_Equation> _astEquations;
  std::list<AST_Statement> _astStatements;
  unsigned int _stateNbr;
  unsigned int _discreteNbr;
  unsigned int _algebraicNbr;
  unsigned int _eventNbr;
  unsigned int _outputNbr;
  unsigned int _inputNbr;
  int _derivativeId;
  int _algebraicId;
  int _statementId;
  int _eventId;
  int _outputId;
  int _inputId;
  bool _externalFunctions;
};

typedef boost::variant<Function, Package, Model> ClassType;

typedef Class* ClassPtr;

}  // namespace IR
}  // namespace MicroModelica
#endif /* MMO_CLASS_H_ */

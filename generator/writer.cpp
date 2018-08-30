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

#include <sstream>
#include <iostream>

#include "writer.h"
#include "../util/util.h"

namespace MicroModelica {
  using namespace Util;
  namespace Generator {

    /* MemoryWriter class. */

    MemoryWriter::MemoryWriter() :
        _indentStr(), 
        _block(), 
        _indent(0), 
        _blockIndent(0)
    {
      for(int i = 0; i < SECTIONS; i++)
      {
        _sections[i] = list<string>();
      }
    }

    void
    MemoryWriter::setFile(string fname)
    {
      _file.open(fname.c_str());
      if(!_file.good())
      {
        cout << "Memory Writer: Can not open file " << fname << endl;
      }
    }

    void
    MemoryWriter::removeFromSection(string str, Section section)
    {
      list<string>::iterator it;
      list<string> rmv;
      _removeIt = _sections[section].end();
      for(it = _sections[section].begin(); it != _sections[section].end(); it++)
      {
        string fi = Utils::instance().trimString(*it);
        string cmp = Utils::instance().trimString(str);
        if(fi.compare("{") == 0)
        {
          _removeIt = it;
        }
        if(fi.compare(cmp) == 0)
        {
          rmv.push_back(*it);
          break;
        }
      }
      for(it = rmv.begin(); it != rmv.end(); it++)
      {
        _sections[section].remove(*it);
      }
    }

    void
    MemoryWriter::clear(Section section)
    {
      _sections[section].clear();
    }

    void
    MemoryWriter::clearFile()
    {
      _file.close();
    }

    MemoryWriter::~MemoryWriter()
    {
      _file.close();
    }

    void
    MemoryWriter::newLine(Section section)
    {
      _sections[section].push_back("");
    }

    void
    MemoryWriter::write(string str, Section section, InsertType it)
    {
      if(!str.empty())
      {
        if(it == PREPEND)
        {
          _sections[section].push_back(str);
        }
        else if(it == APPEND_SIMPLE)
        {
          _sections[section].push_front(str);
        }
        else
        {
          _sections[section].insert(++_removeIt, str);
        }
      }
    }

    void
    MemoryWriter::write(stringstream& s, Section section, bool clean, InsertType it)
    {
      if(!s.str().empty())
      {
        if(it == PREPEND)
        {
          _sections[section].push_back(s.str());
        }
        else if(it == APPEND_SIMPLE)
        {
          _sections[section].push_front(s.str());
        }
        else
        {
          _sections[section].insert(++_removeIt, s.str());
        }
        if(clean)
        {
          s.str("");
        }
      }
    }

    void
    MemoryWriter::writeBlock(list<string> block, Section section)
    {
      list<string>::iterator it;
      for(it = block.begin(); it != block.end(); it++)
      {
        _sections[section].push_back(*it);
      }
    }

    void
    MemoryWriter::print(Section section)
    {
      list<string>::iterator it;
      for(it = _sections[section].begin(); it != _sections[section].end(); it++)
      {
        _file << _block << *it << endl;
      }
    }

    void
    MemoryWriter::print(stringstream& s)
    {
      _file << _block << s.str() << endl;
      s.str("");
    }

    void
    MemoryWriter::print(string s)
    {
      _file << _block << s << endl;
    }

    bool
    MemoryWriter::isEmpty(Section section)
    {
      return _sections[section].empty();
    }

    void
    MemoryWriter::printBlock(list<string> block)
    {
      list<string>::iterator it;
      for(it = block.begin(); it != block.end(); it++)
      {
        _file << _block << _indentStr << *it << endl;
      }
    }

    void
    MemoryWriter::setIndent(int n)
    {
      stringstream s;
      _indent = n;
      for(int i = 0; i < _indent; i++)
      {
        s << TAB;
      }
      _indentStr = s.str();
    }

    string
    MemoryWriter::indent()
    {
      return _indentStr;
    }

    string
    MemoryWriter::indent(int n)
    {
      stringstream s;
      for(int i = 0; i < n; i++)
      {
        s << TAB;
      }
      return s.str();
    }

    void
    MemoryWriter::beginBlock()
    {
      _file << "{";
      _block = indent(++_blockIndent);
    }

    void
    MemoryWriter::endBlock()
    {
      _file << "}";
      _block = indent(--_blockIndent);
    }

    string
    MemoryWriter::block()
    {
      return _block;
    }

    /* FileWriter class. */

    FileWriter::FileWriter() :
        _indentStr(), 
        _indent(0), 
        _blockIndent(0)
    {
      for(int i = 0; i < SECTIONS; i++)
      {
        stringstream name;
        name << "/tmp/temp" << i;
        _sections[i].open(name.str().c_str());
      }
    }

    FileWriter::~FileWriter()
    {
      for(int i = 0; i < SECTIONS; i++)
      {
        stringstream name;
        name << "/tmp/temp" << i;
        _sections[i].close();
        remove(name.str().c_str());
      }
    }

    void
    FileWriter::removeFromSection(string str, Section section)
    {
      return;
    }

    void
    FileWriter::clear(Section section)
    {
      return;
    }

    void
    FileWriter::setFile(string fname)
    {
      _file.open(fname.c_str());
    }

    void
    FileWriter::clearFile()
    {
      _file.close();
    }

    void
    FileWriter::newLine(Section section)
    {
      _sections[section] << endl;
    }

    void
    FileWriter::write(string str, Section section, InsertType it)
    {
      _sections[section] << str << endl;
    }

    void
    FileWriter::write(stringstream& s, Section section, bool clean, InsertType it)
    {
      _sections[section] << s.str() << endl;
      if(clean)
      {
        s.str("");
      }
    }

    void
    FileWriter::writeBlock(list<string> block, Section section)
    {
      list<string>::iterator it;
      for(it = block.begin(); it != block.end(); it++)
      {
        _sections[section] << *it << endl;
      }
    }

    void
    FileWriter::print(Section section)
    {
      _file << _sections[section].rdbuf();
    }

    void
    FileWriter::print(stringstream& s)
    {
      _file << s.str() << endl;
      s.str("");
    }

    void
    FileWriter::print(string s)
    {
      _file << s << endl;
    }

    bool
    FileWriter::isEmpty(Section section)
    {
      return false;
    }

    void
    FileWriter::printBlock(list<string> block)
    {
      list<string>::iterator it;
      for(it = block.begin(); it != block.end(); it++)
      {
        _file << *it << endl << endl;
      }
    }

    void
    FileWriter::setIndent(int n)
    {
      stringstream s;
      _indent = n;
      for(int i = 0; i < _indent; i++)
      {
        s << TAB;
      }
      _indentStr = s.str();
    }

    string
    FileWriter::indent()
    {
      return _indentStr;
    }

    string
    FileWriter::indent(int n)
    {
      stringstream s;
      for(int i = 0; i < n; i++)
      {
        s << TAB;
      }
      return s.str();
    }

    void
    FileWriter::beginBlock()
    {
      _block = indent(++_blockIndent);
    }

    void
    FileWriter::endBlock()
    {
      _block = indent(--_blockIndent);
    }

    string
    FileWriter::block()
    {
      return _block;
    }
  }
}

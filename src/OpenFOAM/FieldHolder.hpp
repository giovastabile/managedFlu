//  managedFlu - OpenFOAM C++ interactive functionality API
//  Copyright (C) 2011- Alexey Petrov
//  
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//  See http://sourceforge.net/projects/pythonflu
//
//  Author : Alexey PETROV, Andrey Simurzin


//---------------------------------------------------------------------------
#ifndef FieldHolder_hpp
#define FieldHolder_hpp


//---------------------------------------------------------------------------
#include "SimpleHolder.hpp"
#include "smart_tmp/smart_tmp.hpp"

#include <Field.H>


//---------------------------------------------------------------------------
namespace Foam
{
  template< class Type >
  class FieldHolder 
    : virtual public SimpleHolder 
    , public smart_tmp< Field< Type > >
  {
  public:
    FieldHolder();
    ~FieldHolder();
    
    virtual SimpleHolder* clone() const;
    
#ifndef SWIG
    using Foam::smart_tmp< Field< Type > >::operator();
    using Foam::smart_tmp< Field< Type > >::operator=;
#endif
  };
} // Foam


//---------------------------------------------------------------------------
namespace Foam
{
  template< class Type >
  FieldHolder< Type >::FieldHolder()
    : SimpleHolder()
    , smart_tmp< Field< Type > >()
  {}
  
  template< class Type >
  SimpleHolder* FieldHolder< Type >::clone() const
  {
    return new FieldHolder< Type >( *this );
  }
  
  template< class Type >
  FieldHolder< Type >::~FieldHolder()
  {}

} //Foam


//---------------------------------------------------------------------------
#endif

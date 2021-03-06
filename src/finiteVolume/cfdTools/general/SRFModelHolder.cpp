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
#include "SRFModelHolder.hpp"


//---------------------------------------------------------------------------
namespace Foam
{

namespace SRF
{  

  SRFModelHolder::SRFModelHolder() 
    : DependentHolder()
    , boost::shared_ptr< SRFModel >()
  {}

  SRFModelHolder::SRFModelHolder( const boost::shared_ptr< SRFModel >& the_Model, const volVectorFieldHolder& Urel ) 
    : DependentHolder( &Urel )
    , boost::shared_ptr< SRFModel >( the_Model )
  {
     IOdictionaryHolder::operator=( boost::shared_ptr< SRFModel >( *this ) );
  }

  SRFModelHolder SRFModelHolder::New( const volVectorFieldHolder& Urel )
  {
    autoPtr< SRFModel > a_Model = SRFModel::New( Urel() );
    
    return SRFModelHolder( boost::shared_ptr< SRFModel >( a_Model.ptr() ), Urel );
  }

  void SRFModelHolder::operator=( const boost::shared_ptr< SRFModel >& bt ) 
  {
    boost::shared_ptr< SRFModel >::operator=( bt );
    boost::shared_ptr< IOdictionary >::operator=( boost::shared_ptr< SRFModel >( *this ) );
  }

  SimpleHolder* SRFModelHolder::clone() const
  {
    return new SRFModelHolder( *this );
  }
  
  SRFModelHolder::~SRFModelHolder()
  {}
  
  void SRFModelHolder::operator()( const SRFModelHolder& the_Arg )
  {
    this->operator=( the_Arg );
  }
} // SRF
} // Foam


//---------------------------------------------------------------------------

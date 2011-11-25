//  managedFlu - OpenFOAM C++ interactive functionality API
//  Copyright (C) 2010- Alexey Petrov
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
#include "turbulenceModelHolder.hpp"


//---------------------------------------------------------------------------
namespace Foam
{
namespace compressible
{

  turbulenceModelHolder::turbulenceModelHolder()
    : DependentHolder()
    , boost::shared_ptr< turbulenceModel >()
  {}

  turbulenceModelHolder::turbulenceModelHolder( const boost::shared_ptr< turbulenceModel >& tm, 
                                                const volScalarFieldHolder& rho,
                                                const volVectorFieldHolder& U,
                                                const surfaceScalarFieldHolder& phi, 
                                                const basicThermoHolder& thermoPhysicalModel )
    : DependentHolder( Deps( &rho, &U, &phi, &thermoPhysicalModel ) )
    , boost::shared_ptr< turbulenceModel >( tm )
  {}

  turbulenceModelHolder turbulenceModelHolder::New( const volScalarFieldHolder& rho, const volVectorFieldHolder& U,
                                                    const surfaceScalarFieldHolder& phi, const basicThermoHolder& thermoPhysicalModel,
                                                    const word& turbulenceModelName )
  {
    autoPtr< turbulenceModel > result = turbulenceModel::New( rho(), U(), phi(), *thermoPhysicalModel, turbulenceModelName );
    
    return turbulenceModelHolder( boost::shared_ptr< turbulenceModel >( result.ptr() ), rho, U, phi, thermoPhysicalModel );
  }

  SimpleHolder* turbulenceModelHolder::clone() const
  {
    return new turbulenceModelHolder( *this );
  }

  turbulenceModelHolder::~turbulenceModelHolder()
  {}

  void turbulenceModelHolder::operator=( const boost::shared_ptr< turbulenceModel >& tm )
  {
    boost::shared_ptr< turbulenceModel >::operator=( tm );
  }
  
  void turbulenceModelHolder::operator()( const turbulenceModelHolder& the_Arg )
  {
    this->operator=( the_Arg );
  }

  
}//compressible
}//Foam

//---------------------------------------------------------------------------

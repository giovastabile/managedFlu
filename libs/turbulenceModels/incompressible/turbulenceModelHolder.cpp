//---------------------------------------------------------------------------
#include "turbulenceModelHolder.hpp"


//---------------------------------------------------------------------------
namespace Foam
{
namespace incompressible
{

  turbulenceModelHolder::turbulenceModelHolder()
    : DependentHolder()
    , boost::shared_ptr< turbulenceModel >()
  {}

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
  
}//incompressible
}//Foam

//---------------------------------------------------------------------------

#ifndef basicPsiThermoArgs_hpp
#define basicPsiThermoArgs_hpp


//---------------------------------------------------------------------------
#include "universalArgs.hpp"
#include "basicThermoArgs.hpp"
#include "Deps.hpp"

#include <boost/shared_ptr.hpp>


//---------------------------------------------------------------------------
namespace Foam
{
  class basicPsiThermoArgs
  : public universalArgs
  {
  protected:
    basicPsiThermoArgs();
  
    basicPsiThermoArgs( const Deps& );
  };
} // Foam


//---------------------------------------------------------------------------
#endif

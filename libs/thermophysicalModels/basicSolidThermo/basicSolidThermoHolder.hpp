#ifndef basicSolidThermoHolder_hpp
#define basicSolidThermoHolder_hpp


//---------------------------------------------------------------------------
#include "fvMeshHolder.hpp"
#include "IOdictionaryHolder.hpp"
#include "DependentHolder.hpp"
#include "Deps.hpp"

#include <basicSolidThermo.H>
#include <boost/shared_ptr.hpp>


//---------------------------------------------------------------------------
namespace Foam
{
  
  class basicSolidThermoHolder 
    : public IOdictionaryHolder
    , public boost::shared_ptr< basicSolidThermo >
  {
  public:
    basicSolidThermoHolder();

    static basicSolidThermoHolder New( const fvMeshHolder& );
    
    ~basicSolidThermoHolder();
    
    virtual SimpleHolder* clone() const;
    
    void operator()( const basicSolidThermoHolder& );
    
    using  boost::shared_ptr< basicSolidThermo >::operator*;
    using  boost::shared_ptr< basicSolidThermo >::operator->;
  protected:
    void operator=( const boost::shared_ptr< basicSolidThermo >& );
    basicSolidThermoHolder( const boost::shared_ptr< basicSolidThermo >&, const fvMeshHolder& );
  };
} // Foam


//---------------------------------------------------------------------------
#endif

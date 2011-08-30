#include "universalArgs.hpp"
#include "universalHolder.hpp"


//---------------------------------------------------------------------------
namespace Foam
{
  universalArgs::universalArgs( const universalHolder* uh )
  {
    this->deps_.insert(  holderPtr( uh->clone() ) );
  }
  
  universalArgs::universalArgs( const std::set< holderPtr >& the_deps )
    : deps_( the_deps )
  {}

/*  universalArgs::universalArgs( const universalHolder* uh1, const universalHolder* uh2 )
  {
    this->deps_.insert( holderPtr( uh1->clone() ) );
    this->deps_.insert( holderPtr( uh2->clone() ) );
  }

  universalArgs::universalArgs( const universalHolder* uh1, const universalHolder* uh2, const universalHolder* uh3 )
  {
    this->deps_.insert( holderPtr( uh1->clone() ) );
    this->deps_.insert( holderPtr( uh2->clone() ) );
    this->deps_.insert( holderPtr( uh3->clone() ) );
  }

  universalArgs::universalArgs( const universalHolder* uh1, const universalHolder* uh2, const universalHolder* uh3, const universalHolder* uh4 )
  {
    this->deps_.insert( holderPtr( uh1->clone() ) );
    this->deps_.insert( holderPtr( uh2->clone() ) );
    this->deps_.insert( holderPtr( uh3->clone() ) );
    this->deps_.insert( holderPtr( uh4->clone() ) );
  }*/

  universalArgs::universalArgs()
  {}
  
  const std::set< holderPtr >& universalArgs::deps() const
  {
    return deps_;
  }
  
  std::set< holderPtr > operator&&( const std::set< holderPtr >& deps1, const std::set< holderPtr >& deps2)
  {
    std::set< holderPtr > result;
  
    set_union( deps1.begin(), deps1.end(), deps2.begin(), deps2.end(),
              std::insert_iterator<std::set< holderPtr > >(result,result.begin()) );

    return result;
  }
  
}//Foam


//---------------------------------------------------------------------------


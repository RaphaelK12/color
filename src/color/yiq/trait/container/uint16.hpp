#ifndef color_yiq_trait_container_uint16
#define color_yiq_trait_container_uint16

#include "../../category.hpp"

#include "../../../_internal/utility/container/cner556.hpp"

#include "../../../generic/trait/container.hpp"



namespace color
 {
  namespace trait
   {

    template< >
     struct container< ::color::category::yiq_uint16 >
      : public  ::color::_internal::utility::container::cner556<  unsigned  >
      {
      };

   }
 }

#endif
#ifndef color_gray_akin_gray
#define color_gray_akin_gray

#include "../../generic/akin/gray.hpp"
#include "../category.hpp"
#include "../../gray/category.hpp"

namespace color
 {
  namespace akin
   {

    template< typename tag_name >
     struct gray< ::color::category::gray< tag_name > >
      {
       public:
         typedef ::color::category::gray< tag_name > akin_type;
      };

   }
 }

#endif

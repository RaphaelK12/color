#ifndef color_generic_place_red
#define color_generic_place_red

// ::color::place::red<category_name>()

#include "../trait/index.hpp"

 namespace color
  {
   namespace place
    {
     namespace _internal
      {

       template< typename category_name >
        struct red
         {
          public:
           typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

           static /*constexpr*/ index_instance_type position()
            {
             return ::color::trait::container< category_name >::size();
            }
         };

      }

     template< typename category_name >
      inline
      /*constexpr*/
      typename ::color::trait::index< category_name >::instance_type
      red()
       {
        return ::color::place::_internal::red<category_name>::position();
       }

    }
  }

#endif

#ifndef color_rgb_place_red
#define color_rgb_place_red

// ::color::place::red<category_name>()

#include "../../generic/place/red.hpp"
#include "../category.hpp"
#include "../trait/index.hpp"

 namespace color
  {
   namespace place
    {
     namespace _internal
      {

       template< typename tag_name >
        struct red< ::color::category::rgb< tag_name > >
         {
          public:
           typedef ::color::category::rgb< tag_name > category_type;
           typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

           enum { position_enum = 0 };
           enum { has_enum = true };

           static /*constexpr*/ index_instance_type position()
            {
             return position_enum;
            }
         };


       template< typename value_name, unsigned red_position, unsigned green_position, unsigned blue_position >
        struct red< ::color::category::rgb< ::color::category::_internal::rgb_scramble< value_name, red_position, green_position, blue_position > > >
         {
          public:
           typedef ::color::category::_internal::rgb_scramble< value_name, red_position, green_position, blue_position > scramble_type;
           typedef ::color::category::rgb< scramble_type > category_type;
           typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

           enum { position_enum = red_position };

           static /*constexpr*/ index_instance_type position()
            {
             return position_enum;
            }
         };

       template< typename value_name, unsigned red_position, unsigned green_position, unsigned blue_position, unsigned alpha_position >
        struct red< ::color::category::rgb< ::color::category::_internal::rgba_scramble< value_name, red_position, green_position, blue_position, alpha_position > > >
         {
          public:
            typedef ::color::category::_internal::rgba_scramble< value_name, red_position, green_position, blue_position, alpha_position > scramble_type;
            typedef ::color::category::rgb< scramble_type > category_type;
            typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

            enum { position_enum = red_position };

            static /*constexpr*/ index_instance_type position()
             {
              return position_enum;
             }
         };

      }
    }
  }

#endif

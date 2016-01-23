#ifndef color_rgb_convert_gray
#define color_rgb_convert_gray

#include "../../_internal/convert.hpp"
#include "../../gray/gray.hpp"

#include "../../_internal/normalize.hpp"
#include "../../_internal/diverse.hpp"

namespace color
 {
  namespace _internal
   {
    namespace  _privateRGB
     {

      template< typename category_left_name, typename category_right_name, typename scalar_name = double >
       struct convert_gray2rgb
        {
         public:
           typedef category_left_name category_left_type;
           typedef category_right_name category_right_type;

           typedef ::color::trait::container<category_left_type>     container_left_trait_type;
           typedef ::color::trait::container<category_right_type>    container_right_trait_type;

           typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_name >    reformat_type;

           typedef typename container_left_trait_type::input_type         container_left_input_type;
           typedef typename container_right_trait_type::input_const_type  container_right_const_input_type;

           static void process
            (
              container_left_input_type         left
             ,container_right_const_input_type  right
            )
            {
             container_left_trait_type::template set<0>( left, reformat_type::template process<0,0>( container_right_trait_type::template get<0>( right ) ) );
             container_left_trait_type::template set<1>( left, reformat_type::template process<1,0>( container_right_trait_type::template get<0>( right ) ) );
             container_left_trait_type::template set<2>( left, reformat_type::template process<2,0>( container_right_trait_type::template get<0>( right ) ) );
            }
        };
     }

     template< typename rgb_tag_name, typename gray_tag_name >
      struct convert
       <
         ::color::category::rgb< rgb_tag_name >
        ,::color::category::gray<gray_tag_name>
       >
      : public ::color::_internal::_privateRGB::convert_gray2rgb
       <
         ::color::category::rgb< rgb_tag_name >
        ,::color::category::gray<gray_tag_name>
        >
      {
      };

   }
 }

#endif
#ifndef color_cmyk_convert_gray
#define color_cmyk_convert_gray

#include "../../_internal/convert.hpp"
#include "../../gray/gray.hpp"

#include "../../generic/operation/invert.hpp"
#include "../../_internal/reformat.hpp"

namespace color
 {
  namespace _internal
   {
    namespace  _privateCMYK
     {

      template< typename category_left_name, typename category_right_name, typename scalar_name = double >
       struct convert_gray2cmyk
        {
         public:
           typedef category_left_name category_left_type;
           typedef category_right_name category_right_type;
           typedef scalar_name  scalar_type;

           typedef ::color::trait::bound<category_left_type>         bound_left_trait_type;
           typedef ::color::trait::container<category_left_type>     container_left_trait_type;
           typedef ::color::trait::container<category_right_type>    container_right_trait_type;

           typedef  ::color::operation::_internal::invert< category_right_type > invert_type;
           typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_name >    reformat_type;

           typedef typename container_left_trait_type::input_type         container_left_input_type;
           typedef typename container_right_trait_type::input_const_type  container_right_const_input_type;

           static void process
            (
              container_left_input_type         left
             ,container_right_const_input_type  right
            )
            {
             container_left_trait_type::template set<0>( left, bound_left_trait_type::template minimum<0>() );
             container_left_trait_type::template set<1>( left, bound_left_trait_type::template minimum<1>() );
             container_left_trait_type::template set<2>( left, bound_left_trait_type::template minimum<2>() );
             container_left_trait_type::template set<3>( left, reformat_type::template process<3,0>( invert_type::template component<0>( container_right_trait_type::template get<0>( right ) ) ) );
            }
        };

     }

     template< typename cmyk_tag_name, typename gray_tag_name >
      struct convert
       <
         ::color::category::cmyk< cmyk_tag_name >
        ,::color::category::gray<  gray_tag_name >
       >
      : public ::color::_internal::_privateCMYK::convert_gray2cmyk
       <
         ::color::category::cmyk< cmyk_tag_name >
        ,::color::category::gray< gray_tag_name >
        >
      {
      };

   }
 }

#endif

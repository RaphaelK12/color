#ifndef color_xyz_convert_YDbDr
#define color_xyz_convert_YDbDr

#include "../../_internal/convert.hpp"

#include "../category.hpp"


#include "../../YDbDr/YDbDr.hpp"
#include "../../rgb/rgb.hpp"

namespace color
 {
  namespace _internal
   {

    template< typename xyz_tag_name, typename YDbDr_tag_name >
     struct convert
      <
        ::color::category::xyz<      xyz_tag_name >
       ,::color::category::YDbDr<  YDbDr_tag_name >
      >
      {
       public:
         typedef ::color::category::xyz< xyz_tag_name >    xyz_category_type, category_left_type;
         typedef ::color::category::YDbDr< YDbDr_tag_name >    YDbDr_category_type, category_right_type;

         typedef typename ::color::akin::rgb< YDbDr_category_type >::akin_type  rgb_category_type;

         typedef ::color::model< xyz_category_type > xyz_model_type;
         typedef ::color::model< YDbDr_category_type >  YDbDr_model_type;

         typedef ::color::model< rgb_category_type >  rgb_model_type;

         typedef ::color::trait::container<category_left_type>     container_left_trait_type;
         typedef ::color::trait::container<category_right_type>    container_right_trait_type;

         typedef typename container_left_trait_type::input_type         container_left_input_type;
         typedef typename container_right_trait_type::input_const_type  container_right_const_input_type;

         static void process
          (
            container_left_input_type         left
           ,container_right_const_input_type  right
          )
          {
           left = xyz_model_type( rgb_model_type( YDbDr_model_type( right ) ) ).container();
          }
        };

   }
 }

#endif
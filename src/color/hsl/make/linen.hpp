#ifndef color_hsl_make_linen
#define color_hsl_make_linen

// ::color::make::linen( c )

 namespace color
  {
   namespace make
    { //RGB equivalent std::array<double,3>( { 0.980392, 0.941176, 0.901961 } ) 

      inline
      void linen( ::color::_internal::model< color::category::hsl_uint8 > & color_parameter )
       {
        color_parameter.container() = 0xa0;
       }

      inline
      void linen( ::color::_internal::model< color::category::hsl_uint16 > & color_parameter )
       {
        color_parameter.container() = 0xee82;
       }

      inline
      void linen( ::color::_internal::model< color::category::hsl_uint32 > & color_parameter )
       {
        color_parameter.container() = 0xfff0a915u;
       }

      inline
      void linen( ::color::_internal::model< color::category::hsl_uint64 > & color_parameter )
       {
        color_parameter.container() = 0xfffff0f0aaa91555ul;
       }

      inline
      void linen( ::color::_internal::model< color::category::hsl_float > & color_parameter )
       {
        color_parameter.container() = std::array<float,3>( { 0.0833333, 0.666667, 0.941176 } );
       }

      inline
      void linen( ::color::_internal::model< color::category::hsl_double> & color_parameter )
       {
        color_parameter.container() = std::array<double,3>( { 0.0833333, 0.666667, 0.941176 } );
       }

      inline
      void linen( ::color::_internal::model< color::category::hsl_ldouble> & color_parameter )
       {
        color_parameter.container() = std::array<long double,3>( { 0.0833333, 0.666667, 0.941176 } );
       }

    }
  }

#endif
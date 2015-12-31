#include <vector>
#include <fstream>

#include "color/color.hpp"

#include "./model/invoke.hpp"
#include "./model/operation.hpp"
#include "./model/make.hpp"
#include "./model/intrisic_conversion.hpp"
#include "./model/set.hpp"
#include "./model/get.hpp"
#include "./model/conversion.hpp"

void invoke()
 {
  test_invoke< color::category::rgb_uint8   >();
  test_invoke< color::category::rgb_uint16  >();
  test_invoke< color::category::rgb_uint32  >();
  test_invoke< color::category::rgb_uint64  >();
  test_invoke< color::category::rgb_float   >();
  test_invoke< color::category::rgb_double  >();
  test_invoke< color::category::rgb_ldouble >();

  test_operation< color::category::rgb_uint8   >();
  test_operation< color::category::rgb_uint16  >();
  test_operation< color::category::rgb_uint32  >();
  test_operation< color::category::rgb_uint64  >();
  test_operation< color::category::rgb_float   >();
  test_operation< color::category::rgb_double  >();
  test_operation< color::category::rgb_ldouble >();

  test_make< color::category::rgb_uint8   >();
  test_make< color::category::rgb_uint16  >();
  test_make< color::category::rgb_uint32  >();
  test_make< color::category::rgb_uint64  >();
  test_make< color::category::rgb_float   >();
  test_make< color::category::rgb_double  >();
  test_make< color::category::rgb_ldouble >();

  test_conversion< color::rgb, color::rgb >();
  test_conversion< color::rgb, color::cmy >();
  test_conversion< color::rgb, color::gray >();
  test_conversion< color::rgb, color::yiq >();
  test_conversion< color::rgb, color::yuv >();
  test_conversion< color::rgb, color::xyz >();

  test_conversion< color::cmy, color::cmy >();
  test_conversion< color::cmy, color::rgb >();
  test_conversion< color::cmy, color::cmyk >();
  test_conversion< color::cmy, color::gray >();

  test_conversion< color::gray, color::gray >();
  test_conversion< color::gray, color::rgb >();
  test_conversion< color::gray, color::cmy >();
  test_conversion< color::gray, color::hsl >();
  test_conversion< color::gray, color::hsv >();
  test_conversion< color::gray, color::yiq >();
  test_conversion< color::gray, color::yuv >();

  test_conversion< color::yiq, color::yiq >();
  test_conversion< color::yiq, color::rgb >();

  test_conversion< color::yuv, color::yuv >();
  test_conversion< color::yuv, color::rgb >();

  test_conversion< color::xyz, color::xyz >();
  test_conversion< color::xyz, color::rgb >();
 }

template < typename model_name >
void make_image(std::string const& name, float y_plane = 0.5 )
 {
  int height = 1000;
  int width  = 1000;
  typedef unsigned char targa_header_struct[18];

  targa_header_struct header;

  void targa_make_header(int height, int width, targa_header_struct header);

  targa_make_header( height, width, header);

  std::vector< color::rgb<std::uint32_t> >   image(height * width);

  for (int y = 0; y < height; y++)
   {
    for (int x = 0; x < width; x++)
     {
      image[y * width + x].set<3>(255);
      image[y * width + x] = model_name( { y / double(height), y_plane, x / double(width) } );
     }
   }

  std::ofstream of(name, std::ios_base::binary);
  of.write((const char *)header, 18);
  of.write((const char *)image.data(), image.size() * 4);
 }

int main(int argc, char const *argv[])
 {

  make_image<color::rgb<double> >( "image-rgb.tga");
  make_image<color::cmy<double> >( "image-cmy.tga");
  make_image<color::cmyk<double> >("image-cmyk.tga");
  make_image<color::hsl<double> >( "image-hsl.tga");
  make_image<color::hsv<double> >( "image-hsv.tga");
  make_image<color::xyz<double> >( "image-xyz.tga");
  make_image<color::yiq<double> >( "image-yiq.tga");

  make_image<color::yuv<double> >("image-yuv_0.0.tga", 0.0);
  make_image<color::yuv<double> >("image-yuv_0.1.tga", 0.1);
  make_image<color::yuv<double> >("image-yuv_0.2.tga", 0.2);
  make_image<color::yuv<double> >("image-yuv_0.3.tga", 0.3);
  make_image<color::yuv<double> >("image-yuv_0.4.tga", 0.4);
  make_image<color::yuv<double> >("image-yuv_0.5.tga", 0.5);
  make_image<color::yuv<double> >("image-yuv_0.6.tga", 0.6);
  make_image<color::yuv<double> >("image-yuv_0.7.tga", 0.7);
  make_image<color::yuv<double> >("image-yuv_0.8.tga", 0.8);
  make_image<color::yuv<double> >("image-yuv_0.9.tga", 0.9);
  make_image<color::yuv<double> >("image-yuv_1.0.tga", 1.0);

  //invoke();

  extern void check_conversion();
  check_conversion();

  //extern void make_test();
  //make_test();

  return 0;
 }


#include "color/rgb.hpp"
#include "color/cmyk.hpp"

int main( int argc, char *argv[] )
 {

    color::cmyk<double >      ck { ::color::constant::bisque_type{}    };




    color::rgb< double >       r { ::color::constant::lavender_type{}  };





  r = ck;

  return EXIT_SUCCESS;
 }
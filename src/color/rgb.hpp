#define COLOR_NEED_MODEL_RGB

#ifndef COLOR_NEED_MODEL_CMY
#define COLOR_EXCLUDE_MODEL_CMY
#endif#endif

#ifndef COLOR_NEED_MODEL_CMYK
#define COLOR_EXCLUDE_MODEL_CMYK
#endif

#ifndef COLOR_NEED_MODEL_GRAY
#define COLOR_EXCLUDE_MODEL_GRAY
#endif

#ifndef COLOR_NEED_MODEL_HSI
#define COLOR_EXCLUDE_MODEL_HSI
#endif

#ifndef COLOR_NEED_MODEL_HSL
#define COLOR_EXCLUDE_MODEL_HSL
#endif

#ifndef COLOR_NEED_MODEL_HSV
#define COLOR_EXCLUDE_MODEL_HSV
#endif

#ifndef COLOR_NEED_MODEL_RGB
#undef COLOR_EXCLUDE_MODEL_RGB
#endif

#ifndef COLOR_NEED_MODEL_YCgCo
#define COLOR_EXCLUDE_MODEL_YCgCo
#endif

#ifndef COLOR_NEED_MODEL_YDbDr
#define COLOR_EXCLUDE_MODEL_YDbDr
#endif

#ifndef COLOR_NEED_MODEL_YIQ
#define COLOR_EXCLUDE_MODEL_YIQ
#endif

#ifndef COLOR_NEED_MODEL_YPbPr
#define COLOR_EXCLUDE_MODEL_YPbPr
#endif

#ifndef COLOR_NEED_MODEL_YUV
#define COLOR_EXCLUDE_MODEL_YUV
#endif

#include "./rgb/rgb.hpp"

// reincluding

#ifdef COLOR_NEED_MODEL_CMY
#include "./cmy/cmy/akin.hpp"
#include "./cmy/cmy/convert.hpp"
#endif

#ifdef COLOR_NEED_MODEL_CMYK
#include "./cmyk/cmyk/akin.hpp"
#include "./cmyk/cmyk/convert.hpp"
#endif

#ifdef COLOR_NEED_MODEL_HSL
#include "./hsl/hsl/akin.hpp"
#include "./hsl/hsl/convert.hpp"
#endif




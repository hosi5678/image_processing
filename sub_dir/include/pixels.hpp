#ifndef AB004A64_177C_4DBB_8542_AC63E3C6F69B
#define AB004A64_177C_4DBB_8542_AC63E3C6F69B

#include <vector>

typedef struct _tagMainPixel {
	std::vector<uint8_t> pixeldata;
} PixelData;

typedef struct _tagPalette {
   std::vector<uint8_t> pixeldata;
} PaletteData;

typedef struct _tagMainStructure {
   int width;
   int height;
   int padding;
   PixelData pixel;
} Image;

typedef struct _tagPaletteStructure {
   int length;
   PaletteData palette_data;
} Palette;
 
#endif /* AB004A64_177C_4DBB_8542_AC63E3C6F69B */

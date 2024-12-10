#include "../include/image.hpp"

void image::initialise(){

  if(!infile.is_open()){
    std::cerr << "ファイルが開いていません。" << filename << std::endl;
  }

  std::cout << "(in initialize:)" << std::endl;

  std::cout << "file readed: " << filename << std::endl;
  std::cout << "bfType:" << std::hex << bmpfileheader.bfType <<std::dec << std::endl;

  if(bmpfileheader.bfType!=FILE_TYPE){
    std::cout << "BMP fileではありません。" << std::endl;
  }else{
    std::cout << "BMP fileです。" << std::endl;
  }

  if(isLittleEndian()){
    std::cout << "リトルエンディアンです。" << std::endl;
  }else{
    std::cout << "ビッグエンディアンです。" << std::endl;
  }

  width=bmpinfoheader.biWidth;
  height=bmpinfoheader.biHeight;

  std::cout << "width: " << width << std::endl;
  std::cout << "height:" << height << std::endl;

  std::cout << "width x height: " << width*height << std::endl;
  std::cout << "biSizeImage: " << bmpinfoheader.biSizeImage << std::endl;

  std::cout << "padding: " << getPadding(width) << std::endl;
  std::cout << "color depth: " << bmpinfoheader.biBitCount << std::endl;

  std::cout << "color palette: " << bmpinfoheader.biClrUsed << std::endl;

  std::streampos _pos = infile.tellg();

  if (_pos!=DEFAULT_HEADER_SIZE){
    std::cerr << "デフォルトサイズを読んでいません。" << std::endl;
  }

  std::cout << "original position: " << _pos << std::endl;

  std::cout << "size of uint8_t: " << sizeof(uint8_t) << std::endl;
  std::cout << "size of uint16_t: " << sizeof(uint16_t) << std::endl;
  std::cout << "size of uint32_t: " << sizeof(uint32_t) << std::endl;

  std::cout << "file size: " << bmpfileheader.bfSize << std::endl;

  std::cout << "default header size+palette sizex4(r,g,b,dummy)+widthxheight: " << DEFAULT_HEADER_SIZE+bmpinfoheader.biClrUsed*4+width*height << std::endl;

  palette.length=bmpinfoheader.biClrUsed;

  imagepixel.width=bmpinfoheader.biWidth;
  imagepixel.height=bmpinfoheader.biHeight;
  imagepixel.padding=getPadding(bmpinfoheader.biWidth);
  padding=imagepixel.padding;

}

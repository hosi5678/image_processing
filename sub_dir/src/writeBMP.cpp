#include "../include/image.hpp"


void image::writeBMP() {

  std::cout << "(in BMP write)" << std::endl;
  std::cout << "output file name:" << "out.bmp" << std::endl;
  std::cout << "padding:" << padding << std::endl;
  std::cout << "width:" << width << std::endl;
  std::cout << "height:" << height << std::endl;
  std::cout << "length of 1d vector of image:" << imagepixel.pixel.pixeldata.size()<< std::endl;
  std::cout << "length of 1d vector of palette:" << palette.palette_data.pixeldata.size() << std::endl;

  std::cout << "endian:" << isLittleEndian() << std::endl;

  std::cout << "biBitCount :" << bmpinfoheader.biBitCount << std::endl;
  std::cout << "biClrUsed :" << bmpinfoheader.biClrUsed << std::endl;
  std::cout << "biSizeImage :" << bmpinfoheader.biSizeImage << std::endl;

  std::streampos pos=outfile.tellp();
  std::cout << "pos=" << pos << std::endl;

  // writeBytes(outfile,bmpfileheader);
  // writeBytes(outfile,bmpinfoheader);

    // ヘッダ情報を書き出し
    writeBytes(outfile, (bmpfileheader.bfType));
    writeBytes(outfile, (bmpfileheader.bfSize));
    writeBytes(outfile, (bmpfileheader.bfReserved1));
    writeBytes(outfile, (bmpfileheader.bfReserved2));
    writeBytes(outfile, (bmpfileheader.bfOffBits));

    writeBytes(outfile, (bmpinfoheader.biSize));
    writeBytes(outfile, (bmpinfoheader.biWidth));
    writeBytes(outfile, (bmpinfoheader.biHeight));
    writeBytes(outfile, (bmpinfoheader.biPlanes));
    writeBytes(outfile, (bmpinfoheader.biBitCount));
    writeBytes(outfile, (bmpinfoheader.biCompression));
    writeBytes(outfile, (bmpinfoheader.biSizeImage));
    writeBytes(outfile, (bmpinfoheader.biXPelsPerMeter));
    writeBytes(outfile, (bmpinfoheader.biYPelsPerMeter));
    writeBytes(outfile, (bmpinfoheader.biClrUsed));
    writeBytes(outfile, (bmpinfoheader.biClrImportant));

  pos=outfile.tellp();
  std::cout << "header pos=" << pos << std::endl;

  // パレットの書き出し

  for (std::size_t i=0; i<bmpinfoheader.biClrUsed; i++) {
    writeBytes(outfile,(palette.palette_data.pixeldata[i]));
    writeBytes(outfile,(palette.palette_data.pixeldata[i]));
    writeBytes(outfile,(palette.palette_data.pixeldata[i]));
    writeBytes(outfile,(palette.palette_data.pixeldata[i]));
  }

  pos=outfile.tellp();
  std::cout << "palette pos=" << pos << std::endl;

    // ピクセルデータの書き出し（下から上へ）
    for (int j = 0; j< height ; j++) {
      for (int i = 0; i < width; i++) {
        // モノクロなので一つのチャンネルだけでよい。
          writeBytes(outfile, (imagepixel.pixel.pixeldata[j * width + i]));
      }
      for (int i = 0; i < padding; i++) {
          writeBytes(outfile, static_cast<uint8_t>(0));
      }
    }

  pos=outfile.tellp();
  std::cout << "image pos=" << pos << std::endl;

  outfile.close();
}

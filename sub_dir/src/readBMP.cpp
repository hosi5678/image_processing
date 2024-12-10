#include "../include/image.hpp"

void image::readBMP() {

    std::cout << "(in read BMP)" << std::endl;

    std::streampos current_pos=infile.tellg();

    std::cout << "current position: " << current_pos << std::endl;

    std::cout << "palette length: " << palette.length << std::endl;

    int temp=0;

    // palette dataの配列の確保

    // palette.palette_data.b.clear();
    // palette.palette_data.g.clear();
    // palette.palette_data.r.clear();
    // palette.palette_data.dummy.clear();

    palette.palette_data.pixeldata.resize(0);

    for (int i=0; i<palette.length; i++) {
      temp=readBytes<uint8_t>(infile,sizeof(uint8_t));
      palette.palette_data.pixeldata.push_back(temp);

      temp=readBytes<uint8_t>(infile,sizeof(uint8_t));
      temp=readBytes<uint8_t>(infile,sizeof(uint8_t));
      temp=readBytes<uint8_t>(infile,sizeof(uint8_t));

    }

    // for (int i=0; i<palette.length; i++) {
    //     std::cout << "i:"<< i <<
    //     " blue:" << palette.palette_data.b[i] <<
    //     " green:" << palette.palette_data.g[i] <<
    //     " red:" << palette.palette_data.r[i] << std::endl;
    // }

    std::cout << "palette data were read." << std::endl;

    current_pos=infile.tellg();
    std::cout << "current position: " << current_pos << std::endl;

    imagepixel.pixel.pixeldata.resize(0);

    temp=0;

    for (int j=0; j<height; j++) {
      for (int i=0; i<width; i++) {
        // モノクロなので1つのチャンネルでよい。
        temp=readBytes<uint8_t>(infile,sizeof(uint8_t));
        imagepixel.pixel.pixeldata.push_back(temp);

      }

      for (int i=0; i<padding; i++){
        temp=readBytes<uint8_t>(infile,sizeof(uint8_t));
      }

    }


    std::cout << "image data were read." << std::endl;

    current_pos=infile.tellg();
    std::cout << "current position: " << current_pos << std::endl;


    infile.close();

}

/*
valgrind --leak-check=full --track-origins=yes --log-file=valgrind.log ./build/main
*/

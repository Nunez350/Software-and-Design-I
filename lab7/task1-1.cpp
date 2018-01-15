/*
  Author: Roy Nunez

  Description:
    The program read a PPM file from the standard input,
    and outputs a modified PPM file through the standard output.

*/


#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAXWIDTH = 512;
const int MAXHEIGHT = 512;

// reads a PPM file.
// Notice that: width and height are passed by reference!

void readImage(int image[MAXWIDTH][MAXHEIGHT], int &width, int &height) {
    cout << " 2"<<endl;
  char c;
  int x;
  ifstream instr;
   cout << " 2"<<endl;
  instr.open("city.pgm");
   cout << " 3"<<endl;

  // read the header P3
  instr >> c;  assert(c == 'P');
  instr >> c;  assert(c == '2');

  // skip the comments (if any)
  while ((instr>>ws).peek() == '#') { instr.ignore(4096, '\n'); }

  instr >> width;
  instr >> height;

  assert(width <= MAXWIDTH);
  assert(height <= MAXHEIGHT);
  int max;
  instr >> max;
  assert(max == 255);

  for (int row = 0; row < height; row++)
    for (int col = 0; col < width; col++)
      instr >> image[col][row];
  instr.close();
  return;
}

void writeImage(int image[MAXWIDTH][MAXHEIGHT], int width, int height) {
  ofstream ostr;
  ostr.open("outImage.pgm");
  if (ostr.fail()) {
    cout << "Unable to write file\n";
    exit(1);
  };

  // print the header
  ostr << "P2" << endl;
  // width, height
  ostr << width << ' ';
  ostr << height << endl;
  ostr << 255 << endl;

  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      assert(image[col][row] < 256);
      assert(image[col][row] >= 0);
      ostr << image[col][row] << ' ';
      // lines should be no longer than 70 characters
      if ((col+1)%16 == 0) ostr << endl;
    }
    ostr << endl;
  }
  ostr.close();
  return;
}

int main() {

  int inImage[MAXWIDTH][MAXHEIGHT];
  int outImage[MAXWIDTH][MAXHEIGHT];
  int imageWidth, imageHeight;


  readImage(inImage, imageWidth, imageHeight);

  for(int i = 0; i<imageWidth; i++)
    for(int j = 0; j<imageHeight; j++) {
	cout << inImage[i][j] << " ";}

  int t1,t2;
  cout << "input t1:"<<endl;
  cin >> t1;
  cout << "input t2:"<<endl;
  cin >>t2;
  for(int i = 0; i<imageWidth; i++)
    for(int j = 0; j<imageHeight; j++) {


if(inImage[i][j] < t1)
  outImage[i][j] = 0;
 else if(inImage[i][j] < t1)
   outImage[i][j] = 255;
 else
   outImage[i][j] = inImage[i][j];
    }

  writeImage(outImage, imageWidth, imageHeight);
  return 0;

}

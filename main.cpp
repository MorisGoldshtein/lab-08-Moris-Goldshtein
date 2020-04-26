#include <iostream>
#include "imagehelpers.h"

int main(){
  int width = 0, height = 0, img[MAX_H][MAX_W];
  invert(width, height, img);
  inverthalf(width, height, img);
  box(width, height, img);
  frame(width, height, img);
  scale(width, height, img);
  pixelate(width, height, img);
}

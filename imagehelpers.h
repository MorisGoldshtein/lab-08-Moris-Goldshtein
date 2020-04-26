#pragma once

const int MAX_H = 512;
const int MAX_W = 512;

void readImage(std::string filename, int image[MAX_H][MAX_W], int &height, int &width);
void writeImage(std::string filename, int image[MAX_H][MAX_W], int height, int width);
void invert(int width, int height, int img[MAX_H][MAX_W]);
void inverthalf(int width, int height, int img[MAX_H][MAX_W]);
void box(int width, int height, int img[MAX_H][MAX_W]);
void frame(int width, int height, int img[MAX_H][MAX_W]);
void scale(int width, int height, int img[MAX_H][MAX_W]);
void pixelate(int width, int height, int img[MAX_H][MAX_W]);

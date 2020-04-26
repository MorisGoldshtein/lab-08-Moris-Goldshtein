#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include "imagehelpers.h"
#include <cmath>


//Complete
void invert(int width, int height, int img[MAX_H][MAX_W]){
    //Create 2D array to hold numbers for colors from input image
//    int out[MAX_H][MAX_W];
//    int h, w;

    //Take inImage.pgm color numbers and store them into the img 2D array (line 9)
//    readImage(input_file, img, h, w);

    //Create 2D array to hold numbers for colors from input image to create output image
    int out[MAX_H][MAX_W];

    //Store color numbers from input image in output array and modify them (based on question)
    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){
            //Invert color by doing 255 - the original color number
            out[row][col] = 255 - img[row][col];
        }
    }
    // and save this new image to file
    writeImage("taska.pgm",out, height, width);
}


//Complete
void inverthalf(int width, int height, int img[MAX_H][MAX_W]){
    //Create 2D array to hold numbers for colors from input image
//   int out[MAX_H][MAX_W];
  //  int h, w;

    //Take inImage.pgm color numbers and store them into the img 2D array (line 9)
//    readImage(input_file, img, h, w);

    //Create 2D array to hold numbers for colors from input image to create output image
    int out[MAX_H][MAX_W];

    //Store color numbers from input image in output array and modify them (based on question)
    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){
            //Invert colors in right half
            if(col > width/2){
                out[row][col] = 255 - img[row][col];
            }
            //Leave colors in left half alone
            else{
                out[row][col] = img[row][col];
            }
        }
    }
    // and save this new image to file
    writeImage("taskb.pgm", out, height, width);
}


//Complete
void box(int width, int height, int img[MAX_H][MAX_W]){
    //Create 2D array to hold numbers for colors from input image
//    int out[MAX_H][MAX_W];
//    int h, w;

    //Take inImage.pgm color numbers and store them into the img 2D array (line 9)
//    readImage(input_file, img, h, w);

    //Create 2D array to hold numbers for colors from input image to create output image
    int out[MAX_H][MAX_W];

    //Sides of white box
    int left = width/4;
    int right = 3*width/4;
    int top = height/4;
    int bottom = 3*height/4;

    //Store color numbers from input image in output array and modify them (based on question)
    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){
            //Change middle area to white to create a white box by staying within sides
            if ( (col <= right && col >= left) && (row >= top && row <= bottom) ){
                out[row][col] = 255;
            }
            //Leave everything else alone
            else{
                out[row][col] = img[row][col];
            }
        }
    }
    // and save this new image to file
    writeImage("taskc.pgm", out, height, width);

    //std::cout << w << " " << h << " " << std::endl;
    //std::cout << left << " " << right << " " << top << " " << bottom << " " << std::endl;

    // With cat photo
    // 250 194
    // 62 187 48 145
}


//Complete
void frame(int width, int height, int img[MAX_H][MAX_W]){
    //Create 2D array to hold numbers for colors from input image
//   int out[MAX_H][MAX_W];
//    int h, w;

    //Take inImage.pgm color numbers and store them into the img 2D array (line 9)
//    readImage(input_file, img, h, w);

    //Create 2D array to hold numbers for colors from input image to create output image
    int out[MAX_H][MAX_W];

    //Sides of white box
    int left = width / 4;
    int right = 3 * width / 4;
    int top = height / 4;
    int bottom = 3 * height / 4;

    //Store color numbers from input image in output array and modify them (based on question)
    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){
            //Change middle area to white to create a white box by staying within sides
            if ((col <= right && col >= left) && (row >= top && row <= bottom)){
                out[row][col] = 255;
            }
            //Leave everything else alone
            else{
                out[row][col] = img[row][col];
            }
            //Change inside of white area back to original but leave outer edge as white
            if ((col < right && col > left) && (row > top && row < bottom)){
                out[row][col] = img[row][col];
            }
        }
    }
    // and save this new image to file
    writeImage("taskd.pgm", out, height, width);
}


//Complete
void scale(int width, int height, int img[MAX_H][MAX_W]){
    //Create 2D array to hold numbers for colors from input image
//    int out[MAX_H][MAX_W];
//    int h, w;

    //Take inImage.pgm color numbers and store them into the img 2D array (line 9)
//    readImage(input_file, img, h, w);

    //Create 2D array to hold numbers for colors from input image to create output image
    int out[MAX_H][MAX_W];

    //Indexes that will direct the original numbers to a new spot, from there make square
    int down = 0;
    int right = 1;

    //Boolean for special case of top left pixel of original not moving
    //bool top_left_special = true;

    //Store color numbers from input image in output array and modify them (based on question)
    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){
            //Top left corner, should work , BECAUSE PUSH STARTS AT 0, THIS IS NOT NEEDED, SECOND IF TAKES CARE OF IT
            // if(top_left_special == true){
            //     //Top Left
            //     out[row][col] = img[row][col];
            //     //Top Right
            //     out[row][col+1] = img[row][col];
            //     //Bottom Left
            //     out[row+1][col] = img[row][col];
            //     //Bottom Right
            //     out[row+1][col+1] = img[row][col];
            //     top_left_special = false;
            // }
            //All left side squares, should work, pushed down before square
            if(col == 0){ //No need for top_left_special
                //Top Left
                out[row+down][col] = img[row][col];
                //Top Right
                out[row+down][col+1] = img[row][col];
                //Bottom Left
                out[row+down+1][col] = img[row][col];
                //Bottom Right
                out[row+down+1][col+1] = img[row][col];
            }
            //All other numbers in first row must be pushed right before square
            else if(row == 0 && col != 0 ){
                //Top Left
                out[row][col+right] = img[row][col];
                //Top Right
                out[row][col+right+1] = img[row][col];
                //Bottom Left
                out[row+1][col+right] = img[row][col];
                //Bottom Right
                out[row+1][col+right+1] = img[row][col];
                right++;
            }
            //All other numbers must be pushed right and down before square
            else{
                //Top Left
                out[row+down][col+right] = img[row][col];
                //Top Right
                out[row+down][col+right+1] = img[row][col];
                //Bottom Left
                out[row+down+1][col+right] = img[row][col];
                //Bottom Right
                out[row+down+1][col+right+1] = img[row][col];
                right++;
            }
        }
        //top_left_special = false;
        down++;
        right = 1;
    }
    // and save śhis new image to file "taska.pgm"
    writeImage("taske.pgm", out, height*5, width*5);
    //h*2 and w*2 because need 200% original size space
}


//Complete
void pixelate(int width, int height, int img[MAX_H][MAX_W]){
    //Create 2D array to hold numbers for colors from input image
//    int img[MAX_H][MAX_W];
//    int h, w;

    //Take inImage.pgm color numbers and store them into the img 2D array (line 9)
//    readImage(input_file, img, h, w);

    //Create 2D array to hold numbers for colors from input image to create output image
    int out[MAX_H][MAX_W];

    //Store color numbers from input image in output array and modify them (based on question)
    for (int row = 0; row < height; row+=2){
        for (int col = 0; col < width; col+=2){
            //Corners of Square
            int top_left = img[row][col];
            int top_right = img[row][col+1];
            int bottom_left = img[row+1][col];
            int bottom_right = img[row+1][col+1];

            //Average number
            int average = round((top_left+top_right+bottom_left+bottom_right)/4);

            //Assign average to corresponding squares (pixelate)
            out[row][col] = average;
            out[row][col+1] = average;
            out[row+1][col] = average;
            out[row+1][col+1] = average;
        }
    }
    // and save this new image to file
    writeImage("taskf.pgm", out, height, width);
}

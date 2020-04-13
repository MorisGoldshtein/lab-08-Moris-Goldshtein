#pragma once

const int MAX_H = 512;
const int MAX_W = 512;


void readImage(std::string filename, int image[MAX_H][MAX_W], int &height, int &width);

void writeImage(std::string filename, int image[MAX_H][MAX_W], int height, int width);

void task_a(std::string);

void task_b(std::string);

void task_c(std::string);

void task_d(std::string);

void task_e(std::string);

void task_f(std::string);
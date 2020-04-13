#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

#include "imagehelpers.h"
int main(){
    //Invert colors 
    task_a("inImage.pgm");
    //Invert colors right side
    task_b("inImage.pgm");
    //White box
    task_c("inImage.pgm");
    //White outline
    task_d("inImage.pgm");
    //200% scale
    task_e("inImage.pgm");    
    //Pixelate
    task_f("inImage.pgm");
}



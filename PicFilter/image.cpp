/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh
*/

#include "image.h"

#include <iostream>
using namespace std;

// Note: see image.h for documentation on functions.

int pixelToIndex(int width, int x, int y) {
    // TODO: implement this function correctly
    //y is number of rows above(which row the pixel is in), and x is number of col before it
    int pixN1 = (y*width*3) + (x*3);
    return pixN1; // this line is just filler so that the code compiles at first
}

void noRed(int width, int height, int* ppm) {
    // TODO: this image transformation
    //
    for(int nRow=0; nRow<height; nRow++){
        for(int nCol=0; nCol<width; nCol++){
          int indexRed = pixelToIndex(width, nCol, nRow);
          ppm[indexRed] = 0;
        }
    }
}

void noGreen(int width, int height, int* ppm) {
    // TODO: this image transformation
    for(int nRow=0; nRow<height; nRow++){
        for(int nCol=0; nCol<width; nCol++){
          int indexRed = pixelToIndex(width, nCol, nRow);
          ppm[indexRed+1] = 0;
        }
    }
}

void noBlue(int width, int height, int* ppm) {
    // TODO: this image transformation
    for(int nRow=0; nRow<height; nRow++){
        for(int nCol=0; nCol<width; nCol++){
          int indexRed = pixelToIndex(width, nCol, nRow);
          ppm[indexRed+2] = 0;
        }
    }
}

void invert(int width, int height, int* ppm) {
    // TODO: this image transformation
    for(int nRow=0; nRow<height; nRow++){
        for(int nCol=0; nCol<width; nCol++){
          int indexRed = pixelToIndex(width, nCol, nRow);
          ppm[indexRed] = 255-ppm[indexRed];
          ppm[indexRed+1] = 255-ppm[indexRed+1];
          ppm[indexRed+2] = 255-ppm[indexRed+2];
        }
    }
}

void grayscale(int width, int height, int* ppm) {
    // TODO: this image transformation
  for(int nRow=0; nRow<height; nRow++){
        for(int nCol=0; nCol<width; nCol++){
          int indexRed = pixelToIndex(width, nCol, nRow);
          int sum = ppm[indexRed]+ppm[indexRed+1]+ppm[indexRed+2];
          int average = sum/3;
          ppm[indexRed] = average;
          ppm[indexRed+1] = average;
          ppm[indexRed+2] = average;
        }
    }
}

void flipHorizontally(int width, int height, int* ppm) {
    // TODO: this image transformation
    /*for each row, get a point in col n and swap it with one in row(width-n-1)..and then move to the next row*/ 
    for(int nRow=0; nRow<height; nRow++){
        for(int nCol=0; nCol<(width/2); nCol++){
            int indexRed1 = pixelToIndex(width, nCol, nRow);
            int indexGreen1 = indexRed1+1;
            int indexBlue1 = indexRed1+2;
            int indexRed2 = pixelToIndex(width, (width-nCol-1), nRow);
            int indexGreen2 = indexRed2+1;
            int indexBlue2 = indexRed2+2;
            //swap
            int tempR=ppm[indexRed1];
            ppm[indexRed1]=ppm[indexRed2];
            ppm[indexRed2] = tempR;
            int tempG=ppm[indexGreen1];
            ppm[indexGreen1]=ppm[indexGreen2];
            ppm[indexGreen2] = tempG;
            int tempB=ppm[indexBlue1];
            ppm[indexBlue1]=ppm[indexBlue2];
            ppm[indexBlue2] = tempB;

        }
    }
}

void flipVertically(int width, int height, int* ppm) {
    // TODO: this image transformation
    /*for each column, get a point in row n and swap it with one in row(height-n-1)..and then move to the next column*/ 
    for(int nCol=0; nCol<width; nCol++){
        for(int nRow=0; nRow<(height/2); nRow++){
            int indexRed1 = pixelToIndex(width, nCol, nRow);
            int indexGreen1 = indexRed1+1;
            int indexBlue1 = indexRed1+2;
            int indexRed2 = pixelToIndex(width, nCol, (height-nRow-1));
            int indexGreen2 = indexRed2+1;
            int indexBlue2 = indexRed2+2;
            //swap
            int tempR=ppm[indexRed1];
            ppm[indexRed1]=ppm[indexRed2];
            ppm[indexRed2] = tempR;
            int tempG=ppm[indexGreen1];
            ppm[indexGreen1]=ppm[indexGreen2];
            ppm[indexGreen2] = tempG;
            int tempB=ppm[indexBlue1];
            ppm[indexBlue1]=ppm[indexBlue2];
            ppm[indexBlue2] = tempB;
        }
    }
}



// TODO: write your other image transformation functions here

/* Remember that the two flips are significantly harder than the
   other transofmations. We recommend that you work out the math
   on paper before attempting to write the code.
*/

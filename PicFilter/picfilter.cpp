/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh

  Dorothy Najjuma Kamya
  Program that modifies .ppm image files
*/

#include <iostream>
#include <string>

#include "image.h"
#include "ppmio.h"

using namespace std;

int main(int argc, char** argv) {
    // TODO: write your program here
    // Remember:
    //   * The first command-line argument in argv is always the name of the
    //     program.

    //if statement to make sure the transform instruction is feasible
    if(argc ==4){
        string instr = argv[2];
        if (instr=="noRed"||instr=="noGreen"||instr=="noBlue"||instr=="invert"||instr=="grayscale"||instr=="flipVertically"||instr=="flipHorizontally"){
                //reads in the filename
            string fileName = argv[1];
            
            //pass file name to the functions
            int nCol = ppm_width(fileName);
            int nRow = ppm_height(fileName);
            int* pixArray = read_ppm(fileName);
            if(instr=="noRed"){
                noRed(nCol,nRow,pixArray);
            }
            else if(instr=="noGreen"){
                noGreen(nCol,nRow,pixArray);
            }
            else if(instr=="noBlue"){
                noBlue(nCol,nRow,pixArray);
            }
            else if(instr=="grayscale"){
                grayscale(nCol,nRow,pixArray);
            }
            else if(instr=="flipHorizontally"){
                flipHorizontally(nCol,nRow,pixArray);
            }
            else if(instr=="flipVertically"){
                flipVertically(nCol,nRow,pixArray);
            }
            else if(instr=="invert"){
                invert(nCol,nRow,pixArray);
            }

            string newfile = argv[3];
            write_ppm(newfile,nCol,nRow,pixArray);
            delete[] pixArray;
        }
        else{
            cout<<"Invalid input for transformation!"<<endl;
        }
    }
    else{
        cout<<"Wrong number of arguments!"<<endl;
    }


    return 0;
}

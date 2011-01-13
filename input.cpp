#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "input.h"
#include "mainwindow.h"

using std::cout;
using std::endl;


input::input()
{
}


void input::addApertureDefinition(int defNum, char type, int x1, int x2 = 0, int x3 = 0, int x4 = 0){


}

void input::readGerber(std::string fileName){
    //int segment = -1;
    //double* xold = NULL;
    //xold = new int[inStr.length()];
    //double* yold = NULL;
    //yold = new int[inStr.length()];
    //std::vector<std::string> path;
    std::vector<std::string> apertures;
    //std::vector<std::string> macros;
    //int macrosN = 0;

    std::string line;

    cout << "Starting Parsing" << endl;

    std::ifstream inFile;

    inFile.open(fileName.c_str());

    bool leadingZerosOmitted = false;
    bool trailingZerosOmitted = false;
    bool explicitDecimalPoint = true;
    bool absoluteCoordinates = true; //False Means Incremental Cooridnates
    int formatXLeading = 2; //Number of Leading or Trailng Digits
    int formatYLeading = 2;
    int formatXTrailing = 3;
    int formatYTrailing = 3;
    bool unitsMM = false; //False Means Inches
    bool imagePolarityPos = true; //False Means Negitave



    int aptures = 0;
    int rectangles = 0;
    int oblongs = 0;


    while(!inFile.eof()){

        inFile >> line;

        if(line.find("%FS") != std::string::npos){
            //Format Statement

            cout << "Found Format Statement" << endl;

            if(line.find("L")){
                leadingZerosOmitted = true;
            }else if(line.find("T")){
                trailingZerosOmitted = true;
            }else{
                leadingZerosOmitted = false;
                trailingZerosOmitted = false;
            }

            if(line.find("D")){
                explicitDecimalPoint = true;
            }else{
                explicitDecimalPoint = true;
            }

            if(line.find("A")){
                absoluteCoordinates = true;
            }else if(line.find("I")){
                absoluteCoordinates = false;
            }//else fail/warn here

            if(line.find("X")){
                formatXLeading = int(line[line.find("X")+1]);
                formatXTrailing = int(line[line.find("X")+2]);
            }
            if(line.find("Y")){
                formatYLeading = int(line[line.find("Y")+1]);
                formatYTrailing = int(line[line.find("Y")+2]);
            }
            //Could also look for: Z-Format (like above)(rare, if ever), Sequence Number (Nn), Prepatory Function (Gn)(rare),
            //Draft Code (Dn), Misc. Code (Mn)

            continue;
        }
        else if(line.find("%MO") != std::string::npos){
            //Units

            if(line.find("IN")){
                unitsMM = false;
            }else if(line.find("MM")){
                unitsMM = true;
            }

            continue;
        }
        else if(line.find("%IP") != std::string::npos){
            //Image Polarity

            if(line.find("POS")){
                imagePolarityPos = true;
            }else if(line.find("NEG")){
                imagePolarityPos = false;
            }

            continue;
        }
        else if(line.find("%AM") != std::string::npos){
            //Aperture Definition
            cout << "Found Aperture Macro" << endl;
            if(line.find("C")){
                //Circle
                cout << "Found Circle Definition" << endl;
                continue;
            }
            else if(line.find("R") != std::string::npos){
                //Rectangle
                cout << "Found Rectangle Definition" << endl;
                continue;
            }
            else if(line.find("O") != std::string::npos){
                //Oblong
                cout << "Found Oblong Definition" << endl;
                continue;
            }
        }
        else if(line.find("%AD") != std::string::npos){
            //Aperture Description

            if(line.find("C")){
                //Circle
                if(line.find("X") != std::string::npos){
                    if(line.find("X", line.find("X")+1) != std::string::npos){
                        //Dos Equis: Circle with square hole.
                        //Not Supported
                    }else{
                        //One X: Circle Pad With Circle Hole
                    }
                }
            }
        }
        else if(line.find("D") == 0){
            //Change Aperture
            cout << "Found Change of Aperture" << endl;
        }
        else if(line.find("G54D") == 0){
            //Change Aperture
            cout << "Found Change of Aperture(G)" << endl;
        }
        else{
            //Unkown Command
            cout << "Unknown Connand: " << line << endl;
        }
    }

}

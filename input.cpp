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

    while(!inFile.eof()){

        inFile >> line;

        if(line.find("%FS") != std::string::npos){
            //Format Statement

            cout << "Found Format Statement" << endl;
            continue;
        }
        else if(line.find("%AM") != std::string::npos){
            //Aperture Macro
            cout << "Found Aperture Macro" << endl;

            //apertures.insert();

            continue;
        }
        else if(line.find("%AM") != std::string::npos){
            //Aperture Definition
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

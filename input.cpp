#include <string>
#include <vector>
#include "input.h"
#include "mainwindow.h"


input::input()
{
}

void input::readGerber(std::string inStr[], int inStrLen){
    int segment = -1;
    double* xold = NULL;
    //xold = new int[inStr.length()];
    double* yold = NULL;
    //yold = new int[inStr.length()];
    int line = 0;
    std::vector<std::string> path;
    std::vector<std::string> apertures;
    std::vector<std::string> macros;
    int macrosN = 0;

    while(line < inStrLen){
        if(inStr[line].find("%FS") != std::string::npos){
            //Format Statement
            continue;
        }
        else if(inStr[line].find("%AM") != std::string::npos){
            //Aperture Macro

            //apertures.insert();

            continue;
        }
        else if(inStr[line].find("%AM") != std::string::npos){
            //Aperture Definition
            if(inStr[line].find("C")){
                //Circle
                continue;
            }
            else if(inStr[line].find("R") != std::string::npos){
                //Rectangle
                continue;
            }
            else if(inStr[line].find("O") != std::string::npos){
                //Oblong
                continue;
            }
        }
        else if(inStr[line].find("D") == 0){
            //Change Aperture
        }
        else if(inStr[line].find("G54D") == 0){
            //Change Aperture
        }
    }

}

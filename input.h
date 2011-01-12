#ifndef INPUT_H
#define INPUT_H

class input
{
public:
    input();

<<<<<<< Updated upstream
    void readGerber(std::string);
=======
    void parseGerber(std::string*, int);

private:
    void addApertureDefinition(int, char, int, int, int, int);
>>>>>>> Stashed changes
};

#endif // INPUT_H

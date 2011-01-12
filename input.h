#ifndef INPUT_H
#define INPUT_H

class input
{
public:
    input();

    void readGerber(std::string);

private:
    void addApertureDefinition(int, char, int, int, int, int);
};

#endif // INPUT_H

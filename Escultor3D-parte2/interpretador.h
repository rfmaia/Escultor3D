#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include "figurageometrica.h"
#include <vector>
#include <string>

using namespace std;

/**
 * @brief A Classe Interpretador irá decodificar o arquivo com ".txt".
 */
class Interpretador{
    int dimx, dimy, dimz;
    float r, g, b, a;
public:
    Interpretador();
    vector<FiguraGeometrica*> parse(string filename);
    int getDimX();
    int getDimY();
    int getDimZ();
};

#endif // INTERPRETADOR_H

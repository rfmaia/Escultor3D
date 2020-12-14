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
    /**
     * @brief Interpretador é o construtor
     */
    Interpretador();
    /**
     * @brief parse
     * @param filename
     * @return
     */
    vector<FiguraGeometrica*> parse(string filename);
    /**
     * @brief getDimX
     * @return retorna o tamanho da dimensão x.
     */
    int getDimX();
    /**
     * @brief getDimY
     * @return retorna o tamanho da dimensão y.
     */
    int getDimY();
    /**
     * @brief getDimZ
     * @return retorna o tamanho da dimensão z.
     */
    int getDimZ();
};

#endif // INTERPRETADOR_H

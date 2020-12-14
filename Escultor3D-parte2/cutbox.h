#ifndef CUTBOX_H
#define CUTBOX_H
#include "sculptor.h"
#include "figurageometrica.h"

/**
 * @brief A Classe CutBox é uma subclasse que herda de FiguraGeometrica os métodos e removerá uma caixa de voxel.
 */
class CutBox : public FiguraGeometrica{
    int x0, x1, y0, y1, z0, z1;
public:
    /**
     * @brief CutBox é o construtor da subclasse.
     * @param x0 é a posição inicial do intervalo de x.
     * @param x1 é a posição final do intervalo de x.
     * @param y0 é a posição inicial do intervalo de y.
     * @param y1 é a posição final do intervalo de y.
     * @param z0 é a posição inicial do intervalo de z.
     * @param z1 é a posição final do intervalo de z.
     */
    CutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    ~CutBox();
    /**
     * @brief draw é o metodo abstrato herdado de FiguraGeometrica para realizar a remoção de uma caixa de voxel.
     * @param t é uma classe com nome Sculptor.
     */
    void draw(Sculptor& t);
};

#endif // CUTBOX_H

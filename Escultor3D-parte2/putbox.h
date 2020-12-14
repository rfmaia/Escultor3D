#ifndef PUTBOX_H
#define PUTBOX_H
#include "sculptor.h"
#include "figurageometrica.h"

/**
 * @brief A Classe PutBox é uma subclasse que herda de FiguraGeometrica os métodos e adicionará uma caixa de voxel.
 */
class PutBox : public FiguraGeometrica{
    int x0, x1, y0, y1, z0, z1;
public:
    /**
     * @brief PutBox é o construtor da subclasse.
     * @param x0 é a posição inicial do intervalo de x.
     * @param x1 é a posição final do intervalo de x.
     * @param y0 é a posição inicial do intervalo de y.
     * @param y1 é a posição final do intervalo de y.
     * @param z0 é a posição inicial do intervalo de z.
     * @param z1 é a posição final do intervalo de z.
     * @param r é a dosagem de vermelho(red).
     * @param g é a dosagem de verde(green).
     * @param b é a dosagem de azul(blue).
     * @param a é a dosagem de alpha(transparência).
     */
    PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);
    ~PutBox();
    /**
     * @brief draw é o metodo abstrato herdado de FiguraGeometrica para desenhar uma caixa de voxel.
     * @param t é uma classe com nome Sculptor.
     */
    void draw(Sculptor &t);
};

#endif // PUTBOX_H

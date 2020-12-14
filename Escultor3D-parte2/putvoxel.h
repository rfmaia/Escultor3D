#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "sculptor.h"
#include "figurageometrica.h"

/**
 * @brief A Classe PutVoxel é uma subclasse que herda de FiguraGeometrica os métodos e adicionará um voxel.
 */
class PutVoxel : public FiguraGeometrica{
    int x, y, z;
public:
    /**
     * @brief PutVoxel é o construtor da subclasse.
     * @param x é a posição x.
     * @param y é a posição y.
     * @param z é a posição z.
     * @param r é a dosagem de vermelho(red).
     * @param g é a dosagem de verde(green).
     * @param b é a dosagem de azul(blue).
     * @param a é a dosagem de alpha(transparência).
     */
    PutVoxel(int x, int y, int z, float r, float g, float b, float a);
    ~PutVoxel();
    /**
     * @brief draw é o metodo abstrato herdado de FiguraGeometrica para desenhar um voxel.
     * @param t é uma classe com nome Sculptor.
     */
    void draw(Sculptor &t);
};

#endif // PUTVOXEL_H

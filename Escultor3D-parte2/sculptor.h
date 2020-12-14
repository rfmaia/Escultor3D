#ifndef SCULPTOR_H
#define SCULPTOR_H
#include <voxel.h>

/**
 * @brief A classe Sculptor serve para criar a escultura de voxel.
 *
 * @details Uma matriz 3D do tipo Voxel será alocada dinamicamente para construir a escultura 3D.
 */
class Sculptor {
protected:
  Voxel ***v;
  int nx, ny, nz;
  float r, g, b, a;
public:
  /**
     * @brief Sculptor é o construtor da classe.
     * @param _nx é a dimensão de eixo x.
     * @param _ny é a dimensão de eixo y.
     * @param _nz é a dimensão de eixo z.
     */
  Sculptor(int _nx, int _ny, int _nz);
  /**
   * @brief ~Sculptor é o destrutor da classe.
   */
  ~Sculptor();
  /**
   * @brief setColor define a cor atual de desenho.
   * @details As variáveis que armazenam a cor rgba devem assumir valores entre 0 e 1.
   * @param r é a dosagem de vermelho(red).
   * @param g é a dosagem de verde(green).
   * @param b é a dosagem de azul(blue).
   * @param alpha é a dosagem de alpha(transparência).
   */
  void setColor(float r, float g, float b, float alpha);
  /**
   * @brief putVoxel ativa o voxel na posição \f$ (x, y, z) \f$ (fazendo isOn = true) e atribui ao mesmo a cor atual de desenho.
   * @param x é a posição x.
   * @param y é a posição y.
   * @param z é a posição z.
   */
  void putVoxel(int x, int y, int z);
  /**
   * @brief cutVoxel desativa o voxel na posição \f$ (x, y, z) \f$ (fazendo isOn = false)
   * @param x é a posição x.
   * @param y é a posição y.
   * @param z é a posição z.
   */
  void cutVoxel(int x, int y, int z);
  /**
   * @brief writeOFF grava a escultura no formato OFF no arquivo filename.
   * @param filename é o nome do arquivo.
   */
  void writeOFF(char* filename);
};

void troca(int &x, int &y);

#endif // SCULPTOR_H

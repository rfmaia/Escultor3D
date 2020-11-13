#ifndef SCULPTOR_H
#define SCULPTOR_H

/**
 * @brief A estrutura de dado Voxel serve para armazenar a cor e transparência de um voxel.
 *
 * @details As variaveis que armazenam a cor rgba podem assumir valores entre 0 e 1,
 * @details enquanto isOn recebe um valor booleano TRUE ou FALSE para indicar se o voxel está ativo ou não.
 */
struct Voxel {
  /**
   * @brief r armazena a dosagem de vermelho(red).
   */
  float r;
  /**
   * @brief g armazena a dosagem de verde(green).
   */
  float g;
  /**
   * @brief b armazena a dosagem de azul(blue).
   */
  float b;
  /**
   * @brief a armazena a dosagem de alpha.
   */
  float a;
  /**
   * @brief isOn armazena se o voxel está incluido ou não.
   */
  bool isOn;
};

/**
 * @brief A classe Sculptor serve para criar a escultura de voxel.
 *
 * @details Uma matriz 3D do tipo Voxel será alocada dinamicamente para a construção de uma escultura 3D.
 */
class Sculptor {
protected:
  /**
   * @brief v
   */
  Voxel ***v; // 3D matrix
  /**
   * @brief nx
   */
  int nx;
  /**
   * @brief ny
   */
  int ny;
  /**
   * @brief nz
   */
  int nz; // Dimensions
  /**
   * @brief r
   */
  float r;
  /**
   * @brief g
   */
  float g;
  /**
   * @brief b
   */
  float b;
  /**
   * @brief a
   */
  float a; // Current drawing color
public:
  /**
   * @brief Sculptor é o construtor da classe.
   * @param _nx
   * @param _ny
   * @param _nz
   */
  Sculptor(int _nx, int _ny, int _nz);
  /**
   * @brief ~Sculptor é o destrutor da classe.
   */
  ~Sculptor();
  /**
   * @brief setColor define a cor atual de desenho.
   * @param r
   * @param g
   * @param b
   * @param alpha
   */
  void setColor(float r, float g, float b, float alpha);
  /**
   * @brief putVoxel
   * @param x
   * @param y
   * @param z
   */
  void putVoxel(int x, int y, int z);
  /**
   * @brief cutVoxel
   * @param x
   * @param y
   * @param z
   */
  void cutVoxel(int x, int y, int z);
  /**
   * @brief putBox
   * @param x0
   * @param x1
   * @param y0
   * @param y1
   * @param z0
   * @param z1
   */
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /**
   * @brief cutBox
   * @param x0
   * @param x1
   * @param y0
   * @param y1
   * @param z0
   * @param z1
   */
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /**
   * @brief putSphere
   * @param xcenter
   * @param ycenter
   * @param zcenter
   * @param radius
   */
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  /**
   * @brief cutSphere
   * @param xcenter
   * @param ycenter
   * @param zcenter
   * @param radius
   */
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  /**
   * @brief putEllipsoid
   * @param xcenter
   * @param ycenter
   * @param zcenter
   * @param rx
   * @param ry
   * @param rz
   */
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  /**
   * @brief cutEllipsoid
   * @param xcenter
   * @param ycenter
   * @param zcenter
   * @param rx
   * @param ry
   * @param rz
   */
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  /**
   * @brief writeOFF grava a escultura no formato OFF no arquivo filename
   * @param filename
   */
  void writeOFF(char* filename);
};

#endif // SCULPTOR_H

#ifndef SCULPTOR_H
#define SCULPTOR_H

/**
 * @brief A estrutura de dado Voxel serve para armazenar a cor e transparência de um voxel.
 *
 * @details As variaveis que armazenam a cor rgba podem assumir valores entre 0 e 1, enquanto isOn recebe um valor booleano TRUE ou FALSE para indicar se o voxel está ativo ou não.
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
   * @brief a armazena a dosagem de alpha(transparência).
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
 * @details Uma matriz 3D do tipo Voxel será alocada dinamicamente para construir a escultura 3D.
 */
class Sculptor {
protected:
  /**
   * @brief v é a matriz 3D de voxels.
   */
  Voxel ***v;
  /**
   * @brief nx é a dimensão no eixo x.
   */
  int nx;
  /**
   * @brief ny é a dimensão no eixo y.
   */
  int ny;
  /**
   * @brief nz é a dimensão no eixo z.
   */
  int nz;
  /**
   * @brief r é a dosagem de vermelho(red).
   */
  float r;
  /**
   * @brief g é a dosagem de verde(green).
   */
  float g;
  /**
   * @brief b é a dosagem de azul(blue).
   */
  float b;
  /**
   * @brief a é a dosagem de alpha(transparência).
   */
  float a;
public:
  /**
   * @brief Sculptor é o construtor da classe.
   * @param _nx é a dimensão no eixo x.
   * @param _ny é a dimensão no eixo y.
   * @param _nz é a dimensão no eixo z.
   */
  Sculptor(int _nx, int _ny, int _nz);
  /**
   * @brief ~Sculptor é o destrutor da classe.
   */
  ~Sculptor();
  /**
   * @brief setColor define a cor atual de desenho.
   * @details As variaveis que armazenam a cor rgba podem assumir valores entre 0 e 1.
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
   * @brief putBox ativa todos os voxels no intervalo \f$ x \in [x_0, x_1] \f$ , \f$ y \in [y_0, y_1] \f$, \f$ z \in [z_0, z_1] \f$ e atribui aos mesmos a cor atual de desenho.
   * @param x0
   * @param x1
   * @param y0
   * @param y1
   * @param z0
   * @param z1
   */
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /**
   * @brief cutBox desativa todos os voxels no intervalo \f$ x \in [x_0, x_1] \f$ , \f$ y \in [y_0, y_1] \f$, \f$ z \in [z_0, z_1] \f$ e atribui aos mesmos a cor atual de desenho.
   * @param x0
   * @param x1
   * @param y0
   * @param y1
   * @param z0
   * @param z1
   */
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /**
   * @brief putSphere ativa todos os voxels que satisfazem à equação da esfera e atribui aos mesmos a cor atual de desenho \f$ (r, g, b, a) \f$.
   * @param xcenter
   * @param ycenter
   * @param zcenter
   * @param radius
   */
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  /**
   * @brief cutSphere desativa todos os voxels que satisfazem à equação da esfera.
   * @param xcenter
   * @param ycenter
   * @param zcenter
   * @param radius
   */
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  /**
   * @brief putEllipsoid ativa todos os voxels que satisfazem à equação do elipsóide e atribui aos mesmos a cor atual de desenho.
   * @param xcenter
   * @param ycenter
   * @param zcenter
   * @param rx
   * @param ry
   * @param rz
   */
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  /**
   * @brief cutEllipsoid desativa todos os voxels que satisfazem à equação do elipsóide.
   * @param xcenter
   * @param ycenter
   * @param zcenter
   * @param rx
   * @param ry
   * @param rz
   */
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  /**
   * @brief writeOFF grava a escultura no formato OFF no arquivo filename.
   * @details Lembre-se de colocar o diretório completo para evitar possíveis erros. Como por exemplo: **tree.writeOFF((char*)"D:/tree.off");**
   * @param filename é o nome do arquivo.
   */
  void writeOFF(char* filename);
};

#endif // SCULPTOR_H

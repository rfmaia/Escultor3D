#ifndef SCULPTOR_H
#define SCULPTOR_H

/**
 * @brief A estrutura de dado Voxel serve para armazenar a cor e transparência de um voxel.
 *
 * @details As variáveis que armazenam a cor rgba podem assumir valores entre 0 e 1, enquanto isOn recebe um valor booleano TRUE ou FALSE para indicar se o voxel está ativo ou não.
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
   * @brief nx é a dimensão de eixo x.
   */
  int nx;
  /**
   * @brief ny é a dimensão de eixo y.
   */
  int ny;
  /**
   * @brief nz é a dimensão de eixo z.
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
   * @brief putBox ativa todos os voxels no intervalo \f$ x \in [x_0, x_1] \f$ , \f$ y \in [y_0, y_1] \f$, \f$ z \in [z_0, z_1] \f$ e atribui aos mesmos a cor atual de desenho.
   * @param x0 é a posição inicial do intervalo de x.
   * @param x1 é a posição final do intervalo de x.
   * @param y0 é a posição inicial do intervalo de y.
   * @param y1 é a posição final do intervalo de y.
   * @param z0 é a posição inicial do intervalo de z.
   * @param z1 é a posição final do intervalo de z.
   */
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /**
   * @brief cutBox desativa todos os voxels no intervalo \f$ x \in [x_0, x_1] \f$ , \f$ y \in [y_0, y_1] \f$, \f$ z \in [z_0, z_1] \f$ e atribui aos mesmos a cor atual de desenho.
   * @param x0 é a posição inicial do intervalo de x.
   * @param x1 é a posição final do intervalo de x.
   * @param y0 é a posição inicial do intervalo de y.
   * @param y1 é a posição final do intervalo de y.
   * @param z0 é a posição inicial do intervalo de z.
   * @param z1 é a posição final do intervalo de z.
   */
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /**
   * @brief putSphere ativa todos os voxels que satisfazem à equação da esfera e atribui aos mesmos a cor atual de desenho \f$ (r, g, b, a) \f$.
   * @param xcenter é o centro da esfera no eixo x.
   * @param ycenter é o centro da esfera no eixo y.
   * @param zcenter é o centro da esfera no eixo z.
   * @param radius é o raio da esfera.
   */
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  /**
   * @brief cutSphere desativa todos os voxels que satisfazem à equação da esfera.
   * @param xcenter é o centro da esfera no eixo x.
   * @param ycenter é o centro da esfera no eixo y.
   * @param zcenter é o centro da esfera no eixo z.
   * @param radius é o raio da esfera.
   */
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  /**
   * @brief putEllipsoid ativa todos os voxels que satisfazem à equação do elipsóide e atribui aos mesmos a cor atual de desenho.
   * @param xcenter é o centro do elipsóide no eixo x.
   * @param ycenter é o centro do elipsóide no eixo y.
   * @param zcenter é o centro do elipsóide no eixo z.
   * @param rx é o semieixo do elipsóide no eixo x.
   * @param ry é o semieixo do elipsóide no eixo y.
   * @param rz é o semieixo do elipsóide no eixo z.
   */
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  /**
   * @brief cutEllipsoid desativa todos os voxels que satisfazem à equação do elipsóide.
   * @param xcenter é o centro do elipsóide no eixo x.
   * @param ycenter é o centro do elipsóide no eixo y.
   * @param zcenter é o centro do elipsóide no eixo z.
   * @param rx é o semieixo do elipsóide no eixo x.
   * @param ry é o semieixo do elipsóide no eixo y.
   * @param rz é o semieixo do elipsóide no eixo z.
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

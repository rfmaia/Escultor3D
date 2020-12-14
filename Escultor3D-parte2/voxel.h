#ifndef VOXEL_H
#define VOXEL_H

/**
 * @brief A estrutura de dado Voxel serve para armazenar a cor e transparência de um voxel.
 *
 * @details As variáveis que armazenam a cor rgba podem assumir valores entre 0 e 1, enquanto isOn recebe um valor booleano TRUE ou FALSE para indicar se o voxel está ativo ou não.
 */
struct Voxel {
  float r, g, b, a;
  bool isOn;
};

#endif // VOXEL_H

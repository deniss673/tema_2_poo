//
// Created by Denis on 5/7/2023.
//

#ifndef OOP_T_TETROMINO_H
#define OOP_T_TETROMINO_H

#include "pieces.h"


class t_tetromino : public pieces{
sf::Vector2i position;
sf::Color color;
std::vector<int> shape;
int size_o;
int size_v;
int rotate;
int number_rotate;
std::vector <int> big_shape;
static void set_t_tetromino(std::shared_ptr<pieces> &tPtr);

public:
t_tetromino();
~t_tetromino();
t_tetromino(sf::Vector2i position_, sf::Color color_,const std::vector<int>& shape_, int size_o_,int size_v_,int rotate_, int number_rotate_,const std::vector<int>& big_shape_);
t_tetromino(const t_tetromino& other);
t_tetromino& operator=(const t_tetromino& other);
void rotate_piece(std::shared_ptr<pieces>& tPtr) override;
std::shared_ptr<pieces> clone() const;
};


#endif //OOP_T_TETROMINO_H

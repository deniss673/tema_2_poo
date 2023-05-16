//
// Created by Denis on 4/27/2023.
//

#ifndef OOP_L_TETROMINO_H
#define OOP_L_TETROMINO_H

#include "pieces.h"


class l_tetromino: public pieces{

private:
sf::Vector2i position;
sf::Color color;
std::vector<int> shape;
int size_o;
int size_v;
int rotate;
int number_rotate;
std::vector <int> big_shape;
static void set_l_tetromino(std::shared_ptr<pieces> &lPtr);

public:
    l_tetromino();
    ~l_tetromino();
    l_tetromino(sf::Vector2i position_, sf::Color color_,const std::vector<int>& shape_, int size_o_,int size_v_,int rotate_, int number_rotate_,const std::vector<int>& big_shape_);
    l_tetromino(const l_tetromino& other);
    l_tetromino& operator=(const l_tetromino& other);
    void rotate_piece(std::shared_ptr<pieces>& lPtr) override;
    std::shared_ptr<pieces> clone() const;

 };


#endif //OOP_L_TETROMINO_H

//
// Created by Denis on 5/7/2023.
//

#ifndef OOP_Z_TETROMINO_H
#define OOP_Z_TETROMINO_H
#include "pieces.h"


class z_tetromino : public pieces{
    sf::Vector2i position;
    sf::Color color;
    std::vector<int> shape;
    int size_o;
    int size_v;
    int rotate;
    int number_rotate;
    std::vector <int> big_shape;
    static void set_z_tetromino(std::shared_ptr<pieces> &zPtr);
public:
    z_tetromino();
    ~z_tetromino();
    z_tetromino(sf::Vector2i position_, sf::Color color_,const std::vector<int>& shape_, int size_o_,int size_v_,int rotate_, int number_rotate_,const std::vector<int>& big_shape_);
    z_tetromino(const z_tetromino& other);
    z_tetromino& operator=(const z_tetromino& other);
    void rotate_piece(std::shared_ptr<pieces>& zPtr) override;
    std::shared_ptr<pieces> clone() const;
};

#endif //OOP_Z_TETROMINO_H

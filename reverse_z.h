//
// Created by Denis on 5/7/2023.
//

#ifndef OOP_REVERSE_Z_H
#define OOP_REVERSE_Z_H

#include "pieces.h"

class reverse_z : public pieces{

private:
    sf::Vector2i position;
    sf::Color color;
    std::vector<int> shape;
    int size_o;
    int size_v;
    int rotate;
    int number_rotate;
    std::vector <int> big_shape;

public:
    reverse_z();
    ~reverse_z();
    reverse_z(sf::Vector2i position_, sf::Color color_, int size_o_,int size_v_,const std::vector<int> shape_,int rotate_, int number_rotate_,const std::vector<int> big_shape_);
    reverse_z(const reverse_z& other);
    reverse_z& operator=(const reverse_z& other);
    static void set_reverse_z(std::shared_ptr<pieces> &r_zPtr);
    void rotate_piece(std::shared_ptr<pieces>& r_zPtr) override;

    std::vector<int> next_rotate(std::shared_ptr<pieces>& r_zPtr) override;



};


#endif //OOP_REVERSE_Z_H

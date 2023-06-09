//
// Created by Denis on 5/7/2023.
//

#ifndef OOP_REVERSE_L_H
#define OOP_REVERSE_L_H

#include "pieces.h"

class reverse_l : public pieces{

private:
    sf::Vector2i position;
    sf::Color color;
    std::vector<int> shape;
    int size_o;
    int size_v;
    int rotate;
    int number_rotate;
    std::vector<int> big_shape;
    static void set_reverse_l(std::shared_ptr<pieces> &rlPtr);
public:
    reverse_l();
    ~reverse_l();
    reverse_l(sf::Vector2i position_, sf::Color color_,const std::vector<int>& shape_, int size_o_,int size_v_,int rotate_, int number_rotate_,const std::vector<int>& big_shape_);
    reverse_l(const reverse_l& other);
    reverse_l& operator=(const reverse_l& other);
    void rotate_piece(std::shared_ptr<pieces>& rlPtr) override;
    std::shared_ptr<pieces> clone() const;
};


#endif //OOP_REVERSE_L_H

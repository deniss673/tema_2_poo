//
// Created by Denis on 4/27/2023.
//

#ifndef OOP_SQUARE_H
#define OOP_SQUARE_H

#include "pieces.h"


class square: public pieces{
private:
    sf::Vector2i position;
    sf::Color color;
    std::vector<int> shape;
    int size_o;
    int size_v;
    std::vector <int> big_shape;
public:
    square();
    ~square();
    square(sf::Vector2i position_, sf::Color color_,const std::vector<int>& shape_,int size_o_,int size_v_,const std::vector<int>& big_shape_);
    square(const square& other);
    square& operator=(const square& other);
    void rotate_piece(std::shared_ptr<pieces>& squarePtr) override{
        squarePtr->set_shape(squarePtr->get_shape());
    }
    std::shared_ptr<pieces> clone() const;
    static void setsquare(std::shared_ptr<pieces> &squarePtr);
};

#endif //OOP_SQUARE_H

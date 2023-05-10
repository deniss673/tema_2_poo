//
// Created by Denis on 5/7/2023.
//

#include "z_tetromino.h"

z_tetromino::z_tetromino()=default;
z_tetromino::~z_tetromino(){}

z_tetromino::z_tetromino(sf::Vector2i position_, sf::Color color_,const std::vector<int>& shape_, int size_o_, int size_v_, int rotate_, int number_rotate_,const std::vector<int>& big_shape_) :position{position_},color{color_},shape{shape_},size_o{size_o_},size_v{size_v_},rotate{rotate_},number_rotate{number_rotate_},big_shape{big_shape_}{}

z_tetromino::z_tetromino(const z_tetromino &other):pieces(other), position{other.position},color{other.color},shape{other.shape},size_o{other.size_o},size_v{other.size_v},rotate{other.rotate},number_rotate{other.number_rotate},big_shape{other.big_shape} {}
z_tetromino &z_tetromino::operator=(const z_tetromino &other) {
    if (this != &other) {
        position = other.position;
        color = other.color;
        size_o = other.size_o;
        size_v = other.size_v;
        shape = other.shape;
        rotate = other.rotate;
        number_rotate = other.number_rotate;
    }
    return *this;
}
void z_tetromino::set_z_tetromino(std::shared_ptr<pieces> &zPtr) {
    zPtr->set_position(sf::Vector2i(4, 0));
    zPtr->set_color(sf::Color(255, 0, 0));
    zPtr->set_shape({1,1,0,0,1,1});
    zPtr->set_size_o(3);
    zPtr->set_size_v(2);
    zPtr->set_rotate(0);
    zPtr->set_number_rotate(2);
    zPtr->set_big_shape({0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0});
}

void z_tetromino::rotate_piece(std::shared_ptr<pieces> &zPtr) {
    int test=zPtr->get_rotate();
    if(test==0){
        zPtr->set_shape({0,1,1,1,1,0});
        zPtr->set_size_o(2);
        zPtr->set_size_v(3);
    }
    else if(test==1){
        zPtr->set_shape({1,1,0,0,1,1});
        zPtr->set_size_o(3);
        zPtr->set_size_v(2);
    }
    test=test+1;
    test=test%zPtr->get_number_rotate();
    zPtr->set_rotate(test);
}

std::vector<int> z_tetromino::next_rotate(std::shared_ptr<pieces> &zPtr) {
    int x=zPtr->get_rotate()+1;
    x=x%zPtr->get_number_rotate();
    if(x==0){
        return {0,1,1,1,1,0};
    }
    else{
        return {1,1,0,0,1,1};
    }
}

//
// Created by Denis on 4/27/2023.
//

#include "l_tetromino.h"

l_tetromino::l_tetromino()=default;
l_tetromino::~l_tetromino(){}

l_tetromino::l_tetromino(sf::Vector2i position_, sf::Color color_, int size_o_,int size_v_,std::vector<int> shape_,int nume_,int rotate_, int number_rotate_, std::vector<int> big_shape_):position{position_},color{color_},size_o{size_o_},size_v{size_v_},shape{shape_},nume{nume_},rotate{rotate_},number_rotate{number_rotate_},
                                                                                                                                                                                           big_shape{big_shape_}{}
l_tetromino::l_tetromino(const l_tetromino &other): position{other.position},color{other.color},size_o{other.size_o},size_v{other.size_v},shape{other.shape},rotate{other.rotate},number_rotate{other.number_rotate} {}

l_tetromino &l_tetromino::operator=(const l_tetromino &other) {
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

void l_tetromino::set_l_tetromino(std::shared_ptr<pieces> &lPtr) {
    lPtr->set_position(sf::Vector2i(4, 0));
    lPtr->set_color(sf::Color(255, 165, 0));
    lPtr->set_shape({0,0,1,1,1,1});
    lPtr->set_size_o(3);
    lPtr->set_size_v(2);
    lPtr->set_nume(1);
    lPtr->set_rotate(0);
    lPtr->set_number_rotate(4);
    lPtr->set_big_shape({0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0});
}

void l_tetromino::rotate_piece(std::shared_ptr<pieces> &lPtr) {
    int size_v=lPtr->Size_o();
    int size_o=lPtr->Size_v();
    int x=lPtr->get_rotate();
    if(x==0){
        lPtr->set_shape({1,0,1,0,1,1});
    }
    else if(x==1){
        lPtr->set_shape({1,1,1,1,0,0});
    }
    else if(x==2){
        lPtr->set_shape({1,1,0,1,0,1});
    }
    else{
        lPtr->set_shape({0,0,1,1,1,1});
    }
    x=(lPtr->get_rotate()+1)%lPtr->get_number_rotate();
    lPtr->set_size_o(size_o);
    lPtr->set_size_v(size_v);
    lPtr->set_rotate(x);
}

std::vector<int> l_tetromino::next_rotate(std::shared_ptr<pieces>& lPtr) {
    int x=lPtr->get_rotate();
    x=x+1;
    x=x%lPtr->get_number_rotate();
    if(x==0){
        return {1,0,1,0,1,1};
    }
    else if(x==1){
        return {1,1,1,1,0,0};
    }
    else if(x==2){
        return {1,1,0,1,0,1};
    }
    else{
        return {0,0,1,1,1,1};
    }
}






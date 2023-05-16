//
// Created by Denis on 5/7/2023.
//

#include "t_tetromino.h"

t_tetromino::t_tetromino()=default;
t_tetromino::~t_tetromino(){}

t_tetromino::t_tetromino(sf::Vector2i position_, sf::Color color_,const std::vector<int>& shape_, int size_o_, int size_v_, int rotate_, int number_rotate_,const std::vector<int>& big_shape_) :position{position_},color{color_},shape{shape_},size_o{size_o_},size_v{size_v_},rotate{rotate_},number_rotate{number_rotate_},big_shape{big_shape_}{}
t_tetromino::t_tetromino(const t_tetromino &other):pieces(other), position{other.position},color{other.color},shape{other.shape},size_o{other.size_o},size_v{other.size_v},rotate{other.rotate},number_rotate{other.number_rotate},big_shape{other.big_shape} {}

t_tetromino &t_tetromino::operator=(const t_tetromino &other) {
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
void t_tetromino::set_t_tetromino(std::shared_ptr<pieces> &tPtr) {
    tPtr->set_position(sf::Vector2i(4, 0));
    tPtr->set_color(sf::Color(128,0,128));
    tPtr->set_shape({0,1,0,1,1,1});
    tPtr->set_size_o(3);
    tPtr->set_size_v(2);
    tPtr->set_rotate(0);
    tPtr->set_number_rotate(4);
    tPtr->set_big_shape({0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0});
}

void t_tetromino::rotate_piece(std::shared_ptr<pieces> &tPtr) {
    int size_v_=tPtr->Size_o();
    int size_o_=tPtr->Size_v();
    int x=tPtr->get_rotate();
    if(x==0){
        tPtr->set_shape({1,0,1,1,1,0});
    }
    else if(x==1){
        tPtr->set_shape({1,1,1,0,1,0});
    }
    else if(x==2){
        tPtr->set_shape({0,1,1,1,0,1});
    }
    else{
        tPtr->set_shape({0,1,0,1,1,1});
    }
    x=x+1;
    x=x%tPtr->get_number_rotate();
    tPtr->set_size_o(size_o_);
    tPtr->set_size_v(size_v_);
    tPtr->set_rotate(x);
}
std::shared_ptr<pieces> t_tetromino::clone() const {
    std::shared_ptr<pieces> cloned = std::make_shared<t_tetromino>(*this);
    set_t_tetromino(cloned);
    return cloned;
}



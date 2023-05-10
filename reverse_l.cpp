//
// Created by Denis on 5/7/2023.
//

#include "reverse_l.h"

reverse_l::reverse_l()=default;
reverse_l::~reverse_l(){}

reverse_l::reverse_l(sf::Vector2i position_, sf::Color color_, int size_o_,int size_v_,const std::vector<int>& shape_,int rotate_, int number_rotate_,const std::vector<int>& big_shape_):position{position_},color{color_},size_o{size_o_},size_v{size_v_},shape{shape_},rotate{rotate_},number_rotate{number_rotate_},
                                                                                                                                                                                       big_shape{big_shape_}{}

reverse_l::reverse_l(const reverse_l &other): position{other.position},color{other.color},size_o{other.size_o},size_v{other.size_v},shape{other.shape},rotate{other.rotate},number_rotate{other.number_rotate} {}

reverse_l &reverse_l::operator=(const reverse_l &other) {
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
void reverse_l::set_reverse_l(std::shared_ptr<pieces> &rlPtr) {
    rlPtr->set_position(sf::Vector2i(4, 0));
    rlPtr->set_color(sf::Color(0, 0, 165));
    rlPtr->set_shape({1,0,0,1,1,1});
    rlPtr->set_size_o(3);
    rlPtr->set_size_v(2);
    rlPtr->set_rotate(0);
    rlPtr->set_number_rotate(4);
    rlPtr->set_big_shape({0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0});
}

void reverse_l::rotate_piece(std::shared_ptr<pieces> &rlPtr) {
    int size_v_=rlPtr->Size_o();
    int size_o_=rlPtr->Size_v();
    int x=rlPtr->get_rotate();
    if(x==0){
        rlPtr->set_shape({1,1,1,0,1,0});
    }
    else if(x==1){
        rlPtr->set_shape({1,1,1,0,0,1});
    }
    else if(x==2){
        rlPtr->set_shape({0,1,0,1,1,1});
    }
    else{
        rlPtr->set_shape({1,0,0,1,1,1});
    }
    x=x+1;
    x=x%rlPtr->get_number_rotate();
    rlPtr->set_size_o(size_o_);
    rlPtr->set_size_v(size_v_);
    rlPtr->set_rotate(x);
}

std::vector<int> reverse_l::next_rotate(std::shared_ptr<pieces>& rlPtr) {
    int x=rlPtr->get_rotate()+1;
    x=x%rlPtr->get_number_rotate();

    if(x==0){
        return {1,1,1,0,1,0};
    }
    else if(x==1){
        return {1,1,1,0,0,1};
    }
    else if(x==2){
        return {0,1,0,1,1,1};
    }
    else{
        return {1,0,0,1,1,1};
    }
}

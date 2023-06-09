//
// Created by Denis on 5/7/2023.
//

#include "reverse_z.h"

reverse_z::reverse_z()=default;
reverse_z::~reverse_z(){}
reverse_z::reverse_z(sf::Vector2i position_, sf::Color color_,const std::vector<int>& shape_, int size_o_,int size_v_,int rotate_, int number_rotate_,const std::vector<int>& big_shape_):position{position_},color{color_},shape{shape_},size_o{size_o_},size_v{size_v_},rotate{rotate_},number_rotate{number_rotate_},
                                                                                                                                                                                       big_shape{big_shape_}{}
reverse_z::reverse_z(const reverse_z &other):pieces(other), position{other.position},color{other.color},shape{other.shape},size_o{other.size_o},size_v{other.size_v},rotate{other.rotate},number_rotate{other.number_rotate},big_shape{other.big_shape} {}

reverse_z &reverse_z::operator=(const reverse_z &other) {
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
void reverse_z::set_reverse_z(std::shared_ptr<pieces> &r_zPtr) {
    r_zPtr->set_position(sf::Vector2i(4, 0));
    r_zPtr->set_color(sf::Color(0, 255, 0));
    r_zPtr->set_shape({0,1,1,1,1,0});
    r_zPtr->set_size_o(3);
    r_zPtr->set_size_v(2);
    r_zPtr->set_rotate(0);
    r_zPtr->set_number_rotate(2);
    r_zPtr->set_big_shape({0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0});
}

void reverse_z::rotate_piece(std::shared_ptr<pieces> &r_zPtr) {
    int test=r_zPtr->get_rotate();
    if(test==0){
        r_zPtr->set_shape({1,0,1,1,0,1});
        r_zPtr->set_size_o(2);
        r_zPtr->set_size_v(3);
    }
    else if(test==1){
        r_zPtr->set_shape({0,1,1,1,1,0});
        r_zPtr->set_size_o(3);
        r_zPtr->set_size_v(2);
    }
    int x=test+1;
    x=x%r_zPtr->get_number_rotate();
    r_zPtr->set_rotate(x);
}
std::shared_ptr<pieces> reverse_z::clone() const {
    std::shared_ptr<pieces> cloned = std::make_shared<reverse_z>(*this);
    set_reverse_z(cloned);
    return cloned;
}




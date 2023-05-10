//
// Created by Denis on 4/24/2023.
//

#include "pieces.h"

pieces::pieces(sf::Vector2i position_, sf::Color color_, int size_o_,int size_v_,const std::vector<int>& shape_,int rotate_, int number_rotate_,const std::vector<int>& big_shape_):position{position_},color{color_},size_o{size_o_},size_v{size_v_},shape{shape_},rotate{rotate_},number_rotate{number_rotate_},
                                                                                                                                                                                 big_shape{big_shape_}{}
pieces::pieces() {}

pieces::pieces(const pieces &other): position{other.position},color{other.color},size_o{other.size_o},size_v{other.size_v},shape{other.shape},rotate{other.rotate},number_rotate{other.number_rotate} {}

pieces &pieces::operator=(const pieces &other) {
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

void pieces::move_down() {
    position.y=position.y+1;
}

std::vector<int> pieces::get_big_shape() {
    return big_shape;
}

void pieces::set_big_shape(const std::vector<int>& bp) {
    big_shape=bp;
}

void pieces::move_right() {
    position.x=position.x+1;
    position.y=position.y;
}

void pieces::move_left() {
    position.x=position.x-1;
    position.y=position.y;
}

std::vector<int> pieces::get_shape() {
    return shape;
}

int pieces::Size_v() {
    return size_v;
}

int pieces::Size_o() {
    return size_o;
}

sf::Color pieces::get_color() {
    return color;
}

sf::Vector2i pieces::get_position() {
    return position;
}



void pieces::set_position(const sf::Vector2i &pos) {
    position = pos;
}

void pieces::set_color(const sf::Color &col) {
    color = col;
}

void pieces::set_shape(const std::vector<int> &shp) {
    shape = shp;
}

void pieces::set_size_v(int size) {
    size_v = size;
}

void pieces::set_size_o(int size) {
    size_o = size;
}

void pieces::set_rotate(int rotate_) {
    rotate=rotate_;
}

void pieces::set_number_rotate(int number) {
    number_rotate=number;
}

int pieces::get_number_rotate() {
    return number_rotate;
}

int pieces::get_rotate() {
    return rotate;
}





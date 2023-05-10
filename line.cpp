//
// Created by Denis on 5/7/2023.
//

#include "line.h"

line::line()=default;

line::~line() {}

line::line(sf::Vector2i position_, sf::Color color_, int size_o_,int size_v_,const std::vector<int>& shape_,int rotate_, int number_rotate_,const std::vector<int>& big_shape_):position{position_},color{color_},size_o{size_o_},size_v{size_v_},shape{shape_},rotate{rotate_},number_rotate{number_rotate_},
                                                                                                                                                                             big_shape{big_shape_}{}

line::line(const line &other): position{other.position},color{other.color},size_o{other.size_o},size_v{other.size_v},shape{other.shape},rotate{other.rotate},number_rotate{other.number_rotate} {}

line &line::operator=(const line &other) {
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
void line::setline(std::shared_ptr<pieces> &linePtr) {
    linePtr->set_position(sf::Vector2i(4, 0));
    linePtr->set_color(sf::Color(173, 216, 230));
    linePtr->set_shape({1, 1, 1, 1});
    linePtr->set_size_o(1);
    linePtr->set_size_v(4);
    linePtr->set_big_shape({0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0});
    linePtr->set_rotate(0);
    linePtr->set_number_rotate(1);
}

void line::rotate_piece(std::shared_ptr<pieces> &linePtr) {
    int size_v_=linePtr->Size_o();
    int size_o_=linePtr->Size_v();
    linePtr->set_size_v(size_v_);
    linePtr->set_size_o(size_o_);
}

std::vector<int> line::next_rotate(std::shared_ptr<pieces> &linePtr) {
    std::vector <int> x={1,1,1,1};
    return x;
}

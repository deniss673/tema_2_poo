//
// Created by Denis on 4/27/2023.
//

#include "square.h"

square::square()=default;
square::~square(){}
square::square(sf::Vector2i position_, sf::Color color_, int size_o_,int size_v_,std::vector<int> shape_,int nume_, std::vector<int> big_shape_):position{position_},color{color_},size_o{size_o_},size_v{size_v_},shape{shape_},nume{nume_},big_shape{big_shape_} {}
square::square(const square &other): position{other.position},color{other.color},size_o{other.size_o},size_v{other.size_v},shape{other.shape}{}

square &square::operator=(const square &other) {
    if (this != &other) {
        position = other.position;
        color = other.color;
        size_o = other.size_o;
        size_v = other.size_v;
        shape = other.shape;
    }
    return *this;
}
void square::setsquare(std::shared_ptr<pieces> &squarePtr) {
    squarePtr->set_position(sf::Vector2i(4, 0));
    squarePtr->set_color(sf::Color(255, 255, 0));
    squarePtr->set_shape({1, 1, 1, 1});
    squarePtr->set_size_o(2);
    squarePtr->set_size_v(2);
    squarePtr->set_nume(5);
    squarePtr->set_big_shape({0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0});
}

std::vector<int> square::next_rotate(std::shared_ptr<pieces>& squarePtr) {
    return {1,1,1,1};
}

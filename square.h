//
// Created by Denis on 4/27/2023.
//

#ifndef OOP_SQUARE_H
#define OOP_SQUARE_H
#include <SFML/Graphics.hpp>
#include "pieces.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <iostream>

class square: public pieces{
private:
    sf::Vector2i position=sf::Vector2i (4,0);
    sf::Color color=sf::Color(255,255,0);
    std::vector<int> shape={1,1,1,1};
    int size_v=2;
    int size_o=2;
    int nume=5;
    std::vector <int> big_shape;

public:
    square()=default;
    ~square(){};
    square(sf::Vector2i position_, sf::Color color_, std::vector<int> shape_,int size_v_, int size_o_, int nume_) : position(position_),color(color_),shape(shape_), size_v(size_v_), size_o(size_o_), nume(nume_) {}
    static std::shared_ptr<pieces> createsquare() {
        auto squarePtr = std::make_shared<square>();
        return squarePtr;
    }
    static void setsquare(std::shared_ptr<pieces> &squarePtr){
        squarePtr->set_position(sf::Vector2i(4, 0));
        squarePtr->set_color(sf::Color(255, 255, 0));
        squarePtr->set_shape({1, 1, 1, 1});
        squarePtr->set_size_o(2);
        squarePtr->set_size_v(2);
        squarePtr->set_nume(5);
        squarePtr->set_big_shape({0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0});
    }

    void set_position(const sf::Vector2i& pos) {
        position = pos;
    }

    void set_color(const sf::Color& col) {
        color = col;
    }

    void set_shape(const std::vector<int>& shp) {
        shape = shp;
    }

    void set_size_v(int size) {
        size_v = size;
    }

    void set_size_o(int size) {
        size_o = size;
    }


    void set_nume(int number) {
        nume = number;
    }

    int Size_v(){
        return size_v;
    }
    int numele(){
        return nume;
    }
    int Size_o(){
        return size_o;
    }
    void move_down(){
        position.y=position.y+1;
        position.x=position.x;
    }

    sf::Vector2i get_position(){
        return position;
    }
    sf::Color get_color(){
        return color;
    }
    void move_right(){
        position.x=position.x+1;
        position.y=position.y;
    }
    void move_left(){
        position.x=position.x-1;
        position.y=position.y;
    }
    std::vector<int> get_shape(){
        return shape;
    }
    void rotate_piece(std::shared_ptr<pieces>& squarePtr) override{
    }
    std::vector<int> next_rotate() override{
        return {1,1,1,1};
    }
};


#endif //OOP_SQUARE_H

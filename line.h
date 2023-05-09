//
// Created by Denis on 5/7/2023.
//

#ifndef OOP_LINE_H
#define OOP_LINE_H

#include "pieces.h"


class line: public pieces{
private:
    sf::Vector2i position=sf::Vector2i (4,0);
    sf::Color color=sf::Color(173,216,230);
    std::vector<int> shape={1,1,1,1};
    int size_v=1;
    int size_o=4;
    int nume=15;
    std::vector <int> big_shape;

public:
    line()=default;
    ~line(){};
    line(sf::Vector2i position_, sf::Color color_, std::vector<int> shape_,int size_v_, int size_o_, int nume_) : position(position_),color(color_),shape(shape_), size_v(size_v_), size_o(size_o_), nume(nume_) {}
    static std::shared_ptr<pieces> createline() {
        auto linePtr = std::make_shared<line>();
        return linePtr;
    }
    static void setline(std::shared_ptr<pieces> &linePtr){
        linePtr->set_position(sf::Vector2i(4, 0));
        linePtr->set_color(sf::Color(173, 216, 230));
        linePtr->set_shape({1, 1, 1, 1});
        linePtr->set_size_o(1);
        linePtr->set_size_v(4);
        linePtr->set_nume(5);
        linePtr->set_big_shape({0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0});
    }
    void rotate_piece(std::shared_ptr<pieces>& linePtr) override{
        int aux=size_v;
        size_v=size_o;
        size_o=aux;
        linePtr->set_size_v(size_v);
        linePtr->set_size_o(size_o);
    }
    std::vector<int> next_rotate() override{
        std::vector <int> x={1,1,1,1};
        return x;
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

};


#endif //OOP_LINE_H

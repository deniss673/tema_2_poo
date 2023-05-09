//
// Created by Denis on 4/24/2023.
//

#ifndef OOP_PIECES_H
#define OOP_PIECES_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

class pieces {
private:
    sf::Vector2i position;
    sf::Color color;
    int size_o;
    int size_v;
    std::vector<int> shape;
    int nume;
    int rotate=0;
    int number_rotate=0;
    std::vector<int> big_shape;
public:
    pieces(sf::Vector2i position_, sf::Color color_, int size_o_,int size_v_): position{position_}, color{color_}, size_o{size_o_},size_v{size_v_} {}
    pieces(){}
    virtual ~pieces(){}
    virtual void rotate_piece(std::shared_ptr<pieces>& piece)=0;
    virtual std::vector<int> next_rotate()=0;
    void move_down(){
        position.y=position.y+1;
    }
    std::vector<int> get_big_shape(){
        return big_shape;
    }
    void set_big_shape(std::vector<int> bp){
        big_shape=bp;
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
    int Size_v(){
        return size_v;
    }
    int Size_o(){
        return size_o;
    }

    sf::Color get_color(){
        return color;
    }
    sf::Vector2i get_position(){
        return position;
    }
    int numele(){
        return nume;
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
    void set_rotate(int rotate_){
        rotate=rotate_;
    }
    void set_number_rotate(int number){
        number_rotate=number;
    }
    void set_nume(int number) {
        nume = number;
    }
    std::vector<int> next_rotate(std::shared_ptr<pieces>& piece){

    }

};


#endif //OOP_PIECES_H

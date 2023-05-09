//
// Created by Denis on 5/7/2023.
//

#ifndef OOP_T_TETROMINO_H
#define OOP_T_TETROMINO_H

#include "pieces.h"
#include <memory>

class t_tetromino : public pieces{
sf::Vector2i position=sf::Vector2i (4,0);
sf::Color color=sf::Color(128,0,128);
std::vector<int> shape={0,1,0,1,1,1};
int size_o=3;
int size_v=2;
int nume=3;
int rotate=0;
int number_rotate=4;
std::vector <int> big_shape;

public:
t_tetromino()=default;
~t_tetromino(){};
int numele(){
    return nume;
}
t_tetromino(sf::Vector2i position_, sf::Color color_, std::vector<int> shape_,int size_v_, int size_o_, int nume_) : position(position_),color(color_),shape(shape_), size_v(size_v_), size_o(size_o_), nume(nume_) {}
static std::shared_ptr<pieces> create_t_tetromino() {
    auto tPtr = std::make_shared<t_tetromino>();
    return tPtr;
}
static void set_t_tetromino(std::shared_ptr<pieces> &tPtr){
    tPtr->set_position(sf::Vector2i(4, 0));
    tPtr->set_color(sf::Color(128,0,128));
    tPtr->set_shape({0,1,0,1,1,1});
    tPtr->set_size_o(3);
    tPtr->set_size_v(2);
    tPtr->set_nume(2);
    tPtr->set_rotate(0);
    tPtr->set_number_rotate(4);
    tPtr->set_big_shape({0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0});
}
int Size_v(){
    return size_v;
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
std::vector<int> get_shape(){
    return shape;
}
void rotate_piece(std::shared_ptr<pieces>& tPtr) override{
    int aux=size_v;
    size_v=size_o;
    size_o=aux;
    int x=rotate;
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
    rotate=rotate+1;
    rotate=rotate%number_rotate;
    x=rotate;
    tPtr->set_size_o(size_o);
    tPtr->set_size_v(size_v);
    tPtr->set_rotate(x);
    }
    std::vector<int> next_rotate() override{
        int x=rotate+1;
        x=x%number_rotate;
        if(x==0){
            return {1,0,1,1,1,0};
        }
        else if(x==1){
            return {1,1,1,0,1,0};
        }
        else if(x==2){
            return {0,1,1,1,0,1};
        }
        else{
            return {0,1,0,1,1,1};
        }
    }

};


#endif //OOP_T_TETROMINO_H

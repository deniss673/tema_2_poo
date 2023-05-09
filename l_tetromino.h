//
// Created by Denis on 4/27/2023.
//

#ifndef OOP_L_TETROMINO_H
#define OOP_L_TETROMINO_H

#include <SFML/Graphics.hpp>
#include "pieces.h"
#include <memory>

class l_tetromino: public pieces{

private:
sf::Vector2i position=sf::Vector2i (4,0);
sf::Color color=sf::Color(255,165,0);
std::vector<int> shape={0,0,1,1,1,1};
int size_o=3;
int size_v=2;
int nume=1;
int rotate=0;
int number_rotate=4;
std::vector <int> big_shape={0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0};

public:
l_tetromino()=default;
~l_tetromino(){};
    int numele(){
        return nume;
    }
    l_tetromino(sf::Vector2i position_, sf::Color color_, std::vector<int> shape_,int size_v_, int size_o_, int nume_) : position(position_),color(color_),shape(shape_), size_v(size_v_), size_o(size_o_), nume(nume_) {}
    static std::shared_ptr<pieces> create_l_tetromino() {
        auto lPtr = std::make_shared<l_tetromino>();
        lPtr->set_position(sf::Vector2i(4, 0));
        lPtr->set_color(sf::Color(255, 165, 0));
        lPtr->set_shape({0,0,1,1,1,1});
        lPtr->set_size_o(3);
        lPtr->set_size_v(2);
        lPtr->set_nume(1);
        return lPtr;
    }
    static void set_l_tetromino(std::shared_ptr<pieces> &lPtr){
        lPtr->set_position(sf::Vector2i(4, 0));
        lPtr->set_color(sf::Color(255, 165, 0));
        lPtr->set_shape({0,0,1,1,1,1});
        lPtr->set_size_o(3);
        lPtr->set_size_v(2);
        lPtr->set_nume(1);
        lPtr->set_rotate(0);
        lPtr->set_number_rotate(4);
        lPtr->set_big_shape({0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0});
    }
    void rotate_piece(std::shared_ptr<pieces>& lPtr) override{
        int aux=size_v;
        size_v=size_o;
        size_o=aux;
        int x=rotate;
        if(x==0){
            lPtr->set_shape({1,0,1,0,1,1});
        }
        else if(x==1){
            lPtr->set_shape({1,1,1,1,0,0});
        }
        else if(x==2){
            lPtr->set_shape({1,1,0,1,0,1});
        }
        else{
            lPtr->set_shape({0,0,1,1,1,1});
        }
        rotate=rotate+1;
        rotate=rotate%number_rotate;
        x=rotate;
        lPtr->set_size_o(size_o);
        lPtr->set_size_v(size_v);
        lPtr->set_rotate(x);
    }
    std::vector<int> next_rotate() override{
        int x=rotate;
        x=x+1;
        x=x%number_rotate;
        if(x==0){
            return {1,0,1,0,1,1};
        }
        else if(x==1){
            return {1,1,1,1,0,0};
        }
        else if(x==2){
            return {1,1,0,1,0,1};
        }
        else{
            return {0,0,1,1,1,1};
        }
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
};


#endif //OOP_L_TETROMINO_H

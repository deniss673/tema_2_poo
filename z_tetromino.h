//
// Created by Denis on 5/7/2023.
//

#ifndef OOP_Z_TETROMINO_H
#define OOP_Z_TETROMINO_H
#include "pieces.h"
#include <memory>

class z_tetromino : public pieces{
    sf::Vector2i position=sf::Vector2i (4,0);
    sf::Color color=sf::Color(255,0,0);
    std::vector<int> shape={1,1,0,0,1,1};
    int size_o=3;
    int size_v=2;
    int nume=2;
    int rotate=0;
    int number_rotate=2;
    std::vector <int> big_shape;
public:
    z_tetromino()=default;
    ~z_tetromino(){};
    int numele(){
        return nume;
    }
    z_tetromino(sf::Vector2i position_, sf::Color color_, std::vector<int> shape_,int size_v_, int size_o_, int nume_) : position(position_),color(color_),shape(shape_), size_v(size_v_), size_o(size_o_), nume(nume_) {}
    static std::shared_ptr<pieces> create_z_tetromino() {
        auto zPtr = std::make_shared<z_tetromino>();
        return zPtr;
    }
    static void set_z_tetromino(std::shared_ptr<pieces> &zPtr){
        zPtr->set_position(sf::Vector2i(4, 0));
        zPtr->set_color(sf::Color(255, 0, 0));
        zPtr->set_shape({1,1,0,0,1,1});
        zPtr->set_size_o(3);
        zPtr->set_size_v(2);
        zPtr->set_nume(2);
        zPtr->set_rotate(0);
        zPtr->set_number_rotate(2);
        zPtr->set_big_shape({0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0});
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
    void rotate_piece(std::shared_ptr<pieces>& zPtr) override{
        int test=rotate;
        if(test==0){
            zPtr->set_shape({0,1,1,1,1,0});
            zPtr->set_size_o(2);
            zPtr->set_size_v(3);
        }
        else if(test==1){
            zPtr->set_shape({1,1,0,0,1,1});
            zPtr->set_size_o(3);
            zPtr->set_size_v(2);
        }
        int x;
        rotate=rotate+1;
        rotate=rotate%number_rotate;
        x=rotate;
        zPtr->set_rotate(x);
    }
    std::vector<int> next_rotate() override{
        int x=rotate+1;
        x=x%number_rotate;
        if(x==0){
            return {0,1,1,1,1,0};
        }
        else{
            return {1,1,0,0,1,1};
        }
    }
};


#endif //OOP_Z_TETROMINO_H

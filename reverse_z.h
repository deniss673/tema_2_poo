//
// Created by Denis on 5/7/2023.
//

#ifndef OOP_REVERSE_Z_H
#define OOP_REVERSE_Z_H

#include "pieces.h"

class reverse_z : public pieces{

private:
    sf::Vector2i position=sf::Vector2i (4,0);
    sf::Color color=sf::Color(0,255,0);
    std::vector<int> shape={0,1,1,1,1,0};
    int size_o=3;
    int size_v=2;
    int nume=12;
    int rotate;
    int number_rotate=2;
    std::vector <int> big_shape;

public:
    reverse_z()=default;
    ~reverse_z(){};
    int numele(){
        return nume;
    }
    reverse_z(sf::Vector2i position_, sf::Color color_, std::vector<int> shape_,int size_v_, int size_o_, int nume_,int rotate_,int number_rotate_) : position(position_),color(color_),shape(shape_), size_v(size_v_), size_o(size_o_), nume(nume_),rotate(rotate_),number_rotate(number_rotate_) {}
    static std::shared_ptr<pieces> create_reverse_z() {
        auto r_zPtr = std::make_shared<reverse_z>();

        return r_zPtr;
    }
    static void set_reverse_z(std::shared_ptr<pieces> &r_zPtr){
        r_zPtr->set_position(sf::Vector2i(4, 0));
        r_zPtr->set_color(sf::Color(0, 255, 0));
        r_zPtr->set_shape({0,1,1,1,1,0});
        r_zPtr->set_size_o(3);
        r_zPtr->set_size_v(2);
        r_zPtr->set_nume(1);
        r_zPtr->set_rotate(0);
        r_zPtr->set_number_rotate(2);
        r_zPtr->set_big_shape({0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0});
    }
    void rotate_piece(std::shared_ptr<pieces>& r_zPtr) override{
        int test=rotate;
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
        int x;
        rotate=rotate+1;
        rotate=rotate%number_rotate;
        x=rotate;

        r_zPtr->set_rotate(x);
    }

    std::vector<int> next_rotate() override{
        int x=rotate+1;
        x=x%number_rotate;
        if(x==0){
            return {1,0,1,1,0,1};
        }
        else{
            return {0,1,1,1,1,0};
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


#endif //OOP_REVERSE_Z_H

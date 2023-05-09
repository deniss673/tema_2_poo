//
// Created by Denis on 5/7/2023.
//

#ifndef OOP_REVERSE_L_H
#define OOP_REVERSE_L_H

#include "pieces.h"

class reverse_l : public pieces{

private:
    sf::Vector2i position=sf::Vector2i (4,0);
    sf::Color color=sf::Color(0,0,165);
    std::vector<int> shape={1,0,0,1,1,1};
    int size_o=3;
    int size_v=2;
    int nume=1;
    int rotate=0;
    int number_rotate=4;
    std::vector<int> big_shape;
public:
    reverse_l()=default;
    ~reverse_l(){};
    int numele(){
        return nume;
    }
    reverse_l(sf::Vector2i position_, sf::Color color_, std::vector<int> shape_,int size_v_, int size_o_, int nume_) : position(position_),color(color_),shape(shape_), size_v(size_v_), size_o(size_o_), nume(nume_) {}
    static std::shared_ptr<pieces> create_reverse_l() {
        auto rlPtr = std::make_shared<reverse_l>();
        return rlPtr;
    }
    static void set_reverse_l(std::shared_ptr<pieces> &rlPtr){
        rlPtr->set_position(sf::Vector2i(4, 0));
        rlPtr->set_color(sf::Color(0, 0, 165));
        rlPtr->set_shape({1,0,0,1,1,1});
        rlPtr->set_size_o(3);
        rlPtr->set_size_v(2);
        rlPtr->set_nume(1);
        rlPtr->set_rotate(0);
        rlPtr->set_number_rotate(4);
        rlPtr->set_big_shape({0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0});
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
    void rotate_piece(std::shared_ptr<pieces>& rlPtr) override{
        int aux=size_v;
        size_v=size_o;
        size_o=aux;
        int x=rotate;
        if(x==0){
            rlPtr->set_shape({1,1,1,0,1,0});
        }
        else if(x==1){
            rlPtr->set_shape({1,1,1,0,0,1});
        }
        else if(x==2){
            rlPtr->set_shape({0,1,0,1,1,1});
        }
        else{
            rlPtr->set_shape({1,0,0,1,1,1});
        }
        rotate=rotate+1;
        rotate=rotate%number_rotate;
        x=rotate;
        rlPtr->set_size_o(size_o);
        rlPtr->set_size_v(size_v);
        rlPtr->set_rotate(x);
    }
    std::vector<int> next_rotate() override{
        int x=rotate+1;
        x=x%number_rotate;

        if(x==0){
            return {1,1,1,0,1,0};
        }
        else if(x==1){
            return {1,1,1,0,0,1};
        }
        else if(x==2){
            return {0,1,0,1,1,1};
        }
        else{
            return {1,0,0,1,1,1};
        }
    }

};


#endif //OOP_REVERSE_L_H

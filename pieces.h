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
    int rotate;
    int number_rotate;
    std::vector<int> big_shape;
public:
    pieces(sf::Vector2i position_, sf::Color color_, int size_o_,int size_v_,const std::vector<int> shape_,int rotate_, int number_rotate_, const std::vector<int> big_shape_);
    pieces();
    pieces(const pieces& other);
    pieces& operator=(const pieces& other);
    virtual ~pieces(){}
    virtual void rotate_piece(std::shared_ptr<pieces>& piece)=0;
    virtual std::vector<int> next_rotate(std::shared_ptr<pieces>& piece)=0;
    void move_down();
    std::vector<int> get_big_shape();
    void set_big_shape(const std::vector<int> bp);
    void move_right();
    void move_left();
    std::vector<int> get_shape();
    int Size_v();
    int Size_o();
    sf::Color get_color();
    sf::Vector2i get_position();

    int get_number_rotate();
    void set_position(const sf::Vector2i& pos);
    int get_rotate();
    void set_color(const sf::Color& col);

    void set_shape(const std::vector<int>& shp);

    void set_size_v(int size);

    void set_size_o(int size);
    void set_rotate(int rotate_);
    void set_number_rotate(int number);



};


#endif //OOP_PIECES_H

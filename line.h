//
// Created by Denis on 5/7/2023.
//

#ifndef OOP_LINE_H
#define OOP_LINE_H

#include "pieces.h"


class line: public pieces{
private:
    sf::Vector2i position;
    sf::Color color;
    std::vector<int> shape;
    int size_o;
    int size_v;
    int rotate;
    int number_rotate;
    std::vector <int> big_shape;
    static void setline(std::shared_ptr<pieces> &linePtr);

public:
    line();
    ~line();
    line(sf::Vector2i position_, sf::Color color_,const std::vector<int>& shape_, int size_o_,int size_v_,int rotate_, int number_rotate_,const std::vector<int>& big_shape_);
    line(const line& other);
    line& operator=(const line& other);
   std::shared_ptr<pieces> clone() const;
    void rotate_piece(std::shared_ptr<pieces>& linePtr) override;
};


#endif //OOP_LINE_H

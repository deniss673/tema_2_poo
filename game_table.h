//
// Created by Denis on 4/24/2023.
//

#ifndef OOP_GAME_TABLE_H
#define OOP_GAME_TABLE_H

#include <array>
#include "pieces.h"
#include "square.h"
#include "l_tetromino.h"
#include <stdlib.h>
#include "z_tetromino.h"
#include "t_tetromino.h"
#include "line.h"
#include "reverse_z.h"
#include "reverse_l.h"
#include "exception.h"


class game_table {
private:
    std::array <int,200> m;
    int scor;
    int level;
    int nr_lines;
    std::vector<std::shared_ptr<pieces>> current_pieces;
    std::vector<std::shared_ptr<pieces>> next_pieces;
public:
    game_table();
    ~game_table();
    game_table(const game_table& other);
    game_table(const std::array<int,200> m_, int scor_,int level_, int nr_lines_, std::vector<std::shared_ptr<pieces>>& current_pieces_,std::vector<std::shared_ptr<pieces>>& next_piece_);
    game_table& operator=(const game_table& other);

    void set_next_piece();

    int return_number(sf::Color color);

    void piece_set_matrix(std::array<int, 200> &m,sf::Vector2i position,std::vector<std::shared_ptr<pieces>> current_pieces,bool set);

    void setcolor(sf::RectangleShape &cell,int number);

    bool verrify_collision(int x,const std::array <int,200> m);

    bool verrify_rotate(std::array <int,200> m);

    void show_next_piece(sf::RenderWindow& window);

    void show_score_and_level(sf::RenderWindow& window);

    void show_screen(sf::RenderWindow& window,std::array <int,200> m);

    void pieces_move_down(std::array<int, 200> &m,const std::vector<std::shared_ptr<pieces>>& current_pieces);

    void pieces_move_right(std::array<int, 200> &m, const std::vector<std::shared_ptr<pieces>>& current_pieces);

    void pieces_move_left(std::array<int, 200> &m,const std::vector<std::shared_ptr<pieces>>& current_pieces);

    void pieces_rotate(std::array<int, 200> &m,std::vector<std::shared_ptr<pieces>>& current_pieces);

    void pieces_goto_end(std::array <int,200> &m,const std::vector<std::shared_ptr<pieces>>& current_pieces);

    bool verify_game(const std::array<int,200> m);

    bool complete_line(const std::array <int,200> m,int line);

    void set_line(std::array <int,200> &m, int number,int line);

    void swap_lines(std::array <int,200> &m,int line);

    int delete_lines(std::array <int,200> &m);

    void scoring(int lines);

    void play_game(sf::RenderWindow& window);

    void start_game(sf::RenderWindow& window);

};


#endif //OOP_GAME_TABLE_H

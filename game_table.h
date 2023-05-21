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
#include <random>

class game_table {
private:
    std::array <int,200> table;
    int scor;
    int level;
    int nr_lines;
    std::vector<std::shared_ptr<pieces>> current_piece;
    std::vector<std::shared_ptr<pieces>> next_piece;
    enum game_pieces{
        gl_tetromino,
        gline,
        greverse_l,
        greverse_z,
        gt_tetromino,
        gz_tetromino,
        gsquare
    };
    void set_next_piece();
    int return_number(sf::Color color);

    void piece_set_matrix(sf::Vector2i position,bool set);

    void setcolor(sf::RectangleShape &cell,int number);

    bool verrify_collision_right();

    bool verrify_collision_left();

    bool verrify_collision_down();

    bool verrify_rotate();

    void show_next_piece(sf::RenderWindow& window);

    void show_score_and_level(sf::RenderWindow& window);

    void show_screen(sf::RenderWindow& window);

    void pieces_move_down();

    void pieces_move_right();

    void pieces_move_left();

    void pieces_rotate();

    void pieces_goto_end();

    bool verify_game();

    bool complete_line(int line);

    void set_line( int number,int line);

    void swap_lines(int line);

    int delete_lines();

    void scoring(int lines);

    void play_game(sf::RenderWindow& window);

    void set_table(){
        std::array<int,200> matrix{0};
        table=matrix;
    }
public:
    game_table();
    ~game_table();
    game_table(const game_table& other);
    game_table(const std::array<int,200> m_, int scor_,int level_, int nr_lines_, std::vector<std::shared_ptr<pieces>>& current_pieces_,std::vector<std::shared_ptr<pieces>>& next_piece_);
    game_table& operator=(const game_table& other);



    void start_game(sf::RenderWindow& window);


};


#endif //OOP_GAME_TABLE_H

//
// Created by Denis on 4/24/2023.
//

#include "game_table.h"


game_table::game_table():table({0}), scor(0), level(1), nr_lines(0), current_piece({}), next_piece({}){}

game_table::~game_table() {}

game_table::game_table(const game_table &other): table{other.table}, scor{other.scor}, level{other.level},nr_lines{other.nr_lines},current_piece{other.current_piece},
                                                 next_piece(other.next_piece) {}

game_table::game_table(const std::array<int, 200> table_, int scor_, int level_, int nr_lines_,
                       std::vector<std::shared_ptr<pieces>>& current_piece_,
                       std::vector<std::shared_ptr<pieces>>& next_piece_): table{table_},scor{scor_},level{level_},nr_lines{nr_lines_},current_piece{current_piece_},next_piece{next_piece_} {}

game_table &game_table::operator=(const game_table &other) {
    if (this != &other) {
        table = other.table;
        scor = other.scor;
        level=other.level;
        nr_lines=other.level;
        current_piece=other.current_piece;
        next_piece=other.next_piece;
    }
    return *this;
}

void game_table::set_next_piece() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 6 );

    int randomIndex=dis(gen);
    game_pieces g_piece= static_cast<game_pieces>(randomIndex);

    if(g_piece==gl_tetromino){
        this->next_piece.push_back(l_tetromino().clone());
    }
    else if(g_piece==gline){
        this->next_piece.push_back(line().clone());
    }
    else if(g_piece==greverse_l){
        this->next_piece.push_back(reverse_l().clone());
    }
    else if(g_piece==greverse_z){
        this->next_piece.push_back(reverse_z().clone());
    }
    else if(g_piece==gsquare){
        this->next_piece.push_back(square().clone());
    }
    else if(g_piece==gz_tetromino){
        this->next_piece.push_back(z_tetromino().clone());
    }
    else if(g_piece==gt_tetromino){
        this->next_piece.push_back(t_tetromino().clone());
    }

    /*
    if(random==1) {
        pieces* ptrPieces= new square();
        square* ptrSquare=dynamic_cast<square*>(ptrPieces);
        next_piece.emplace_back(ptrSquare);
        square::setsquare(next_piece[0]);
    }
    else if(random==2) {
        pieces* ptrPieces= new l_tetromino();
        l_tetromino* ptrL=dynamic_cast<l_tetromino*>(ptrPieces);
        next_piece.emplace_back(ptrL);
        l_tetromino::set_l_tetromino(next_piece[0]);
    }
    else if(random==3){
        pieces* ptrPieces= new z_tetromino();
        z_tetromino* zPtr=dynamic_cast<z_tetromino*>(ptrPieces);
        next_piece.emplace_back(zPtr);
        z_tetromino::set_z_tetromino(next_piece[0]);
    }
    else if(random==4){
        pieces* ptrPieces=new t_tetromino();
        t_tetromino* tPtr=dynamic_cast<t_tetromino*>(ptrPieces);
        next_piece.emplace_back(tPtr);
        t_tetromino::set_t_tetromino(next_piece[0]);
    }
    else if(random==5){
        pieces* ptrPieces= new line();
        line* linePtr=dynamic_cast<line*>(ptrPieces);
        next_piece.emplace_back(linePtr);
        line::setline(next_piece[0]);
    }
    else if(random==6){
        pieces* ptrPieces= new reverse_l;
        reverse_l* rlPtr=dynamic_cast<reverse_l*>(ptrPieces);
        next_piece.emplace_back(rlPtr);
        reverse_l::set_reverse_l(next_piece[0]);
    }
    else if(random==7){
        pieces* ptrPieces= new reverse_z;
        reverse_z* rzPtr=dynamic_cast<reverse_z*>(ptrPieces);
        next_piece.emplace_back(rzPtr);
        reverse_z::set_reverse_z(next_piece[0]);
    }
     */
}

int game_table::return_number(sf::Color color) {
    int final_color=0;
    if(color==sf::Color(255,0,0))
        final_color=1;
    else if(color==sf::Color(255,255,0))
        final_color=2;
    else if(color==sf::Color(255,165,0))
        final_color=3;
    else if(color==sf::Color(128,0,128))
        final_color=4;
    else if(color==sf::Color(173,216,230))
        final_color=5;
    else if(color==sf::Color(0,0,165))
        final_color=6;
    else if(color==sf::Color(0,255,0))
        final_color=7;
    return final_color;
}

void game_table::piece_set_matrix( sf::Vector2i position,
                                   bool set) {
    auto& piece=*this->current_piece[0];
    int size_v=piece.Size_v();
    int size_o=piece.Size_o();
    std::vector shape=this->current_piece[0]->get_shape();
    int c=0;
    for(int i=position.y;i<position.y+size_v;i++){
        for(int j=position.x;j<position.x+size_o;j++){
            if(set==true){
                if(this->table[i*10+j]==0)
                    this->table[i*10+j]=return_number(piece.get_color())*shape[c];
                c++;
            }
            else{
                if(shape[c]==1)
                    this->table[i*10+j]=0;
                c++;
            }
        }
    }

}

void game_table::setcolor(sf::RectangleShape &cell, int number) {
    sf::Color color(128,128,128);
    if(number==1)
        color=sf::Color(255,0,0);
    else if(number==2){
        color=sf::Color(255,255,0);
    }
    else if(number==3){
        color=sf::Color(255,165,0);
    }
    else if(number==4){
        color=sf::Color(128,0,128);
    }
    else if(number==5){
        color=sf::Color(173,216,230);
    }
    else if(number==6){
        color=sf::Color(0,0,165);
    }
    else if(number==7){
        color=sf::Color(0,255,0);
    }
    cell.setFillColor(color);
}

bool game_table::verrify_collision(int x) {
    if(x==1){
        std::vector<int> shape=current_piece[0]->get_shape();
        int poz=(current_piece[0]->get_position().y+current_piece[0]->Size_v())*10+current_piece[0]->get_position().x;
        for(int i=0;i<current_piece[0]->Size_o();i++){
            int aux=poz;
            if(poz>199)
                return false;
            int j=current_piece[0]->Size_v()-1;
            int lp=0;
            while(j>=0) {
                if(shape[i+j*current_piece[0]->Size_o()]==1){
                    if(lp==0 && this->table[poz]>0){
                        return false;
                    }
                    lp=1;
                }
                else{
                    lp=0;
                }
                poz=poz-10;
                j--;
            }
            aux++;
            poz=aux;
        }
    }


    else if(x==2){
        std::vector<int> shape=current_piece[0]->get_shape();
        int poz=(current_piece[0]->get_position().y)*10+current_piece[0]->get_position().x+current_piece[0]->Size_o();
        int shape_size=shape.size();
        for(auto i=current_piece[0]->Size_o()-1;i<shape_size;i=i+current_piece[0]->Size_o()){
            /*if(shape[i]==1 && m[poz]>0 || poz%10==0){
                return false;
            }
            if(shape[i]==0 && m[poz]>0 && shape[i-current_pieces[0]->Size_o()]){
                return false;
            }
            poz=poz+10;*/
            int aux=poz;
            if(poz%10==0)
                return false;
            int j=0;
            int lp=0;
            while(j<current_piece[0]->Size_v()) {

                if (shape[i - j] == 1) {
                    if (lp == 0 && this->table[poz] > 0) {
                        return false;
                    }
                    lp = 1;
                }
                else {
                    lp = 0;
                }
                poz = poz - 1;
                j++;
            }
            aux=aux+10;
            poz=aux;
        }
    }
    else if(x==3){
        std::vector<int> shape=current_piece[0]->get_shape();
        int poz=(current_piece[0]->get_position().y)*10+current_piece[0]->get_position().x-1;
        for(auto i=0ull;i<shape.size();i=i+current_piece[0]->Size_o()){
            int aux=poz;
            if(poz%10==9){
                return false;
            }
            int j=0;
            int lp=0;
            while(j<current_piece[0]->Size_v()) {

                if (shape[i + j] == 1) {
                    if (lp == 0 && this->table[poz] > 0) {
                        return false;
                    }
                    lp = 1;
                }
                else {
                    lp = 0;
                }
                poz = poz + 1;
                j++;
            }
            aux=aux+10;
            poz=aux;
        }
    }
    return true;
}

bool game_table::verrify_rotate() {
    int size_v=current_piece[0]->Size_o();
    int size_o=current_piece[0]->Size_v();

    sf::Vector2i position=current_piece[0]->get_position();
    if(size_v<size_o && verrify_collision(2)==false){
        return false;
    }
    if(size_v==1){
        if(position.x%10>=7){
            return false;}
        int j=size_o-1;
        while(j>0){
            if(this->table[position.y*10+position.x+j]>0) {
                return false;
            }
            j--;
        }
    }
    return true;
}

void game_table::show_next_piece(sf::RenderWindow &window) {
    int cell_size=40;
    sf::RectangleShape cell(sf::Vector2f(cell_size-1,cell_size-1));
    std::vector shape=next_piece[0]->get_big_shape();
    int c=0;

    for(int j=5;j<9;j++){
        for(int i=13;i<17;i++){
            setcolor(cell, return_number(next_piece[0]->get_color())*shape[c]);
            cell.setPosition(cell_size*i,cell_size*j);
            window.draw(cell);
            c=c+1;
        }
    }
}

void game_table::show_score_and_level(sf::RenderWindow &window) {
    sf::Font font;
    sf::Text text;
    sf::Text Scor;
    sf::Text Level;
    font.loadFromFile("font.ttf");
    if(!font.loadFromFile("font.ttf"))
        throw FontNotFound();
    text.setFont(font);
    text.setString("NEXT PIECE:");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(520,160);
    Scor.setFont(font);
    Scor.setString("SCORE: "+std::to_string(scor));
    Scor.setCharacterSize(24);
    Scor.setPosition(520,360);
    Scor.setFillColor(sf::Color::White);
    Level.setFont(font);
    Level.setString("LEVEL: " +std::to_string(level));
    Level.setCharacterSize(24);
    Level.setPosition(520,400);
    Level.setFillColor(sf::Color::White);
    window.draw(text);
    window.draw(Scor);
    window.draw(Level);
}

void game_table::show_screen(sf::RenderWindow &window) {
    int cell_size=40;
    sf::RectangleShape cell(sf::Vector2f(cell_size-1,cell_size-1));
    window.clear();
    for(int i=0;i<10;i++){
        for(int j=0;j<20;j++){
            setcolor(cell,this->table[j*10+i]);
            cell.setPosition(cell_size*i,cell_size*j);
            window.draw(cell);
        }
    }
    show_next_piece(window);
    show_score_and_level(window);
    window.display();
}

void game_table::pieces_move_down() {
    auto& piece=*this->current_piece[0];
    piece_set_matrix(piece.get_position(),false);
    piece.move_down();
    piece_set_matrix(piece.get_position(),true);
}

void game_table::pieces_move_right() {
    auto& piece=*this->current_piece[0];
    piece_set_matrix(piece.get_position(),false);
    piece.move_right();
    piece_set_matrix(piece.get_position(),true);
}

void game_table::pieces_move_left() {
    auto& piece=*this->current_piece[0];
    piece_set_matrix(piece.get_position(),false);
    piece.move_left();
    piece_set_matrix(piece.get_position(),true);
}

void game_table::pieces_rotate() {
    auto& piece=*this->current_piece[0];
    piece_set_matrix(piece.get_position(),false);
    this->current_piece[0]->rotate_piece(this->current_piece[0]);
    piece_set_matrix(piece.get_position(),true);
}

void game_table::pieces_goto_end() {
    while(verrify_collision(1)){
        pieces_move_down();
    }
}

bool game_table::verify_game() {
    bool test=true;
    for(int i=0;i<10;i++){
        if(this->table[i]!=0){
            test=false;
        }
    }
    return test;
}

bool game_table::complete_line( int line) {
    line = line * 10;
    for (int i = 0; i < 10; i++) {
        if (this->table[line + i] == 0) {
            return false;
        }
    }
    return true;
}

void game_table::set_line( int number, int line) {
    line=line*10;

    for(int i=0;i<10;i++){
        this->table[line+i]=number;
    }
}

void game_table::swap_lines( int line) {
    line=line*10;
    std::array <int,10> temp;
    if(line>0) {
        for (int i = 0; i < 10; i++) {
            temp[i] = this->table[line + i];
        }
        for (int i = line; i < line + 10; i++) {
            this->table[i] = this->table[i - 10];
        }
        for (int i = 0; i < 10; i++) {
            this->table[line + i - 10] = temp[i];
        }
    }
    else{
        for (int i = 0; i < 10; i++) {
            this->table[line+i] = 0;
        }
    }
}

int game_table::delete_lines() {
    int completed_lines=0;
    for(int i=0;i<20;i++) {
        if (complete_line(i)) {
            set_line( -1, i);
            nr_lines=nr_lines+1;
            completed_lines=completed_lines+1;
        }
    }
    bool verify=true;
    while(verify) {
        int c=0;
        for (int i = 0; i < 20; i++) {
            if (this->table[i * 10] == -1) {
                swap_lines( i);
                c++;
            }
            if(c>0){
                set_line(0,0);
            }
        }
        if(c==0){
            verify=false;
        }
    }
    return completed_lines;
}

void game_table::scoring(int lines) {
    if (lines==1){
        scor=scor+100*level;
    }
    else if(lines==2){
        scor=scor+300*level;
    }
    else if(lines==3){
        scor=scor+500*level;
    }
    else{
        scor=scor+800*level;
    }
}


void game_table::play_game(sf::RenderWindow &window) {
    int cell_size=40;
    window.setFramerateLimit(60);
    set_next_piece();
    sf::RectangleShape cell(sf::Vector2f(cell_size-1,cell_size-1));
    set_table();
    show_screen(window);
    bool play=true;
    int counter=0;
    while(play) {
        bool ver=true;
        if(table[14]==0 && table[15]==0) {
            current_piece.emplace_back(next_piece[0]);
            next_piece.pop_back();
            set_next_piece();
        }
        else{
            play=false;
            ver=false;
        }
        int frame_counter=0;
        while (ver) {
            show_screen(window);
            frame_counter++;
            if(frame_counter%20==0){
                if(verrify_collision(1)==true)
                    pieces_move_down();
                show_screen(window);
                counter++;
                frame_counter=0;
            }
            if(frame_counter%5==0){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))  {
                    if(verrify_collision(2))
                        pieces_move_right();

                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && verrify_collision(3))
                    pieces_move_left();
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&& verrify_collision(1))
                    pieces_move_down();
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                    pieces_goto_end();
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && verrify_rotate()){
                    pieces_rotate();
                }

            }
            if (verrify_collision(1)==false) {
                ver = false;
                current_piece.pop_back();
                int lines= delete_lines();
                if(lines>0){
                    scoring(lines);

                }
                if(nr_lines==10){
                    level=level+1;
                    nr_lines=0;
                }

            }
        }
        if(!verify_game())
            play=false;
        if(counter==20)
            frame_counter=0;
    }
    window.close();

}

void game_table::start_game(sf::RenderWindow &window) {
    if (!window.isOpen())
        throw WindowNotOpened();
    while (window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type==sf::Event::Closed)
                window.close();
        }
        play_game(window);
    }
}











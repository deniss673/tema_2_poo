#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <array>
#include "game_table.h"


int main() {
    int width=800,height=800;
    sf::RenderWindow window(sf::VideoMode(width,height), "My window");
    while (window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type==sf::Event::Closed)
                window.close();
        }
        std::array <int,200> m{0};
        game_table game;
        game.play_game(window);
    }
    return 0;
}

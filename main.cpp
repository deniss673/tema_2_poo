#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "game_table.h"

int main() {
    int width=800,height=800;
    sf::RenderWindow window(sf::VideoMode(width,height), "My window");
    game_table game;
    game.start_game(window);
    return 0;
}

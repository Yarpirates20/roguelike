#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game();
    ~Game();

    void run();

private:
    void process_input();
    void render();

    bool is_running;
    int player_x;
    int player_y;
};

#endif // GAME_H
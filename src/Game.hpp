/**
 * @file Game.hpp
 * @brief Declaration of the Game class which implements the core loop and 
 * state for a simple roguelike.
 *
 */

#ifndef GAME_H
#define GAME_H

/**
 * @brief Game class which runs game, processes input, and renders map, also 
 * storing player state.
 *
 */
class Game
{
public:
    /**
     * @brief Construct a new Game object.
     * 
     */
    Game();

    /**
     * @brief Destroy the Game object.
     * 
     */
    ~Game();

    /**
     * @brief Main game loop.
     * 
     */
    void run();

private:
    /**
     * @brief Retrieves player input and takes appropriate action.
     * 
     */
    void process_input();
    
    /**
     * @brief Draws game objects to screen.
     * 
     */
    void render();

    bool is_running;
    int player_x;
    int player_y;
};

#endif // GAME_H
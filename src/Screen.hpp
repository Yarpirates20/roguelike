#ifndef SCREEN_H
#define SCREEN_H

class Screen
{
private:
    int m_height;
    int m_width;

public:
    /**
     * @brief Initialize ncurses library.
     *
     */
    Screen();
    
    /**
     * @brief Clear ncurses.
     * 
     */
    ~Screen();

    /**
     * @brief Prints message on screen.
     * 
     * @param message Message to print.
     */
    void add(const char *message);
    
    /**
     * @brief Height accessor.
     * 
     * @return int Height of screen.
     */
    int height();

    /**
     * @brief Width accessor.
     * 
     * @return int Screen width.
     */
    int width();
};

#endif // SCREEN_H
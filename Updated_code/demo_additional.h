// demo_additional.h
#ifndef DEMO_ADDITIONAL_H
#define DEMO_ADDITIONAL_H

#include <string>

// Global Variables
extern int lives;  // Default lives when game starts
extern int level;  // Default value for level

// Function declarations

/**
 * @brief Decrements the number of lives if the player falls.
 * 
 * @param fell A boolean indicating whether the player fell.
 * @return The current number of lives.
 */
int num_lives(bool fell);

/**
 * @brief Displays the level-up message and increments the level.
 */
void level_up();

/**
 * @brief Applies a random power-up to the game elements.
 * 
 * @param ball_speedx Reference to the horizontal speed of the ball.
 * @param ball_speedy Reference to the vertical speed of the ball.
 * @param paddle_width Reference to the paddle width.
 * @return The updated value for the number of lives.
 */
float apply_power_up(float &ball_speedx, float &ball_speedy, int &paddle_width);

/**
 * @brief Displays the number of lives on the screen.
 */
void display_lives_on_screen();

#endif // DEMO_ADDITIONAL_H
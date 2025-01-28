// file_management.h
#ifndef FILE_MANAGEMENT_H
#define FILE_MANAGEMENT_H

#include <string>
#include <vector>
#include "yssimplesound.h"

// Constants
const int windowWidth = 800;
const int windowHeight = 600;
const int frameRate = 16;
const int numAsteroids = 7;
const int demoDuration = 60;
const int numStars = 100;

// Global Variables
extern float spaceshipX;
extern float spaceshipY;

// Menu States
enum MenuState {
    MAIN_MENU,
    NEW_GAME,
    INSTRUCTIONS,
    LEADERBOARD
};

// Global Menu State
extern MenuState currentState;

// Star struct
struct Star {
    float x, y;
    float speed;
};

// Global Variables
extern std::vector<Star> stars;
extern YsSoundPlayer player;
extern YsSoundPlayer::SoundData bgSound, collisionSound;

// Function Declarations

/**
 * @brief Initializes the sounds for the game.
 */
void initSounds();

/**
 * @brief Plays the background sound.
 */
void playBackgroundSound();

/**
 * @brief Calculates the Euclidean distance between two points.
 * 
 * @param x1 The x-coordinate of the first point.
 * @param y1 The y-coordinate of the first point.
 * @param x2 The x-coordinate of the second point.
 * @param y2 The y-coordinate of the second point.
 * @return The Euclidean distance between the two points.
 */
float calculateDistance(float x1, float y1, float x2, float y2);

/**
 * @brief Initializes the star positions and speeds.
 */
void initStars();

/**
 * @brief Renders text at the given position on the screen.
 * 
 * @param x The x-coordinate.
 * @param y The y-coordinate.
 * @param text The text to render.
 */
void renderText(int x, int y, const char* text);

/**
 * @brief Reads the leaderboard from a file.
 * 
 * @param filename The name of the file containing leaderboard data.
 * @return A vector of strings representing the leaderboard.
 */
std::vector<std::string> readLeaderboardFromFile(const std::string& filename);

/**
 * @brief Displays the main menu.
 * 
 * @return 0 on completion.
 */
int displayMainMenu();

/**
 * @brief Displays the "New Game" screen.
 */
void displayNewGame();

/**
 * @brief Displays the "Instructions" screen.
 */
void displayInstructions();

/**
 * @brief Displays the leaderboard screen.
 */
void displayLeaderboard();

/**
 * @brief Displays the "Resume" screen.
 */
void displayResume();

/**
 * @brief Displays the "Better Luck Next Time" screen.
 */
void displayBetterLuckNextTime();

/**
 * @brief Displays the pause menu and handles user selection.
 * 
 * @return The user's menu selection.
 */
int displayPauseMenu();

#endif // FILE_MANAGEMENT_H

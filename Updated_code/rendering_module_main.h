// rendering_module.h
#ifndef RENDERING_MODULE_H
#define RENDERING_MODULE_H

#include <vector>
#include <string>
#include "yssimplesound.h"

// Constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int TILE_ROWS = 5;
const int TILE_COLUMNS = 10;
const int TILE_WIDTH = 60;
const int TILE_HEIGHT = 20;
const float BL_PI = 3.14159265f;

// Paddle Class
class Paddle {
public:
    int x, y;
    int width, height;
    int speed;

    Paddle(int x, int y, int width, int height, int speed);
    void MoveLeft();
    void MoveRight();
    void Render();
};

// Ball Class
class Ball {
public:
    float x, y;
    float radius;
    float speedX, speedY;
    YsSoundPlayer::SoundData wallSound;

    Ball(float x, float y, float radius, float speedX, float speedY);
    void LoadSounds(const std::string &wallSoundFile);
    void Move();
    void CheckScreenCollision();
    bool CheckPaddleCollision(const Paddle &paddle);
    void Render();
    bool IsOutOfBounds() const;
};

// Tile Class
class Tile {
public:
    int x, y;
    int width, height;
    bool destroyed;
    bool isSpecial;

    Tile(int x, int y, int width, int height, bool isSpecial = false);
    void Render();
    bool IsDestroyed();
    bool IsSpecial();
};

// Particle Class
class Particle {
public:
    float x, y;
    float dx, dy;
    float life;

    Particle(float x, float y, float dx, float dy, float life);
    void Update();
    void Render();
};

// ParticleSystem Class
class ParticleSystem {
public:
    std::vector<Particle> particles;

    void Explode(int x, int y);
    void Update();
    void Render();
};

// Function declarations
bool AreAllTilesDestroyed(const std::vector<Tile> &tiles, Ball &ball, Paddle &paddle);
void RenderBackground();
void ResetGame(Ball &ball, Paddle &paddle, std::vector<Tile> &tiles);
int GameLoop();

#endif // RENDERING_MODULE_H

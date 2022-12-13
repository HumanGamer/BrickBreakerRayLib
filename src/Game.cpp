#include "Game.hpp"
#include <raylib.h>

Game::Game()
{

}

Game::~Game()
{

}

void Game::Init()
{

}

void Game::Update(double deltaTime)
{

}

void Game::Render()
{
    BeginDrawing();
    {
        ClearBackground(BLACK);

        DrawFPS(10, 10);
    }
    EndDrawing();
}

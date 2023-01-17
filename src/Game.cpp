#include "Game.hpp"
#include <raylib.h>
#include "GameObject.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"

Game::Game(int width, int height)
{
    mSize = {(float)width, (float)height};
    mGameSize = {800, 600};
}

Game::~Game()
{
    for (auto& obj : mGameObjects)
    {
        delete obj;
    }

    mGameObjects.clear();
}

void Game::Init()
{
    Paddle* paddle = new Paddle();
    mGameObjects.push_back(paddle);
    Ball* ball = new Ball();
    mGameObjects.push_back(ball);

    for (auto& obj : mGameObjects)
    {
        obj->SetGameObject(this);
        obj->Init();
    }

    //DisableCursor();
}

void Game::Update(double deltaTime)
{
    for (auto& obj : mGameObjects)
    {
        obj->Update(deltaTime);
    }
}

void Game::Render()
{
    BeginDrawing();
    {
        ClearBackground(BLACK);

        for (auto& obj : mGameObjects)
        {
            obj->Render();
        }

        DrawFPS(10, 10);
    }
    EndDrawing();
}

Vector2 Game::ToGlobalCoord(Vector2 gameCoord)
{
    return {gameCoord.x * mSize.x / mGameSize.x, gameCoord.y * mSize.y / mGameSize.y};
}

Vector2 Game::ToGameCoord(Vector2 globalCoord)
{
    return {globalCoord.x * mGameSize.x / mSize.x, globalCoord.y * mGameSize.y / mSize.y};
}

#include "Game.hpp"
#include <raylib.h>
#include "GameObject.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"
#include "RenderUtil.hpp"

Game::Game(int width, int height)
{
    mSize = {(float)width, (float)height};
    mGameSize = {800, 450};
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
    RenderUtil::Init();
    mPaddle = new Paddle();
    mGameObjects.push_back(mPaddle);
    Ball* ball = new Ball(mPaddle);
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
    std::vector<GameObject*> removeList;
    for (auto& obj : mGameObjects)
    {
        obj->Update(deltaTime);
        if (obj->ShouldRemove())
            removeList.push_back(obj);
    }

    for (auto& obj : removeList)
    {
        auto e = std::find(mGameObjects.begin(), mGameObjects.end(), obj);
        if (e != mGameObjects.end())
            mGameObjects.erase(e);
        delete obj;
    }

    int ballCount = 0;
    for (auto& obj : mGameObjects)
    {
        Ball* ball = dynamic_cast<Ball*>(obj);
        if (ball != nullptr)
            ballCount++;
    }

    if (ballCount <= 0)
    {
        Ball* ball = new Ball(mPaddle);
        mGameObjects.push_back(ball);

        ball->SetGameObject(this);
        ball->Init();

//        Ball* ball2 = new Ball(mPaddle);
//        mGameObjects.push_back(ball2);
//
//        ball2->SetGameObject(this);
//        ball2->Init();
//        ball2->SetPosition({20, 20});
//        ball2->SetVelocity({100, 500});
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

void Game::RemoveObject(GameObject *obj)
{
    //mGameObjectsToRemove.push_back(obj);
    //std::remove(mGameObjects.begin(), mGameObjects.end(), obj);
    //delete obj;
}

Vector2 Game::ToGlobalCoord(Vector2 gameCoord)
{
    return {gameCoord.x * mSize.x / mGameSize.x, gameCoord.y * mSize.y / mGameSize.y};
}

Vector2 Game::ToGameCoord(Vector2 globalCoord)
{
    return {globalCoord.x * mGameSize.x / mSize.x, globalCoord.y * mGameSize.y / mSize.y};
}

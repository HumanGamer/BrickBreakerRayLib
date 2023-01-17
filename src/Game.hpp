#pragma once

#include "raylib.h"
#include <vector>

class GameObject;

class Game
{
public:
    Game(int width, int height);
    ~Game();

    void Init();
    void Update(double deltaTime);
    void Render();

    Vector2 ToGameCoord(Vector2 globalCoord);
    Vector2 ToGlobalCoord(Vector2 gameCoord);

    Vector2& GetSize() { return mSize; }
    Vector2& GetGameSize() { return mGameSize; }

private:
    std::vector<GameObject*> mGameObjects;

    Vector2 mSize;
    Vector2 mGameSize;
};

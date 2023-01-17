#pragma once

#include "raylib.h"
#include "Game.hpp"

class GameObject
{
public:
    GameObject();
    virtual ~GameObject();

    virtual void Init();
    virtual void Update(double deltaTime);
    virtual void Render();

    Vector2 GetRenderPos();
    Vector2 GetRenderSize();

    void SetGameObject(Game* game) { mGame = game; }
protected:
    Game* mGame;
    Vector2 mPosition;
    Vector2 mSize;
};

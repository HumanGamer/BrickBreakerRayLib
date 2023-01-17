#include "Paddle.hpp"

#include <algorithm>

Paddle::Paddle()
{

}

Paddle::~Paddle() noexcept
{

}

void Paddle::Init()
{
    mSize = {100, 20};
    mPosition = {0, mGame->GetGameSize().y - mSize.y - 20};
}

void Paddle::Update(double deltaTime)
{
    Vector2 mouseCoord = mGame->ToGameCoord({(float)GetMouseX(), (float)GetMouseY()});
    mPosition.x = std::clamp(mouseCoord.x - mSize.x / 2.0f, 0.0f, mGame->GetGameSize().x - mSize.x);
}

void Paddle::Render()
{
    Vector2 paddlePos = GetRenderPos();
    Vector2 paddleSize = GetRenderSize();
    DrawRectangle(paddlePos.x, paddlePos.y, paddleSize.x, paddleSize.y, WHITE);
}

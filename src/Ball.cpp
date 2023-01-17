#include "Ball.hpp"

Ball::Ball()
{

}

Ball::~Ball() noexcept
{

}

void Ball::Init()
{
    mSize = {10, 10};
    mPosition = {mGame->GetGameSize().x / 2 - mSize.x, mGame->GetGameSize().y / 2 - mSize.y};
    mVelocity = {500, 350};
}

void Ball::Update(double deltaTime)
{
    mPosition.x += mVelocity.x * deltaTime;
    mPosition.y += mVelocity.y * deltaTime;

    if ((mPosition.x < mSize.x && mVelocity.x < 0) || (mPosition.x >= mGame->GetGameSize().x - mSize.y && mVelocity.x > 0))
        mVelocity.x *= -1;
    if ((mPosition.y < mSize.x && mVelocity.y < 0) || (mPosition.y >= mGame->GetGameSize().y - mSize.y && mVelocity.y > 0))
        mVelocity.y *= -1;

}

void Ball::Render()
{
    Vector2 ballPos = GetRenderPos();
    Vector2 ballSize = GetRenderSize();
    DrawEllipse(ballPos.x, ballPos.y, ballSize.x, ballSize.y, WHITE);
}

#include "Ball.hpp"

Ball::Ball(Paddle* paddle)
{
    mPaddle = paddle;
}

Ball::~Ball() noexcept
{

}

void Ball::Init()
{
    mSize = {10, 10};
    mPosition = {mGame->GetGameSize().x / 2 - mSize.x, mGame->GetGameSize().y / 2 - mSize.y};
    mVelocity = {0, 500}; //500, 350};
}

void Ball::Update(double deltaTime)
{
    mPosition.x += mVelocity.x * deltaTime;
    mPosition.y += mVelocity.y * deltaTime;

    if ((mPosition.x < mSize.x && mVelocity.x < 0) || (mPosition.x >= mGame->GetGameSize().x - mSize.y && mVelocity.x > 0))
        mVelocity.x *= -1;
    if ((mPosition.y < mSize.x && mVelocity.y < 0))// || (mPosition.y >= mGame->GetGameSize().y - mSize.y && mVelocity.y > 0))
        mVelocity.y *= -1;

    if ((mPosition.y > mGame->GetGameSize().y))
    {
        // Lost!
        mRemove = true;
        return;
    }

    Rectangle paddleRect = mPaddle->GetRectangle();

    if (CheckCollisionCircleRec(Vector2{mPosition.x, mPosition.y}, mSize.x, paddleRect))
    {
        if (mVelocity.y > 0)
        {
            mVelocity.y *= -1.0f;//-1.1f;
            float diff = (mPosition.x - paddleRect.x - (paddleRect.width / 2));
            float paddleCenter = (paddleRect.width / 2);
            mVelocity.x = diff / paddleCenter * -mVelocity.y;
        }
    }
}

void Ball::Render()
{
    Vector2 ballPos = GetRenderPos();
    Vector2 ballSize = GetRenderSize();
    DrawEllipse(ballPos.x, ballPos.y, ballSize.x, ballSize.y, WHITE);
}

void Ball::SetPosition(Vector2 pos)
{
    mPosition = pos;
}

void Ball::SetVelocity(Vector2 vel)
{
    mVelocity = vel;
}

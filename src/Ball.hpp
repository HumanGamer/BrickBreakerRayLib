#pragma once

#include "GameObject.hpp"
#include "Paddle.hpp"

class Ball : public GameObject
{
public:
    Ball(Paddle* paddle);
    ~Ball() override;

    void Init() override;
    void Update(double deltaTime) override;
    void Render() override;

    void SetPosition(Vector2 pos);
    void SetVelocity(Vector2 vel);

protected:
    Vector2 mVelocity;
    Paddle* mPaddle;
};

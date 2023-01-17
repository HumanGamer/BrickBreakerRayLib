#pragma once

#include "GameObject.hpp"

class Ball : public GameObject
{
public:
    Ball();
    ~Ball() override;

    void Init() override;
    void Update(double deltaTime) override;
    void Render() override;

protected:
    Vector2 mVelocity;
};

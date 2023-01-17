#pragma once

#include "GameObject.hpp"

class Paddle : public GameObject
{
public:
    Paddle();
    ~Paddle() override;

    void Init() override;
    void Update(double deltaTime) override;
    void Render() override;
};

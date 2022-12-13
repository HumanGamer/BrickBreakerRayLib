#pragma once

class Game
{
public:
    Game();
    ~Game();

    void Init();
    void Update(double deltaTime);
    void Render();
};

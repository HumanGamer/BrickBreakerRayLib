#pragma once

#include "raylib.h"

class RenderUtil
{
public:
    static void Init();
    static void DrawBlock(Rectangle rect, Color tint);
private:
    static Texture smBlockTexture;
};

#include "RenderUtil.hpp"

Texture RenderUtil::smBlockTexture;

void RenderUtil::Init()
{
    smBlockTexture = LoadTexture("data/block.png");
}

void RenderUtil::DrawBlock(Rectangle rect, Color tint)
{
    Vector2 origin = {0, 0};
    // Top Left
    Rectangle src1 = {0, 0, 5, 5};
    Rectangle dest1 = {rect.x, rect.y, 5, 5};
    DrawTexturePro(smBlockTexture, src1, dest1, origin, 0, tint);

    // Top
    Rectangle src2 = {0, 5, 5, 5};
    Rectangle dest2 = {rect.x + 5, rect.y, rect.width - 15, 5};
    DrawTexturePro(smBlockTexture, src2, dest2, origin, 0, tint);

    // Top Right
    Rectangle src3 = {0, 10, 5, 5};
    Rectangle dest3 = {rect.x + rect.width - 10, rect.y, 5, 5};
    DrawTexturePro(smBlockTexture, src3, dest3, origin, 0, tint);

    // Right
    Rectangle src4 = {5, 0, 5, 5};
    Rectangle dest4 = {rect.x + rect.width - 10, rect.y + 5, 5, rect.height - 15};
    DrawTexturePro(smBlockTexture, src4, dest4, origin, 0, tint);

    // Bottom Right
    Rectangle src5 = {5, 5, 5, 5};
    Rectangle dest5 = {rect.x + rect.width - 10, rect.y + rect.height - 10, 5, 5};
    DrawTexturePro(smBlockTexture, src5, dest5, origin, 0, tint);

    // Bottom
    Rectangle src6 = {5, 10, 5, 5};
    Rectangle dest6 = {rect.x + 5, rect.y + rect.height - 10, rect.width - 15, 5};
    DrawTexturePro(smBlockTexture, src6, dest6, origin, 0, tint);

    // Bottom Left
    Rectangle src7 = {5, 15, 5, 5};
    Rectangle dest7 = {rect.x, rect.y + rect.height - 10, 5, 5};
    DrawTexturePro(smBlockTexture, src7, dest7, origin, 0, tint);

    // Left
    Rectangle src8 = {0, 15, 5, 5};
    Rectangle dest8 = {rect.x, rect.y + 5, 5, rect.height - 15};
    DrawTexturePro(smBlockTexture, src8, dest8, origin, 0, tint);

    // Center
    Rectangle src9 = {10, 0, 10, 10};
    Rectangle dest9 = {rect.x + 5, rect.y + 5, rect.width - 15, rect.height - 15};
    DrawTexturePro(smBlockTexture, src9, dest9, origin, 0, tint);
}
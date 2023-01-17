#include "GameObject.hpp"

GameObject::GameObject()
{
    this->mPosition = {0, 0};
    this->mSize = {0, 0};
}

GameObject::~GameObject()
{

}

void GameObject::Init()
{

}

void GameObject::Update(double deltaTime)
{

}

void GameObject::Render()
{

}

Vector2 GameObject::GetRenderPos()
{
    return mGame->ToGlobalCoord(mPosition);
    //return {mPosition.x * mGame->GetSize().x / mGame->GetGameSize().x, mPosition.y * mGame->GetSize().y / mGame->GetGameSize().y};
}

Vector2 GameObject::GetRenderSize()
{
    return mGame->ToGlobalCoord(mSize);
    //return {mSize.x * mGame->GetSize().x / mGame->GetGameSize().x, mSize.y * mGame->GetSize().y / mGame->GetGameSize().y};
}

#pragma once
//------------------------------------------------
// @brief
//------------------------------------------------

namespace My3dApp
{
    enum class CollisionType 
    {
        Line,           //線分
        Sphere,         //球
        Capsule,        //カプセル
        Model           //モデル(メッシュ)
    };
}
#pragma once
#include "../GameObject/GameObject.h"
namespace My3dApp
{
    class Reticle :
        public GameObject
    {
     public:
        Reticle();
        ~Reticle();
        void Update(float deltaTime)override;
        void Draw();
     private:
    };
};

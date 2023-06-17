#pragma once
#include "../GameObject/GameObject.h"
namespace My3dApp 
{
    class DangerZone final
    {
    public:
        static void Intialize();
        static void Update(float deltaTime);
        static void Draw();
        
    private:
        DangerZone();
        ~DangerZone();
        static DangerZone* mpInstance;
        static int mHandle;
    };
}

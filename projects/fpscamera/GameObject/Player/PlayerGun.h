#pragma once
#include "DxLib.h"
#include "Player3D.h"
#include "../GameObject.h"
#include "../Camera/CameraFps.h"
#include "../GameObjectManager.h"
#include "../../Animation/AnimationController.h"
#include "../../UI/Life.h"

namespace My3dApp 
{
    class PlayerGun :
        public GameObject
    {
    public:
        PlayerGun();
        ~PlayerGun();
        void Shot();
        void Update(float deltaTime) override;
        void Draw() override;
        void OnCollisionEnter(GameObject* other);
    protected:
        
        VECTOR mGunSet{ 15,0,-15 };
        VECTOR mGanRadius;         //èeâÒì]îºåa
        VECTOR mGunOffSet;

        float mShotTime;
        float mShotIntervalTime;
    };
}

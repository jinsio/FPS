#pragma once
#include "../SceneBase.h"

namespace My3dApp
{
    class PlayScene :
        public SceneBase
    {
    public:
        PlayScene();
        ~PlayScene();
        SceneBase* Update(float deltaTime)override;
        void Draw()override;

    private:
        float coolTime;
        bool BossFlag;
    };
}


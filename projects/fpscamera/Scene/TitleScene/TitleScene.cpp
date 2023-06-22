#include "TitleScene.h"
#include "DxLib.h"
#include "../PlayScene/PlayScene.h"

using namespace My3dApp;
namespace My3dApp {
    TitleScene::TitleScene()
        :mHandle()
        ,mPos()
    {
        mHandle = LoadGraph("data/model/Title/Title2.png");
        mPos.x = FirstPosX;
        mPos.y = FirstPosY;
    }
    TitleScene::~TitleScene()
    {
        if (BgHandle != -1)
        {
            DeleteGraph(BgHandle);
        }
    }
    SceneBase* TitleScene::Update(float deltaTime)
    {
        if (CheckHitKey(KEY_INPUT_P))
        {
            return new PlayScene();
        }
        return this;
    }
    void TitleScene::Draw()
    {
        DrawFormatString(0, 0, GetColor(255, 255, 255), "TitleâÊñ :PÇ≈PlayÉVÅ[ÉìÇ÷à⁄çs");
        DrawExtendGraph(1920/4,0,1920/2+1920/4,600/2,mHandle,TRUE);
    }
}
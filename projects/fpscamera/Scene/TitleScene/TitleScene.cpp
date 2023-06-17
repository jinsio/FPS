#include "TitleScene.h"
#include "DxLib.h"
#include "../PlayScene/PlayScene.h"

using namespace My3dApp;
namespace My3dApp {
    TitleScene::TitleScene()
        :mHandle()
    {
        mHandle = LoadGraph("data/model/Title/_Title.png");
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
        DrawExtendGraph(0,100,1920,300,mHandle,TRUE);
    }
}
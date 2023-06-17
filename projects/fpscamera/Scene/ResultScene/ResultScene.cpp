#include "DxLib.h"
#include "../TitleScene/TitleScene.h"
#include "ResultScene.h"
using namespace My3dApp;

namespace My3dApp
{
    ResultScene::ResultScene()
    {
    }
    ResultScene::~ResultScene()
    {
    }
    SceneBase* ResultScene::Update(float deltaTime)
    {
        if (CheckHitKey(KEY_INPUT_T))
        {
            return new TitleScene();
        }
        return this;
    }
    void ResultScene::Draw()
    {
        DrawFormatString(0, 0, GetColor(255, 255, 255), "ResultâÊñ :TÇ≈TitleÉVÅ[ÉìÇ÷à⁄çs");
    }
}
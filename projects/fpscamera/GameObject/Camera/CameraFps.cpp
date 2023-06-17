#include "CameraFps.h"
#include <DxLib.h>
#include "../Player/Player3D.h"
#include"../GameObjectManager.h"
using namespace My3dApp;
// @brief CameraFpsコンストラクター //
namespace My3dApp{
CameraFps::CameraFps()
    :GameObject(ObjectTag::Camera)
    ,camLookPos{0,0,0}
    ,mouseX(0)
    ,mouseY(0)
    ,movePos{0,0,0}
{
    SetCameraNearFar(CameraNear, CameraFar);                                            //カメラの描画範囲設定
    SetMouseDispFlag(FALSE);
}

// @brief CameraFps更新処理 //

void CameraFps::Update(float deltaTime)
{
    GameObject* player = GameObjectManager::GetFirstGameObject(ObjectTag::Player);                    //プレイヤーオブジェクト取得
    if (player)                                                                         //オブジェクトの中身が空でなければ
    {
        //---カメラ座標設定---//
        mPosition = player->GetPosition();                                                      //カメラの位置はプレイヤーの座標
        mPosition.y = 200;                                                                  //高さは目線の位置

        Move(deltaTime);
        SetCameraPositionAndTarget_UpVecY(mPosition, mPosition + camLookPos);      //プレイヤーの位置から注視点に向けてカメラをセット
        mDir = camLookPos;                                                   //カメラの正面方向ベクトル
    }
    SetMousePoint(1920 / 2, 1080 / 2);                        //マウス座標を画面の中心にセット
}

// @brief CameraFps移動処理 //

void CameraFps::Move(float deltaTime)
{
        GetMousePoint(&mouseX, &mouseY);                                        //マウス座標取得

        //---マウス座標からスクリーン座標の中心を引く---//
        movePos.x = (float)mouseX - static_cast<float>(1920) / 2;
        movePos.y = (float)mouseY - static_cast<float>(1080) / 2;

        //---視点移動--//
        if (abs(movePos.x) > 0)                                                      //マウスカーソルX方向スライド時
        {
            mYaw -= movePos.x * deltaTime * (float)DX_PI / 30;                         //カーソルの移動量分水平方向に回転
        }
        if (abs(movePos.y) > 0)                                                     //マウスカーソルY方向スライド時
        {
            mPitch -= movePos.y * deltaTime * (float)DX_PI / 30;                     //カーソルの移動領分垂直方向に回転
        }

        //---注視点処理---//
        camLookPos.x = cosf(mYaw);
        camLookPos.y = mPitch;
        camLookPos.z = sinf(mYaw);
}
}
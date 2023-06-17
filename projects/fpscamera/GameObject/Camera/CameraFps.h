#pragma once
#include"../GameObject.h"

namespace My3dApp {
    const float CameraNear = 1.0f;       //カメラの描画範囲(近)
    const float CameraFar = 8000.0f;     //カメラの描画範囲(遠)

    /*一人称視点のクラス*/
    class CameraFps :public GameObject
    {
    public:
        /// <summary>
        /// CamreFpsコンストラクター
        /// </summary>
        /// <param name="targetPos">カメラ注視座標</param>
        CameraFps();

        /// <summary>
        /// CamreFpsデストラクター
        /// </summary>
        ~CameraFps() {};

        /// <summary>
        /// CameraFps更新処理
        /// </summary>
        /// <param name="deltaTime">:フレームレート</param>
        void Update(float deltaTime)override;

        /// <summary>
        /// CameraFps移動処理
        /// </summary>
        /// <param name="deltaTime">:フレームレート</param>
        void Move(float deltaTime);

        float GetYaw() { return mYaw; }
        float GetPitch() { return mPitch; }

    protected:
        int mouseX;             //マウス座標X
        int mouseY;             //マウス座標Y
        VECTOR movePos;         //移動座標

        VECTOR camLookPos;      //注視点
    };
}

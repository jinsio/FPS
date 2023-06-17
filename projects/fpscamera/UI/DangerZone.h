#pragma once
#include "../GameObject/GameObject.h"
namespace My3dApp 
{
    class DangerZone final
    {
    public:
        static void Intialize();
        static void SetFlag();
        static void Update(float deltaTime);
        static void Draw();
        
    private:
        DangerZone();
        ~DangerZone();
        static DangerZone* mpInstance;
        static float DangerRenge;   //描画される範囲
        static int Handle;          //画像ハンドル
        static bool DrawFlag;       //描画フラグ
        static float Degtorad; // 度数表記をラジアンに変換する定数
        static float Fade;          //Fade指数
    };
}

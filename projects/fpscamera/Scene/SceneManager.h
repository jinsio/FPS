#pragma once
#include"SceneBase.h"
#include"../UI/TimeManager.h"

/*シーンマネージャーのクラス*/
namespace My3dApp 
{
    class SceneManager
    {
    private:
        SceneBase* nowScene;
        TimeManager* timeManager;
    public:
        /// <summary>
        /// コンストラクター
        /// </summary>
        SceneManager();

        /// <summary>
        /// デストラクター
        /// </summary>
        ~SceneManager();

        /// <summary>
        /// SceneManager更新処理
        /// </summary>
        void Update();

        /// <summary>
        /// 現在のシーンの描画
        /// </summary>
        void Draw();
    };
}

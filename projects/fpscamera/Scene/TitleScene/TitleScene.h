#pragma once
#include "../SceneBase.h"
namespace My3dApp {
    class TitleScene :
        public SceneBase
    {
    public:
        /// <summary>
        /// コンストラクター
        /// </summary>
        TitleScene();

        /// <summary>
        /// デストラクター
        /// </summary>
        ~TitleScene();

        /// <summary>
        /// TitleScene更新処理
        /// </summary>
        /// <param name="deltaTime"></param>
        /// <returns>現在のシーンのポインタ</returns>
        SceneBase* Update(float deltaTime)override;

        /// <summary>
        /// タイトルシーンの描画
        /// </summary>
        void Draw()override;

    private:
        int mHandle;
    };
}


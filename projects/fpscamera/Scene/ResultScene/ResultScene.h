#pragma once
#include"../SceneBase.h"

namespace My3dApp {
	/*リザルトシーンのクラス*/
	class ResultScene :public SceneBase
	{
	public:
		/// <summary>
		/// コンストラクター
		/// </summary>
		ResultScene();

		/// <summary>
		/// デストラクター
		/// </summary>
		~ResultScene();

		/// <summary>
		/// ResultScene更新処理
		/// </summary>
		/// <param name="deltaTime"></param>
		/// <returns>現在のシーンのポインタ</returns>
		SceneBase* Update(float deltaTime)override;

		/// <summary>
		/// リザルトシーンの描画
		/// </summary>
		void Draw()override;

	};
}


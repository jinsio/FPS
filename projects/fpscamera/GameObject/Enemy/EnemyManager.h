//-----------------------------------------------------------------------------
// @brief アセットマネージャクラス
// メッシュファイル・アニメーションの管理を行う。複数回mv1ファイルを読み込みしようとした
// 場合、クローンを作成し、ファイル読み込みを抑制する.
//-----------------------------------------------------------------------------
#pragma once
#include <string>
#include <unordered_map>
//#include <atlstr.h>
#include <DxLib.h>

namespace My3dApp
{
	class EnemyManager final
	{
	public:
		static void Initialize();                                   // アセットマネージャの初期化
		static void Finalize();                                     // アセットマネージャの終了処理
		
		void  SubCoolTime(float deltaTime) { EnemyCoolTime -= deltaTime; }
		float GetCoolTime() { return EnemyCoolTime; }
		float SetCoolTime() { EnemyCoolTime = 2.0f; }

	private:
		EnemyManager();
		~EnemyManager();
		static EnemyManager* mpInstance;                    // AssetManagerインスタンスへのポインタ（アプリ中に唯一存在する）

		float EnemyCoolTime;
	};

}// namespace My3dApp
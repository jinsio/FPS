#include "EnemyManager.h"
#include <string>

namespace My3dApp
{
	// アセットマネージャ実体へのポインタ定義
	EnemyManager* EnemyManager::mpInstance = nullptr;

	//-----------------------------------------------------------------------------
	// @brief  コンストラクタ.
	//-----------------------------------------------------------------------------
	EnemyManager::EnemyManager()
		:EnemyCoolTime(2.0f)
	{
		mpInstance = nullptr;
	}

	//-----------------------------------------------------------------------------
	// @brief  デストラクタ.
	//-----------------------------------------------------------------------------
	EnemyManager::~EnemyManager()
	{
		mpInstance = nullptr;
	}
	//-----------------------------------------------------------------------------
	// @brief  アセットマネージャの生成
	// @detail dxlibInitの後にアセットマネージャを使用するための初期化処理を行う
	// Create無しに他のアセットマネージャの関数をを使用することはできない。
	//-----------------------------------------------------------------------------
	void EnemyManager::Initialize()
	{
		if (!mpInstance)
		{
			mpInstance = new EnemyManager;
		}
	}

	//------------------------------------------------------------------------------------------
	// @brief  AssetManagerの後始末処理.
	// @detail アプリケーション終了前に呼び出す必要がある。マネージャが確保した領域と
	// マネージャ自身の解放処理を行う。Endを行わずに終了した場合はメモリリークを起こす。
	// またこの関数以降にAssetMangerの関数を使用することはできない。
	//------------------------------------------------------------------------------------------
	void EnemyManager::Finalize()
	{
		if (mpInstance)
		{
			delete mpInstance;
		}
	}

} // namespace My3dApp
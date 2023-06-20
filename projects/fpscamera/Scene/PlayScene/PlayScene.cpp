#include "PlayScene.h"
#include "DxLib.h"
#include "../../math/math3D.h"
#include "../../GameObject/Player/Player3D.h"
#include "../../GameObject/Camera/CameraFps.h"
#include "../../GameObject/Player/PlayerGun.h"
#include "../../GameObject/Player/PlayerBullet.h"
#include "../../GameObject/Enemy/Zako.h"
#include "../../GameObject/Enemy/Dragon.h"
#include "../../UI/Reticle.h"
#include "../../Collision/Collision.h"
#include "../../GameObject/GameObject.h"
#include "../../GameObject/GameObjectManager.h"
#include "../../Animation/AssetManager.h"
#include "../../GameObject/Map/Map.h"
#include "../../UI/Score.h"
#include "../../UI/Life.h"
#include "../../UI/DangerZone.h"
#include "../ResultScene/ResultScene.h"

using namespace My3dApp;

namespace My3dApp {
	PlayScene::PlayScene()
		:coolTime(1.5)
		,BossFlag(FALSE)
	{
		// ゲームオブジェクトマネージャーを初期化
		GameObjectManager::Initialize();
		AssetManager::Initialize();
		Score::Initialize();
		DangerZone::Intialize();

		//レティクルの生成
		Reticle* reticle = new Reticle;
		GameObjectManager::Entry(reticle);
		
		// プレイヤー生成＆GameObjectManagerに登録
		Player3D* player = new Player3D;
		GameObjectManager::Entry(player);

		// カメラ生成＆GameObjectManagerに登録
		CameraFps* camerafps = new CameraFps;
		GameObjectManager::Entry(camerafps);

		//PlayerGunを生成＆GameObjectManagerに登録
		PlayerGun* playergun = new PlayerGun();
		GameObjectManager::Entry(playergun);

		// // マップを生成
		GameObjectManager::Entry(new Map(VGet(0, 0, 0)));

	}

	PlayScene::~PlayScene()
	{
	}

	SceneBase* PlayScene::Update(float deltaTime)
	{
		coolTime -= deltaTime;
			//雑魚配置
			if (coolTime < 0)
			{// 雑魚を配置
				Zako* zako = new Zako;
				GameObjectManager::Entry(zako);
				
				coolTime = 4.0f;
			}

			//Bossの出現
			if (!BossFlag&&Score::GetScore()>5)
			{
				Dragon* dragon = new Dragon;
				GameObjectManager::Entry(dragon);
				BossFlag = TRUE;
			}
			
		DangerZone::Update(deltaTime);

		if (CheckHitKey(KEY_INPUT_R)||Life::GetLife()<1||Score::GetGameClearFlag()==TRUE)
		{
			return new ResultScene();
		}
		GameObjectManager::Update(deltaTime);
		GameObjectManager::Collision();
		return this;
	}

	void PlayScene::Draw()
	{
		GameObjectManager::Draw();
		int mHandle = LoadGraph("data/model/FPS/Reticle.png");
		DrawGraph(928, 572 - 50, mHandle, TRUE);
		DangerZone::Draw();
	}

}
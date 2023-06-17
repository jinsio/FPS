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
	{
		// �Q�[���I�u�W�F�N�g�}�l�[�W���[��������
		GameObjectManager::Initialize();
		AssetManager::Initialize();
		Score::Initialize();
		DangerZone::Intialize();

		//���e�B�N���̐���
		Reticle* reticle = new Reticle;
		GameObjectManager::Entry(reticle);
		
		// �v���C���[������GameObjectManager�ɓo�^
		Player3D* player = new Player3D;
		GameObjectManager::Entry(player);

		// �J����������GameObjectManager�ɓo�^
		CameraFps* camerafps = new CameraFps;
		GameObjectManager::Entry(camerafps);

		//PlayerGun�𐶐���GameObjectManager�ɓo�^
		PlayerGun* playergun = new PlayerGun();
		GameObjectManager::Entry(playergun);

		// // �}�b�v�𐶐�
		GameObjectManager::Entry(new Map(VGet(0, 0, 0)));

	}

	PlayScene::~PlayScene()
	{
	}

	SceneBase* PlayScene::Update(float deltaTime)
	{
		coolTime -= deltaTime;
			if (coolTime < 0)
			{// �G����z�u
				Zako* zako = new Zako;
				GameObjectManager::Entry(zako);
				/*Dragon* dragon = new Dragon;
				GameObjectManager::Entry(dragon);*/
				coolTime = 4.0f;
			}

		DangerZone::Update(deltaTime);

		if (CheckHitKey(KEY_INPUT_R)||Life::GetLife()<1)
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
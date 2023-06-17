#include "DangerZone.h"
#include "../GameObject/GameObject.h"
#include "../GameObject/GameObjectManager.h"
using namespace My3dApp;

namespace My3dApp {
	DangerZone* DangerZone::mpInstance = nullptr;
	int DangerZone::Handle = 0;
	bool DangerZone::DrawFlag = FALSE;
	float DangerZone::DangerRenge = 2000;
	float DangerZone::Degtorad = 0.017453293f;
	float DangerZone::Fade = 0;

	DangerZone::DangerZone()
	{
		Handle = LoadGraph("data/model/DangerZone/Red_frame.png");
	}

	DangerZone::~DangerZone()
	{
		delete mpInstance;
	}

	void DangerZone::Intialize()
	{
		mpInstance = new DangerZone;
	}

	void DangerZone::SetFlag()
	{

		GameObject* PlayerGunptr = GameObjectManager::GetFirstGameObject(ObjectTag::PlayerGun);
		GameObject* Enemyptr = GameObjectManager::GetFirstGameObject(ObjectTag::Enemy);

		if (PlayerGunptr&&Enemyptr)
		{
			if (VSize(Enemyptr->GetPosition() - PlayerGunptr->GetPosition()) < DangerRenge)
			{
				DrawFlag = TRUE;
			}
			if (VSize(Enemyptr->GetPosition() - PlayerGunptr->GetPosition()) > DangerRenge)
			{
				DrawFlag = FALSE;
			}
		}
	}

	void DangerZone::Update(float deltaTime)
	{	
		SetFlag();
		if (Fade < 180) {
			Fade+=400*deltaTime;
			if (Fade >= 180)
			{
				Fade = 0;
			}
		}
		
	}
	void DangerZone::Draw()
	{
		if(DrawFlag==TRUE)
		{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, Fade);
		DrawGraph(0,0, Handle, TRUE);
		// 描画ブレンドモードをノーブレンドにする
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}
}
#include "Dragon.h"
#include <iostream>
#include <random>
#include "DxLib.h"
#include "../../math/math3D.h"
#include "../../Collision/Collision.h"
#include "../Player/Player3D.h"
#include "../../Animation/AssetManager.h"
#include "../../Animation/AnimationController.h"

My3dApp::Dragon::Dragon() 
	: GameObject(ObjectTag::Enemy)
	, mAnimControl(nullptr)
	, mAnimTime(0)
	, mCollisionFlag(TRUE)
{
	mModelHandle = AssetManager::GetMesh("data/model/enemy/EnemyMax.mv1");
	mSpeed = 500.0f;

	GameObject* playergun = GameObjectManager::GetFirstGameObject(ObjectTag::PlayerGun);
	GameObject* cameraptr = GameObjectManager::GetFirstGameObject(ObjectTag::Player);
	
	SetPosition(BOSS_SPOT);
	SetDir(VNorm((VSub(playergun->GetPosition(), BOSS_SPOT))));//向き決定

	MV1SetScale(mModelHandle, VGet(1.5f, 1.5f, 1.5f));
	MV1SetPosition(mModelHandle, mPosition);

	// アニメーションコントローラ
	mAnimControl = new AnimationController(mModelHandle);

	mAnimControl->AddAnimation("data/model/enemy/Walking.mv1", 30.0f);
	mAnimControl->AddAnimation("data/model/enemy/KnockedDown.mv1", 30.0f, FALSE);
	mAnimControl->StartAnimation(mAnimTypeId);

	// 当たり判定球を設定
	mCollisionSphere.mLocalCenter = VGet(0, 150, 0);
	mCollisionSphere.mRadius = 75.0f;
	mCollisionSphere.mWorldCenter = mPosition;
}

My3dApp::Dragon::~Dragon()
{
}

void My3dApp::Dragon::Update(float deltaTime)
{
	if (mAnimTypeId == 1)
	{
		mAnimTime += deltaTime;
		if (mAnimTime > 1.5)
		{
			mAlive = FALSE;
		}
	}
	mAnimControl->AddAnimationTime(deltaTime);

	MV1SetPosition(mModelHandle, mPosition);
	GameObject* Cameraptr = GameObjectManager::GetFirstGameObject(ObjectTag::PlayerGun);

	// z軸が逆を向いているのでmDirを180度回転させる
	MATRIX rotYMat = MGetRotY(180.0f * (float)(DX_PI / 180.0f));
	VECTOR negativeVec = VTransform(mDir, rotYMat);
	MV1SetRotationZYAxis(mModelHandle, mPosition, Cameraptr->GetPosition(), 0.0f);

	mPosition += mDir * deltaTime * mSpeed;
	mPosition.y = 0;
	//当たり判定の更新
	CollisionUpdate();
}

void My3dApp::Dragon::Draw()
{
	MV1DrawModel(mModelHandle);
	// 当たり判定デバッグ描画（後で消す）
	DrawSphere3D(mCollisionSphere.mWorldCenter, mCollisionSphere.mRadius, 8, GetColor(0, 255, 255), 0, FALSE);
}

void My3dApp::Dragon::OnCollisionEnter(GameObject* other)
{
	ObjectTag tag = other->GetTag();

	if (mCollisionFlag) {
		//敵との衝突
		if (tag == ObjectTag::PlayerBullet)
		{
			//プレイヤーの弾と敵の当たり判定
			if (CollisionPair(mCollisionSphere, other->GetCollisionSphere()))
			{
				mAnimTypeId = 1;
				mAnimControl->StartAnimation(1);
				mDir = { 0 };
				mCollisionFlag = FALSE;
				other->SetAlive(FALSE);
				Score::ScoreAdd();
			}
		}
	}
}

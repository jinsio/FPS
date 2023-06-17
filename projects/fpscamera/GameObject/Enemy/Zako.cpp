#include "Zako.h"
#include <iostream>
#include <random>
#include "DxLib.h"
#include "../../math/math3D.h"
#include "../../Collision/Collision.h"
#include "../Player/Player3D.h"
#include "../../Animation/AssetManager.h"
#include "../../Animation/AnimationController.h"

using namespace My3dApp;

namespace My3dApp
{

	//@brief Asteroidコンストラクタ　
	Zako::Zako()
		: GameObject(ObjectTag::Enemy)
		, mAnimControl(nullptr)
		, mAnimTime(0)
		,mCollisionFlag(TRUE)
	{
		mModelHandle = AssetManager::GetMesh("data/model/zako/zako.mv1");

		GameObject* playergun = GameObjectManager::GetFirstGameObject(ObjectTag::PlayerGun);
		GameObject* cameraptr = GameObjectManager::GetFirstGameObject(ObjectTag::Player);

		// 0から10の範囲の整数を生成
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(0, 3);
		int random_number = dis(gen);

		//正面方向のモンスター湧き
		if (random_number == 1)
		{
			SetPosition(FIRST_SPOT);
			SetDir(VNorm((VSub(playergun->GetPosition(), FIRST_SPOT))));//向き決定
		}
		//右方向のモンスター湧き
		else if (random_number == 2)
		{
			SetPosition(SECOND_SPOT);
			SetDir(VNorm((VSub(playergun->GetPosition(), SECOND_SPOT))));//向き決定
		}
		//左方向のモンスター湧き
		else
		{
			SetPosition(THIRD_SPOT);
			SetDir(VNorm((VSub(playergun->GetPosition(), THIRD_SPOT))));//向き決定
		}

		MV1SetScale(mModelHandle, VGet(0.5f, 0.5f, 0.5f));
		MV1SetPosition(mModelHandle, mPosition);

		// アニメーションコントローラ
		mAnimControl = new AnimationController(mModelHandle);

		mAnimControl->AddAnimation("data/model/zako/walk.mv1", 30.0f);
		mAnimControl->AddAnimation("data/model/zako/down.mv1", 30.0f, FALSE);
		mAnimControl->StartAnimation(mAnimTypeId);

		// 当たり判定球を設定
		mCollisionSphere.mLocalCenter = VGet(0, 150, 0);
		mCollisionSphere.mRadius = 75.0f;
		mCollisionSphere.mWorldCenter = mPosition;
	}

	Zako::~Zako()
	{
	}


	void Zako::Update(float deltaTime)
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

	void Zako::Draw()
	{
		MV1DrawModel(mModelHandle);
		// 当たり判定デバッグ描画（後で消す）
		DrawSphere3D(mCollisionSphere.mWorldCenter, mCollisionSphere.mRadius, 8, GetColor(0, 255, 255), 0, FALSE);
	}

	void Zako::OnCollisionEnter(GameObject* other)
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
					Score::ScoreAdd();
				}
			}
		}
	}
}
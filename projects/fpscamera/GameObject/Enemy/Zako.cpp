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

	//@brief Asteroid�R���X�g���N�^�@
	Zako::Zako()
		: GameObject(ObjectTag::Enemy)
		, mAnimControl(nullptr)
		, mAnimTime(0)
		,mCollisionFlag(TRUE)
	{
		mModelHandle = AssetManager::GetMesh("data/model/zako/zako.mv1");

		GameObject* playergun = GameObjectManager::GetFirstGameObject(ObjectTag::PlayerGun);
		GameObject* cameraptr = GameObjectManager::GetFirstGameObject(ObjectTag::Player);

		// 0����10�͈̔͂̐����𐶐�
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(0, 3);
		int random_number = dis(gen);

		//���ʕ����̃����X�^�[�N��
		if (random_number == 1)
		{
			SetPosition(FIRST_SPOT);
			SetDir(VNorm((VSub(playergun->GetPosition(), FIRST_SPOT))));//��������
		}
		//�E�����̃����X�^�[�N��
		else if (random_number == 2)
		{
			SetPosition(SECOND_SPOT);
			SetDir(VNorm((VSub(playergun->GetPosition(), SECOND_SPOT))));//��������
		}
		//�������̃����X�^�[�N��
		else
		{
			SetPosition(THIRD_SPOT);
			SetDir(VNorm((VSub(playergun->GetPosition(), THIRD_SPOT))));//��������
		}

		MV1SetScale(mModelHandle, VGet(0.5f, 0.5f, 0.5f));
		MV1SetPosition(mModelHandle, mPosition);

		// �A�j���[�V�����R���g���[��
		mAnimControl = new AnimationController(mModelHandle);

		mAnimControl->AddAnimation("data/model/zako/walk.mv1", 30.0f);
		mAnimControl->AddAnimation("data/model/zako/down.mv1", 30.0f, FALSE);
		mAnimControl->StartAnimation(mAnimTypeId);

		// �����蔻�苅��ݒ�
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

		// z�����t�������Ă���̂�mDir��180�x��]������
		MATRIX rotYMat = MGetRotY(180.0f * (float)(DX_PI / 180.0f));
		VECTOR negativeVec = VTransform(mDir, rotYMat);
		MV1SetRotationZYAxis(mModelHandle, mPosition, Cameraptr->GetPosition(), 0.0f);


		mPosition += mDir * deltaTime * mSpeed;
		mPosition.y = 0;
		//�����蔻��̍X�V
		CollisionUpdate();
	}

	void Zako::Draw()
	{
		MV1DrawModel(mModelHandle);
		// �����蔻��f�o�b�O�`��i��ŏ����j
		DrawSphere3D(mCollisionSphere.mWorldCenter, mCollisionSphere.mRadius, 8, GetColor(0, 255, 255), 0, FALSE);
	}

	void Zako::OnCollisionEnter(GameObject* other)
	{
		ObjectTag tag = other->GetTag();

		if (mCollisionFlag) {
			//�G�Ƃ̏Փ�
			if (tag == ObjectTag::PlayerBullet)
			{
				//�v���C���[�̒e�ƓG�̓����蔻��
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
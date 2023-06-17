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
	SetDir(VNorm((VSub(playergun->GetPosition(), BOSS_SPOT))));//��������

	MV1SetScale(mModelHandle, VGet(1.5f, 1.5f, 1.5f));
	MV1SetPosition(mModelHandle, mPosition);

	// �A�j���[�V�����R���g���[��
	mAnimControl = new AnimationController(mModelHandle);

	mAnimControl->AddAnimation("data/model/enemy/Walking.mv1", 30.0f);
	mAnimControl->AddAnimation("data/model/enemy/KnockedDown.mv1", 30.0f, FALSE);
	mAnimControl->StartAnimation(mAnimTypeId);

	// �����蔻�苅��ݒ�
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

	// z�����t�������Ă���̂�mDir��180�x��]������
	MATRIX rotYMat = MGetRotY(180.0f * (float)(DX_PI / 180.0f));
	VECTOR negativeVec = VTransform(mDir, rotYMat);
	MV1SetRotationZYAxis(mModelHandle, mPosition, Cameraptr->GetPosition(), 0.0f);

	mPosition += mDir * deltaTime * mSpeed;
	mPosition.y = 0;
	//�����蔻��̍X�V
	CollisionUpdate();
}

void My3dApp::Dragon::Draw()
{
	MV1DrawModel(mModelHandle);
	// �����蔻��f�o�b�O�`��i��ŏ����j
	DrawSphere3D(mCollisionSphere.mWorldCenter, mCollisionSphere.mRadius, 8, GetColor(0, 255, 255), 0, FALSE);
}

void My3dApp::Dragon::OnCollisionEnter(GameObject* other)
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
				other->SetAlive(FALSE);
				Score::ScoreAdd();
			}
		}
	}
}

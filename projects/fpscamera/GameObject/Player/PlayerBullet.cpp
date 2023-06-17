#include "PlayerBullet.h"


#pragma warning(disable:4996)

using namespace My3dApp;

// @brief PlayerBullet �R���X�g���N�^ �v���C���[�̈ʒu�E��������e���쐬�E���f���ǂݍ���
My3dApp::PlayerBullet::PlayerBullet(PlayerGun*playergun)
	:GameObject(ObjectTag::PlayerBullet)
	,mAnimControl(nullptr)
{
	// ���f���ǂݍ���
	mModelHandle = AssetManager::GetMesh("data/model/beam/beam.mv1");
	MV1SetScale(mModelHandle, VGet(0.1f, 0.1f, 0.1f));

	// �v���C���[�̈ʒu�E�������擾��������
	mSpeed = 5.0f;
	GameObject* Cameraptr = GameObjectManager::GetFirstGameObject(ObjectTag::Camera);
	GameObject* PlayerGunptr = GameObjectManager::GetFirstGameObject(ObjectTag::PlayerGun);
	mPosition = PlayerGunptr->GetPosition();
	//mPosition.y = 125;			//�e�̍�������
	mDir = Cameraptr->GetDir();

	// �v���C���[�e�̉�]
	MV1SetRotationZYAxis(mModelHandle, mDir, VGet(0.0f, 1.0f, 0.0f), 0.0f);
	MV1SetPosition(mModelHandle, mPosition);

	// �����蔻�苅��ݒ�
	mCollisionSphere.mLocalCenter = VGet(0, 0, 0);
	mCollisionSphere.mRadius = 25.0f;
	mCollisionSphere.mWorldCenter = mPosition;
}

// @brief PlayerBullet�f�X�g���N�^�B���f���̍폜�̓x�[�X�N���X�ōs��
My3dApp::PlayerBullet::~PlayerBullet()
{
}

// @brief Update �t���[�����Ƃ̍X�V����
void My3dApp::PlayerBullet::Update(float deltaTime)
{
	mPosition += mDir * deltaTime * mSpeed*1000;
	MV1SetPosition(mModelHandle, mPosition);

	CollisionUpdate();
}

// @brief �`��
void My3dApp::PlayerBullet::Draw()
{
	MV1DrawModel(mModelHandle);
	MV1SetScale(mModelHandle, VGet(0.1, 0.1, 0.1));

	// �����蔻��f�o�b�O�`��i��ŏ����j
	//DrawSphere3D(mCollisionSphere.mWorldCenter, mCollisionSphere.mRadius,8, GetColor(0, 255, 0), 0, FALSE);
	
	//DrawString(100, 100, mCoord, GetColor(255, 255, 255));
}

void My3dApp::PlayerBullet::Coordinate()
{
	//sprintf(mCoord," X : %f, Y : %f, Z : %f",mPosition.x,mPosition.y,mPosition.z);
}

//-----------------------------------------------------------------------------
// @brief     �v���C���[�����̃I�u�W�F�N�g�Ɠ����������̏���
// @other[in] GameObject* ���̃N���X�Ƒ��̃Q�[���I�u�W�F�N�g(other)���Փ˂����Ƃ��̏������s��
// @detail    �v���C���[�̂߂荞�ݖ߂��Ȃǂ̃��A�N�V�����������L�q����
//-----------------------------------------------------------------------------

void My3dApp::PlayerBullet::OnCollisionEnter( GameObject* other)
{
	ObjectTag tag = other->GetTag();

	//�G�Ƃ̏Փ�
	if (tag == ObjectTag::Enemy)
	{
		//�v���C���[�̒e�ƓG�̓����蔻��
		if (CollisionPair(mCollisionSphere, other->GetCollisionSphere()))
		{
			mAlive = FALSE;
		}
	}
}



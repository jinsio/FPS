#include "GameObject.h"


My3dApp::GameObject::GameObject(ObjectTag tag)
	: mTag(tag)
	, mPosition()
	, mDir()
	, mCollisionModel()
	, mCollisionType()
	, mCollisionSphere()
	, mModelHandle(-1)
	, mCoord()
	, mVisible(true)
	, mAlive(true)
	, mYaw()
	, mPitch()
	, mAnimTypeId(0)
	, mCoolTime()
{
}

My3dApp::GameObject::GameObject(ObjectTag tag,VECTOR pos)
	: mTag(tag)
	, mPosition()
	, mDir()
	, mCollisionModel()
	, mCollisionType()
	, mCollisionSphere()
	, mModelHandle(-1)
	, mCoord()
	, mVisible(true)
	, mAlive(true)
	, mYaw()
	, mPitch()
	, mAnimTypeId(0)
	, mCoolTime()
{
	mPosition = pos;
}

//--------------------------------------------
// @brief. �Q�[���I�u�W�F�N�g�f�X�g���N�^.
//--------------------------------------------
My3dApp::GameObject::~GameObject()
{
	if (mModelHandle != -1)
	{
		// ���f���̃A�����[�h.
		AssetManager::ReleaseMesh(mModelHandle);
		mModelHandle = -1;
	}
}

//--------------------------------------------
// @brief. �`��i���f���`��K�v�Ȃ����͉̂����`����Ȃ��j.
//--------------------------------------------
void My3dApp::GameObject::Draw()
{
}


void My3dApp::GameObject::Coordinate()
{
}

void My3dApp::GameObject::CollisionUpdate()
{
	mCollisionSphere.Move(mPosition);
	//// ���f���̓����蔻������č\�z
	//if (mCollisionModel != -1)
	//{
	//	MV1SetPosition(mCollisionModel, mPosision);
	//	MV1SetupCollInfo(mCollisionModel);
	//}
}


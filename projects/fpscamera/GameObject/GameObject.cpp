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
// @brief. ゲームオブジェクトデストラクタ.
//--------------------------------------------
My3dApp::GameObject::~GameObject()
{
	if (mModelHandle != -1)
	{
		// モデルのアンロード.
		AssetManager::ReleaseMesh(mModelHandle);
		mModelHandle = -1;
	}
}

//--------------------------------------------
// @brief. 描画（モデル描画必要ないものは何も描かれない）.
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
	//// モデルの当たり判定情報を再構築
	//if (mCollisionModel != -1)
	//{
	//	MV1SetPosition(mCollisionModel, mPosision);
	//	MV1SetupCollInfo(mCollisionModel);
	//}
}


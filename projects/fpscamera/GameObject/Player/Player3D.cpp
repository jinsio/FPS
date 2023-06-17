#include "Player3D.h"

using namespace My3dApp;

namespace My3dApp
{
	Player3D::Player3D()
		:	GameObject(ObjectTag::Player),          // GameObjectを継承する際は、GameObjectのコンストラクタを呼ぶ必要がある。
		                                          // GameObjectのコンストラクタはタグを必須とするのでこのように呼ぶ
			mShootTime(0.0f),
			mCameraPosition(VGet(0.0f,0.0f,0.0f)),
			mCameraTarget(VGet(0.0f,0.0f,0.0f)),
			mNowCameraTime(0),
			mMouseX(0),
			mMouseY(0),
			tmpMouseX(0),
			tmpMouseY(0),
			mCameraCoolTime(0),
			mMovePos()
	{
		mDir = VGet(1.0f, 0.0f, 0.0f);

		mCameraYaw = (3.14/2.0f);
		mCameraPitch = (3.14/2.0f);
		

		//マウスを画面中央にセット
		SetMousePoint(1920 / 2, 1080 / 2);
	}
	
	Player3D::~Player3D()
	{
	}

	void Player3D::Update(float deltaTime)
	{
		GameObject* cameraptr = GameObjectManager::GetFirstGameObject(ObjectTag::Camera);
		//カメラの正面方向の位置ベクトルを計算
		VECTOR front = cameraptr->GetDir();
		front.y = 0.0f;//高さ方向無効に

		//ベクトルを正規化
		front = VNorm(front);

		//Y軸ベクトル
		VECTOR YAxis = { 0,1,0 };
		

		// 上下左右方向
		VECTOR UP = front;
		VECTOR DOWN = VScale(front,-1.0f);
		VECTOR RIGHT = VCross(YAxis,front);
		VECTOR LEFT = VScale(RIGHT,-1.0f);

		VECTOR inputVec = VGet(0, 0, 0);

		mDir = front;	//キャラの向きに前方向を代入


		// mPosition , mDir よりキャラクターの位置・回転をセット
		MV1SetPosition(mModelHandle, mPosition);

		// z軸が逆を向いているのでmDirを180度回転させる
		MATRIX rotYMat = MGetRotY(180.0f * (float)(DX_PI / 180.0f));
		VECTOR negativeVec = VTransform(mDir, rotYMat);

		// モデルに回転をセット mDirを向く
		MV1SetRotationZYAxis(mModelHandle, negativeVec, VGet(0.0f, 1.0f, 0.0f), 0.0f);

		//当たり判定の更新
		CollisionUpdate();
}

	void Player3D::Draw()
	{
		
	}
}
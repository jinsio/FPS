#pragma once
#include "PlayerGun.h"
#include "PlayerBullet.h"
#include "../GameObject.h"
#include "../GameObjectManager.h"
#include "../../math/math3D.h"
#include "../../Animation/AssetManager.h"
#include "../../Animation/AnimationController.h"

namespace My3dApp
{
	class Player3D : public GameObject
	{
	public:
		Player3D();
		~Player3D();

		void Update(float deltaTime) override;
		void Draw() override;
		VECTOR GetCameraTarget() { return mCameraTarget; }
		VECTOR GetCameraPosition() { return mCameraPosition; }
	protected:
		const float mSpeed = 100.0f;
		const float mShootIntervalTime = 0.3f;
		float       mShootTime;
		float		mCameraCoolTime;

		//カメラ関連の変数
		VECTOR		mCameraPosition;	//カメラ位置
		VECTOR		mCameraTarget;		//カメラターゲット
		const float	mCameraRadius=500.0f;		//カメラ回転半径
		float		mCameraYaw;			//水平方向回転角(ヨー)
		float		mCameraPitch;		//垂直方向回転角(ピッチ)
		float		mNowCameraTime;
		int			mMouseX;
		int			mMouseY;
		int			tmpMouseX;
		int			tmpMouseY;
		VECTOR		mMovePos;


		PlayerGun* playergun;
	};

}


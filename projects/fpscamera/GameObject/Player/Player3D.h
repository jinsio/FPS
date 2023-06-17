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

		//�J�����֘A�̕ϐ�
		VECTOR		mCameraPosition;	//�J�����ʒu
		VECTOR		mCameraTarget;		//�J�����^�[�Q�b�g
		const float	mCameraRadius=500.0f;		//�J������]���a
		float		mCameraYaw;			//����������]�p(���[)
		float		mCameraPitch;		//����������]�p(�s�b�`)
		float		mNowCameraTime;
		int			mMouseX;
		int			mMouseY;
		int			tmpMouseX;
		int			tmpMouseY;
		VECTOR		mMovePos;


		PlayerGun* playergun;
	};

}


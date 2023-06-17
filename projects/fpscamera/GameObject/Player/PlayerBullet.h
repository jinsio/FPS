#pragma once
#include "DxLib.h"
#include "Player3D.h"
#include "PlayerGun.h"
#include "../GameObject.h"
#include "../../math/math3D.h"
#include "../../Collision/Collision.h"
#include "../../Animation/AnimationController.h"
#include "../../Animation/AssetManager.h"
#include "../../UI/Score.h"

namespace My3dApp
{
	class PlayerBullet : public GameObject
	{
	public:
		PlayerBullet(class PlayerGun* playergun);
		~PlayerBullet();


		float  GetPositionX() { return mPosition.x; }
		float  GetPositionY() { return mPosition.y; }
		float  GetPositionZ() { return mPosition.z; }

		void Update(float deltaTime);
		void Draw();
		void Coordinate();
		void OnCollisionEnter(GameObject* other);

		//Sphere GetCollsionSphere() { return mCollisionSphere; }

	private:
		class   AnimationController* mAnimControl;// アニメーション管理用
		VECTOR mDir;                     // 弾進行方向
		float  mSpeed;                   // 弾の速度
	};

};


#pragma once
#include "../GameObject.h"

namespace My3dApp
{
	class Zako : public GameObject
	{
	public:
		Zako();
		~Zako();

		void Update(float deltaTime);
		void Draw();

		void SetAnimTypeId(int a) {mAnimTypeId = a;}
		void OnCollisionEnter(GameObject* other);


	protected:
		float      mSpeed=500.0f          ; // 移動速度
		float      mAnimTime;
		class   AnimationController* mAnimControl;// アニメーション管理用
		bool    mCollisionFlag;
		const VECTOR FIRST_SPOT = VGet(5000.0f, 0.0f, 0.0f);
		const VECTOR SECOND_SPOT = VGet(0.0f, 0.0f, 5000.0f);
		const VECTOR THIRD_SPOT = VGet(0.0f, 0.0f, -5000.0f);
	};
}
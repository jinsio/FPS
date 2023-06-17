#pragma once
#include <DxLib.h>
#include "../math/math3D.h"

namespace My3dApp
{
	// @brief 球体当たり判定.
	struct Sphere
	{
		Sphere();
		Sphere(const VECTOR& center, float radius);
		void Move(const VECTOR& pos);

		VECTOR mLocalCenter; // 球体のローカル中心座標
		VECTOR mWorldCenter; // 球体のワールド中心座標
		float  mRadius;      // 球体の半径
	};

	// 当たり判定の関数組み合わせ
	bool CollisionPair(const Sphere& sphere1, const Sphere& sphere2);


}


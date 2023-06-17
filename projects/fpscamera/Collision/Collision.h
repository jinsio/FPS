#pragma once
#include <DxLib.h>
#include "../math/math3D.h"

namespace My3dApp
{
	// @brief ���̓����蔻��.
	struct Sphere
	{
		Sphere();
		Sphere(const VECTOR& center, float radius);
		void Move(const VECTOR& pos);

		VECTOR mLocalCenter; // ���̂̃��[�J�����S���W
		VECTOR mWorldCenter; // ���̂̃��[���h���S���W
		float  mRadius;      // ���̂̔��a
	};

	// �����蔻��̊֐��g�ݍ��킹
	bool CollisionPair(const Sphere& sphere1, const Sphere& sphere2);


}


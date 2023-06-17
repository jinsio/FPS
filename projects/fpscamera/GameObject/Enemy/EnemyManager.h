//-----------------------------------------------------------------------------
// @brief �A�Z�b�g�}�l�[�W���N���X
// ���b�V���t�@�C���E�A�j���[�V�����̊Ǘ����s���B������mv1�t�@�C����ǂݍ��݂��悤�Ƃ���
// �ꍇ�A�N���[�����쐬���A�t�@�C���ǂݍ��݂�}������.
//-----------------------------------------------------------------------------
#pragma once
#include <string>
#include <unordered_map>
//#include <atlstr.h>
#include <DxLib.h>

namespace My3dApp
{
	class EnemyManager final
	{
	public:
		static void Initialize();                                   // �A�Z�b�g�}�l�[�W���̏�����
		static void Finalize();                                     // �A�Z�b�g�}�l�[�W���̏I������
		
		void  SubCoolTime(float deltaTime) { EnemyCoolTime -= deltaTime; }
		float GetCoolTime() { return EnemyCoolTime; }
		float SetCoolTime() { EnemyCoolTime = 2.0f; }

	private:
		EnemyManager();
		~EnemyManager();
		static EnemyManager* mpInstance;                    // AssetManager�C���X�^���X�ւ̃|�C���^�i�A�v�����ɗB�ꑶ�݂���j

		float EnemyCoolTime;
	};

}// namespace My3dApp
//-----------------------------------------------------------------------------
// @brief �A�j���[�V�����R���g���[���N���X
// �A�j���[�V�����̓o�^�A���[�v�Đ��Ȃǂ̊Ǘ�
//-----------------------------------------------------------------------------
#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include <DxLib.h>

namespace My3dApp
{
	class AnimationController final
	{
	public:
		AnimationController(int modelHandle);
		~AnimationController();

		int AddAnimation(std::string animFileName, float animFps = 30.0f, bool isLoop = true); // �A�j���[�V�����̒ǉ�

		void AddAnimationTime(float deltaTime);       // �A�j���[�V�������Ԃ̃Z�b�g
		void StartAnimation(int animID);              // �A�j���[�V�����̍Đ��J�n
		void StopAnimation();                         // �A�j���[�V�����̍Đ����X�g�b�v
		bool IsPlaying();                             // ���ݍĐ�����

		// �A�j���[�V�����f�[�^�p�\���� �A�j���[�V����1��
		struct AnimData
		{
		public:
			AnimData();
			int   mAnimationHandle;                   // �A�j���[�V�����n���h��
			int   mAnimationIndex;                    // �A�^�b�`����A�j���[�V�����ԍ�
			float mAnimationTotalTime;                // ���̃A�j���̑��Đ�����
			float mAnimationPlayFps;                  // �A�j���[�V�����Đ����x
			bool  mIsLoopAnimation;                   // ���[�v�Đ��������邩
		};

	private:
		int   mModelHandle;                           // �匳�̃��f���n���h���B����ɃA�j���[�V���������t����
		std::vector<AnimData> mAnimDatas;             // �A�j���[�V���������o�^�p
		int   mNowAnimTypeNum;                        // ���ݍĐ����̃A�j���[�V����ID
		int   mAttachedIndex;                         // ��t��̃C���f�b�N�X
		float mNowAnimTime;                           // ���ݍĐ����̃A�j���[�V��������
	};

}// namespace My3dApp
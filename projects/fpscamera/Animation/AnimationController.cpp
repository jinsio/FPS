#include "AnimationController.h"
#include "AssetManager.h"

namespace My3dApp
{
	//-----------------------------------------------------------------------------
	// @brief  �R���X�g���N�^.
	// @param[in] modelHandle �A�j���[�V������K�p���郂�f���n���h��.
	//-----------------------------------------------------------------------------

	AnimationController::AnimationController(int modelHandle)
		: mModelHandle(modelHandle)
		, mNowAnimTypeNum(-1)
		, mNowAnimTime(0.0f)
		, mAttachedIndex(0)
	{
	}

	//-----------------------------------------------------------------------------
	// @brief  �f�X�g���N�^.
	//-----------------------------------------------------------------------------
	AnimationController::~AnimationController()
	{
	}
	//-----------------------------------------------------------------------------
	// @brief  �A�j���[�V�����̒ǉ�.
	// @param[in] animFileName �ǉ��������A�j���[�V�����t�@�C����.
	// @param[in] animFPS �A�j���[�V�����̍Đ����x�i�ȗ��B�f�t�H���g��30fps).
	// @param[in] isLoop ���[�v�A�j���[�V���������邩�i�ȗ��B�f�t�H���g�̓��[�v������).
	// @return int �A�j���[�V�����Đ��pID.
	// 
	// @details �R���X�g���N�^�Ŏw�肵��modelHandle�̃��f���ɑ΂��A�A�j���[�V������ǉ�����B
	// �A�j���[�V�������ǉ��ł������̓A�j���[�V�����Đ�ID��Ԃ��B���s����-1��Ԃ�.         
	//-----------------------------------------------------------------------------
	int AnimationController::AddAnimation(std::string animFileName, float animFps, bool isLoop)
	{
		AnimData anim;
		anim.mAnimationPlayFps = animFps;
		anim.mIsLoopAnimation = isLoop;

		// �A�j���[�V�����f�[�^�ǂݍ���
		anim.mAnimationHandle = AssetManager::GetAnimation(animFileName.c_str());
		if (anim.mAnimationHandle == -1)
		{
			return -1;
		}
		anim.mAnimationIndex = MV1GetAnimNum(anim.mAnimationHandle) - 1;

		mAttachedIndex = MV1AttachAnim(mModelHandle, anim.mAnimationIndex, anim.mAnimationHandle, TRUE);
		anim.mAnimationTotalTime = MV1GetAnimTotalTime(anim.mAnimationHandle, anim.mAnimationIndex);

		// �A�j���[�V��������
		int test;
		test = MV1DetachAnim(mModelHandle, mAttachedIndex);

		// �����ɃA�j���[�V�����f�[�^�ǉ�
		mAnimDatas.push_back(anim);

		// vector�ɓ���Y�����ԍ��Ԃ�
		return static_cast<int>(mAnimDatas.size() - 1);
	}

	//-----------------------------------------------------------------------------
	// @brief  �A�j���[�V�����̑���������ݒ�.
	// @param[in] deltaTime 1�t���[���̑��������B�b�P��.
	//
	// @details StartAnimation�Őݒ肳�ꂽ�A�j���[�V�����̍Đ���i�߂�B
	// ���t���[��AddAnimationTime���Ăяo���K�v������B.         
	//-----------------------------------------------------------------------------
	void AnimationController::AddAnimationTime(float deltaTime)
	{
		mNowAnimTime += deltaTime * mAnimDatas[mNowAnimTypeNum].mAnimationPlayFps;

		// ���[�v�Đ�
		if (mAnimDatas[mNowAnimTypeNum].mIsLoopAnimation && mNowAnimTime > mAnimDatas[mNowAnimTypeNum].mAnimationTotalTime)
		{
			mNowAnimTime = 0.0f;
		}
		int test;
		test = MV1SetAttachAnimTime(mModelHandle, mAttachedIndex, mNowAnimTime);
	}
	//-----------------------------------------------------------------------------
	// @brief  �A�j���[�V�����̍Đ����J�n.
	// @param[in] animID �A�j���[�V�������������A�j���[�V�����Đ�ID���w��. 
	//
	// @details animID�Ŏw�肵���A�j���[�V�����̍Đ����J�n����
	// �����A�j���[�V�������w�肳�ꂽ�ꍇ�A�͂��߂���ĊJ����.
	//-----------------------------------------------------------------------------
	void AnimationController::StartAnimation(int animID)
	{
		// �ȑO�̃A�j���[�V�����ƈႤ�A�j���[�V�������������x�f�^�b�`
		if (animID != mNowAnimTypeNum)
		{
			if (mNowAnimTypeNum != -1)
			{
				MV1DetachAnim(mModelHandle, mAttachedIndex);
			}
			// �V�K�A�j���[�V�������Z�b�g
			mNowAnimTypeNum = animID;
			mAttachedIndex = MV1AttachAnim(mModelHandle, mAnimDatas[animID].mAnimationIndex, mAnimDatas[mNowAnimTypeNum].mAnimationHandle, TRUE);
		}
		mNowAnimTime = 0.0f;
		MV1SetAttachAnimTime(mModelHandle, mAttachedIndex, mNowAnimTime);
	}

	//-----------------------------------------------------------------------------
	// @brief  ���ݎw�肳��Ă���A�j���[�V�����̍Đ����I��.
	//
	// @details ���ݎw�肳��Ă���A�j���[�V�������I�������ŃX�g�b�v����
	// �Đ��r���̃|�[�Y�Ŏ~�܂�Ȃ����Ƃɒ��ӁB���[�v�Đ��w��̃A�j���[�V�����͖��������.
	//-----------------------------------------------------------------------------
	void AnimationController::StopAnimation()
	{
		mNowAnimTime = mAnimDatas[mNowAnimTypeNum].mAnimationTotalTime;
	}

	//-----------------------------------------------------------------------------
	// @brief  ���ݎw�肳��Ă���A�j���[�V�����͍Đ������H.
	// @return true : �Đ��� false : �Đ��I��
	//
	// @details ���ݎw�肳��Ă���A�j���[�V�������Đ�������Ԃ�
	// ���[�v�w�肳�ꂽ���̂͏��true��Ԃ��B
	//-----------------------------------------------------------------------------
	bool AnimationController::IsPlaying()
	{
		if (mAnimDatas[mNowAnimTypeNum].mIsLoopAnimation && mNowAnimTime > mAnimDatas[mNowAnimTypeNum].mAnimationTotalTime)
		{
			return false;
		}
		return true;
	}
	//-------------------------------------------------------------------------
	// @brief �A�j���[�V�����f�[�^�N���X �R���X�g���N�^
	//-------------------------------------------------------------------------
	AnimationController::AnimData::AnimData()
		: mAnimationHandle(-1)
		, mAnimationIndex(-1)
		, mAnimationTotalTime(-1.0f)
		, mAnimationPlayFps(0.0f)
		, mIsLoopAnimation(false)
	{
	}

} // namespace My3dApp
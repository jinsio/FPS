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
	class AssetManager final
	{
	public:
		static void Initialize();                                   // �A�Z�b�g�}�l�[�W���̏�����
		static int  GetMesh(std::string meshFileName);              // ���b�V���i���f���j�̎擾
		static int  GetAnimation(std::string animFileName);    // �A�j���[�V�����̎擾
		static void ReleaseMesh(int meshID);                        // ���b�V���i���f���j�̍폜
		static void ReleaseAllAsset();                              // �S���b�V���E�A�j���[�V�����̍폜
		static void Finalize();                                     // �A�Z�b�g�}�l�[�W���̏I������

	private:
		AssetManager();
		~AssetManager();
		static AssetManager* mpInstance;                    // AssetManager�C���X�^���X�ւ̃|�C���^�i�A�v�����ɗB�ꑶ�݂���j

		std::unordered_map<std::string, int> mMeshMap;      // ���b�V�����{�i������͌��{�Ƃ��ĕۑ������s���ADuplicate���ꂽ���̂�Ԃ��j
		std::unordered_map<std::string, int> mAnimationMap; // �A�j���[�V�������{�i������͕Ԃ�)
		std::vector<int> mDuplicatesMesh;                   // ���b�V�����R�s�[�������́i��������g�p����j
	};

}// namespace My3dApp
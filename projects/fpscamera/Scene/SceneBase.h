#pragma once

const int ScreenWidth = 1024;		//�X�N���[�����w��
const int ScreenHeight = 768;		//�X�N���[�������w��
//---�X�N���[���T�C�Y�̗�: 640*480, 800*600, 1024*768, 1280*1024, 1280*720, 1920*1080---//

const int ColorBit = 16;			//�J���[�r�b�g��
//---�J���[�r�b�g���̗�: 16, 32---//

namespace My3dApp
{
	/*SceneBase�̃N���X*/
	class SceneBase
	{
	public:
		/// <summary>
		/// �R���X�g���N�^�\
		/// </summary>
		SceneBase();

		/// <summary>
		/// �f�X�g���N�^�\
		/// </summary>
		virtual ~SceneBase();

		/// <summary>
		/// Scene�X�V����
		/// </summary>
		/// <param name="deltaTime"></param>
		/// <returns>���݂̃V�[���̃|�C���^</returns>
		virtual SceneBase* Update(float deltaTime) = 0;

		/// <summary>
		/// �V�[���̕`��
		/// </summary>
		virtual void Draw() = 0;

	protected:
		int BgHandle;		//�w�i�摜�n���h��
		int BgX;			//�w�i���WX
		int BgY;			//�w�i���WY
	};
}


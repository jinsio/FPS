#pragma once
#include"../SceneBase.h"

namespace My3dApp {
	/*���U���g�V�[���̃N���X*/
	class ResultScene :public SceneBase
	{
	public:
		/// <summary>
		/// �R���X�g���N�^�[
		/// </summary>
		ResultScene();

		/// <summary>
		/// �f�X�g���N�^�[
		/// </summary>
		~ResultScene();

		/// <summary>
		/// ResultScene�X�V����
		/// </summary>
		/// <param name="deltaTime"></param>
		/// <returns>���݂̃V�[���̃|�C���^</returns>
		SceneBase* Update(float deltaTime)override;

		/// <summary>
		/// ���U���g�V�[���̕`��
		/// </summary>
		void Draw()override;

	private:
		int TextHandle;
		int MovieHandle;
		int graph;
	};
}


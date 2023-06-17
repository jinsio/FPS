#pragma once
namespace My3dApp{
	/*TimeManager�̃N���X*/
	class TimeManager
	{
	public:
		/// <summary>
		/// �R���X�g���N�^�\
		/// </summary>
		TimeManager();

		/// <summary>
		/// �f�X�g���N�^�\
		/// </summary>
		~TimeManager();

		/// <summary>
		/// Time�X�V����
		/// </summary>
		void Update();

		/// <summary>
		/// DeltaTime�擾
		/// </summary>
		/// <returns>deltaTime</returns>
		float DeltaTime() { return deltaTime; }

	private:

		float nowTime;		//���݂̎���
		float prevTime;		//�ߋ��̎���
		float deltaTime;	//�t���[�����[�g
	};

}
#pragma once
#include"SceneBase.h"
#include"../UI/TimeManager.h"

/*�V�[���}�l�[�W���[�̃N���X*/
namespace My3dApp 
{
    class SceneManager
    {
    private:
        SceneBase* nowScene;
        TimeManager* timeManager;
    public:
        /// <summary>
        /// �R���X�g���N�^�[
        /// </summary>
        SceneManager();

        /// <summary>
        /// �f�X�g���N�^�[
        /// </summary>
        ~SceneManager();

        /// <summary>
        /// SceneManager�X�V����
        /// </summary>
        void Update();

        /// <summary>
        /// ���݂̃V�[���̕`��
        /// </summary>
        void Draw();
    };
}

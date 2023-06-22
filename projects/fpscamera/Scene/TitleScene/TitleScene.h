#pragma once
#include "../SceneBase.h"
namespace My3dApp {
    class TitleScene :
        public SceneBase
    {
    public:
        /// <summary>
        /// �R���X�g���N�^�[
        /// </summary>
        TitleScene();

        /// <summary>
        /// �f�X�g���N�^�[
        /// </summary>
        ~TitleScene();

        /// <summary>
        /// TitleScene�X�V����
        /// </summary>
        /// <param name="deltaTime"></param>
        /// <returns>���݂̃V�[���̃|�C���^</returns>
        SceneBase* Update(float deltaTime)override;

        /// <summary>
        /// �^�C�g���V�[���̕`��
        /// </summary>
        void Draw()override;

    private:
        int mHandle;
        VECTOR mPos;

        const int FirstPosX=1920/4;
        const int FirstPosY=-300;
    };
}


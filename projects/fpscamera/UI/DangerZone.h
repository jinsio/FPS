#pragma once
#include "../GameObject/GameObject.h"
namespace My3dApp 
{
    class DangerZone final
    {
    public:
        static void Intialize();
        static void SetFlag();
        static void Update(float deltaTime);
        static void Draw();
        
    private:
        DangerZone();
        ~DangerZone();
        static DangerZone* mpInstance;
        static float DangerRenge;   //�`�悳���͈�
        static int Handle;          //�摜�n���h��
        static bool DrawFlag;       //�`��t���O
        static float Degtorad; // �x���\�L�����W�A���ɕϊ�����萔
        static float Fade;          //Fade�w��
    };
}

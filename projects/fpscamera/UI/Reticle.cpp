#include "Reticle.h"

namespace My3dApp
{
    Reticle::Reticle()
        :GameObject(ObjectTag::Reticle)
    {

    }
    Reticle::~Reticle()
    {

    }
    void My3dApp::Reticle::Update(float deltaTime)
    {
    }

    void My3dApp::Reticle::Draw()
    {
        //LoadGraphScreen(928, 572 - 50, "data/model/FPS/Reticle.png", TRUE);
    }
}
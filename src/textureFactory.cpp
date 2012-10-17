#include "textureFactory.h"

Texture *TextureFactory::m_pCubeTexture = 0;

Texture *TextureFactory::getCubeTexture()
{
    if (TextureFactory::m_pCubeTexture == 0) {
        TextureFactory::m_pCubeTexture = new Texture(GL_TEXTURE_2D, "../resources/test.png");
        if (!TextureFactory::m_pCubeTexture->Load()) {
            //return 1;
        }
    }
    return TextureFactory::m_pCubeTexture;
}

void TextureFactory::die()
{
    delete m_pCubeTexture;
}

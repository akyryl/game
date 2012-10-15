#ifndef __TEXTURE_FACTORY_H__
#define __TEXTURE_FACTORY_H__


#include <GL/glew.h>
#include "texture.h"


class TextureFactory
{
    static Texture *m_pCubeTexture;
public:
    static Texture *getCubeTexture()
    {
        if (m_pCubeTexture == 0) {
            m_pCubeTexture = new Texture(GL_TEXTURE_2D, "../resources/test.png");
            if (!m_pCubeTexture->Load()) {
                //return 1;
            }
        }
        return m_pCubeTexture;
    }
};

Texture *TextureFactory::m_pCubeTexture = 0;


#endif // __TEXTURE_FACTORY_H__

#ifndef __TEXTURE_FACTORY_H__
#define __TEXTURE_FACTORY_H__


#include <GL/glew.h>
#include "texture.h"


class TextureFactory
{
    static Texture *m_pCubeTexture;
public:
    static Texture *getCubeTexture();
    static void die();
};

#endif // __TEXTURE_FACTORY_H__

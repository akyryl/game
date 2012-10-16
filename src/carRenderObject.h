#ifndef __CAR_RENDER_OBJECT_H__
#define __CAR_RENDER_OBJECT_H__


#include <GL/glew.h>
#include "renderObject.h"
#include "math_3d.h"
#include "texture.h"


struct Vertex
{
    Vector3f m_pos;
    Vector2f m_tex;

    Vertex() {}

    Vertex(Vector3f pos, Vector2f tex)
    {
        m_pos = pos;
        m_tex = tex;
    }
};

class CarRenderObject : public RenderObject
{
public:
    CarRenderObject();
    virtual ~CarRenderObject();

    void render();

private:
    GLuint VBO;
    GLuint IBO;
    Texture* pTexture;

    unsigned int vertices_count;

    void createVertexBuffer();
    void createIndexBuffer();
};


#endif // __CAR_RENDER_OBJECT_H__

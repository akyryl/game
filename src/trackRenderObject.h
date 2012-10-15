#ifndef __TRACK_RENDER_OBJECT_H__
#define __TRACK_RENDER_OBJECT_H__


#include "renderObject.h"

#include <GL/glew.h>
#include "renderObject.h"
#include "math_3d.h"
#include "texture.h"

class TrackRenderObject : public RenderObject
{
public:
    TrackRenderObject();
    virtual ~TrackRenderObject();

    void render() const;

private:
    GLuint VBO;
    GLuint IBO;
    Texture* pTexture;

    unsigned int vertices_count;

    void createVertexBuffer();
    void createIndexBuffer();
};


#endif // __TRACK_RENDER_OBJECT_H__

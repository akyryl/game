#ifndef __CAR_RENDER_OBJECT_H__
#define __CAR_RENDER_OBJECT_H__


#include <GL/glew.h>
#include "renderObject.h"
#include "math_3d.h"
#include "texture.h"
#include "vertex.h"


static const char* cpVS = "                                                          \n\
#version 330                                                                        \n\
                                                                                    \n\
layout (location = 0) in vec3 Position;                                             \n\
layout (location = 1) in vec2 TexCoord;                                             \n\
//\n\
                                                                                    \n\
uniform mat4 gWVP;                                                                  \n\
                                                                                    \n\
out vec2 TexCoord0;                                                                 \n\
                                                                                    \n\
void main()                                                                         \n\
{                                                                                   \n\
    gl_Position = gWVP * vec4(Position, 1.0);                                       \n\
    TexCoord0 = TexCoord;                                                           \n\
//\n\
}";

static const char* cpFS = "                                                          \n\
#version 330                                                                        \n\
                                                                                    \n\
in vec2 TexCoord0;                                                                  \n\
//\n\
                                                                                    \n\
out vec4 FragColor;                                                                 \n\
                                                                                    \n\
uniform sampler2D gSampler;                                                         \n\
                                                                                    \n\
void main()                                                                         \n\
{                                                                                   \n\
    FragColor = texture2D(gSampler, TexCoord0.xy);                                  \n\
//FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n\
}";

class CarRenderObject : public RenderObject
{
public:
    CarRenderObject();
    virtual ~CarRenderObject();

    void render();
    void stepLeft();
    void stepRight();

private:
    GLuint VBO;
    GLuint IBO;
    Texture* pTexture;

    GLuint gWVPLocation;
    GLuint gSampler;

    GLuint m_shaderProgram;

    Vector3f m_pos;

    unsigned int vertices_count;

    void createVertexBuffer();
    void createIndexBuffer();

    void compileShaders();
    void addShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType);
};


#endif // __CAR_RENDER_OBJECT_H__

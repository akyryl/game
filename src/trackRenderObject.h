#ifndef __TRACK_RENDER_OBJECT_H__
#define __TRACK_RENDER_OBJECT_H__


#include "renderObject.h"

#include <GL/glew.h>
#include "renderObject.h"
#include "math_3d.h"
#include "texture.h"
#include <vector>

class Vertex;

static const char* tpVS = "                                                          \n\
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

static const char* tpFS = "                                                          \n\
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

class TrackRenderObject : public RenderObject
{
public:
    TrackRenderObject();
    virtual ~TrackRenderObject();

    void render();
    void move();

private:
    GLuint VBO;
    GLuint IBO;
    Texture* pTexture;

    GLuint gWVPLocation;
    GLuint gSampler;

    GLuint m_shaderProgram;

    unsigned int vertices_count;

    std::vector <Vertex> m_trackVertices;
    int m_trackDeep;
    int m_trackItemStep;

    void initTrackVertices();
    void updateTrackVertices(float newX);

    void createVertexBuffer();
    void bindVertexBuffer();
    void createIndexBuffer();

    void compileShaders();
    void renderTrack(const Vector3f &worldPos);
    void addShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType);

    static const Vertex m_trackItemTemplate[];
    static int m_trackItemVerticesCount;
};


#endif // __TRACK_RENDER_OBJECT_H__

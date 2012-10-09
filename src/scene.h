#ifndef __SCENE_H__
#define __SCENE_H__


#include <GL/glew.h>

#include "camera.h"
#include "game.h"


static const char* pVS = "                                                          \n\
#version 330                                                                        \n\
                                                                                    \n\
layout (location = 0) in vec3 Position;                                             \n\
//layout (location = 1) in vec2 TexCoord;                                             \n\
                                                                                    \n\
uniform mat4 gWVP;                                                                  \n\
                                                                                    \n\
out vec2 TexCoord0;                                                                 \n\
                                                                                    \n\
void main()                                                                         \n\
{                                                                                   \n\
    gl_Position = gWVP * vec4(Position, 1.0);                                       \n\
//    TexCoord0 = TexCoord;                                                           \n\
}";

static const char* pFS = "                                                          \n\
#version 330                                                                        \n\
                                                                                    \n\
//in vec2 TexCoord0;                                                                  \n\
                                                                                    \n\
out vec4 FragColor;                                                                 \n\
                                                                                    \n\
uniform sampler2D gSampler;                                                         \n\
                                                                                    \n\
void main()                                                                         \n\
{                                                                                   \n\
//    FragColor = texture2D(gSampler, TexCoord0.xy);                                  \n\
FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n\
}";


class Scene
{
public:
    Scene();
    ~Scene();

    void renderScene() const;
    void compileShaders();
    void addShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType);
    void onKeyboard() const;
    void onSpecialKeyboard(int Key, int x, int y) const;
    void onMouse(int x, int y) const;

private:
    int m_windowWidth;
    int m_windowHeight;

    Camera* pGameCamera;

    GLuint gWVPLocation;
    GLuint gSampler;

    Game *m_pGame;

};


#endif // __SCENE_H__

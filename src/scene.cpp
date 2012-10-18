#include "scene.h"

#include "pipeline.h"

#include <GL/freeglut.h>
#include <string.h>
#include <assert.h>
#include "commonRenderData.h"
#include "textureFactory.h"


Scene::Scene()
    : pGameCamera(NULL)
{
    pGameCamera = CommonRenderData::getInstance()->getCamera();
    m_windowWidth = CommonRenderData::getInstance()->getWindowWidth();
    m_windowHeight = CommonRenderData::getInstance()->getWindowHeight();

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    //glFrontFace(GL_CW);
    //glCullFace(GL_BACK);

    // enable drawing texture back side
    glDisable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    m_pGame = new Game();

    //compileShaders();
    //glUniform1i(gSampler, 0);
}

Scene::~Scene()
{
    delete m_pGame;
    TextureFactory::die();
    CommonRenderData::getInstance()->die();
}

void Scene::renderScene()
{
    //glUseProgram(m_shaderProgram);

    pGameCamera->OnRender();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    static float Scale = 0.0f;
    Scale += 0.01f;

    Pipeline p;
    p.Rotate(0.0f, 0.0f, 0.0f);
    p.WorldPos(0.0f, -5.0f, 15.0f);
    p.SetCamera(pGameCamera->GetPos(), pGameCamera->GetTarget(), pGameCamera->GetUp());
    p.SetPerspectiveProj(60.0f, m_windowWidth, m_windowHeight, 1.0f, 100.0f);

    glUniformMatrix4fv(gWVPLocation, 1, GL_TRUE, (const GLfloat*)p.GetTrans());

    const RenderObjectsArr *pRenderObjects = m_pGame->getRenderObjects();
    RenderObjectsConstIter end = pRenderObjects->end();
    for (RenderObjectsConstIter iter = pRenderObjects->begin(); iter != end; ++iter) {
        (*iter)->render();
    }

    glutSwapBuffers();
}

void Scene::compileShaders()
{
    m_shaderProgram = glCreateProgram();

    if (m_shaderProgram == 0) {
        fprintf(stderr, "Error creating shader program\n");
        exit(1);
    }

    addShader(m_shaderProgram, pVS, GL_VERTEX_SHADER);
    addShader(m_shaderProgram, pFS, GL_FRAGMENT_SHADER);

    GLint Success = 0;
    GLchar ErrorLog[1024] = { 0 };

    glLinkProgram(m_shaderProgram);
    glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &Success);
    if (Success == 0) {
        glGetProgramInfoLog(m_shaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
        fprintf(stderr, "Error linking shader program: '%s'\n", ErrorLog);
        exit(1);
    }

    glValidateProgram(m_shaderProgram);
    glGetProgramiv(m_shaderProgram, GL_VALIDATE_STATUS, &Success);
    if (!Success) {
        glGetProgramInfoLog(m_shaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
        fprintf(stderr, "Invalid shader program: '%s'\n", ErrorLog);
        exit(1);
    }

    glUseProgram(m_shaderProgram);

    gWVPLocation = glGetUniformLocation(m_shaderProgram, "gWVP");
    assert(gWVPLocation != 0xFFFFFFFF);
    /*gSampler = glGetUniformLocation(m_shaderProgram, "gSampler");
    assert(gSampler != 0xFFFFFFFF);*/
}

void Scene::addShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType)
{
    GLuint ShaderObj = glCreateShader(ShaderType);

    if (ShaderObj == 0) {
        fprintf(stderr, "Error creating shader type %d\n", ShaderType);
        exit(0);
    }

    const GLchar* p[1];
    p[0] = pShaderText;
    GLint Lengths[1];
    Lengths[0]= strlen(pShaderText);
    glShaderSource(ShaderObj, 1, p, Lengths);
    glCompileShader(ShaderObj);
    GLint success;
    glGetShaderiv(ShaderObj, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLchar InfoLog[1024];
        glGetShaderInfoLog(ShaderObj, 1024, NULL, InfoLog);
        fprintf(stderr, "Error compiling shader type %d: '%s'\n", ShaderType, InfoLog);
        exit(1);
    }

    glAttachShader(ShaderProgram, ShaderObj);
}

void Scene::onKeyboard() const
{
}

void Scene::onSpecialKeyboard(int Key, int x, int y) const
{
    pGameCamera->OnKeyboard(Key);
}

void Scene::onMouse(int x, int y) const
{
    pGameCamera->OnMouse(x, y);
}

#include "trackRenderObject.h"

#include "carRenderObject.h"
#include <assert.h>
#include <string.h>
#include "pipeline.h"
#include "textureFactory.h"
#include "vertex.h"
#include "camera.h"


TrackRenderObject::TrackRenderObject()
    : pTexture(NULL)
{
    createVertexBuffer();
    createIndexBuffer();
    pTexture = TextureFactory::getCubeTexture();

    compileShaders();
    glUniform1i(gSampler, 0);
}

TrackRenderObject::~TrackRenderObject()
{

}

void TrackRenderObject::createVertexBuffer()
{
    Vertex vertices[] = {

        // top

        Vertex(Vector3f(0.0f, 1.0f, -1.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(0.0f, 1.0f, 0.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(1.0f, 1.0f, -1.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(1.0f, 1.0f, 0.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(0.0f, 1.0f, -2.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(0.0f, 1.0f, -1.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(1.0f, 1.0f, -2.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(1.0f, 1.0f, -1.0f), Vector2f(1.0f, 1.0f)),

        // front side

        Vertex(Vector3f(0.0f, 1.0f, 0.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(0.0f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(1.0f, 1.0f, 0.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(1.0f, 0.0f, 0.0f), Vector2f(1.0f, 1.0f)),

        // right sides

        Vertex(Vector3f(0.0f, 1.0f, 0.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(0.0f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(0.0f, 1.0f, -1.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(0.0f, 0.0f, -1.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(0.0f, 1.0f, -1.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(0.0f, 0.0f, -1.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(0.0f, 1.0f, -2.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(0.0f, 0.0f, -2.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(1.0f, 1.0f, 0.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(1.0f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(1.0f, 1.0f, -1.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(1.0f, 0.0f, -1.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(1.0f, 1.0f, -1.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(1.0f, 0.0f, -1.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(1.0f, 1.0f, -2.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(1.0f, 0.0f, -2.0f), Vector2f(1.0f, 1.0f)),

        // back side

        Vertex(Vector3f(0.0f, 1.0f, -2.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(0.0f, 0.0f, -2.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(1.0f, 1.0f, -2.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(1.0f, 0.0f, -2.0f), Vector2f(1.0f, 1.0f)),
    };

    vertices_count = sizeof(vertices) / sizeof(Vertex);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void TrackRenderObject::createIndexBuffer()
{
    int indices_count = vertices_count * 1.5;

    unsigned int indices[indices_count];
    unsigned int index = -1;

    for (int i = 0; i < vertices_count; i += 4) {
        indices[++index] = i + 0;  // 0
        indices[++index] = i + 1;  // 1
        indices[++index] = i + 2;  // 2

        indices[++index] = i + 1;  // 1
        indices[++index] = i + 3;  // 3
        indices[++index] = i + 2;  // 2, 4, 5, 6, 5, 7, 6, ...
    }

    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void TrackRenderObject::move()
{

}

void TrackRenderObject::render()
{
    // use track program
    glUseProgram(m_shaderProgram);

    // calculate transormation and set it
    static float Scale = 0.0f;
    Scale += 0.01f;
    // TODO: use global camera
    Camera* pGameCamera = new Camera(1920, 1200);
    Pipeline p;
    p.Rotate(0.0f, Scale, 0.0f);
    p.WorldPos(0.0f, -5.0f, 15.0f);
    p.SetCamera(pGameCamera->GetPos(), pGameCamera->GetTarget(), pGameCamera->GetUp());
    p.SetPerspectiveProj(60.0f, 1920, 1200, 1.0f, 100.0f);
    glUniformMatrix4fv(gWVPLocation, 1, GL_TRUE, (const GLfloat*)p.GetTrans());

    // draw
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)12);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    pTexture->Bind(GL_TEXTURE0);

    unsigned int points_count = vertices_count * 1.5;
    glDrawElements(GL_TRIANGLES, points_count, GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

void TrackRenderObject::compileShaders()
{
    m_shaderProgram = glCreateProgram();

    if (m_shaderProgram == 0) {
        fprintf(stderr, "Error creating shader program\n");
        exit(1);
    }

    addShader(m_shaderProgram, tpVS, GL_VERTEX_SHADER);
    addShader(m_shaderProgram, tpFS, GL_FRAGMENT_SHADER);

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
    //gSampler = glGetUniformLocation(m_shaderProgram, "gSampler");
    //assert(gSampler != 0xFFFFFFFF);
}

void TrackRenderObject::addShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType)
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

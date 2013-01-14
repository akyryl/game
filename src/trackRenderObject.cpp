#include "trackRenderObject.h"

#include "carRenderObject.h"
#include <assert.h>
#include <string.h>
#include "pipeline.h"
#include "textureFactory.h"
#include "vertex.h"
#include "camera.h"
#include "commonRenderData.h"

const Vertex TrackRenderObject::m_trackItemTemplate[] =
{
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

int TrackRenderObject::m_trackItemVerticesCount = sizeof(TrackRenderObject::m_trackItemTemplate) / sizeof(Vertex);
int TrackRenderObject::m_trackLinesCount = 2;

TrackRenderObject::TrackRenderObject()
    : pTexture(NULL)
{
    m_trackDeep = 99;
    m_trackItemStep = 3;
    m_trackWidth = 8;
    initTrackVertices();
    createIndexBuffer();
    pTexture = TextureFactory::getCubeTexture();

    compileShaders();
    glUniform1i(gSampler, 0);
}

TrackRenderObject::~TrackRenderObject()
{

}

void TrackRenderObject::initTrackVertices()
{
    m_trackVertices.clear();
    const int trackItemsCount = m_trackDeep / m_trackItemStep;
    const int trackVerticesCount = trackItemsCount * m_trackItemVerticesCount * m_trackLinesCount;
    m_trackVertices.reserve(trackVerticesCount);

    // build vertices from farther to closest one
    for (int i = 0; i < m_trackDeep - 1; i += m_trackItemStep) {
        // add left item
        addTrackItemVertices(Vector3f(0, 0, m_trackDeep - i));
        // add right item
        addTrackItemVertices(Vector3f(0, m_trackWidth, m_trackDeep - i));
    }

    vertices_count = m_trackVertices.size();
    glGenBuffers(1, &VBO);
    bindVertexBuffer();
}

void TrackRenderObject::addTrackItemVertices(Vector3f movingVertex)
{
    for (int i = 0; i < m_trackItemVerticesCount; ++i) {
        Vertex vertex = m_trackItemTemplate[i];
        vertex.m_pos.x += movingVertex.x;
        vertex.m_pos.y += movingVertex.y;
        vertex.m_pos.z += movingVertex.z;
        m_trackVertices.push_back(vertex);
    }
}

void TrackRenderObject::updateTrackVertices(float newX)
{
    // copy x of first item to next one
    for (int i = m_trackVertices.size() - 1; i >= m_trackItemVerticesCount ; --i) {
        m_trackVertices[i].m_pos.x = m_trackVertices[i - m_trackItemVerticesCount * m_trackLinesCount].m_pos.x;
    }
    // set new X for first item
    for (int i = 0; i < m_trackItemVerticesCount * m_trackLinesCount; ++i) {
        m_trackVertices[i].m_pos.x = m_trackVertices[i].m_pos.x + newX;
    }
    bindVertexBuffer();
}

void TrackRenderObject::bindVertexBuffer()
{
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_trackVertices[0]) * m_trackVertices.size(), m_trackVertices.data(), GL_STATIC_DRAW);
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

static float nextItemNewXPos = 1.f;
static int waveEffect = 0;

void TrackRenderObject::render()
{
    // track animation
    // TODO: do animation in track object.
    static float z_road_pos = 13.0f;
    z_road_pos -= 0.01f;
    if (z_road_pos < 10) {
        z_road_pos = 13.0f;

        waveEffect += 1;
        if (waveEffect % 5 == 0) {
            nextItemNewXPos = -nextItemNewXPos;
        }
        updateTrackVertices(nextItemNewXPos);
    }
    // :ODOT

    renderTrack(Vector3f(1.5f, -5.0f, z_road_pos));
}

void TrackRenderObject::renderTrack(const Vector3f &worldPos)
{
    glUseProgram(m_shaderProgram);

    Camera* pGameCamera = CommonRenderData::getInstance()->getCamera();
    Pipeline p;
    p.Rotate(0.0f, 0.0f, 0.0f);
    p.SetCamera(pGameCamera->GetPos(), pGameCamera->GetTarget(), pGameCamera->GetUp());
    int windowWidth = CommonRenderData::getInstance()->getWindowWidth();
    int windowHeight = CommonRenderData::getInstance()->getWindowHeight();
    p.SetPerspectiveProj(60.0f, windowWidth, windowHeight, 1.0f, 100.0f);
    p.WorldPos(worldPos.x, worldPos.y, worldPos.z);
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

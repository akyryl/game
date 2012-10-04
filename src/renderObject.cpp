#include "renderObject.h"


RenderObject::RenderObject()
    : pTexture(NULL)
{
    createVertexBuffer();
    createIndexBuffer();
    pTexture = new Texture(GL_TEXTURE_2D, "../resources/test.png");
    if (!pTexture->Load()) {
        //return 1;
    }
}

RenderObject::~RenderObject()
{
    delete pTexture;
}

void RenderObject::createVertexBuffer()
{
    Vertex Vertices[4] = { Vertex(Vector3f(-1.0f, -1.0f, 0.5773f), Vector2f(0.0f, 0.0f)),
                           Vertex(Vector3f(0.0f, -1.0f, -1.15475), Vector2f(0.5f, 0.0f)),
                           Vertex(Vector3f(1.0f, -1.0f, 0.5773f),  Vector2f(1.0f, 0.0f)),
                           Vertex(Vector3f(0.0f, 1.0f, 0.0f),      Vector2f(0.5f, 1.0f)) };

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
}

void RenderObject::createIndexBuffer()
{
    unsigned int Indices[] = { 0, 3, 1,
                               1, 3, 2,
                               2, 3, 0,
                               1, 2, 0 };

    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indices), Indices, GL_STATIC_DRAW);
}

void RenderObject::render()
{
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)12);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    pTexture->Bind(GL_TEXTURE0);
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

#include "carRenderObject.h"


CarRenderObject::CarRenderObject()
    : pTexture(NULL)
{
    createVertexBuffer();
    createIndexBuffer();
    pTexture = new Texture(GL_TEXTURE_2D, "../resources/test.png");
    if (!pTexture->Load()) {
        //return 1;
    }
}

CarRenderObject::~CarRenderObject()
{
    delete pTexture;
}

void CarRenderObject::createVertexBuffer()
{
    Vertex vertices[12] = {
        Vertex(Vector3f(-0.5f, -1.0f, -1.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(-0.5f, -1.0f, 0.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(0.5f, -1.0f, -1.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(0.5f, -1.0f, 0.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(-1.5f, -1.0f, -2.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(-1.5f, -1.0f, -1.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(-0.5f, -1.0f, -2.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(-0.5f, -1.0f, -1.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(-0.5f, -1.0f, -2.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(-0.5f, -1.0f, -1.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(0.5f, -1.0f, -2.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(0.5f, -1.0f, -1.0f), Vector2f(1.0f, 1.0f))/*,

        Vertex(Vector3f(0.5f, -1.0f, -2.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(0.5f, -1.0f, -1.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(1.5f, -1.0f, -2.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(1.5f, -1.0f, -1.0f), Vector2f(1.0f, 1.0f))*/
    };

    /*Vertex vertices[4] = { Vertex(Vector3f(-1.0f, -1.0f, 0.5773f), Vector2f(0.0f, 0.0f)),
                           Vertex(Vector3f(0.0f, -1.0f, -1.15475), Vector2f(0.5f, 0.0f)),
                           Vertex(Vector3f(1.0f, -1.0f, 0.5773f),  Vector2f(1.0f, 0.0f)),
                           Vertex(Vector3f(0.0f, 1.0f, 0.0f),      Vector2f(0.5f, 1.0f)) };*/

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void CarRenderObject::createIndexBuffer()
{
    /*unsigned int indices[] = { 0, 3, 1,
                               1, 3, 2,
                               2, 3, 0,
                               1, 2, 0 };*/

    unsigned int indices[] = { 0, 1, 2,
                               1, 3, 2,
                               4, 5, 6,
                               5, 7, 6,
                               8, 9, 10,
                               9, 11, 10/*,
                               12, 13, 14,
                               13, 15, 14*/};

    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void CarRenderObject::render() const
{
    /*glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)12);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    pTexture->Bind(GL_TEXTURE0);
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);*/

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)12);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    pTexture->Bind(GL_TEXTURE0);
    glDrawElements(GL_TRIANGLES, 16, GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

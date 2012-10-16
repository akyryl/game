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
    Vertex vertices[] = {

        // top

        Vertex(Vector3f(-0.5f, 1.0f, -1.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(-0.5f, 1.0f, 0.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(0.5f, 1.0f, -1.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(0.5f, 1.0f, 0.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(-1.5f, 1.0f, -2.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(-1.5f, 1.0f, -1.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(-0.5f, 1.0f, -2.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(-0.5f, 1.0f, -1.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(-0.5f, 1.0f, -2.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(-0.5f, 1.0f, -1.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(0.5f, 1.0f, -2.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(0.5f, 1.0f, -1.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(0.5f, 1.0f, -2.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(0.5f, 1.0f, -1.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(1.5f, 1.0f, -2.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(1.5f, 1.0f, -1.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(-0.5f, 1.0f, -3.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(-0.5f, 1.0f, -2.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(0.5f, 1.0f, -3.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(0.5f, 1.0f, -2.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(-1.5f, 1.0f, -4.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(-1.5f, 1.0f, -3.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(-0.5f, 1.0f, -4.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(-0.5f, 1.0f, -3.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(0.5f, 1.0f, -4.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(0.5f, 1.0f, -3.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(1.5f, 1.0f, -4.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(1.5f, 1.0f, -3.0f), Vector2f(1.0f, 1.0f)),

        // front sides

        Vertex(Vector3f(-0.5f, 1.0f, 0.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(-0.5f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(0.5f, 1.0f, 0.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(0.5f, 0.0f, 0.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(-1.5f, 1.0f, -1.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(-1.5f, 0.0f, -1.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(-0.5f, 1.0f, -1.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(-0.5f, 0.0f, -1.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(0.5f, 1.0f, -1.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(0.5f, 0.0f, -1.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(1.5f, 1.0f, -1.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(1.5f, 0.0f, -1.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(-1.5f, 1.0f, -3.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(-1.5f, 0.0f, -3.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(-0.5f, 1.0f, -3.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(-0.5f, 0.0f, -3.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(0.5f, 1.0f, -3.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(0.5f, 0.0f, -3.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(1.5f, 1.0f, -3.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(1.5f, 0.0f, -3.0f), Vector2f(1.0f, 1.0f)),

        // back sides

        Vertex(Vector3f(-1.5f, 1.0f, -2.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(-1.5f, 0.0f, -2.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(-0.5f, 1.0f, -2.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(-0.5f, 0.0f, -2.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(0.5f, 1.0f, -2.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(0.5f, 0.0f, -2.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(1.5f, 1.0f, -2.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(1.5f, 0.0f, -2.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(-1.5f, 1.0f, -4.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(-1.5f, 0.0f, -4.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(-0.5f, 1.0f, -4.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(-0.5f, 0.0f, -4.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(0.5f, 1.0f, -4.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(0.5f, 0.0f, -4.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(1.5f, 1.0f, -4.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(1.5f, 0.0f, -4.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(-0.5f, 1.0f, -3.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(-0.5f, 0.0f, -3.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(0.5f, 1.0f, -3.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(0.5f, 0.0f, -3.0f), Vector2f(1.0f, 1.0f)),

        // right sides

        Vertex(Vector3f(-0.5f, 1.0f, 0.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(-0.5f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(-0.5f, 1.0f, -1.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(-0.5f, 0.0f, -1.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(-1.5f, 1.0f, -1.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(-1.5f, 0.0f, -1.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(-1.5f, 1.0f, -2.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(-1.5f, 0.0f, -2.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(-0.5f, 1.0f, -2.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(-0.5f, 0.0f, -2.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(-0.5f, 1.0f, -3.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(-0.5f, 0.0f, -3.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(-1.5f, 1.0f, -3.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(-1.5f, 0.0f, -3.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(-1.5f, 1.0f, -4.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(-1.5f, 0.0f, -4.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(-0.5f, 1.0f, -3.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(-0.5f, 0.0f, -3.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(-0.5f, 1.0f, -4.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(-0.5f, 0.0f, -4.0f), Vector2f(1.0f, 1.0f)),

        // left sides

        Vertex(Vector3f(0.5f, 1.0f, 0.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(0.5f, 0.0f, 0.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(0.5f, 1.0f, -1.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(0.5f, 0.0f, -1.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(1.5f, 1.0f, -1.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(1.5f, 0.0f, -1.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(1.5f, 1.0f, -2.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(1.5f, 0.0f, -2.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(0.5f, 1.0f, -2.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(0.5f, 0.0f, -2.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(0.5f, 1.0f, -3.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(0.5f, 0.0f, -3.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(1.5f, 1.0f, -3.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(1.5f, 0.0f, -3.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(1.5f, 1.0f, -4.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(1.5f, 0.0f, -4.0f), Vector2f(1.0f, 1.0f)),

        Vertex(Vector3f(0.5f, 1.0f, -3.0f), Vector2f(0.0f, 0.0f)),
        Vertex(Vector3f(0.5f, 0.0f, -3.0f), Vector2f(0.0f, 1.0f)),
        Vertex(Vector3f(0.5f, 1.0f, -4.0f), Vector2f(1.0f, 0.0f)),
        Vertex(Vector3f(0.5f, 0.0f, -4.0f), Vector2f(1.0f, 1.0f)),
    };

    /*Vertex vertices[4] = { Vertex(Vector3f(-1.0f, -1.0f, 0.5773f), Vector2f(0.0f, 0.0f)),
                           Vertex(Vector3f(0.0f, -1.0f, -1.15475), Vector2f(0.5f, 0.0f)),
                           Vertex(Vector3f(1.0f, -1.0f, 0.5773f),  Vector2f(1.0f, 0.0f)),
                           Vertex(Vector3f(0.0f, 1.0f, 0.0f),      Vector2f(0.5f, 1.0f)) };*/

    vertices_count = sizeof(vertices) / sizeof(Vertex);
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

void CarRenderObject::render()
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

    unsigned int points_count = vertices_count * 1.5;
    glDrawElements(GL_TRIANGLES, points_count, GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

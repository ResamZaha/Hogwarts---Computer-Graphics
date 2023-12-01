#pragma once
#ifndef PYRAMID_H
#define PYRAMID_H
#include "stb_image.h"
#include <iostream>
#include <string>
#include <glm/glm.hpp>
#include "shader.h"

class Pyramid {
public:
    Pyramid(const glm::mat4& transform, GLuint textureId);
    ~Pyramid();

    void draw(Shader& shader);
    void setTransform(glm::mat4 model);

private:
    GLuint VAO, VBO, texture;
    glm::mat4 modelMatrix;

    // Initialize the pyramid (setup VAO, VBO, texture, etc.)
    void init();
};

Pyramid::Pyramid(const glm::mat4& transform, GLuint textureId)
    : modelMatrix(transform), texture(textureId)
{
    init();
}

Pyramid::~Pyramid() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    // Handle texture deletion if necessary
}

void Pyramid::init() {
    GLfloat vertices[] = {
        // Positions         // Normals           // Texture Coords
        // Base (y = 0, normal pointing down)
        -0.5f, 0.0f, -0.5f,  0.0f, -1.0f, 0.0f,  0.0f, 0.0f,
         0.5f, 0.0f, -0.5f,  0.0f, -1.0f, 0.0f,  10.0f, 0.0f,
         0.5f, 0.0f,  0.5f,  0.0f, -1.0f, 0.0f,  10.0f, 10.0f,
        -0.5f, 0.0f,  0.5f,  0.0f, -1.0f, 0.0f,  0.0f, 10.0f,

        // Side 1 (Front)
        -0.5f, 0.0f, -0.5f,  0.0f,  0.707f, 0.707f,  0.0f, 0.0f,
         0.5f, 0.0f, -0.5f,  0.0f,  0.707f, 0.707f,  10.0f, 0.0f,
         0.0f, 1.0f,  0.0f,  0.0f,  0.707f, 0.707f,  5, 10.0f,

         // Side 2 (Right)
          0.5f, 0.0f, -0.5f,  0.707f, 0.707f, 0.0f,  0.0f, 0.0f,
          0.5f, 0.0f,  0.5f,  0.707f, 0.707f, 0.0f,  10.0f, 0.0f,
          0.0f, 1.0f,  0.0f,  0.707f, 0.707f, 0.0f,  5, 10.0f,

          // Side 3 (Back)
           0.5f, 0.0f,  0.5f,  0.0f,  0.707f, -0.707f, 0.0f, 0.0f,
          -0.5f, 0.0f,  0.5f,  0.0f,  0.707f, -0.707f, 10.0f, 0.0f,
           0.0f, 1.0f,  0.0f,  0.0f,  0.707f, -0.707f, 5, 10.0f,

           // Side 4 (Left)
           -0.5f, 0.0f,  0.5f, -0.707f, 0.707f, 0.0f,  0.0f, 0.0f,
           -0.5f, 0.0f, -0.5f, -0.707f, 0.707f, 0.0f,  10.0f, 0.0f,
            0.0f, 1.0f,  0.0f, -0.707f, 0.707f, 0.0f,  5, 10.0f,
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Vertex positions
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Vertex normals
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Texture coords
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);
}

void Pyramid::draw(Shader& shader) {
    glBindVertexArray(VAO);

    shader.use();

    shader.setInt("textures.diffuse", 0);
    shader.setInt("textures.specular", 1);
    shader.setFloat("textures.shininess", 32);

    shader.setBool("drawWithTexture", true);

    // bind diffuse map
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    // bind specular map
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture);

    shader.setMat4("model", modelMatrix);

    // Draw the pyramid
    glDrawArrays(GL_TRIANGLES, 0, 18); // 6 triangles (4 sides + base) * 3 vertices each

    glBindVertexArray(0);
}

void Pyramid::setTransform(glm::mat4 model) {
    modelMatrix = model;
}

#endif // PYRAMID_H




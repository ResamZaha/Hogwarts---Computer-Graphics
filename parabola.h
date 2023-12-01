#pragma once
#ifndef parabolicsurface_h
#define parabolicsurface_h

#include <glad/glad.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include <cmath>

const int MIN_SEGMENTS = 3;

class ParabolicSurface {
public:
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    float shininess;

    ParabolicSurface(float width = 2.0f, float length = 2.0f, int segments = 36, glm::vec3 amb = glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3 diff = glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3 spec = glm::vec3(0.5f, 0.5f, 0.5f), float shiny = 32.0f)
        : verticesStride(6 * sizeof(float)) {
        set(width, length, segments, amb, diff, spec, shiny);
        glGenVertexArrays(1, &surfaceVAO);
        glBindVertexArray(surfaceVAO);

        unsigned int surfaceVBO;
        glGenBuffers(1, &surfaceVBO);
        glBindBuffer(GL_ARRAY_BUFFER, surfaceVBO);
        glBufferData(GL_ARRAY_BUFFER, this->getVertexSize(), this->getVertices(), GL_STATIC_DRAW);

        unsigned int surfaceEBO;
        glGenBuffers(1, &surfaceEBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, surfaceEBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->getIndexSize(), this->getIndices(), GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        int stride = this->getVerticesStride();
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float)));

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    ~ParabolicSurface() {}

    void set(float width, float length, int segments, glm::vec3 amb, glm::vec3 diff, glm::vec3 spec, float shiny) {
        if (width > 0)
            this->width = width;
        if (length > 0)
            this->length = length;
        this->segments = segments;
        if (segments < MIN_SEGMENTS)
            this->segments = MIN_SEGMENTS;
        this->ambient = amb;
        this->diffuse = diff;
        this->specular = spec;
        this->shininess = shiny;

        // Rebuild the parabolic surface geometry when settings change
        buildCoordinatesAndIndices();
        buildVertices();
    }

    void setWidth(float width) {
        if (width != this->width)
            set(width, length, segments, ambient, diffuse, specular, shininess);
    }

    void setLength(float length) {
        if (length != this->length)
            set(width, length, segments, ambient, diffuse, specular, shininess);
    }

    void setSegments(int segments) {
        if (segments != this->segments)
            set(width, length, segments, ambient, diffuse, specular, shininess);
    }

    unsigned int getVertexCount() const {
        return (unsigned int)coordinates.size() / 3;
    }

    unsigned int getVertexSize() const {
        return (unsigned int)vertices.size() * sizeof(float);
    }

    int getVerticesStride() const {
        return verticesStride;
    }

    const float* getVertices() const {
        return vertices.data();
    }

    unsigned int getIndexSize() const {
        return (unsigned int)indices.size() * sizeof(unsigned int);
    }

    const unsigned int* getIndices() const {
        return indices.data();
    }

    unsigned int getIndexCount() const {
        return (unsigned int)indices.size();
    }

    void drawParabolicSurface(Shader& lightingShader, glm::mat4 model = glm::mat4(1.0f), float r = 1.0f, float g = 1.0f, float b = 1.0f) const {
        lightingShader.use();
        lightingShader.setVec3("material.ambient", glm::vec3(r, g, b));
        lightingShader.setVec3("material.diffuse", glm::vec3(r, g, b));
        lightingShader.setVec3("material.specular", glm::vec3(0.5f, 0.5f, 0.5f));
        lightingShader.setFloat("material.shininess", this->shininess);
        lightingShader.setMat4("model", model);

        glBindVertexArray(surfaceVAO);
        glDrawElements(GL_TRIANGLES, this->getIndexCount(), GL_UNSIGNED_INT, (void*)0);
        glBindVertexArray(0);
    }

private:
    void buildCoordinatesAndIndices() {
        coordinates.clear();
        normals.clear();

        float dx = width / static_cast<float>(segments);
        float dy = length / static_cast<float>(segments);
        float x0 = -width / 2.0f;
        float y0 = -length / 2.0f;

        for (int i = 0; i < segments; ++i) {
            for (int j = 0; j < segments; ++j) {
                float x = x0 + i * dx;
                float y = y0 + j * dy;
                float z = x * x; // Parabolic surface formula

                // Vertex
                coordinates.push_back(x);
                coordinates.push_back(y);
                coordinates.push_back(z);

                // Normal
                normals.push_back(-2.0f * x);
                normals.push_back(0.0f);
                normals.push_back(1.0f);
            }
        }

        indices.clear();

        for (int i = 0; i < segments - 1; ++i) {
            for (int j = 0; j < segments - 1; ++j) {
                int index1 = i * segments + j;
                int index2 = index1 + 1;
                int index3 = (i + 1) * segments + j;
                int index4 = index3 + 1;

                indices.push_back(index1);
                indices.push_back(index4);
                indices.push_back(index2);

                indices.push_back(index1);
                indices.push_back(index3);
                indices.push_back(index4);
            }
        }
    }

    void buildVertices() {
        size_t numVertices = coordinates.size();
        vertices.clear();

        for (size_t i = 0; i < numVertices; i += 3) {
            vertices.push_back(coordinates[i]);
            vertices.push_back(coordinates[i + 1]);
            vertices.push_back(coordinates[i + 2]);
            vertices.push_back(normals[i]);
            vertices.push_back(normals[i + 1]);
            vertices.push_back(normals[i + 2]);
        }
    }

    // Member variables
    unsigned int surfaceVAO;
    float width;
    float length;
    int segments;
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    std::vector<float> coordinates;
    std::vector<float> normals;
    int verticesStride;
};

#endif /* parabolicsurface_h */

#ifndef flatcircle_h
#define flatcircle_h

#include <glad/glad.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include <cmath>

const int MIN_SIDES_flatcircle = 3;

class flatCircle {
public:
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    float shininess;

    flatCircle(float radius = 1.0f, float height = 2.0f, int sides = 36, glm::vec3 amb = glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3 diff = glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3 spec = glm::vec3(0.5f, 0.5f, 0.5f), float shiny = 32.0f)
        : verticesStride(6 * sizeof(float)) {
        set(radius, height, sides, amb, diff, spec, shiny);
        glGenVertexArrays(1, &cylinderVAO);
        glBindVertexArray(cylinderVAO);

        unsigned int cylinderVBO;
        glGenBuffers(1, &cylinderVBO);
        glBindBuffer(GL_ARRAY_BUFFER, cylinderVBO);
        glBufferData(GL_ARRAY_BUFFER, this->getVertexSize(), this->getVertices(), GL_STATIC_DRAW);

        unsigned int cylinderEBO;
        glGenBuffers(1, &cylinderEBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cylinderEBO);
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

    ~flatCircle() {}

    void set(float radius, float height, int sides, glm::vec3 amb, glm::vec3 diff, glm::vec3 spec, float shiny) {
        if (radius > 0)
            this->radius = radius;
        if (height > 0)
            this->height = height;
        this->sides = sides;
        if (sides < MIN_SIDES_flatcircle)
            this->sides = MIN_SIDES_flatcircle;
        this->ambient = amb;
        this->diffuse = diff;
        this->specular = spec;
        this->shininess = shiny;

        // Rebuild the cylinder geometry when settings change
        buildCoordinatesAndIndices();
        buildVertices();
    }

    void setRadius(float radius) {
        if (radius != this->radius)
            set(radius, height, sides, ambient, diffuse, specular, shininess);
    }

    void setHeight(float height) {
        if (height != this->height)
            set(radius, height, sides, ambient, diffuse, specular, shininess);
    }

    void setSides(int sides) {
        if (sides != this->sides)
            set(radius, height, sides, ambient, diffuse, specular, shininess);
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

    void drawflatCircle(Shader& lightingShader, glm::mat4 model = glm::mat4(1.0f), float r = 1.0f, float g = 1.0f, float b = 1.0f) const {
        lightingShader.use();
        lightingShader.setVec3("material.ambient", glm::vec3(r, g, b));
        lightingShader.setVec3("material.diffuse", glm::vec3(r, g, b));
        lightingShader.setVec3("material.specular", glm::vec3(0.5f, 0.5f, 0.5f));
        lightingShader.setFloat("material.shininess", this->shininess);
        lightingShader.setMat4("model", model);
        glBindVertexArray(cylinderVAO);
        glDrawElements(GL_TRIANGLES, this->getIndexCount(), GL_UNSIGNED_INT, (void*)0);
        glBindVertexArray(0);
    }

private:
    void buildCoordinatesAndIndices() {
        coordinates.clear();
        normals.clear();
        float x, y, z, normalX, normalY, normalZ;
        float sectorStep = 2 * 3.14159265358979323846 / static_cast<float>(sides);
        // Create vertices for the sides of the half cylinder
        for (int i = 0; i <= sides; ++i) {
            float angle = i * sectorStep;
            x = radius * cos(angle);
            z = radius * sin(angle);
            // Vertices for the curved side
            coordinates.push_back(x);
            coordinates.push_back(z);
            coordinates.push_back(height / 2.0f);
            normals.push_back(0.0f);
            normals.push_back(0.0f);
            normals.push_back(1.0f);
        }
        // Create indices for the sides
        indices.clear();
        for (int i = 0; i < sides; ++i) {
            int i1 = i;
            int i2 = i1 + 1;
            int i3 = sides;
            indices.push_back(i1);
            indices.push_back(i2);
            indices.push_back(i3);
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

    unsigned int cylinderVAO;
    float radius;
    float height;
    int sides;
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    std::vector<float> coordinates;
    std::vector<float> normals;
    int verticesStride;
};

#endif /* flatcircle_h */

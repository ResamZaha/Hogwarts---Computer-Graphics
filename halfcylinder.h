#ifndef halfpipe_h
#define halfpipe_h

#include <glad/glad.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include <cmath>
const int MIN_SIDES_halfpipe = 3;
class HalfPipe {
public:
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    float shininess;

    HalfPipe(int sides = 36, float radius = 1.0f, float height = 2.0f, glm::vec3 amb = glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3 diff = glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3 spec = glm::vec3(0.5f, 0.5f, 0.5f), float shiny = 32.0f)
        : verticesStride(6 * sizeof(float)) {
        set(sides, radius, height, amb, diff, spec, shiny);
        glGenVertexArrays(1, &shapeVAO);
        glBindVertexArray(shapeVAO);

        unsigned int shapeVBO;
        glGenBuffers(1, &shapeVBO);
        glBindBuffer(GL_ARRAY_BUFFER, shapeVBO);
        glBufferData(GL_ARRAY_BUFFER, this->getVertexSize(), this->getVertices(), GL_STATIC_DRAW);

        unsigned int shapeEBO;
        glGenBuffers(1, &shapeEBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, shapeEBO);
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

    ~HalfPipe() {}

    void set(int sides, float radius, float height, glm::vec3 amb, glm::vec3 diff, glm::vec3 spec, float shiny) {
        this->sides = sides;
        if (sides < MIN_SIDES_halfpipe)
            this->sides = MIN_SIDES_halfpipe;
        if (radius > 0)
            this->radius = radius;
        if (height > 0)
            this->height = height;
        this->ambient = amb;
        this->diffuse = diff;
        this->specular = spec;
        this->shininess = shiny;

        // Rebuild the shape geometry when settings change
        buildCoordinatesAndIndices();
        buildVertices();
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

    void drawHalfPipe(Shader& lightingShader, glm::mat4 model = glm::mat4(1.0f), float r = 1.0f, float g = 1.0f, float b = 1.0f) const {
        lightingShader.use();
        lightingShader.setVec3("material.ambient", glm::vec3(r, g, b));
        lightingShader.setVec3("material.diffuse", glm::vec3(r, g, b));
        lightingShader.setVec3("material.specular", glm::vec3(0.5f, 0.5f, 0.5f));
        lightingShader.setFloat("material.shininess", this->shininess);
        lightingShader.setMat4("model", model);

        glBindVertexArray(shapeVAO);
        glDrawElements(GL_TRIANGLES, this->getIndexCount(), GL_UNSIGNED_INT, (void*)0);
        glBindVertexArray(0);
    }

private:
    void buildCoordinatesAndIndices() {
        coordinates.clear();
        normals.clear();

        float sectorStep = static_cast<float>(2 * 3.14159265358979323846 / sides);
        float stackStep = height / sides;

        for (int i = 0; i <= sides; ++i) {
            float stack = i * stackStep - height / 2.0f;
            for (int j = 0; j <= sides; ++j) {
                float sector = j * sectorStep;

                float x = radius * cos(sector);
                float y = radius * sin(sector);
                float z = stack;

                coordinates.push_back(x);
                coordinates.push_back(y);
                coordinates.push_back(z);

                float length = sqrt(x * x + y * y + radius * radius);
                float normalX = x / length;
                float normalY = y / length;
                float normalZ = radius / length;

                normals.push_back(normalX);
                normals.push_back(normalY);
                normals.push_back(normalZ);
            }
        }

        indices.clear();

        for (int i = 0; i < sides; ++i) {
            for (int j = 0; j < sides; ++j) {
                int index1 = i * (sides + 1) + j;
                int index2 = index1 + 1;
                int index3 = (i + 1) * (sides + 1) + j;
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

    unsigned int shapeVAO;
    float radius;
    float height;
    int sides;
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    std::vector<float> coordinates;
    std::vector<float> normals;
    int verticesStride;
};

#endif /* halfpipe_h */

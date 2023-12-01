// custom_object.h

#ifndef custom_object_h
#define custom_object_h

#include <glad/glad.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"

class CustomObject {
public:
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    float shininess;

    CustomObject(const std::vector<float>& points, glm::vec3 amb = glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3 diff = glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3 spec = glm::vec3(0.5f, 0.5f, 0.5f), float shiny = 32.0f) :
        verticesStride(6 * sizeof(float)), ambient(amb), diffuse(diff), specular(spec), shininess(shiny) {
        setPoints(points);
        buildVertices();

        glGenVertexArrays(1, &customObjectVAO);
        glBindVertexArray(customObjectVAO);

        unsigned int customObjectVBO;
        glGenBuffers(1, &customObjectVBO);
        glBindBuffer(GL_ARRAY_BUFFER, customObjectVBO);
        glBufferData(GL_ARRAY_BUFFER, this->getVertexSize(), this->getVertices(), GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        int stride = this->getVerticesStride();
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float)));

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    ~CustomObject() {}

    void setPoints(const std::vector<float>& points) {
        this->points = points;
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

    unsigned int getVertexCount() const {
        return (unsigned int)points.size() / 3;
    }

    // Add a drawCustomObject method that takes r, g, b as arguments
    void drawCustomObject(Shader& lightingShader, glm::mat4 model = glm::mat4(1.0f), float r = 1.0f, float g = 1.0f, float b = 1.0f) const {
        lightingShader.use();
        lightingShader.setVec3("material.ambient", ambient);
        lightingShader.setVec3("material.diffuse", diffuse);
        lightingShader.setVec3("material.specular", specular);
        lightingShader.setFloat("material.shininess", shininess);
        lightingShader.setMat4("model", model);

        glBindVertexArray(customObjectVAO);
        glDrawArrays(GL_TRIANGLES, 0, getVertexCount());
        glBindVertexArray(0);
    }

private:
    unsigned int customObjectVAO;
    int verticesStride;
    std::vector<float> vertices;
    std::vector<float> points;

    void buildVertices() {
        size_t i, j;
        size_t count = points.size();
        for (i = 0, j = 0; i < count; i += 3, j += 2) {
            vertices.push_back(points[i]);
            vertices.push_back(points[i + 1]);
            vertices.push_back(points[i + 2]);
            vertices.push_back(0.0f);  // Placeholder for normals
            vertices.push_back(0.0f);
            vertices.push_back(0.0f);
        }
    }
};

#endif /* custom_object_h */

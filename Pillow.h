#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"

void pillow(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;


    //Sofa Seat
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.15, 0.375, 0.875));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.175,0.15,0.05f));
    model = als * translateMatrix * rotateYMatrix* scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.6, 0.2f, 0.3f);
}
#pragma once

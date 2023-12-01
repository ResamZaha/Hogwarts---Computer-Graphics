#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"
#include "cube.h"
void chair(Cube& cube, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;


    //round matha
    float rotateAngle_Z = 0.0;


    glm::mat4 rotateY = glm::mat4(1.0f);
    glm::mat4 rotateZ = glm::mat4(1.0f);
    //glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    //base
    for (float i = 0.0f; i <= 360.0f; i += 2.5f) {
        //Center

        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.3, 1.5, -0.9));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Z + i), glm::vec3(0.0f, 0.0f, 1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25, 0.15, 0.05));
        model = als * translateMatrix * rotateZMatrix * scaleMatrix;
        //drawCube(cubeVAO, lightingShader, model, 0.247f, 0.114f, 0.043f); //this model is later sent to the vertex shader. //altogether is a matrix that is multiplied with every parts of the bed, so everything is part of Altogether. when rotated, everything is rotated AllTogether
        cube.setMaterialisticEimu(0.247f, 0.114f, 0.043f);
        cube.drawCubeWithMaterialisticProperty(lightingShader, model);
        //glBindVertexArray(VAO);

    }

    //Sofa Seat
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05, 0.4, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.5f, .2f, 0.5f));
    model = als * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
    cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);

    //left handle
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05, 0.8, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.05f, .05f, 0.5f));
    model = als * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
    cube.setMaterialisticEimu(0.247f, 0.114f, 0.043f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);

    //left handle
    translateMatrix = glm::translate(identityMatrix, glm::vec3(.5, 0.8, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.05f, .05f, 0.5f));
    model = als * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
    cube.setMaterialisticEimu(0.247f, 0.114f, 0.043f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);



    //Sofa Head
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05, 0.3 + 0.5 * 0.2, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.5f, 1.0f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.247f, 0.114f, 0.043f);
    cube.setMaterialisticEimu(0.247f, 0.114f, 0.043f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);

    //Sofa leg1
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05, 0.3 + 0.5 * 0.2, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.075f, -.4f, 0.075f));
    model = als * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.247f, 0.114f, 0.043f);
    cube.setMaterialisticEimu(0.247f, 0.114f, 0.043f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);

    //Sofa leg3
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05, 0.3 + 0.5 * 0.2, -0.9 + 0.5 - 0.05));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.075f, -.4f, 0.075f));
    model = als * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.247f, 0.114f, 0.043f);
    cube.setMaterialisticEimu(0.247f, 0.114f, 0.043f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);

    //Sofa leg2
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.5 - 0.025, 0.3 + 0.5 * 0.2, -0.9));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.075f, -.4f, 0.075f));
    model = als * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.247f, 0.114f, 0.043f);
    cube.setMaterialisticEimu(0.247f, 0.114f, 0.043f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);

    //Sofa leg4
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.5 - 0.025, 0.3 + 0.5 * 0.2, -0.9 + 0.5 - 0.05));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.075f, -.4f, 0.075f));
    model = als * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.247f, 0.114f, 0.043f);
    cube.setMaterialisticEimu(0.247f, 0.114f, 0.043f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);



}
#pragma once
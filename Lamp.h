#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"
void lamp(Cube& cube, Shader& lightingShader, glm::mat4 als, float r, float g, float b)
{
    float rotateAngle_Y = 0.0;
    // positions of the point lights
    glm::vec3 pointLightPositions[] = {
    glm::vec3(-3.50f, 4.0f - 0.18, -2.0f + .05)}; //point light position

    PointLight pointlight1(
        pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z,  // position
        // ambient
        0.3f, 0.3f, 0.3f,     // diffuse
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,        // specular
        1.0f,   //k_c
        0.014f,  //k_l
        0.0007, //k_q
        1       // light number
    );


    glm::mat4 rotateY = glm::mat4(1.0f);
    glm::mat4 rotateZ = glm::mat4(1.0f);
    float rotateAngle_Z = 0.0f;
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    //base
    for (float i = 0.0f; i < 360.0f; i += 2.50f) {
        //Center

        translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.50f, 4.0f, -2.0f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Z + i), glm::vec3(-.2f,-1.0f,1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(-0.005, -0.05, 0.7));
        model = als * translateMatrix * rotateYMatrix * scaleMatrix;
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(-3.5, 0.09, 0.9));
        model = model * scaleMatrix;
        //drawCube(cubeVAO, lightingShader, model, 0.0, 0.5, 1.0); //this model is later sent to the vertex shader. //altogether is a matrix that is multiplied with every parts of the bed, so everything is part of Altogether. when rotated, everything is rotated AllTogether
        //glBindVertexArray(VAO);
        cube.setMaterialisticEimu(r, g, b);
        cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    }
    //body
    for (float i = 0.0f; i < 360.0f; i += 2.50f) {
        //Center

        translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.50f, 4.0f, -2.0f-0.15));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Z + i), glm::vec3(0.0f, 1.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(-0.055, -4.095, 0.005));
        model = als * translateMatrix * rotateYMatrix * scaleMatrix;

        //drawCube(cubeVAO, lightingShader, model, 0.9, 0.9, 0.9); //this model is later sent to the vertex shader. //altogether is a matrix that is multiplied with every parts of the bed, so everything is part of Altogether. when rotated, everything is rotated AllTogether
        cube.setMaterialisticEimu(0.9, 0.9, 0.9);
        cube.drawCubeWithMaterialisticProperty(lightingShader, model);
        
        //glBindVertexArray(VAO);
    }
    //light
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.50f, 4.0f-0.18, -2.0f+.05));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.09,0.09,0.09));
    model = als * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 1.0, 0.0, 1.0);
    cube.setMaterialisticEimu(1.0, 0.0, 1.0);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);

}
#pragma once
#pragma once

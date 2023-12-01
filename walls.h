#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "cube.h"
#include "drawcube.h"


void walls(Cube& cube, Shader& lightingShader, glm::mat4 alTogether)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;

    //floor
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-6.5, -0.5, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(25, .5, 25));
    model = alTogether*translateMatrix * scaleMatrix;
    //void drawCube(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 model = glm::mat4(1.0f), float r = 1.0f, float g = 1.0f, float b = 1.0f)
    //drawCube(cubeVAO, lightingShader, model, 0.5647, 0.6509f, 0.5176f);
    cube.setMaterialisticEimu(0.5647, 0.6509f, 0.5176f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    //cube.drawCubeWithTexture(lightingShader, model);

    //back wall
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-6.5, -0.5, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(25, 6, 0.25));
    model = alTogether * translateMatrix * scaleMatrix;

    //cube.setMaterialisticEimu(0.0, 0.6509f, 0.5176f);
    //cube.drawCubeWithTexture(lightingShader, model);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    //drawCube(cubeVAO, lightingShader, model, 0.5647, 0.6509f, 0.5176f);
    /*
    //front wall
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-6.5, -0.45, 6));
   
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(25, 8, 0.25));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.6, 0.0f, 0.125f);
    
    //left wall
    translateMatrix = glm::translate(identityMatrix, glm::vec3(6, -0.45, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25, 8, 25));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.6, 0.0f, 0.125f);
    
    //right wall
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-6.5, -0.45, 6));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25, 8, -25));
    model = alTogether * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.6, 0.0f, 0.125f);
    */
    //ceiling
    translateMatrix = glm::translate(identityMatrix, glm::vec3(-6.5, 6-0.5, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(25, .5, 25));
    model = alTogether * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.5647, 0.6509f, 0.5176f);
    //cube.drawCubeWithTexture(lightingShader, model);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    //left wall
    translateMatrix = glm::translate(identityMatrix, glm::vec3(6, -0.45, -6.5));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25, 6, 10));
    model = alTogether * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.5647, 0.6509f, 0.5176f);
    //cube.drawCubeWithTexture(lightingShader, model);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);
}

#pragma once

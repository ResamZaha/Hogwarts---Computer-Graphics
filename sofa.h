#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"

void sofa(Cube& cube, Shader& lightingShader, glm::mat4 als, float r, float g, float b) 
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;
    

    //Sofa Seat
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05, 0.1+0.15, 0.875));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, .125f, 0.55f));
    model = als * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
    cube.setMaterialisticEimu(r,g,b);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);

    //Sofa Head
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05, 0.1+ 0.5*0.2, 0.8));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, .5f, 0.1f));
    model = als * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
    cube.setMaterialisticEimu(r, g, b);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);

    //frame
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05 - 0.1, 0.1, 0.72));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.15f, .25f, 0.7f));
    model = als * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.05, 0.1f, 0.125f);
    cube.setMaterialisticEimu(0.05, 0.1f, 0.125f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);

    //Sofa leg1
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05, 0.1 + 0.5 * 0.2, 0.8));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.025f, -.5f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.05, 0.1f, 0.125f);
    cube.setMaterialisticEimu(0.05, 0.1f, 0.125f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);

    //Sofa leg3
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05, 0.1 + 0.5 * 0.2, 0.8+0.5-0.05));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.025f, -.5f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    cube.setMaterialisticEimu(0.05, 0.1f, 0.125f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);

    //Sofa leg2
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.05-0.25, 0.1 + 0.5 * 0.2, 0.8));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.025f, -.5f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.05, 0.1f, 0.125f);
    cube.setMaterialisticEimu(0.05, 0.1f, 0.125f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);

    //Sofa leg4
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.05-0.025, 0.1 + 0.5 * 0.2, 0.8 + 0.5 - 0.05));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.025f, -.5f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.05, 0.1f, 0.125f);
    cube.setMaterialisticEimu(0.05, 0.1f, 0.125f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);

    //handle1
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05 - 0.1, 0.1, 0.72));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.125f, .3f, 0.7f));
    model = als * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.05, 0.1f, 0.125f);
    cube.setMaterialisticEimu(0.05, 0.1f, 0.125f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);

    //handle2
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.1+0.025, 0.1, 0.72));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(-.125f, .3f, 0.7f));
    model = als * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.05, 0.1f, 0.125f);
    cube.setMaterialisticEimu(0.05, 0.1f, 0.125f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);
}


/*
void BLuesofa(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 als)
{
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;


    //Sofa Seat
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05, 0.1 + 0.15, 0.875));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, .125f, 0.55f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.0, 0.6f, 0.125f);

    //Sofa Head
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05, 0.1 + 0.5 * 0.2, 0.8));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, .5f, 0.1f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.0, 0.6f, 0.125f);

    //frame
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05 - 0.1, 0.1, 0.72));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.15f, .25f, 0.7f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.05, 0.1f, 0.125f);

    //Sofa leg1
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05, 0.1 + 0.5 * 0.2, 0.8));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.025f, -.5f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.05, 0.1f, 0.125f);

    //Sofa leg3
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05, 0.1 + 0.5 * 0.2, 0.8 + 0.5 - 0.05));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.025f, -.5f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.05, 0.1f, 0.125f);

    //Sofa leg2
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.05 - 0.25, 0.1 + 0.5 * 0.2, 0.8));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.025f, -.5f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.05, 0.1f, 0.125f);

    //Sofa leg4
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.05 - 0.025, 0.1 + 0.5 * 0.2, 0.8 + 0.5 - 0.05));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.025f, -.5f, 0.05f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.05, 0.1f, 0.125f);

    //handle1
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.05 - 0.1, 0.1, 0.72));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.125f, .3f, 0.7f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.05, 0.1f, 0.125f);

    //handle2
    translateMatrix = glm::translate(identityMatrix, glm::vec3(1.1 + 0.025, 0.1, 0.72));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(-.125f, .3f, 0.7f));
    model = als * translateMatrix * scaleMatrix;
    drawCube(cubeVAO, lightingShader, model, 0.05, 0.1f, 0.125f);
}

*/
#pragma once

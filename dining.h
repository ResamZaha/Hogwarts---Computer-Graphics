#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"
#include "cube.h"

void dining(Cube& cube, Shader& lightingShader, glm::mat4 als, unsigned int wood1,unsigned int wood2, float r, float g, float b)
{
    //table left leg
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 translate = glm::mat4(1.0f);
    glm::mat4 translate2 = glm::mat4(1.0f);
    glm::mat4 scale = glm::mat4(1.0f);


    scale = glm::scale(model, glm::vec3(.1f, .3f, .1f));
    translate = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
    model = als * scale;
    //drawCube(cubeVAO, lightingShader, model, 0.804, 0.271, 0.075);
    cube.setMaterialisticEimu(0.247f, 0.114f, 0.043f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    //cube.setTextureProperty(3, 4, 32.0);
    //cube.drawCubeWithTexture(lightingShader, model);

    // 
    // 
    //table right leg
    model = glm::mat4(1.0f);
    translate = glm::mat4(1.0f);
    scale = glm::mat4(1.0f);
    scale = glm::scale(model, glm::vec3(.1f, .3f, .1f));
    translate = glm::translate(model, glm::vec3(5.0f, 0.0f, 0.0f));
    model = als * scale * translate;
    //drawCube(cubeVAO, lightingShader, model, 0.804, 0.271, 0.075);
    cube.setMaterialisticEimu(0.247f, 0.114f, 0.043f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    //cube.setTextureProperty(3, 4, 32.0);
    //cube.drawCubeWithTexture(lightingShader, model);

    //table top
    model = glm::mat4(1.0f);
    translate = glm::mat4(1.0f);
    scale = glm::mat4(1.0f);
    scale = glm::scale(model, glm::vec3(1.0f, .05f, .5f));
    translate = glm::translate(model, glm::vec3(-.225f, 5.0f, -0.40f));
    model = als * scale * translate;
    //drawCube(cubeVAO, lightingShader, model, 0.804, 0.271, 0.075);
    cube.setMaterialisticEimu(0.247f, 0.114f, 0.043f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    //cube.setTextureProperty(3, 4, 32.0);
    //cube.drawCubeWithTexture(lightingShader, model);

    //table top cloth
    model = glm::mat4(1.0f);
    translate = glm::mat4(1.0f);
    scale = glm::mat4(1.0f);
    scale = glm::scale(model, glm::vec3(.33f, .01f, .5f));
    translate = glm::translate(model, glm::vec3(0.425, 30.0f, -0.40f));
    model = als * scale * translate;
    //drawCube(cubeVAO, lightingShader, model, 0.804, 0.271, 0.075);
    cube.setMaterialisticEimu(r, g, b);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);



    //left chair top
    model = glm::mat4(1.0f);
    translate = glm::mat4(1.0f);
    translate2 = glm::mat4(1.0f);
    scale = glm::mat4(1.0f);
    scale = glm::scale(model, glm::vec3(.3f, .025f, .5f));
    translate = glm::translate(model, glm::vec3(-1.70f, 5.0f, -0.35f));
    model = als * scale * translate;
    //drawCube(cubeVAO, lightingShader, model, .6, 0.271, 0.075);
    cube.setMaterialisticEimu(0.247f, 0.114f, 0.043f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    //cube.setTextureProperty(3, 4, 32.0);
    //cube.drawCubeWithTexture(lightingShader, model);

    //left chair stand
    model = glm::mat4(1.0f);
    translate = glm::mat4(1.0f);
    translate2 = glm::mat4(1.0f);
    scale = glm::mat4(1.0f);
    scale = glm::scale(model, glm::vec3(.1f, .15f, .1f));
    translate = glm::translate(model, glm::vec3(-4.0f, 0.0f, 0.0f));
    model = als * scale * translate;
    //drawCube(cubeVAO, lightingShader, model, .6, 0.271, 0.075);
    cube.setMaterialisticEimu(0.247f, 0.114f, 0.043f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    //cube.setTextureProperty(3, 4, 32.0);
    //cube.drawCubeWithTexture(lightingShader, model);



    //right chair top
    model = glm::mat4(1.0f);
    translate = glm::mat4(1.0f);
    translate2 = glm::mat4(1.0f);
    scale = glm::mat4(1.0f);
    scale = glm::scale(model, glm::vec3(.3f, .025f, .5f));
    translate = glm::translate(model, glm::vec3(3.0f, 5.0f, -0.35f));
    model = als * scale * translate;
    //drawCube(cubeVAO, lightingShader, model, .6, 0.271, 0.075);
    cube.setMaterialisticEimu(0.247f, 0.114f, 0.043f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    //cube.setTextureProperty(3, 4, 32.0);
    //cube.drawCubeWithTexture(lightingShader, model);

    //right chair stand
    model = glm::mat4(1.0f);
    translate = glm::mat4(1.0f);
    translate2 = glm::mat4(1.0f);
    scale = glm::mat4(1.0f);
    scale = glm::scale(model, glm::vec3(.1f, .15f, .1f));
    translate = glm::translate(model, glm::vec3(10.0f, 0.0f, 0.0f));
    model = als * scale * translate;
    //drawCube(cubeVAO, lightingShader, model, .6, 0.271, 0.075);
    cube.setMaterialisticEimu(0.247f, 0.114f, 0.043f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    //cube.setTextureProperty(3, 4, 32.0);
    //cube.drawCubeWithTexture(lightingShader, model);
}

void forstair(Cube& cube, Shader& lightingShader, glm::mat4 als)
{
    //////////////////////////////////sphere and cylinder
    Sphere sphere = Sphere();
    Cylinder cylinder2 = Cylinder(.1, 1.6);
    glm::mat4 temp = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model, ttranslate;
    float rotateAngle_Z = 25.0;
    glm::mat4 modelForSphere = glm::mat4(1.0f);
    glm::mat4 modelForCylinder = glm::mat4(1.0f);

    //stairs
    temp = als;
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5, .25, 3.0));
    als = als * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.6, 0.3f, 0.125f);
    cube.setMaterialisticEimu(0.247f, 0.114f, 0.043f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, als);
    als = temp;
    /*

    */
    //bam handle pillar
    temp = als;
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.125, .25, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.25, 1.5, .25));
    als = als * translateMatrix * scaleMatrix;
    cube.setMaterialisticEimu(0.247f, 0.114f, 0.043f);
    //cube.drawCubeWithMaterialisticProperty(lightingShader, als);
    als = temp;

    //dan handle pillar
    temp = als;
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.125, .25, 2.75));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.25, 1.5, .25));
    als = als * translateMatrix * scaleMatrix;
    cube.setMaterialisticEimu(0.247f, 0.114f, 0.043f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, als);
    als = temp;


    //bam handle 
    temp = als;
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.125, 1.6, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5, .25, .25));
    rotateZMatrix = glm::rotate(identityMatrix, glm::radians(18.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    als = als * translateMatrix * rotateZMatrix * scaleMatrix;
    cube.setMaterialisticEimu(0.6, 0.3f, 0.125f);
    //cube.drawCubeWithMaterialisticProperty(lightingShader, als);
    als = temp;

    //dan handle 
    temp = als;
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.125, 1.6, 2.75));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5, .25, .25));
    als = als * translateMatrix * rotateZMatrix * scaleMatrix;
    cube.setMaterialisticEimu(0.6, 0.3f, 0.125f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, als);
    als = temp;

    

}

#pragma once

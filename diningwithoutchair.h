#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"
#include "cube.h"

void diningWithoutChair(Cube &cube, Shader& lightingShader, glm::mat4 als)
{

    //table left leg
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 translate = glm::mat4(1.0f);
    glm::mat4 translate2 = glm::mat4(1.0f);
    glm::mat4 scale = glm::mat4(1.0f);
    glm::mat4 identityMatrix = glm::mat4(1.0f);
    glm::mat4 rotateYMatrix;
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    translate = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
    //model = als * translate * scale;
    //drawCube(cubeVAO, lightingShader, model, 0.247f, 0.114f, 0.043f);

    //table right leg
    model = glm::mat4(1.0f);
    translate = glm::mat4(1.0f);
    scale = glm::mat4(1.0f);
    scale = glm::scale(model, glm::vec3(.1f, 0.75f, .1f));
    translate = glm::translate(model, glm::vec3(9.75f, 0.0f, 0.45f));
    model = als  * translate * scale;
    //drawCube(cubeVAO, lightingShader, model, 0.247f, 0.114f, 0.043f);
    cube.setMaterialisticEimu(0.247f, 0.114f, 0.043f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    //table right leg bottom
    model = glm::mat4(1.0f);
    translate = glm::mat4(1.0f);
    scale = glm::mat4(1.0f);
    scale = glm::scale(model, glm::vec3(.1f, 0.05f, 1.0f));
    translate = glm::translate(model, glm::vec3(9.75f, 0.0f, -0.05));
    model = als * translate * scale;
    //drawCube(cubeVAO, lightingShader, model, 0.247f, 0.114f, 0.043f);
    cube.setMaterialisticEimu(0.247f, 0.114f, 0.043f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);

    //table left leg
    model = glm::mat4(1.0f);
    translate = glm::mat4(1.0f);
    scale = glm::mat4(1.0f);
    scale = glm::scale(model, glm::vec3(.1f, .75f, .1f));
    translate = glm::translate(model, glm::vec3(0.25f, 0.0f, 0.45f));
    model = als * translate * scale;
    //drawCube(cubeVAO, lightingShader, model, 0.247f, 0.114f, 0.043f);
    cube.setMaterialisticEimu(0.247f, 0.114f, 0.043f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);

    //table left leg bottom
    model = glm::mat4(1.0f);
    translate = glm::mat4(1.0f);
    scale = glm::mat4(1.0f);
    scale = glm::scale(model, glm::vec3(.1f, 0.05f, 1.0f));
    translate = glm::translate(model, glm::vec3(0.25f, 0.0f, -0.05));
    model = als * translate * scale;
    //drawCube(cubeVAO, lightingShader, model, 0.247f, 0.114f, 0.043f);
    cube.setMaterialisticEimu(0.247f, 0.114f, 0.043f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);

    //table top
    model = glm::mat4(1.0f);
    translate = glm::mat4(1.0f);
    scale = glm::mat4(1.0f);
    scale = glm::scale(model, glm::vec3(10.0f, .05f, 1.0f));
    translate = glm::translate(model, glm::vec3(0.0f, .75f, 0.0f));
    model = als * translate * scale;
    //drawCube(cubeVAO, lightingShader, model, 0.247f, 0.114f, 0.043f);
    cube.setMaterialisticEimu(0.247f, 0.114f, 0.043f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);

}

#pragma once

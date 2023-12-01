#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"
#include "halfsphere.h"
#include "sphere.h"
#include "Cylinder.h"
#include "flatcircle.h"

void hari(Cube& cube, Shader& lightingShader, glm::mat4 als)
{

	glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model,temp;
	float rotateAngle_Y = 22.5;

	{
		Sphere haribody(.5f);
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, .75f, 1.0f));
		haribody.drawSphere(lightingShader, als * scaleMatrix, 0.0f, 0.0f, 0.0f);

		temp = als;
		//Sphere haridhakna(.5f);
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, .45f, 1.0f));
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, .375f, 0.0f));
		als = als * translateMatrix * scaleMatrix;
		haribody.drawSphere(lightingShader, als * scaleMatrix, 0.0f, 0.0f, 0.0f);
		als = temp;
	}
}

void harionStand(Cube& cube, Shader& lightingShader, glm::mat4 als)
{

	glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model, temp;
	float rotateAngle_Y = 22.5;

	{
		Sphere haribody(.5f);
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, .75f, 1.0f));
        translateMatrix = glm::translate(identityMatrix, glm::vec3(0.125f, 0.8, 0.0f));
		haribody.drawSphere(lightingShader, als * translateMatrix * scaleMatrix, 0.0f, 0.0f, 0.0f);



		temp = als;
		Sphere haridhakna(.5f);
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, .45f, 1.0f));
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.125f, .375f +.8, 0.0f));
		als = als * translateMatrix * scaleMatrix;
		haribody.drawSphere(lightingShader, als * scaleMatrix, 0.0f, 0.0f, 0.0f);
		als = temp;
	}

    //leg 1
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.125, 0.7, 0.0));
    rotateZMatrix = glm::rotate(identityMatrix, glm::radians(30.0f), glm::vec3(0.0f, 0.5f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.05, -0.85, 0.05));
    model = als * translateMatrix * rotateZMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
    cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);

    //leg 2
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.125, 0.7, 0.0));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(0.0f, 0.5f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.05, -0.85, 0.05));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
    cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    //leg 3
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.125, 0.7, 0.0));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(-1.0f, 0.5f, -1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.05, -0.85, 0.05));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
    cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    //leg 4
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.125, 0.7, 0.0));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(30.0f), glm::vec3(-1.0f, 0.5f, -1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.05, -0.85, 0.05));
    model = als * translateMatrix * rotateYMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
    cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);
}


void gamlaonStand(Cube& cube, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model, temp;
    float rotateAngle_Y = 22.5;
    
    HalfSphere halfSphere(0.4f);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.4, 0.875, 0.1));
    rotateXMatrix = glm::rotate(identityMatrix, glm::radians(180.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    halfSphere.drawHalfSphere(lightingShader, als * translateMatrix * rotateXMatrix, 0.243f, 0.271f, 0.298f);

    flatCircle flatcircle(0.35f);
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.4, 0.7+.85, 0.2));
    rotateXMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    flatcircle.drawflatCircle(lightingShader, als * translateMatrix * rotateXMatrix, 0.0f, 0.0f, 0.0f);

    //leg 1
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.625, 0.7, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.05, -0.85, 0.05));
    model = als * translateMatrix  * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
    cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);

    //leg 2
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.375, 0.7, 0.25));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.05, -0.85, 0.05));
    model = als * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
    cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);
    //leg 3
    translateMatrix = glm::translate(identityMatrix, glm::vec3(0.125, 0.7, 0.0));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.05, -0.85, 0.05));
    model = als * translateMatrix * scaleMatrix;
    //drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
    cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, model);

}

void bottleonTable(Cube& cube, Shader& lightingShader, glm::mat4 als)
{

    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model, temp, ytranslate;
    float rotateAngle_Y = 22.5;
    Cylinder cylinder = Cylinder(.15, .65);
    Sphere sphere = Sphere(.2);
    {
        int index = 0;
        temp = als;
        translateMatrix = glm::translate(identityMatrix, glm::vec3(.45, 0.55f, 0.2f));
        als = als * translateMatrix;
        cylinder.drawCylinder(lightingShader, als, 1.0f, 1.0f, 1.0f);
        index = index + 3;
        als = temp;
        temp = als;
        translateMatrix = glm::translate(identityMatrix, glm::vec3(.45, .9, 0.2f));
        sphere.drawSphere(lightingShader, als * translateMatrix, 0.0f, 0.0f, 0.0f);
        als = temp;
    }

}

#pragma once

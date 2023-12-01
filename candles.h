#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"
#include "sphere.h"
#include "cylinder.h"

void candle(Cube& cube, Shader& lightingShader, glm::mat4 als)
{

	glm::mat4 temp = glm::mat4(1.0f);
	glm::mat4 temp2 = glm::mat4(1.0f);
	glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, ztranslate, xtranslate;

	//////////////////////////////////sphere and cylinder
	Sphere sphere1 = Sphere();

	glm::mat4 modelForSphere = glm::mat4(1.0f);
	glm::mat4 modelForCylinder = glm::mat4(1.0f);

	{
		//bottom
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 3.0, 0.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1, .5f, .1f));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cubeVAO, lightingShader, als, 1.0, 1.0, 1.0);
		cube.setMaterialisticEimu(1.0, 1.0, 1.0);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;
	}

	//top
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.03f, 1.775, 0.04f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5, 1.0f, .5f));
		Sphere canfire = Sphere(.1);
		als = als * translateMatrix * scaleMatrix;
		canfire.drawSphere(lightingShader, als * translateMatrix, 1.0, 1.0, 0.0);
		als = temp;
	}
}

#pragma once


#pragma once

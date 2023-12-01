#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"
#include "benchtoll.h"
void librarybenchToll(Cube& cube, Shader& lightingShader, glm::mat4 als)
{

	glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model,temp;
	float rotateAngle_Y = 22.5;
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 0.1, -3.2));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0, 1.0, 0.0));
		als = als * translateMatrix * rotateYMatrix;
		benchToll(cube, lightingShader, als);
		als = temp;
	}
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.75, 0.1, -6.0));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(270.0f), glm::vec3(0.0, 1.0, 0.0));
		als = als * translateMatrix * rotateYMatrix;
		benchToll(cube, lightingShader, als);
		als = temp;
	}
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.6, 0.1, -6.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5, 1.15, 2.85));
		als = als * translateMatrix * scaleMatrix;
		
		///drawCube(cubeVAO, lightingShader, als, 0.545f, 0.271f, 0.075f);
		cube.setMaterialisticEimu(0.545f, 0.271f, 0.075f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);

		als = temp;
	}
	


}

#pragma once

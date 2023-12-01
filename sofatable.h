#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"
#include "sofa.h"
#include "roundTable.h"
#include "Lamp.h"
void sofaTable(Cube& cube, Shader& lightingShader, glm::mat4 als, float r, float g, float b)
{
	glm::mat4 temp = glm::mat4(1.0f);
	glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;
	float rotateAngle_Y = 90.0;
	//sofa back
	{
		temp = als;
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.25f, 1.25f, 1.25f));
		als = als * scaleMatrix;
		sofa(cube, lightingShader, als, r,g,b);
		als = temp;
	}
	//sofa left
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.85, 0.0, 3.5));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.25f, 1.25f, 1.25f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		sofa(cube, lightingShader, als, r, g, b);
		als = temp;
	}
	//sofa left
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(.55, 0.0, 2.60));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, .65f, 1.0f));
		als = als * translateMatrix * scaleMatrix;
		coffeeTable(cube, lightingShader, als);
		als = temp;
	}
	//sofa right
	rotateAngle_Y = -90.0;
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(3.2, 0.0, 2.15));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.25f, 1.25f, 1.25f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		sofa(cube, lightingShader, als, r, g, b);
		als = temp;
	}
	///Lamp
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(3.4, 0.0, 2.3));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5f, .5f, .5f));
		//rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
		als = als * translateMatrix  * scaleMatrix;
		lamp(cube, lightingShader, als, 0.98f, 0.698f, 0.38f);
		als = temp;
	}
	/*
	//toll right leg1
	translateMatrix = glm::translate(identityMatrix, glm::vec3(2.75, 0.0, 0.0));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, .5f, 0.1f));
	model = als * translateMatrix * scaleMatrix;
	drawCube(cubeVAO, lightingShader, model, 0.545f, 0.271f, 0.075f);
	*/


}

#pragma once

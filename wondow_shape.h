#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"
#include "halfsphere.h"
#include "sphere.h"
#include "Cylinder.h"
#include "cube.h"



void Window(Cube& cube, Shader& lightingShader, glm::mat4 als)
{

	glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model, temp;
	float rotateAngle_Y = 22.5;


	temp = als;
	
}


#pragma once

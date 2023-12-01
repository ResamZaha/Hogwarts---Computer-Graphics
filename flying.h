#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"
#include "sphere.h"
#include "cylinder.h"
#include "chair.h"
#include <random>
#include "wallFireHolder.h"
#include "roundTable.h"
#include "floorlampholder.h"
#include "benchtoll.h"
#include "staircase.h"
#include "flatcircle.h"
#include "Triangle.h"
#include "RightAngleTriangle.h"
#include "almari.h"
#include "parabola.h"
#include "bookshelf.h"
#include "tableTop.h"

void broomStick(Cube& cube, Shader& lightingShader, glm::mat4 als)
{
	glm::mat4 temp = glm::mat4(1.0f);
	glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, ztranslate, xtranslate;
	float rotateAngle_Y = 0.0;
	//////////////////////////////////sphere and cylinder
	Sphere sphere1 = Sphere();

	{
		temp = als;
		Cylinder stick = Cylinder(.15, 5.0);
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 7.5f, 0.0f));
		rotateZMatrix = glm::rotate(identityMatrix, glm::radians(60.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		als = als * translateMatrix;
		stick.drawCylinder(lightingShader, als, 0.361f, 0.278f, 0.282f);
		als = temp;
	}

	{
		temp = als;
		Sphere end = Sphere(.75, 5.0);
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 4.5f, 0.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.65f, 1.0f, 1.0f));
		als = als * translateMatrix * scaleMatrix;
		end.drawSphere(lightingShader, als, 0.467f, 0.369f, 0.239f);
		als = temp;
	}
}
#pragma once

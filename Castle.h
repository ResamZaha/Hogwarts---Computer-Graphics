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
#include "pyramid.h"

//void greatHall(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 als)
void castle(Cube& cube, Shader& lightingShader, glm::mat4 als, unsigned int potionroomwalltilesdiffMap, unsigned int potionroomwalltilesspecMap, unsigned int woodfloordiff, unsigned int woodfloorspec, unsigned int walltilesdiff, unsigned int walltilesspec, float doorAngle, unsigned int castleWallMap, unsigned int grassMap, unsigned int  castleDoorMap)
{

	glm::mat4 temp = glm::mat4(1.0f);
	glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, ztranslate, xtranslate;
	float rotateAngle_Y = 0.0;
	//////////////////////////////////sphere and cylinder
	Sphere sphere1 = Sphere();

	//floor nicher front
	{
		//floor front \
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-41.0f, 0.0, 15.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(85.0, 0.1f, 50.0f));
		als = als * translateMatrix * scaleMatrix;
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(walltilesdiff, walltilesspec, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}

	//left wall
	{
		//left wall
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-42.0f, 0.0, 5.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1f, 17.3f, 60.0f));
		als = als * translateMatrix * scaleMatrix;
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(walltilesdiff, walltilesspec, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}

	//left font facing wall
	{
		//left font facing wall
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-41.0f, 0.0, 65.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(34.5f, 17.3f, 1.0f));
		als = als * translateMatrix * scaleMatrix;
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(castleWallMap, castleWallMap, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}
	//right font facing wall
	{
		//right font facing wall
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(9.5f, 0.0, 65.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(34.5f, 17.3f, 1.0f));
		als = als * translateMatrix * scaleMatrix;
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(castleWallMap, castleWallMap, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}

	//left front cylinder
	{
		//left front cylinder
		Cylinder cylinderLeft = Cylinder(1.0, 17.3);
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-5.5f, 8.65, 65.0f));
		als = als * translateMatrix;
		cylinderLeft.drawCylinder(lightingShader, als, 0.231f, 0.173f, 0.18f);
		als = temp;
	}

	//right front cylinder
	{
		//right front cylinder
		Cylinder cylinderLeft = Cylinder(1.0, 17.3);
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(8.5f, 8.65, 65.0f));
		als = als * translateMatrix;
		cylinderLeft.drawCylinder(lightingShader, als, 0.231f, 0.173f, 0.18f);
		als = temp;
	}
	//if (doorOpen)
	// 
	float angle = 0.0f;
	//left door
	{
		//left door
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-5.0, 0.0, 65.0f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(doorAngle), glm::vec3(0.0f, 1.0f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.0f, 17.3f, 0.0f));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(castleDoorMap, castleDoorMap, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}
	//right door
	{
		//right door
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(7.25, 0.0, 65.0f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-doorAngle), glm::vec3(0.0f, 1.0f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(-6.0f, 17.3f, 0.0f));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(castleDoorMap, castleDoorMap, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}
	
	//front lomba diyal
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-41.0f, 17.3f, 65.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(85.0f, 2.0f, 1.0f));
		als = als * translateMatrix * scaleMatrix;
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(walltilesdiff, walltilesspec, 32.0);
		//cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}
	//left uchu gula
	for (float i = 0.0; i < 9.0f; i = i + 1.0f)
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-41.0f + i * 4.0f,17.3, 65.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0f, 2.0f, 1.0f));
		als = als * translateMatrix * scaleMatrix;
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(potionroomwalltilesdiffMap, potionroomwalltilesspecMap, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}

	//right uchu gula
	for (float i = 12.0; i < 21.0f; i = i + 1.0f)
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-40.5f + i * 4.0f, 17.3, 65.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0f, 2.0f, 1.0f));
		als = als * translateMatrix * scaleMatrix;
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(potionroomwalltilesdiffMap, potionroomwalltilesspecMap, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}
	//left cylinder tower
	{
		for(float i = 0; i < 3.0f; i = i + 1.0f)
		{
			//left tower cylinder
			Cylinder cylinderLeft = Cylinder(5.0, 26.0, 8);
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(-41.0f, 13.0, 65.0f - i* 20.0));
			als = als * translateMatrix;
			cylinderLeft.drawCylinder(lightingShader, als, 0.529f, 0.529f, 0.529f);
			als = temp;
		}
	}

	//right cylinder tower
	{
		for (float i = 0; i < 3.0f; i = i + 1.0f)
		{
			//right tower cylinder
			Cylinder cylinderLeft = Cylinder(5.0, 26.0, 8);
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(46.0f, 13.0, 65.0f - i * 20.0));
			als = als * translateMatrix;
			cylinderLeft.drawCylinder(lightingShader, als, 0.529f, 0.529f, 0.529f);
			als = temp;
		}
	}
	float stc = 5.0f;
	//siri
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-5.0, 0.0, 70.0f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0f, 2.0f, 4.0f));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		stairCaseCastle(cube, lightingShader, als, stc);
		als = temp;
	}



	//LEFT cylinder er uporer gol part
	for (float i = 0; i < 3.0f; i = i + 1.0f)
	{
		//left tower cylinder
		Sphere sphere1 = Sphere(5.0);
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-41.0f, 26.5, 65.0f - i * 20.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, .25f, 1.0f));
		als = als * translateMatrix * scaleMatrix;
		sphere1.drawSphere(lightingShader, als, 0.0f, 0.0f, 0.0f);
		als = temp;
	}
	
	//RIGHT cylinder er uporer gol part
	for (float i = 0; i < 3.0f; i = i + 1.0f)
	{
		//left tower cylinder
		Sphere sphere1 = Sphere(5.0);
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(46.0f, 26.0, 65.0f - i * 20.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0f, .25f, 1.0f));
		als = als * translateMatrix * scaleMatrix;
		sphere1.drawSphere(lightingShader, als, 0.0f, 0.0f, 0.0f);
		als = temp;
	}
	//pyramid left
	{
		for (float i = 0; i < 3.0f; i = i + 1.0f)
		{
			translateMatrix = glm::translate(identityMatrix, glm::vec3(-41.0f, 26.5, 65.0f - i * 20.0));
			scaleMatrix = glm::scale(identityMatrix, glm::vec3(11.0f, 11.0f, 11.0f));
			glm::mat4 pyramidTransform = glm::mat4(1.0f);
			pyramidTransform = als * translateMatrix * scaleMatrix;
			// Use your desired transformation here

			// Create a Pyramid instance
			Pyramid pyramid(pyramidTransform, potionroomwalltilesdiffMap );
			pyramid.draw(lightingShader);
		}
	}

	//pyramid right
	{
		for (float i = 0; i < 3.0f; i = i + 1.0f)
		{
			translateMatrix = glm::translate(identityMatrix, glm::vec3(46.0f, 26.5, 65.0f - i * 20.0));
			scaleMatrix = glm::scale(identityMatrix, glm::vec3(10.0f, 10.0f, 10.0f));
			glm::mat4 pyramidTransform = glm::mat4(1.0f);
			pyramidTransform = als * translateMatrix * scaleMatrix;
			// Use your desired transformation here

			// Create a Pyramid instance
			Pyramid pyramid(pyramidTransform, potionroomwalltilesdiffMap);
			pyramid.draw(lightingShader);
		}
	}

	//backwall
	{
		//backwall
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-41.0f, 0.0, -25.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(95.5f, 35.0f, .1f));
		als = als * translateMatrix * scaleMatrix;
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(walltilesdiff, walltilesspec, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}

	//vumi
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-96.0f, -0.3, 120.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(160.0f, 0.1f, -140.0f));
		als = als * translateMatrix * scaleMatrix;
		//cube.setMaterialisticEimu(0.0f, 1.0f, 0.0f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(grassMap, grassMap, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}

}
#pragma once

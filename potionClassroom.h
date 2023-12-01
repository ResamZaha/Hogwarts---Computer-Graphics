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

void potionClassroom(Cube& cube, Shader& lightingShader, glm::mat4 als, float colorArray[], int binaryArray[], unsigned int potionroomwallMap, unsigned int woodfloordiff, unsigned int woodfloorspec, unsigned int walltilesdiff, unsigned int walltilesspec)
{

	glm::mat4 temp = glm::mat4(1.0f);
	glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, ztranslate, xtranslate;
	float rotateAngle_Y = 0.0;
	//////////////////////////////////sphere and cylinder
	Sphere sphere1 = Sphere();


	//FLOOR AND CEILING
	{
		//floor
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-7.5f, 0.0f, -10.5f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(20.0f, 0.0f, 27.0f));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cubeVAO, lightingShader, als, 0.545f, 0.270f, 0.075f);
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(walltilesdiff, walltilesspec, 32.0f);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;

		//ceil
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-7.5f, 12.0, -10.5f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(20.0f, .1f, 27.0f));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cubeVAO, lightingShader, als, 0.545f, 0.270f, 0.075f);
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(walltilesdiff, walltilesspec, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}

	//BACK WALL
	{
		//back wall
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-7.5f, 0.0, -10.5f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(20.0, 12.0f, .1f));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cubeVAO, lightingShader, als, 0.545f, 0.270f, 0.075f);
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(walltilesdiff, walltilesspec, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}


	//LEFT WALL
	{
		//left wall
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-7.5f, 0.0, -10.5f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 12.0f, 27.0));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cubeVAO, lightingShader, als, 0.545f, 0.270f, 0.075f);
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(walltilesdiff, walltilesspec, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;

		//right wall
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(12.5f, 0.0, -10.5f));
		//rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-75.0f), glm::vec3(0.0f, 1.0f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 12.0f, 27.0));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cubeVAO, lightingShader, als, 0.545f, 0.270f, 0.075f);
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(walltilesdiff, walltilesspec, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	



	/////curved ceiling
	{
		ParabolicSurface ceiling = ParabolicSurface();
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(2.5f, 12.0f, 4.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(10.0f, 13.5f, 4.5f));
		rotateXMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0));
		als = als * translateMatrix * rotateXMatrix * scaleMatrix;
		ceiling.drawParabolicSurface(lightingShader, als, 0.4f, 0.396f, 0.388f);
		als = temp;
	}
	//parabolic arches
	{
		ParabolicSurface arches = ParabolicSurface();
		for (float i = 0.0f; i < 5.0f; i = i + 1.0f)
		{
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(2.5f, 12.0f, -9.1 + i * 6.0f));
			scaleMatrix = glm::scale(identityMatrix, glm::vec3(10.0f, 1.4f, 8.0f));
			rotateXMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0));
			als = als * translateMatrix * rotateXMatrix * scaleMatrix;
			arches.drawParabolicSurface(lightingShader, als, 0.4f, 0.396f, 0.388f);
			arches.drawParabolicSurface(lightingShader, als * glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, .05)), 0.4f, 0.396f, 0.388f);
			als = temp;
		}

	}
	//PIllars
	{
		for (float i = 0.0f; i < 5.0f; i = i + 1.0f)
		{
			//left
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(-7.5f, 0.1, -10.5f + i * 6.0f));
			scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 12.0, 2.75));
			als = als * translateMatrix * scaleMatrix;
			//drawCube(cubeVAO, lightingShader, als, 0.545f, 0.270f, 0.075f);
			//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
			//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
			cube.setTextureProperty(walltilesdiff, walltilesspec, 32.0);
			cube.drawCubeWithTexture(lightingShader, als);
			als = temp;

			//right
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(12.5f, 0.1, -10.5f + i * 6.0f));
			scaleMatrix = glm::scale(identityMatrix, glm::vec3(-1.0, 12.0, 2.75));
			als = als * translateMatrix * scaleMatrix;
			//drawCube(cubeVAO, lightingShader, als, 0.545f, 0.270f, 0.075f);
			//cube.setMaterialisticEimu(0.0f, 0.270f, 0.0f);
			//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
			cube.setTextureProperty(walltilesdiff, walltilesspec, 32.0);
			cube.drawCubeWithTexture(lightingShader, als);
			als = temp;
		}
	}

	//bottleShelf
	{
		for (float i = 1.0f; i < 4.0f; i = i + 1.0f)
		{
			//left
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(-7.0f, 0.1, -4.5f + i * 6.0f));
			rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0));
			als = als * translateMatrix * rotateYMatrix;
			bottleShelf(cube, lightingShader, als, colorArray, binaryArray, woodfloordiff, woodfloorspec);
			als = temp;

			//right
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(12.5f, 0.1, -7.75f + i * 6.0f));
			rotateYMatrix = glm::rotate(identityMatrix, glm::radians(270.0f), glm::vec3(0.0f, 1.0f, 0.0));
			als = als * translateMatrix * rotateYMatrix;
			bottleShelf(cube, lightingShader, als, colorArray, binaryArray, woodfloordiff, woodfloorspec);
			als = temp;
		}
		//soja gula
		{
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(8.0f, 0.1, -10.0));
			als = als * translateMatrix;
			bottleShelf(cube, lightingShader, als, colorArray, binaryArray, woodfloordiff, woodfloorspec);
			als = temp;

			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(-6.0f, 0.1, -10.0));
			als = als * translateMatrix;
			bottleShelf(cube, lightingShader, als, colorArray, binaryArray, woodfloordiff, woodfloorspec);
			als = temp;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////


	
	//ceiling light
	{
		//ceiling light
		for (float i = 0.0f; i < 3.0f; i = i + 2.0)
		{
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(2.5f, 2.0f, -3.5f + i * 7.0f));
			als = als * translateMatrix;
			ceilLight(cube, lightingShader, als);
			als = temp;
		}
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	

	//FIRST ROUND TABLE
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(2.2f, 0.0f, -6.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0, 3.0f, 3.0f));
		als = als * translateMatrix * scaleMatrix;
		coffeeTable(cube, lightingShader, als);
		als = temp;
	}
	//baki TABLEs
	{
		{
			//left pichone
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(-4.0f, 0.0f, -2.0f));
			als = als * translateMatrix;
			potionTable(cube, lightingShader, als, colorArray);
			als = temp;

			//middle
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(6.0f, 0.0f, 4.0f));
			als = als * translateMatrix;
			potionTable(cube, lightingShader, als, colorArray);
			als = temp;

			//right
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(-4.0f, 0.0f, 10.0f));
			als = als * translateMatrix;
			potionTable(cube, lightingShader, als, colorArray);
			als = temp;


		}
	}

	//toll
	{
		for (float i = 0.0f; i < 2.0f; i = i + 1.0)
		{
			//pichone
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f - i * 3.0, 0.0f, -2.0f + i * 4.0));
			als = als * translateMatrix;
			potionToll(cube, lightingShader, als, colorArray);
			als = temp;
		}

		for (float i = 0.0f; i < 2.0f; i = i + 1.0)
		{
			//middle
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(4.0f + i * 3.0, 0.0f, 5.0f + i * 4.0));
			als = als * translateMatrix;
			potionToll(cube, lightingShader, als, colorArray);
			als = temp;
		}

		for (float i = 0.0f; i < 2.0f; i = i + 1.0)
		{
			//shamne
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f - i * 3.0, 0.0f, 10.0f + i * 4.0));
			als = als * translateMatrix;
			potionToll(cube, lightingShader, als, colorArray);
			als = temp;
		}
	}


	//backwall texture
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.0f, 0.0f, -10.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.0, 10.0, 0.1));
		als = als * translateMatrix * scaleMatrix;
		//cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(potionroomwallMap, potionroomwallMap, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
}
#pragma once

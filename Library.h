#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include "drawcube.h"
#include "sphere.h"
#include "cylinder.h"
#include "chair.h"
#include <random>
#include "dining.h"
#include "wallFireHolder.h"
#include "roundTable.h"
#include "diningwithoutchair.h"
#include "bookshelf.h"
#include "benchtoll.h"
#include "librarybenchtool.h"
#include "sofatable.h"
void library(Cube& cube, Shader& lightingShader, glm::mat4 als, float colorArray[], unsigned int tiles1, unsigned int tiles2, unsigned int brick1, unsigned int brick2, unsigned int wood1, unsigned int wood2)
{

	glm::mat4 temp = glm::mat4(1.0f);
	glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, ztranslate, xtranslate;
	float rotateAngle_Y = 0.0;
	//////////////////////////////////sphere and cylinder
	Sphere sphere1 = Sphere();

	glm::mat4 modelForSphere = glm::mat4(1.0f);
	glm::mat4 modelForCylinder = glm::mat4(1.0f);


	{
		//floor
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-15.0f, 0.0, -15.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(25.0f, 0.0f, 30.0f));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cubeVAO, lightingShader, als, 0.545f, 0.270f, 0.075f);
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(tiles1, tiles2, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;

		//ceil
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-15.0f, 10.0, -15.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(25.0f, .1f, 30.0f));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cubeVAO, lightingShader, als, 0.545f, 0.270f, 0.075f);
		cube.setMaterialisticEimu(0.678f, 0.494f, 0.341f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;
	}

	{
		//back wall
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-15.0f, 0.0, -15.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(25.0, 10.0f, .1f));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cubeVAO, lightingShader, als, 0.545f, 0.270f, 0.075f);
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(brick1, brick2, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}
	{
		//left wall
		temp = als;
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 10.0f, 30.0));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cubeVAO, lightingShader, als, 0.545f, 0.270f, 0.075f);
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(brick1, brick2, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;

		//right wall
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(10.0f, 0.0, -15.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 10.0f, 30.0));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cubeVAO, lightingShader, als, 0.545f, 0.270f, 0.075f);
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(brick1, brick2, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	


	//pillars
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-14.0f, 5.0, -5.4f));
	for (float j = 0.0; j < 30.0; j = j + 15.0)
	{
		xtranslate = glm::translate(identityMatrix, glm::vec3(static_cast<float>(j), 0.0, 0.0));
		for (float i = 0.0; i < 20.0; i = i + 2.0)
		{
			Cylinder cylinder1 = Cylinder(.4, 10.0);
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(-14.0f, 5.0, -5.4f));
			ztranslate = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, static_cast<float>(i)));
			als = als * modelForCylinder * translateMatrix;
			cylinder1.drawCylinder(lightingShader, als * ztranslate, 0.678f, 0.494f, 0.341f);
			//cylinder1.drawCylinder(lightingShader, als * ztranslate * (glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f))), 0.545f, 0.270f, 0.075f);
			als = temp;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(8.0f, 5.0, -5.4f));
			als = als * modelForCylinder * translateMatrix;
			cylinder1.drawCylinder(lightingShader, als * ztranslate, 0.678f, 0.494f, 0.341f);
			//cylinder1.drawCylinder(lightingShader, als * ztranslate * (glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f))), 0.545f, 0.270f, 0.075f);
			als = temp;


		}
	}

	translateMatrix = glm::translate(identityMatrix, glm::vec3(-12.5f, 1.75, -5.4 + 2.5f));
	for (float i = 0; i <= 30.0; i = i + 10.0)
	{
		//flooar agun
		temp = als;
		ztranslate = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, static_cast<float>(i)));
		xtranslate = glm::translate(identityMatrix, glm::vec3(39.0, 0.0, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5, .5f, .5f));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cubeVAO, lightingShader, als, 0.545f, 0.270f, 0.075f);
		floorFireHolder2(cube, lightingShader, als * ztranslate);
		floorFireHolder2(cube, lightingShader, als * ztranslate * xtranslate);
		als = temp;
	}


	/////////////arches
	translateMatrix = glm::translate(identityMatrix, glm::vec3(-13.75f, 5.0, -5.4));
	rotateZMatrix = glm::rotate(identityMatrix, glm::radians(-65.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(.2, 12.0, .2));
	for (float i = 0.0; i < 100.0; i = i + 10.0)
	{
		temp = als;
		ztranslate = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, static_cast<float>(i)));
		als = als * translateMatrix * rotateZMatrix * scaleMatrix;
		//drawCube(cubeVAO, lightingShader, als * ztranslate, 0.545f, 0.270f, 0.075f);
		cube.setMaterialisticEimu(0.678f, 0.494f, 0.341f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als * ztranslate);
		als = temp;
	}
	translateMatrix = glm::translate(identityMatrix, glm::vec3(8.0f, 4.8, -5.4));
	rotateZMatrix = glm::rotate(identityMatrix, glm::radians(65.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	scaleMatrix = glm::scale(identityMatrix, glm::vec3(.2, 12.0, .2));
	for (float i = 0.0; i < 100.0; i = i + 10.0)
	{
		temp = als;
		ztranslate = glm::translate(identityMatrix, glm::vec3(0.0, 0.0, static_cast<float>(i)));
		als = als * translateMatrix * rotateZMatrix * scaleMatrix;
		//drawCube(cubeVAO, lightingShader, als * ztranslate, 0.545f, 0.270f, 0.075f);
		cube.setMaterialisticEimu(0.678f, 0.494f, 0.341f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als * ztranslate);
		als = temp;
	}
	

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//////////lamps left
	for (float i = 0.0; i < 20.0; i = i + 6.0)
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-13.0f, 5.5, -5.4 + static_cast<float>(i)));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.25, 1.25, 1.25));
		als = als * translateMatrix * scaleMatrix;
		wallFireHolder(cube, lightingShader, als);
		als = temp;
	}
	//////////lamps right
	for (float i = 0.0; i < 20.0; i = i + 6.0)
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(7.0f, 5.5, -5.4 + static_cast<float>(i)));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(-1.25, 1.25, 1.25));
		als = als * translateMatrix * scaleMatrix;
		wallFireHolder(cube, lightingShader, als);
		als = temp;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	

	{
		///////////bookShelf
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-15.0f, 0.0, -8.0f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5, 1.5, 1.5));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		bookShelf(cube, lightingShader, als, colorArray, wood1, wood2);
		als = temp;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-15.0f, 4.0, -8.0f));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		bookShelf(cube, lightingShader, als, colorArray, wood1, wood2);
		als = temp;
	}

	///////////bookShelf
	for (float i = 5.0; i <= 20.0; i += 5.0)
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-15.0f + static_cast<float>(i), 0.0, -8.0f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5, 1.5, 1.5));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;

		bookShelf(cube, lightingShader, als, colorArray, wood1, wood2);
		bookShelf(cube, lightingShader, als * glm::scale(identityMatrix, glm::vec3(1.0, 1.0, -1.0)), colorArray, wood1, wood2);
		als = temp;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-15.0f + static_cast<float>(i), 4.0, -8.0f));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		bookShelf(cube, lightingShader, als, colorArray, wood1, 4);
		bookShelf(cube, lightingShader, als * glm::scale(identityMatrix, glm::vec3(1.0, 1.0, -1.0)), colorArray, wood1, wood2);
		als = temp;
	}

	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-15.0f + 25.0, 0.0, -8.0f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5, 1.5, 1.5));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		bookShelf(cube, lightingShader, als * glm::scale(identityMatrix, glm::vec3(1.0, 1.0, -1.0)), colorArray, wood1, wood2);
		als = temp;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-15.0f + 25.0, 4.0, -8.0f));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		bookShelf(cube, lightingShader, als * glm::scale(identityMatrix, glm::vec3(1.0, 1.0, -1.0)), colorArray, wood1, wood2);
		als = temp;
	}



	///////////////////library benchs
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-7.0, 0.1, 2.0));
		als = als * translateMatrix;
		glm::mat4 ttranslateMatrix = translateMatrix;
		for (float j = 0; j < 14; j += 3) {
			ttranslateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 3.0f));
			als = als * ttranslateMatrix;
			librarybenchToll(cube, lightingShader, als);
		}
		als = temp;
		for (float j = 0; j < 14; j += 3) {
			ttranslateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, 3.0f));
			als = als * ttranslateMatrix;
			librarybenchToll(cube, lightingShader, als * glm::translate(identityMatrix, glm::vec3(5.0f, 0.0f, 0.0f)));
		}
		
	}
	als = temp;


	///////sofatables
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.0f, 0.25f, 0.0f));
		als = als * translateMatrix;
		sofaTable(cube, lightingShader, als, 0.188f, 0.098f, 0.027f);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-5.0f, 0.25f, 4.5f));
		als = als * translateMatrix;
		sofaTable(cube, lightingShader, als, 0.361f, 0.098f, 0.086f);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.0f, 0.25f, 9.0f));
		als = als * translateMatrix;
		sofaTable(cube, lightingShader, als, 0.188f, 0.098f, 0.027f);
		als = temp;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
}
#pragma once

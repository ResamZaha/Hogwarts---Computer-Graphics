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
#include "walls.h"
#include "bed.h"
#include "sofa.h"
#include "sofatable.h"
#include "cube.h"
#include "floorlampholder.h"
#include "tableTop.h"
#include "parabola.h"

void bedroom(Cube& cube, Shader& lightingShader, glm::mat4 als, float colorArray[], float houseName, unsigned int akashiwindowMap, unsigned int bedroomAgunMap, unsigned int bedroomPhotoFrame1Map, unsigned int bedroomPhotoFrame2Map, unsigned int tiles1, unsigned int tiles2, unsigned int brick1, unsigned int brick2, unsigned int wood1, unsigned int wood2, unsigned int redcarpetMap, unsigned int greencarpetMap)
{

	glm::mat4 temp = glm::mat4(1.0f);
	glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, ztranslate, xtranslate;
	float rotateAngle_Y = 0.0;
	//////////////////////////////////sphere and cylinder
	Sphere sphere1 = Sphere();
	float r, g, b;
	if (houseName == 1.0)
	{
		r = 0.455f;
		g = 0.0f;
		b = 0.004f;
	}
	else
	{
		r = 0.0f;
		g = 0.22f;
		b = 0.122;
	}
	glm::mat4 modelForSphere = glm::mat4(1.0f);
	glm::mat4 modelForCylinder = glm::mat4(1.0f);





	{
		//floor
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-7.5f, -0.05, -7.5f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(26.5f, 0.0f, 15.0f));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cube, lightingShader, als, 0.545f, 0.270f, 0.075f);
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(tiles1, tiles2, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
		//double
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-7.5f, 0.0, -7.5f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(26.5f, 0.0f, 15.0f));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cube, lightingShader, als, 0.545f, 0.270f, 0.075f);
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(tiles1, tiles2, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;

		//carpet
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.0f, 0.01, 6.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.5f, 0.0f, 4.5f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		//drawCube(cube, lightingShader, als, 0.545f, 0.270f, 0.075f);
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		if(houseName == 1.0)
			cube.setTextureProperty(redcarpetMap, redcarpetMap, 32.0);
		else
			cube.setTextureProperty(greencarpetMap, greencarpetMap, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;


		//ceil
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-7.5f, 7.0, -7.5f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(26.5f, .1f, 15.0f));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cube, lightingShader, als, 0.545f, 0.270f, 0.075f);
		cube.setMaterialisticEimu(0.737, 0.514, 0.322);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		//cube.setTextureProperty(tiles1, tiles2, 32.0);
		//cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}

	{
		//back wall
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-7.5f, 0.0, -7.5f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(26.5, 7.0f, .1f));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cube, lightingShader, als, 0.545f, 0.270f, 0.075f);
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(tiles1, tiles2, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}
	///chobi
	{
		//middle
		{
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(-.5f, 4.0, -7.4f));
			scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0, 3.0f, .05f));
			als = als * translateMatrix * scaleMatrix;
			//drawCube(cube, lightingShader, als, 0.545f, 0.270f, 0.075f);
			//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
			//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
			if (houseName == 1.0)
				cube.setTextureProperty(redcarpetMap, redcarpetMap, 32.0);
			else
				cube.setTextureProperty(greencarpetMap, greencarpetMap, 32.0);
			cube.drawCubeWithTexture(lightingShader, als);
			als = temp;
		}

		//left janala
		{
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(-6.0f, 1.0, -7.4f));
			scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0, 6.0f, .05f));
			als = als * translateMatrix * scaleMatrix;
			//drawCube(cube, lightingShader, als, 0.545f, 0.270f, 0.075f);
			//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
			//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
			cube.setTextureProperty(akashiwindowMap, akashiwindowMap, 32.0);
			cube.drawCubeWithTexture(lightingShader, als);
			als = temp;
		}

		//right janala
		{
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(3.5f, 1.0, -7.4f));
			scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0, 6.0f, .05f));
			als = als * translateMatrix * scaleMatrix;
			//drawCube(cube, lightingShader, als, 0.545f, 0.270f, 0.075f);
			//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
			//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
			cube.setTextureProperty(akashiwindowMap, akashiwindowMap, 32.0);
			cube.drawCubeWithTexture(lightingShader, als);
			als = temp;
		}
	}
	{
		//left wall
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-7.5f, 0.0, -7.5f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 7.0f, 15.0));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cube, lightingShader, als, 0.545f, 0.270f, 0.075f);
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(tiles1, tiles2, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;

		//middle wall
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(7.3f, 0.0, -7.5f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(-0.1, 7.0f, 14.0));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cube, lightingShader, als, 0.545f, 0.270f, 0.075f);
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(tiles1, tiles2, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;

		//right wall
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(19.0f, 0.0, -7.5f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.1, 7.0f, 15.0));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cube, lightingShader, als, 0.545f, 0.270f, 0.075f);
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(tiles1, tiles2, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	
	//Fire place
	{
		//pillar left
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(10.5f, 0.0, -7.5f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 7.0f, 2.0));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cube, lightingShader, als, 0.545f, 0.270f, 0.075f);
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(tiles1, tiles2, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;


		//texture box
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(11.5f, 0.0, -6.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0, 3.0f, .1));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cube, lightingShader, als, 0.545f, 0.270f, 0.075f);
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(bedroomAgunMap, bedroomAgunMap, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;


		//texture box er uporer matha
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(11.5f, 3.0, -7.5f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0, .5f, 2.0));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cube, lightingShader, als, 0.545f, 0.270f, 0.075f);
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(tiles1, tiles2, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;


		//pillar right
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(14.5f, 0.0, -7.5f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 7.0f, 2.0));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cube, lightingShader, als, 0.545f, 0.270f, 0.075f);
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(tiles1, tiles2, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}

	//hari
	{
		//hari
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(12.25f, 3.8, -6.0f));
		als = als * translateMatrix;
		hari(cube, lightingShader, als);
		hari(cube, lightingShader, als * glm::translate(identityMatrix, glm::vec3(1.5f, 0.0, 0.0)));
		als = temp;
	}


	//sofatable pasher room
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(10.0f, 0.0, -5.0f));
		rotateXMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0));
		als = als * translateMatrix;
		sofaTable(cube, lightingShader, als, r, g, b);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(15.0f, 0.0, -2.0));
		rotateXMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0));
		als = als * translateMatrix;
		sofaTable(cube, lightingShader, als, r, g, b);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(10.0f, 0.0, 1.0));
		rotateXMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0));
		als = als * translateMatrix;
		sofaTable(cube, lightingShader, als, r, g, b);
		als = temp;
	}



	//photo frame
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(8.1, 3.6f, -7.4f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.4, 3.0, .1));
		als = als * translateMatrix * scaleMatrix;
		cube.setTextureProperty(bedroomPhotoFrame1Map, bedroomPhotoFrame1Map, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(16.1f, 3.6f, -7.4f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0, 3.0, .1));
		als = als * translateMatrix * scaleMatrix;
		cube.setTextureProperty(bedroomPhotoFrame2Map, bedroomPhotoFrame2Map, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//ceiling light
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0, 1.5f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5, .5, .5));
		als = als * translateMatrix * scaleMatrix;
		ceilLight(cube, lightingShader, als);
		ceilLight(cube, lightingShader, als * glm::translate(identityMatrix, glm::vec3(13.25 * 2, 0.0f, 0.0)));
		als = temp;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	

	
	///middle bed
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(0.0f, 0.0f, -2.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, 4.0f, 4.0f));
		als = als * translateMatrix * scaleMatrix;
		bed(cube, lightingShader, als, r, g, b);
		als = temp;
	}

	//left bed
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.0f, 0.0f, 0.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, 4.0f, 4.0f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(65.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		bed(cube, lightingShader, als, r, g, b);
		als = temp;
	}

	//right bed
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(1.70f, 0.0f, -1.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, 4.0f, 4.0f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-65.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		bed(cube, lightingShader, als, r, g, b);
		als = temp;
	}



	//sofa right
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(2.0f, 0.3f, -5.5f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5f, 1.5f, 1.0f));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		sofa(cube, lightingShader, als, r,g,b);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(5.0f, 0.3f, -6.0f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5f, 1.5f, 1.0f));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		sofa(cube, lightingShader, als, r, g, b);
		als = temp;
	}

	//sofa table
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-6.0, 0.1f, -7.0f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		als = als * translateMatrix * rotateYMatrix;
		sofaTable(cube, lightingShader, als, r, g, b);
		als = temp;
	}
	///////flooar lamp 1
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(6.5, 0.1f, -6.0f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.75f, .75f, .75f));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		floorFireHolder1(cube, lightingShader, als);
		als = temp;
	}
	///////flooar lamp 2
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-5.0, 1.625f, 1.0f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5f, .5f, .5f));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		floorFireHolder2(cube, lightingShader, als);
		als = temp;
	}

	//1st book shelf
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-4.0f, 0.0f, -7.25f));
		als = als * translateMatrix;
		bookShelf(cube, lightingShader, als, colorArray, wood1, wood2);
		als = temp;
	}
	//2nd book shelf
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-7.3f, 0.0f, 3.0f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		als = als * translateMatrix * rotateYMatrix;
		bookShelf(cube, lightingShader, als, colorArray, wood1, wood2);
		als = temp;
	}
	//3rd book shelf
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(7.0f, 0.0f, 0.0f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(270.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		als = als * translateMatrix * rotateYMatrix;
		bookShelf(cube, lightingShader, als, colorArray, wood1, wood2);
		als = temp;
	}

	//bookshelf pasher room
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(7.3, 0.1f, -7.4f));
		als = als * translateMatrix;
		bookShelf(cube, lightingShader, als, colorArray, wood1, wood2);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(15.6f, 0.1f, -7.4f));
		als = als * translateMatrix;
		bookShelf(cube, lightingShader, als, colorArray, wood1, wood2);
		als = temp;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	

}

#pragma once

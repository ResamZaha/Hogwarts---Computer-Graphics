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

//void greatHall(unsigned int& cubeVAO, Shader& lightingShader, glm::mat4 als)
void classroom(Cube& cube, Shader& lightingShader, glm::mat4 als, unsigned int windowdiffMap, unsigned int akashiwindow, unsigned int woodfloordiff, unsigned int woodfloorspec, unsigned int walltilesdiff, unsigned int walltilesspec)
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
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-23.0f, 0.0, -15.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(33.0f, 0.0f, 30.0f));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cubeVAO, lightingShader, als, 0.545f, 0.270f, 0.075f);
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(woodfloordiff, woodfloorspec, 32.0f);
		cube.drawCubeWithTexture(lightingShader, als);

		als = temp;

		//ceil
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-23.0f, 15.0, -15.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(33.0f, .1f, 30.0f));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cubeVAO, lightingShader, als, 0.545f, 0.270f, 0.075f);
		cube.setMaterialisticEimu(0.6f, 0.482f, 0.376f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;
	}

	//BACK WALL
	{
		//back wall
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-23.0f, 0.0, -15.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(33.0, 15.0f, .1f));
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
		//left wall boro ta
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-23.0f, 0.0, -15.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 15.0f, 30.0));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cubeVAO, lightingShader, als, 0.545f, 0.270f, 0.075f);
		cube.setMaterialisticEimu(0.6f, 0.482f, 0.376f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		//cube.setTextureProperty(walltilesdiff, walltilesspec, 32.0);
		//cube.drawCubeWithTexture(lightingShader, als);
		als = temp;


		//right wall boro ta
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(9.2f, 0.0, -15.0f));
		//rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-75.0f), glm::vec3(0.0f, 1.0f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 15.0f, 80.0));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cubeVAO, lightingShader, als, 0.545f, 0.270f, 0.075f);
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(walltilesdiff, walltilesspec, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;

		//right wall choto ta
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(9.0f, 0.0, -15.0f));
		//rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-75.0f), glm::vec3(0.0f, 1.0f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1, 27.0f, 37.0));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cubeVAO, lightingShader, als, 0.545f, 0.270f, 0.075f);
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(walltilesdiff, walltilesspec, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	
	


	//right wall er pasher box
	{
		//right wall er pasher box
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(6.0f, 0.0, -15.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0, 2.0f, 30.0));
		als = als * translateMatrix * scaleMatrix;
		//drawCube(cubeVAO, lightingShader, als, 0.545f, 0.270f, 0.075f);
		cube.setMaterialisticEimu(0.137f, 0.09f, 0.035f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		//cube.setTextureProperty(brick1, brick2, 32.0);
		//cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}
	
	//right wall er pasher PILLARS and windows
	{
		for(float i = 0.0f; i < 3.0f; i = i+1.0f)
		{
			
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(7.5f, 2.01, -13.0f + i * 10.0f));
			scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.5, 10.0, 3.0));
			als = als * translateMatrix * scaleMatrix;
			//drawCube(cubeVAO, lightingShader, als, 0.545f, 0.270f, 0.075f);
			//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
			//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
			cube.setTextureProperty(walltilesdiff, walltilesspec, 32.0);
			cube.drawCubeWithTexture(lightingShader, als);
			als = temp;
			///////windows
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(8.75f, 2.01, -8.5f + i * 10.0f));
			scaleMatrix = glm::scale(identityMatrix, glm::vec3(.25, 9.0, 4.0));
			als = als * translateMatrix * scaleMatrix;
			//drawCube(cubeVAO, lightingShader, als, 0.545f, 0.270f, 0.075f);
			//cube.setMaterialisticEimu(0.0f, 0.270f, 0.0f);
			//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
			cube.setTextureProperty(akashiwindow, akashiwindow, 32.0);
			cube.drawCubeWithTexture(lightingShader, als);
			als = temp;
		}
	}
	

	
	
	//door er shamner jaiga ta
	{
		//door er shamner jaiga
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(2.5, 2.5, -15.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0, .25f, 3.0));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;
	}
	
	//door
	{
		//door
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(2.5, 2.5, -15.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0, 5.75f, .25));
		als = als * translateMatrix * scaleMatrix;
		//cube.setMaterialisticEimu(0.0f, 0.0f, 0.0f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(windowdiffMap, windowdiffMap, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}

	//door er shamner jaiga bam handles
	{
		//door er shamner jaiga bam handle21
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(2.5, 2.5, -12.25f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.25, 1.5f, .25));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		//door er shamner jaiga bam handle22
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(2.5 + .7083, 2.5, -12.25f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.25, 1.5f, .25));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;


		//door er shamner jaiga bam handle23
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(2.5 + 1.666, 2.5, -12.25f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.25, 1.5f, .25));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;
	}

	//door er shamner jaiga dan handle
	{
		//door er shamner jaiga dan handle
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(5.25, 2.5, -14.75f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.25, 1.5f, 2.75));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;
	}

	//door er shamner jaiga bam handle
	{
		//door er shamner jaiga bam handle
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(2.35, 4.0, -12.25f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.15, .5f, .25));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

	}
	float siribarota = 12.0f;
	////////siri
	{
		//siri
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-2.5, 0.0, -15.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.0, .25f, .25));
		als = als * translateMatrix;
		stairCaseforClassroom(cube, lightingShader, als);
		als = temp;
	}

	//lwft curved wall
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-15.0, 0.0, -15.05f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(75.0f), glm::vec3(0.0f, 1.0f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(-30.5, 15.0f, .25));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(walltilesdiff, walltilesspec, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}

	//lwft curved wall er box/drawyer
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-15.0, 0.0, -15.05f));
		//rotateYMatrix = glm::rotate(identityMatrix, glm::radians(75.0f), glm::vec3(0.0f, 1.0f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(-30.5, 2.0f, 3.0));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.137f, 0.09f, 0.035f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;
	}


	//right curved wall
	{
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(6.0, 0.0, -15.05f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(150.0f), glm::vec3(0.0f, 1.0f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(-4.5, 15.0f, .25));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(walltilesdiff, walltilesspec, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}

	//door er nicher beam
	{
		//door er nicher beam
		temp = als;
		Cylinder beam = Cylinder(.5,2.5);
		translateMatrix = glm::translate(identityMatrix, glm::vec3(4.0, 1.25, -12.5f));
        als = als * translateMatrix;
		beam.drawCylinder(lightingShader, als, 0.545f, 0.270f, 0.075f);
		als = temp;
	}

	/////////////////////BENCHES
	{

		//benches right
		for(float i = 2.0f; i < 12.0f; i += 2.0f)
		{
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.0f - i * .15, 0.1, -6.0+ 2.0*i));
			als = als * translateMatrix;
			benchToll(cube, lightingShader, als);
			als = temp;
		}
		//benches middle
		for (float i = 2.0f; i < 12.0f; i += 2.0f)
		{
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(-6.0f - i * .2, 0.1 , -6.0 + 2.0 * i));
			rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-15.0f), glm::vec3(0.0f, 1.0f, 0.0));
			als = als * translateMatrix * rotateYMatrix;
			benchToll(cube, lightingShader, als);
			als = temp;
		}
		//benches left
		for (float i = 2.0f; i < 12.0f; i += 2.0f)
		{
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(-11.0f - i * .30, 0.1, -6.0 + 1.9 * i));
			rotateYMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(0.0f, 1.0f, 0.0));
			als = als * translateMatrix * rotateYMatrix;			
			benchToll(cube, lightingShader, als);
			als = temp;
		}

	}


	//left we window gula
	{
		//left er window gula
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-15.0-2.0, 2.01f, -15.05f+7.96));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(75.0f), glm::vec3(0.0f, 1.0f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(-4.5, 11.f, .25));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		//cube.setMaterialisticEimu(0.545f, 0.0f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(akashiwindow, akashiwindow, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-15.0-4.0, 2.01f, -15.05f + 15.42));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(75.0f), glm::vec3(0.0f, 1.0f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(-4.5, 10.f, .25));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		//cube.setMaterialisticEimu(0.545f, 0.0f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(akashiwindow, akashiwindow, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;


		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-15.0 - 6.0, 2.01f, -15.05f + 22.89));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(75.0f), glm::vec3(0.0f, 1.0f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(-4.5, 9.f, .25));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		//cube.setMaterialisticEimu(0.545f, 0.0f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(akashiwindow, akashiwindow, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}

	//triangles/beka pillar gula left
	{
		//triangles gula/beka pillar
		RightAngleTriangle rightAngleTriangle = RightAngleTriangle();
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-15.0, 4.01, -10.05f));
		//scaleMatrix = glm::scale(identityMatrix, glm::vec3(12.0f, -4.0f, 1.0f));
		//als = als * translateMatrix * scaleMatrix;
		//rightAngleTriangle.drawRightAngleTriangle(lightingShader, als, 0.545f, 0.0f, 0.075f);
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(15.25f, 2.0f, .25f));
		rotateZMatrix = glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0));
		als = als * translateMatrix * rotateZMatrix * scaleMatrix;
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		//cube.setTextureProperty(walltilesdiff, walltilesspec, 32.0);
		//cube.drawCubeWithTexture(lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-17.0, 4.01, -10.05f + 9.0*1));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(17.25f, 2.0f, .25f));
		rotateZMatrix = glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0));
		als = als * translateMatrix * rotateZMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.545f, 0.0f, 0.075f);
		//////////////////////////cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-19.0, 4.01, -10.05f + 8.5 * 2));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(19.25f, 2.0f, .25f));
		rotateZMatrix = glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0));
		als = als * translateMatrix * rotateZMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.545f, 0.0f, 0.075f);
		/////////////////////////////////cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-21.0, 4.01, -10.05f + 7.5 * 3));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(21.25f, 2.0f, .25f));
		rotateZMatrix = glm::rotate(identityMatrix, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0));
		als = als * translateMatrix * rotateZMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.545f, 0.0f, 0.075f);
		//////////////////////cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;



		
		//temp = als;
		//translateMatrix = glm::translate(identityMatrix, glm::vec3(-12.0 - 2.4, 8.0, 0.0));
		//scaleMatrix = glm::scale(identityMatrix, glm::vec3(12.0f, -4.0f, 1.0f));
		//als = als * translateMatrix * scaleMatrix;
		//triangle.drawTriangle(lightingShader, als, 0.545f, 0.0f, 0.075f);
		//rightAngleTriangle.drawRightAngleTriangle(lightingShader, als, 0.545f, 0.0f, 0.075f);
		//als = temp;

		//temp = als;
		//translateMatrix = glm::translate(identityMatrix, glm::vec3(-12.0 - 4.8, 8.0, 7.5));
		//scaleMatrix = glm::scale(identityMatrix, glm::vec3(12.0f, -4.0f, 1.0f));
		//als = als * translateMatrix * scaleMatrix;
		//triangle.drawTriangle(lightingShader, als, 0.545f, 0.0f, 0.075f);
		//rightAngleTriangle.drawRightAngleTriangle(lightingShader, als, 0.545f, 0.0f, 0.075f);
		//als = temp;

		//temp = als;
		//translateMatrix = glm::translate(identityMatrix, glm::vec3(-12.0 - 5.0, 8.0, 13.75));
		//scaleMatrix = glm::scale(identityMatrix, glm::vec3(12.0f, -4.0f, 1.0f));
		//als = als * translateMatrix * scaleMatrix;
		//triangle.drawTriangle(lightingShader, als, 0.545f, 0.0f, 0.075f);
		//rightAngleTriangle.drawRightAngleTriangle(lightingShader, als, 0.545f, 0.0f, 0.075f);
		//als = temp;
		

	}
	
	////////////////PILLARS left
	{
		//left er pillars
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-15.0 - 1.0, 2.01, -15.05f + 4.22));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(75.0f), glm::vec3(0.0f, 1.0f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(-2.0f, 12.0f, 1.5));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(walltilesdiff, walltilesspec, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-15.0 - 4.0, 2.01, -15.05f + 15.425));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(75.0f), glm::vec3(0.0f, 1.0f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0f, 11.0f, 1.5));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(walltilesdiff, walltilesspec, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;


		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-15.0 - 6.0, 2.01, -15.05f + 22.895));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(75.0f), glm::vec3(0.0f, 1.0f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0f, 10.0f, 1.5));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(walltilesdiff, walltilesspec, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;

		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-15.0 - 7.5, 2.01, -15.05f + 28.5));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(75.0f), glm::vec3(0.0f, 1.0f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.0f, 9.0f, 1.5));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
		//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		cube.setTextureProperty(walltilesdiff, walltilesspec, 32.0);
		cube.drawCubeWithTexture(lightingShader, als);
		als = temp;
	}











	////////TABLE MAIN
	{
		///table top
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-5.0, 2.01f, -10.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.0f, .25f, 3.0f));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.247f, 0.165f, 0.051f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		///table back left leg
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-5.0, 2.01f, -10.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5f, -2.0, .5f));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.247f, 0.165f, 0.051f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		///table back right leg
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.5, 2.01f, -10.0f));
		//scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5f, 2.0, .5f));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.247f, 0.165f, 0.051f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		///table front left leg
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-5.0, 2.01f, -7.5f));
		//scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5f, 2.0, .5f));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.247f, 0.165f, 0.051f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		///table front right leg
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-1.5, 2.01f, -7.5f));
		//scaleMatrix = glm::scale(identityMatrix, glm::vec3(.5f, 2.0, .5f));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.247f, 0.165f, 0.051f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;
	}

	//Board
	{
		//left stand
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-12.0, 0.01f, -7.5f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(.25f, 5.0, .25f));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.498f, 0.294f, 0.075f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		//right stand
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-12.0 +3.29, 0.01f, -7.5f-1.0));
		//scaleMatrix = glm::scale(identityMatrix, glm::vec3(.25f, 5.0, .25f));
		als = als * translateMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.498f, 0.294f, 0.075f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		//board
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-11.75, 2.01f, -7.5f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(20.0f), glm::vec3(0.0f, 1.0f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.3f, 3.0, .25f));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.278f, 0.451f, 0.333f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		//board top first design
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-12.0, 5.01f, -7.5f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(20.0f), glm::vec3(0.0f, 1.0f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.75f, .1, .5f));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.498f, 0.294f, 0.075f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;
		//board top 2nd design
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-12.0, 5.02f, -7.5f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(20.0f), glm::vec3(0.0f, 1.0f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.75f, .25, .25f));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.498f, 0.294f, 0.075f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;
		//board top 3rd design
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-12.0, 5.27f, -7.5f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(20.0f), glm::vec3(0.0f, 1.0f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.75f, .1, .5f));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.498f, 0.294f, 0.075f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		//board bottom first design
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-12.0, 2.01f, -7.5f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(20.0f), glm::vec3(0.0f, 1.0f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.75f, .1, .5f));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.498f, 0.294f, 0.075f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;
		//board bottom 2nd design
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-12.0, 2.02f, -7.1f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(20.0f), glm::vec3(0.0f, 1.0f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.75f, .25, .25f));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.498f, 0.294f, 0.075f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;
		//board bottom 3rd design
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-12.0, 2.27f, -7.5f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(20.0f), glm::vec3(0.0f, 1.0f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.75f, .1, .5f));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.498f, 0.294f, 0.075f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;

		//board bottom ekdom
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-12.5, .01f, -7.5f));
		rotateYMatrix = glm::rotate(identityMatrix, glm::radians(20.0f), glm::vec3(0.0f, 1.0f, 0.0));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(4.5f, .35, .75f));
		als = als * translateMatrix * rotateYMatrix * scaleMatrix;
		cube.setMaterialisticEimu(0.498f, 0.294f, 0.075f);
		cube.drawCubeWithMaterialisticProperty(lightingShader, als);
		als = temp;
	}
	//almari
	{
		//almari
		for(float i = 0.0; i < 4.0f; i = i + 1.0)
		{
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(4.5f, 0.01, -7.0f + i* 7.0));
			rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0));
			als = als * translateMatrix * rotateYMatrix;
			almari(cube, lightingShader, als);
			als = temp;
		}
	}

	//////////right er triangles/beka pillar gula
	{
		for(float i = 0.0f; i < 3.0f; i = i + 1.0f)
		{
			//triangles gula
			//RightAngleTriangle rightAngleTriangle = RightAngleTriangle();
			temp = als;
			//translateMatrix = glm::translate(identityMatrix, glm::vec3(2.5, 12.0, -11.0f + i * 10.0f));
			translateMatrix = glm::translate(identityMatrix, glm::vec3(7.5f, 4.01, -11.5f + i * 10.0f));
			scaleMatrix = glm::scale(identityMatrix, glm::vec3(-15.25f, 2.0f, .25f));
			rotateZMatrix = glm::rotate(identityMatrix, glm::radians(-45.0f), glm::vec3(0.0f, 0.0f, 1.0));
			als = als * translateMatrix * rotateZMatrix * scaleMatrix;
			//cube.setMaterialisticEimu(0.545f, 0.270f, 0.075f);
			//cube.drawCubeWithMaterialisticProperty(lightingShader, als);
			//cube.setTextureProperty(walltilesdiff, walltilesspec, 32.0);
			//cube.drawCubeWithTexture(lightingShader, als);
			//triangle.drawTriangle(lightingShader, als, 0.545f, 0.0f, 0.075f);
			//rightAngleTriangle.drawRightAngleTriangle(lightingShader, als, 0.545f, 0.0f, 0.075f);
			als = temp;
		}
	}


	//////side tables
	{
		//side tables
		for (float i = 2.0; i < 5.0f; i = i + 1.0)
		{
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(-5.5f - i * 2.0f , 0.0, -20.05f + i*7.47f));
			scaleMatrix = glm::scale(identityMatrix, glm::vec3(.75f, .75f, .5f));
			rotateYMatrix = glm::rotate(identityMatrix, glm::radians(75.0f), glm::vec3(0.0f, 1.0f, 0.0));
			als = als * translateMatrix * rotateYMatrix * scaleMatrix;
			Table(cube, lightingShader, als);
			als = temp;
		}
	}

	

	
	/////curved ceiling
	{
		ParabolicSurface parabolicSurface = ParabolicSurface();
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-6.0f, 15.0f,0.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(16.0f, 16.0f, 4.0f));
		rotateXMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0));
		als = als * translateMatrix * rotateXMatrix * scaleMatrix;
		parabolicSurface.drawParabolicSurface(lightingShader, als, 0.6f, 0.482f, 0.376f);
		als = temp;

		/////////////////////////////////////////////////////////////////////////
		ParabolicSurface parabolicSurface1 = ParabolicSurface();
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.5f, 15.0f, -11.25));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(13.5f, 1.25f, 14.0f));
		rotateXMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0));
		als = als * translateMatrix * rotateXMatrix * scaleMatrix;
		parabolicSurface.drawParabolicSurface(lightingShader, als, 0.6f, 0.482f, 0.376f);
		parabolicSurface.drawParabolicSurface(lightingShader, als * glm::translate(identityMatrix, glm::vec3(0.0, 3.0, 0.0)), 0.6f, 0.482f, 0.376f);

		als = temp;

		ParabolicSurface parabolicSurface2 = ParabolicSurface();
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-5.0f, 15.0f, -1.25f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(14.0f, 1.25f, 14.0f));
		rotateXMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0));
		als = als * translateMatrix * rotateXMatrix * scaleMatrix;
		parabolicSurface.drawParabolicSurface(lightingShader, als, 0.6f, 0.482f, 0.376f);
		als = temp;

		ParabolicSurface parabolicSurface3 = ParabolicSurface();
		temp = als;
		translateMatrix = glm::translate(identityMatrix, glm::vec3(-6.5f, 14.0f, 7.0f));
		scaleMatrix = glm::scale(identityMatrix, glm::vec3(15.0f, 1.25f, 14.0f));
		rotateXMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0));
		als = als * translateMatrix * rotateXMatrix * scaleMatrix;
		parabolicSurface.drawParabolicSurface(lightingShader, als, 0.6f, 0.482f, 0.376f);
		als = temp;

	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////



	//ceiling light
	{
		//side tables
		for (float i = 0.0f; i < 2.0f; i = i + 1.0)
		{
			temp = als;
			translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.0f - i * 4.0f,4.0f, -5.0f + i * 10.0f));
			als = als * translateMatrix;
			ceilLight(cube, lightingShader, als);
			als = temp;
		}
	}
	

}
#pragma once

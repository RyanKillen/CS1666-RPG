#define GLM_ENABLE_EXPERIMENTAL
#ifndef _____GRAPHICS_H_____
#define _____GRAPHICS_H_____

#include <string>
#include <list>
#include <algorithm>
#include <iostream>
#include "time.h"

#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <ft2build.h>
#include <freetype/freetype.h>

#include "Globals.h"
#include "ResourceManager/ResourceManager.h"
#include "UI/TextRenderer.h"
#include "ResourceManager/ResourceManager.h"
#include "UI/TextRenderer.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define BUFFER_OFFSET( offset )   ((GLvoid*) (offset))

class GraphicsObject
{
public:
	int ID;
	int type; //0 = 3d object color, 1 = 3d object texture
	GLuint VAO;
	GLuint VBO;
	int num_vertices;
	glm::vec3 position = { 0.0, 0.0, 0.0 };
	glm::vec4 color;
	std::string texture_ID;
	int texture_sheet_it;
	int texture_sheet_size;
	glm::vec4* position_array;
	glm::vec4* color_array;
	glm::vec2* texture_array;
	glm::mat4 ctm = { { 1.0, 0.0, 0.0, 0.0 },{ 0.0, 1.0, 0.0, 0.0 },{ 0.0, 0.0, 1.0, 0.0 },{ 0.0, 0.0, 0.0, 1.0 } };
	int idle_animation_type = 0; //0 = no animation, 1 = sprite animation, 2 = motion animation, 3 = sprite and motion animation
	glm::mat4 idle_animation_motion = { { 1.0, 0.0, 0.0, 0.0 },{ 0.0, 1.0, 0.0, 0.0 },{ 0.0, 0.0, 1.0, 0.0 },{ 0.0, 0.0, 0.0, 1.0 } };
	int animation_type = 0; //0 = no animation, 1 = motion animation, 2 = motion animation consume
	int animation_frame = 0;
	int animation_frame_max = 0;
	int animation_it = 0;
	int animation_size;
	int* animation_frame_max_array;
	glm::mat4 animation_motion = { { 1.0, 0.0, 0.0, 0.0 },{ 0.0, 1.0, 0.0, 0.0 },{ 0.0, 0.0, 1.0, 0.0 },{ 0.0, 0.0, 0.0, 1.0 } };
	glm::mat4* animation_motion_array;
private:
};

class Graphics
{
public:
	void init(void);
	void clean(void);
	void display(void);
	void idle(void);

	int genQuadColor(int height, int width, glm::vec4 color);
	int genQuadTexture(int height, int width, const GLchar *file, std::string texture_ID, int texture_sheet_it, int texture_sheet_size);
	int genCone(GLfloat radius, GLfloat height, int resolution, int color_type, glm::vec4 color);
	int genSphere(GLfloat radius, int resolution, int color_type, glm::vec4 color);
	int genCube(int color_type, glm::vec4 color);
	
	//Color Options
	glm::vec4* genRandomTriangleColors(int num_vertices); //color_type == 0
	glm::vec4* genRandomTriangleColorsAlpha(int num_vertices); //color_type == 1
	glm::vec4* genRandomTriangleColorsSimilar(int num_vertices, glm::vec4 color); //color_type == 2

	int recolorQuad(int ID, glm::vec4 color);
	int retextureQuad(int ID, const GLchar *file, std::string texture_ID);
	int removeObject(int ID);

	int translateObjectByPixel(int ID, int x, int y, GLfloat z);
	int transformCtm(int ID, glm::mat4 transform);

	glm::vec3 rotateRandom(void);

	int setPosition(int ID, glm::vec3 position);
	glm::vec3 getPosition(int ID);
	glm::vec3 getVectorFromTo(int ID1, int ID2);
	
	int setIdleAnimationType(int ID, int type);
	void iterateSpriteAnimation(std::list<GraphicsObject>::iterator it); // 1 = sprite animation
	int setIdleAnimationMotion(int ID, glm::mat4 motion); // 2 = motion animation

	int setAnimation(int ID, int type); 
	int setAnimationMotion(int ID, glm::mat4 motion);
	int setAnimationFrameMax(int ID, int frame_max);
	int setAnimationMultiStep(int ID, int animation_size, glm::mat4* animation_motion_array, int* animation_frame_max_array);

	void animateMotion(std::list<GraphicsObject>::iterator it); // 1 = motion animation 
	void animateMotionConsume(std::list<GraphicsObject>::iterator it); // 2 = motion animation consume
	void animateMultiStep(std::list<GraphicsObject>::iterator it); // 3 = multistep animation
	void animateMultiStepConsume(std::list<GraphicsObject>::iterator it); // 4 = multistep animation consume

	// Adds text to render to the screen.
	// You will need to do this every tick for it to continuously display 
	void addTextToRender(RenderableText text);
	void addTextsToRender(std::vector<RenderableText> texts);

	TextRenderer textRenderer;
private:
	int object_counter = 0;
	GLuint HUDVAO;
	GLuint HUDVBO;
	GLuint vPosition;
	GLuint vColor;
	GLuint vTexCoords;
	std::list<GraphicsObject> objectList;
	std::list<int> eraseBuffer;
	// Vertices for a simple 1x1 textured quad
	int quad_num_vertices = 6;
	glm::vec4 quadVertices[6] = {
		{ -1.0f, 1.0f, 0.0f, 1.0f },
		{ -1.0f, -1.0f, 0.0f, 1.0f },
		{ 1.0f, -1.0f, 0.0f, 1.0f },
		{ -1.0f, 1.0f, 0.0f, 1.0f },
		{ 1.0f, -1.0f, 0.0f, 1.0f },
		{ 1.0f, 1.0f, 0.0f, 1.0f }
	};
	glm::vec2 quadTexCoords[6] = {
		{ 0.0f, 0.0f },
		{ 0.0f, 1.0f },
		{ 1.0f, 1.0f },
		{ 0.0f, 0.0f },
		{ 1.0f, 1.0f },
		{ 1.0f, 0.0f }
	};
	std::vector<RenderableText> m_textToRender; // Stores the text to render for the current tick. Cleared after flushing to screen.
};

#endif

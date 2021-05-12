/* scene.c file */

#include "scene.h"
#include <GL/glut.h>
#include <time.h>

double moon_y_rotation, mercury_y_rotation = 0;
double moon_z_rotation, mercury_z_rotation = 0;
double moon_rotate, mercury_rotate = 0;

double brightness=5;
double flash_light=5;


void init_scene(Scene* scene)
{
    load_model(&(scene->ground), "models/ground.obj");
    load_model(&(scene->penguin), "models/penguin.obj");
    load_model(&(scene->moon), "models/moon.obj");
    load_model(&(scene->mercury), "models/mercury.obj");
    load_model(&(scene->water), "models/water.obj");

    scene->texture_ground = load_texture("textures/ground.jpg"); 	
	scene->texture_penguin = load_texture("textures/penguin.png"); 	
    scene->texture_moon = load_texture("textures/moon.png"); 
    scene->texture_mercury = load_texture("textures/mercury.png"); 		
    scene->texture_water = load_texture("textures/water.jpg");
	scene->information = load_texture("textures/information.PNG"); 

    scene->material.ambient.red = 5.0;
    scene->material.ambient.green = 5.0;
    scene->material.ambient.blue = 5.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;
	
    scene->material.specular.red = 1.0;
    scene->material.specular.green = 1.0;
    scene->material.specular.blue = 1.0;

    scene->material.shininess = 10.0;
}

void set_lighting()
{
    float ambient_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light[] = { 1.0f+brightness, 1.0f+brightness, 1.0f+brightness, 1.0f+brightness };
    float specular_light[] = { 1.0f+flash_light, 1.0f+flash_light, 1.0f+flash_light, 1.0f+flash_light };
    float position[] = { 40.0f, 20.0f, 0.0f, 2.0f };
 
	GLfloat light_position[] = {300, 0, -1000, 0.};
    GLfloat light_color[] = {0, 1, 0, 1};
	
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void update_lighting(Scene* scene, double value)
{
	brightness= brightness + value;
	
}	

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void draw_scene(const Scene* scene)
{

    set_material(&(scene->material));
    set_lighting();
	glBindTexture(GL_TEXTURE_2D, scene->texture_ground);	
    draw_model(&(scene->ground));
	
	glBindTexture(GL_TEXTURE_2D, scene->texture_water);	
	glPushMatrix();	
	draw_model(&(scene->water));
	glPopMatrix();
	
    glBindTexture(GL_TEXTURE_2D, scene->texture_moon);	
	glPushMatrix();
	glRotatef(0, 0, 0+moon_rotate, 0);
	glTranslatef(1.0, 1.0+moon_y_rotation, 1.0+moon_z_rotation);
	glScalef(0.1, 0.1, 0.1);
	draw_model(&(scene->moon));
	glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, scene->texture_mercury);	
	glPushMatrix();
	glRotatef(0, 0, 0+mercury_rotate, 0);
	glTranslatef(2.0, 1.0+mercury_y_rotation, 1.0+mercury_z_rotation);
	glScalef(0.1, 0.1, 0.1);
	draw_model(&(scene->mercury));
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, scene->texture_penguin);
    glPushMatrix();
	glTranslatef(0.5,0.5,0.1);
	glScalef(0.1, 0.1, 0.1);
    draw_model(&(scene->penguin));
	glPopMatrix();
		
	glBindTexture(GL_TEXTURE_2D, scene->information);
}

void moon_movement(double time)
{
	moon_y_rotation=moon_y_rotation-time/500;
	moon_z_rotation=moon_z_rotation+time/500;
	moon_rotate=moon_rotate+time*5;	
}		

void mercury_movement(double time)
{
	mercury_y_rotation=mercury_y_rotation-time/800;
	mercury_z_rotation=mercury_z_rotation+time/800;
	mercury_rotate=mercury_rotate+time*5;	
}	

void invisible() // To invisible.
{
	glBlendFunc(1, 1);
}

void invisible2() // To black.
{
	glBlendFunc(0, 0);
}
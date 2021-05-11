/* scene.h file */

#ifndef SCENE_H_
#define SCENE_H_

#include "camera.h"
#include "texture.h"
#include <obj/model.h>

typedef struct Scene
{
    Camera camera;
	Model ground;
    Model water;
    Model moon;
    Model mercury;
	Model penguin;
    Material material;
    GLuint texture_ground;
    GLuint texture_water;
    GLuint texture_moon;
    GLuint texture_mercury;
    GLuint texture_penguin;
    GLuint information;
} Scene;

/* Initialize the scene by loading models. */
void init_scene(Scene* scene);

/* Set the lighting of the scene. */
void set_lighting();

/* Set the current material. */
void set_material(const Material* material);

/* Draw the scene objects. */
void draw_scene(const Scene* scene);

/* Update the light of the scene. */
void update_lighting(Scene* scene, double value);

/* Set the moon move of the scene. */
void moon_movement();

#endif /* SCENE_H_ */
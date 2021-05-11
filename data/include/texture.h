/* texture.h file */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <GL/glut.h>

typedef GLubyte Pixel[3];

/* Load texture from file and returns with the texture name. */
GLuint load_texture(char* filename);

#endif /* TEXTURE_H_ */
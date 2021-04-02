#ifndef MATRIX_H
#define MATRIX_H

/**
 * Initializes all elements of the matrix to zero.
 */
void init_zero_matrix(float matrix[3][3]);


/**
 * Initializes all elements of the matrix to identity.
 */
void init_identity_matrix(float matrix[3][3]);


/**
	*Muliple matrix by a scalar value.
	*/
void mult_scalar_matrix(float matrix[3][3], float scalar);


/**
 * Print the elements of the matrix.
 */
void print_matrix(const float matrix[3][3]);

/**
 * Add matrices.
 */
void add_matrices(const float a[3][3], const float b[3][3], float c[3][3]);

/**
	*Muliply matrices.
	*/
void multiply_matrices(const float a[3][3], const float b[3][3], float c[3][3]);



#endif // MATRIX_H


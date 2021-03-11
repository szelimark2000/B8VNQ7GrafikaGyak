#include <obj/info.h>
#include <obj/load.h>
#include <stdio.h>


int main(int argc, char* argv[])
{
	Model model;
	
	load_model(&model, "deer.obj");
	print_model_info(&model);
	print_bounding_box(&model);
	
	return 0;
}
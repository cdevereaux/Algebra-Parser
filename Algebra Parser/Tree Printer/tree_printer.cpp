#include "tree_printer.h"
#include <iostream>


unsigned int get_height(Parse_Tree_Ptr root)
{
	//root should only be null in the empty tree
	if (root == nullptr) return 0;

	if ((*root)[0] == nullptr) return 1;

	auto max = 0u;
	for (auto i = 0; (*root)[i] != nullptr; i++)
	{
		auto h = get_height((*root)[i]);
		max = h > max ? h : max;
	}
	return max + 1;
}


unsigned int get_width(Parse_Tree_Ptr root)
{
	//root should only be null in the empty tree
	if (root == nullptr) return 0;

	if ((*root)[0] == nullptr) return 1;

	auto leaves = 0;
	for (auto i = 0; (*root)[i] != nullptr; i++)
	{
		leaves += get_width((*root)[i]);
	}
	return leaves;
}


void draw_tree(std::string& str, unsigned int height, unsigned int width, unsigned int level, int direction)
{
	;
}


void write_to_file(std::string str)
{
	;
}


void Tree_Printer::print(Parse_Tree_Ptr root)
{
	std::cout << "Height: " << get_height(root)
		<< " Width: " << get_width(root) << std::endl;
	
	std::string svg_contents;
	svg_contents += "<svg height=\"";
	svg_contents += get_height(root);
	svg_contents += "\" width=\"";
	svg_contents += get_width(root);
	svg_contents += "\">";

	//draw_tree(svg_contents, );

	svg_contents += "< / svg>";
	write_to_file(svg_contents);
	
}

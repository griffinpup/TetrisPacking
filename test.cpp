#include "node.h"
#include "shape.h"
#include "recursive_place.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <numeric>

int main() {
  int GRAPH_SIZE = 8;
  //Builds the 8x8 graph
  hrl::node ** graph = new hrl::node*[GRAPH_SIZE];
  for (int i = 0; i < GRAPH_SIZE; i++) {
    graph[i] = new hrl::node[GRAPH_SIZE];
  }

  //Builds a node at each point
  for (int i = 0; i < GRAPH_SIZE; i++) {
    for (int j = 0; j < GRAPH_SIZE; j++) {
      graph[i][j] = hrl::node();
    }
  }

  //Connects each node to its neighbors
  for (int i = 0; i < GRAPH_SIZE; i++) {
    for (int j = 0; j < GRAPH_SIZE; j++) {
      //Top
      if (i-1 > -1)
        graph[i][j].top = &graph[i-1][j];
      //Right
      if (j+1 < GRAPH_SIZE+1)
        graph[i][j].right = &graph[j+1][j];
      //Bottom
      if (i+1 < GRAPH_SIZE+1)
        graph[i][j].bottom = &graph[i+1][j];
      //Left
      if (j-1 > -1)
        graph[i][j].left = &graph[i-1][j];
    }
  }

  //Build shapes.
  hrl::node * one           = shape::get_shape_one();
  hrl::node * two          	= shape::get_shape_two();
  hrl::node * three        	= shape::get_shape_three();
  hrl::node * five_square  	= shape::get_shape_five_square();
  hrl::node * five_l       	= shape::get_shape_five_l();
  hrl::node * five_jagged  	= shape::get_shape_five_jagged();
  hrl::node * five_plus    	= shape::get_shape_five_plus();
  hrl::node * five_cross   	= shape::get_shape_five_cross();
  hrl::node * six_square   	= shape::get_shape_six_square();
  hrl::node * six_cross    	= shape::get_shape_six_cross();
  hrl::node * seven_bottom  = shape::get_shape_seven_bottom();
  hrl::node * seven_top     = shape::get_shape_seven_top();
  hrl::node * seven_middle  = shape::get_shape_seven_middle();
  //Place all the shapes in a vector.
  std::vector<hrl::node *> shapes;
  shapes.push_back(seven_middle);
  shapes.push_back(seven_top);
  shapes.push_back(seven_bottom);
  shapes.push_back(six_cross);
  shapes.push_back(six_square);
  shapes.push_back(five_cross);
  shapes.push_back(five_plus);
  shapes.push_back(five_jagged);
  shapes.push_back(five_l);
  shapes.push_back(five_square);
  shapes.push_back(three);
  shapes.push_back(two);
  shapes.push_back(one);

 bool succeeded = recursive_place::recursive_pack(shapes, graph);
 if (succeeded)
   std::cout <<"Succeeded" << std::endl;
else
  std::cout <<"Failed" << std::endl;
}

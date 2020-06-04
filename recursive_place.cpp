#include "recursive_place.h"
#include "node.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <numeric>



/*
 * Greedy dual axis weighted algorithm with rotation and repacking, which
 * takes and packs a series of shapes onto a graph.
 * Inputs:
 *  shapes: A vector of the shapes to pack.
 *  graph:  The graph of nodes to pack on.
 * Outputs:
 *  bool:   Whether or not packing was successful.
 *
 */
bool recursive_place::recursive_pack(std::vector<hrl::node *> shapes, hrl::node ** graph){
  bool solved = false;
  int count = 0;
  hrl::node * cur_shape;
  //For every shape
  for (int idx = 0; idx < shapes.size(); idx++) {
    cur_shape = shapes[idx];
    //For every node in graph
    for (int x = 0; x < GRAPH_SIZE; x++) {
      for (int y = 0; y < GRAPH_SIZE; y++) {
        //Try every rotation of the object
        for (int times_rotated = 0; times_rotated < 4; times_rotated++) {
          //If shape fits, place it and recurse
          if (fit_shape(cur_shape, graph, x, y)) {
            static int count = 1;
            count++;
            place_shape(cur_shape, graph, x, y, 13 -  shapes.size() + (idx+1));
            //Base case
            if (is_solved(graph)){
              std::cout << std::endl;
              std::cout << "Number of times a piece was placed: " << count << std::endl;
              std::cout << std::endl;
              return true;
            }
            std::vector<hrl::node *> new_shapes = shapes;
            new_shapes.erase(new_shapes.begin() + idx);
            //If recursion worked, report success
            if (recursive_pack(new_shapes, graph))
              return true;
            //If recursion failed, take piece back out
            else
              remove_shape(cur_shape, graph, x, y);
            //Prints the graph at the top of every failure
            draw_graph(graph);
          }
          cur_shape = rotate_shape(cur_shape);
        }
      }
    }
  return false;
  }
  return false;
}


/*
 * Checks to see if the shape fits.  This recursively searches from the
 * head node and checks all connected nodes.
 * Inputs:
 *  shape:  node pointer to head node
 *  graph:  pointer to graph to test against
 *  x:      x location on the graph to check
 *  y:      y location on the graph to check
 * Output:
 *  bool: Whether the inputted shape fits in the spot specified
 */
bool recursive_place::fit_shape(hrl::node * shape, hrl::node ** graph, int x, int y) {
  if (x < 0 || x >= GRAPH_SIZE || y < 0 || y >= GRAPH_SIZE || graph[x][y].state == true) {
      return false;
  }
  if (shape->top != NULL) {
    if (!fit_shape(shape->top, graph, x, y-1)){
      return false;
    }
  }
  if (shape->right != NULL) {
    if (!fit_shape(shape->right, graph, x+1, y)){
      return false;
    }
  }
  if (shape->bottom != NULL) {
    if (!fit_shape(shape->bottom, graph, x, y+1)){
      return false;
    }
  }
  if (shape->left != NULL) {
    if (!fit_shape(shape->left, graph, x-1, y)){
      return false;
    }
  }
  return true;
}

/*
 * Tries to take an object out at the specified location.  Returns false is an
 * object is already there.  A false return means that the graph may be currupted.
 * Inputs:
 *  shape:  node pointer to head node
 *  graph:  pointer to graph to test against
 *  x:      x location on the graph to remove the object
 *  y:      y location on the graph to remove the object
 * Output:
 *  bool: Whether the inputted shape was successfully removed
 */
bool recursive_place::remove_shape(hrl::node * shape, hrl::node ** graph, int x, int y) {
  if (!graph[x][y].state){
    return false;
  }
  graph[x][y].state = false;
  graph[x][y].piece = 0;
  if (shape->top != NULL) {
    if (!remove_shape(shape->top, graph, x, y-1)){
      return false;
    }
  }
  if (shape->right != NULL) {
    if (!remove_shape(shape->right, graph, x+1, y)){
      return false;
    }
  }
  if (shape->bottom != NULL) {
    if (!remove_shape(shape->bottom, graph, x, y+1)){
      return false;
    }
  }
  if (shape->left != NULL) {
    if (!remove_shape(shape->left, graph, x-1, y)){
      return false;
    }
  }
  return true;
}

/*
 * Tries to place an object at the specified location.  Returns false is an
 * object is already there.  A false return means that the graph may be currupted
 * Inputs:
 *  shape:  node pointer to head node
 *  graph:  pointer to graph to place in
 *  x:      x location on the graph to remove the object
 *  y:      y location on the graph to remove the object
 *  id:     which shape is being fitted, used for drawing the graph
 * Output:
 *  bool: Whether the inputted shape was successfully added
 */
bool recursive_place::place_shape(hrl::node * shape, hrl::node ** graph, int x, int y, int id) {
  if (graph[x][y].state){
    return false;
  }
  graph[x][y].state = true;
  graph[x][y].piece = id;
  if (shape->top != NULL) {
    if (!place_shape(shape->top, graph, x, y-1, id)){
      return false;
    }
  }
  if (shape->right != NULL) {
    if (!place_shape(shape->right, graph, x+1, y, id)){
      return false;
    }
  }
  if (shape->bottom != NULL) {
    if (!place_shape(shape->bottom, graph, x, y+1, id)){
      return false;
    }
  }
  if (shape->left != NULL) {
    if (!place_shape(shape->left, graph, x-1, y, id)){
      return false;
    }
  }
  return true;
}

/*
 * Recursively rotates the shape, so we can try all 4 configurations
 * Changes the pointer that was provided
 * Inputs:
 *  shape:  node pointer to head node that is to be shifted
 * Output:
 *  hrl::node *: Pointer to the shifted node
 */
hrl::node * recursive_place::rotate_shape(hrl::node * shape) {
  //TODO: Deconstructor stuff?
  hrl::node * temp_top = shape->top;
  shape->top = shape->left;
  shape->left = shape->bottom;
  shape->bottom = shape->right;
  shape->right = temp_top;
  if (shape->top != NULL) {
    temp_top = rotate_shape(shape->top);
  }
  if (shape->right != NULL) {
    temp_top = rotate_shape(shape->right);
  }
  if (shape->bottom != NULL) {
    temp_top = rotate_shape(shape->bottom);
  }
  if (shape->left != NULL) {
    temp_top = rotate_shape(shape->left);
  }
  return shape;
}

/*
 * Checks to see if the graph has no blank spaces
 * Inputs:
 *  graph:  Graph that's checked for completeness
 * Output:
 *  bool:   Whether the graph has been solved
 */
bool recursive_place::is_solved(hrl::node ** graph) {
  for (int x = 0; x < GRAPH_SIZE; x++) {
    for (int y = 0; y < GRAPH_SIZE; y++) {
      if (!graph[x][y].state)
        return false;
    }
  }
  draw_graph(graph);
  return true;
}

/*
 * Debugging helper function that places itself and its connections recursively onto
 * a 2d string vector for display
 * Inputs:
 *  shape:  Pointer to head node of the shape to draw
 *  out:    2D vector that is written on to display shapes
 *  x:      The x location to change on out
 *  y:      The y location to change on out
 */
void recursive_place::draw_node(hrl::node * shape, std::vector<std::vector<std::string> > * out, int x,int y) {
  (*out)[x][y] = "X";

  if (shape->top != NULL) {
    draw_node(shape->top, out, x, y-1);
  }
  if (shape->right != NULL) {
    draw_node(shape->right, out, x+1, y);
  }
  if (shape->bottom != NULL) {
    draw_node(shape->bottom, out, x, y+1);
  }
  if (shape->left != NULL) {
    draw_node(shape->left, out, x-1, y);
  }
}

/*
 * Draws a shape to console.
 * Inputs:
 *  shape:  Pointer to head node of the shape to draw
 */
void recursive_place::draw_shape(hrl::node * shape) {
  std::vector<std::vector<std::string> > output;
  for (int i = 0; i < 10; i++){
    std::vector<std::string> line;
    for (int i = 0; i < 10; i++){
      line.push_back("_");
    }
    output.push_back(line);
  }

  int base_x = 5;
  int base_y = 5;
  draw_node(shape, &output, base_x, base_y);
  for (int i = 0; i < 10; i++) {
    std::cout << accumulate(output[i].begin(), output[i].end(), std::string("")) << std::endl;
  }
}

/*
 * Draws a given graph to console.  Only draws if the calculated error on the
 * graph is lower then previously.  This gives more readable results
 * Inputs:
 *  Graph:  Pointer to graph to print to console
 */
void recursive_place::draw_graph(hrl::node ** graph) {
  static int error = GRAPH_SIZE * GRAPH_SIZE;
  std::vector<std::vector<std::string> > output = build_drawing_vector();
  //Calculates error
  int local_error = 0;
  for (int x = 0; x < GRAPH_SIZE; x++){
    for (int y = 0; y < GRAPH_SIZE; y++){
      if (graph[x][y].piece == 0){
        output[x][y] = "_";
        local_error ++;
      }
      else {
        output[x][y] = (static_cast<char>(graph[x][y].piece + 64));
      }

    }
  }
  if (local_error < error) {
    std::cout << std::endl;
    std::cout << "Error: " << local_error << std::endl;
    error = local_error;
  }
  else
    return;
  std::cout << std::endl;
  for (int i = GRAPH_SIZE-1; i >= 0; i--) {
    std::cout << accumulate(output[i].begin(), output[i].end(), std::string("")) << std::endl;
  }
}

/*
 * Helper function to build a drawing vector for use by draw_graph and draw_shape
 * Output:
 *  std::vector<std::vector<std::string> >: 2D string vector used for outputting to console
 */
std::vector<std::vector<std::string> > recursive_place::build_drawing_vector() {
  std::vector<std::vector<std::string> > output;
  for (int x = 0; x < GRAPH_SIZE; x++){
    std::vector<std::string> line;
    for (int y = 0; y < GRAPH_SIZE; y++){
      line.push_back("_");
    }
    output.push_back(line);
  }
  return output;
}

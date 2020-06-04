

#ifndef RECURSIVE_PLACE
#define RECURSIVE_PLACE

#include "node.h"
#include "shape.h"
#include <vector>
class recursive_place {
  public:
    static bool recursive_pack(std::vector<hrl::node *> shapes, hrl::node ** graph);
  private:
    static bool place_shape(hrl::node * shape, hrl::node ** graph, int x, int y, int id);
    static bool remove_shape(hrl::node * shape, hrl::node ** graph, int x, int y);
    static bool fit_shape(hrl::node * shape, hrl::node ** graph, int x, int y);
    static void draw_node(hrl::node * shape, std::vector<std::vector<std::string> > * out, int x,int y);
    static void draw_shape(hrl::node * shape);
    static void draw_graph(hrl::node ** graph);
    static std::vector<std::vector<std::string> > build_drawing_vector();
    static hrl::node * rotate_shape(hrl::node * shape);
    static bool is_solved(hrl::node ** graph);
    static const int GRAPH_SIZE = 8;
};

#endif

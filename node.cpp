// Contains definitions for node.h

#include "node.h"

namespace hrl
{

node::node() {
  this->state = false;
  //Sets all the pointers to null
  node * top = NULL;
  node * bottom = NULL;
  node * right = NULL;
  node * left = NULL;
  piece = 0;


}
node::node(bool _state) {
  this->state = _state;
  node * top = NULL;
  node * bottom = NULL;
  node * right = NULL;
  node * left = NULL;
  piece = 0;
}

int node::count_connections() {
  return 0;
}
}

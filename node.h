/* This node class is used to build a graph and shapes for hrl programming challenge
 * Christopher DuHadway
 * Febuary 16, 2018
 */

#ifndef NODE_H
#define NODE_H

#include<string>

namespace hrl
{
/* Node class for holding elements. */
class node
{
  public:
    node();
    node(bool _state);
    int count_connections();

    bool state;
    //Array of node pointers
    //Order is top, right, bottom, left
    node * top;
    node * bottom;
    node * right;
    node * left;
    int piece;

};
}

#endif

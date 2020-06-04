

#include "shape.h"
#include "node.h"

shape::shape() {
  node = hrl::node();
  count = 0;
}

void shape::link_nodes(hrl::node * node1, hrl::node * node2, std::string direction) {
  if (direction == "left") {
    node1->left = node2;
    //node2->right = node1;
  }
  if (direction == "right") {
    node1->right = node2;
    // node2->left = node1;
  }
  if (direction == "top") {
    node1->top = node2;
    // node2->bottom = node1;
  }
  if (direction == "bottom") {
    node1->bottom = node2;
    // node2->top = node1;
  }
}

 hrl::node * shape::get_shape_one() {
  // X1
  hrl::node * head = new hrl::node();
  return head;
 }

 hrl::node * shape::get_shape_two() {
  /*
   * X1
   * X2
   */
  hrl::node * X2;
  X2 = new hrl::node();
  hrl::node * head = new hrl::node();
  link_nodes(head, X2, "bottom");
  return head;
 }

 hrl::node * shape::get_shape_three() {
  /*
   * X1
   * X2X3
   */
   hrl::node * X2 = new hrl::node();
   hrl::node * X3 = new hrl::node();
  hrl::node * head = new hrl::node();
  link_nodes(head, X2, "bottom");
  link_nodes(X2, X3, "right");
  return head;
 }

 hrl::node * shape::get_shape_five_square() {
  /*
   * X1
   * X2X3
   * X5X4
   */
 hrl::node * X2 = new hrl::node();
 hrl::node * X3 = new hrl::node();
 hrl::node * X4 = new hrl::node();
 hrl::node * X5 = new hrl::node();
  hrl::node * head = new hrl::node();
  link_nodes(head, X2, "bottom");
  link_nodes(X2, X3, "right");
  link_nodes(X3, X4, "bottom");
  link_nodes(X4, X5, "left");

  return head;

 }

 hrl::node * shape::get_shape_five_l() {
  /*
   * X1
   * X2
   * X3X4X5
   */
 hrl::node * X2 = new hrl::node();
 hrl::node * X3 = new hrl::node();
 hrl::node * X4 = new hrl::node();
 hrl::node * X5 = new hrl::node();
  hrl::node * head = new hrl::node();
  link_nodes(head, X2, "bottom");
  link_nodes(X2, X3, "bottom");
  link_nodes(X3, X4, "right");
  link_nodes(X4, X5, "right");


  return head;
 }

 hrl::node * shape::get_shape_five_jagged() {
  /*
   * X1
   * X2
   * X3X4
   * X5
   */
 hrl::node * X2 = new hrl::node();
 hrl::node * X3 = new hrl::node();
 hrl::node * X4 = new hrl::node();
 hrl::node * X5 = new hrl::node();
  hrl::node * head = new hrl::node();
  link_nodes(head, X2, "bottom");
  link_nodes(X2, X3, "bottom");
  link_nodes(X3, X4, "right");
  link_nodes(X3, X5, "bottom");

  return head;

 }

 hrl::node * shape::get_shape_five_plus() {
  /*
   *    X1
   *  X5X2X3
   *    X4
   */
 hrl::node * X2 = new hrl::node();
 hrl::node * X3 = new hrl::node();
 hrl::node * X4 = new hrl::node();
 hrl::node * X5 = new hrl::node();
  hrl::node * head = new hrl::node();
  link_nodes(head, X2, "bottom");
  link_nodes(X2, X3, "right");
  link_nodes(X2, X4, "bottom");
  link_nodes(X2, X5, "left");

  return head;

 }

 hrl::node * shape::get_shape_five_cross() {
  /*
   *    X1
   *    X2
   *  X5X3X4
   */
 hrl::node * X2 = new hrl::node();
 hrl::node * X3 = new hrl::node();
 hrl::node * X4 = new hrl::node();
 hrl::node * X5 = new hrl::node();
  hrl::node * head = new hrl::node();
  link_nodes(head, X2, "bottom");
  link_nodes(X2, X3, "bottom");
  link_nodes(X3, X4, "right");
  link_nodes(X3, X5, "left");

  return head;

 }

 hrl::node * shape::get_shape_six_square() {
  /*
   *  X1X2
   *  X3X4
   *  X5X6
   */
 hrl::node * X2 = new hrl::node();
 hrl::node * X3 = new hrl::node();
 hrl::node * X4 = new hrl::node();
 hrl::node * X5 = new hrl::node();
 hrl::node * X6 = new hrl::node();
  hrl::node * head = new hrl::node();
  link_nodes(head, X2, "right");
  link_nodes(head, X3, "bottom");
  link_nodes(X3, X5, "bottom");
  link_nodes(X2, X4, "bottom");
  link_nodes(X4, X6, "bottom");
  return head;
 }

 hrl::node * shape::get_shape_six_cross() {
  /*
   *    X1
   *    X2
   *  X5X3X4
   *    X6
   */
 hrl::node * X2 = new hrl::node();
 hrl::node * X3 = new hrl::node();
 hrl::node * X4 = new hrl::node();
 hrl::node * X5 = new hrl::node();
 hrl::node * X6 = new hrl::node();
  hrl::node * head = new hrl::node();
  link_nodes(head, X2, "bottom");
  link_nodes(X2, X3, "bottom");
  link_nodes(X3, X4, "right");
  link_nodes(X3, X5, "left");
  link_nodes(X3, X6, "bottom");
  return head;
 }

 hrl::node * shape::get_shape_seven_bottom() {
  /*
   *  X1X2
   *  X3X4
   *  X5X6X7
   */
 hrl::node * X2 = new hrl::node();
 hrl::node * X3 = new hrl::node();
 hrl::node * X4 = new hrl::node();
 hrl::node * X5 = new hrl::node();
 hrl::node * X6 = new hrl::node();
 hrl::node * X7 = new hrl::node();
  hrl::node * head = new hrl::node();
  link_nodes(head, X2, "right");
  link_nodes(head, X3, "bottom");
  link_nodes(X2, X4, "bottom");
  link_nodes(X3, X5, "bottom");
  link_nodes(X4, X6, "bottom");
  link_nodes(X6, X7, "right");
  return head;
 }

 hrl::node * shape::get_shape_seven_top() {
  /*
   *  X1X2X7
   *  X3X4
   *  X5X6
   */
 hrl::node * X2 = new hrl::node();
 hrl::node * X3 = new hrl::node();
 hrl::node * X4 = new hrl::node();
 hrl::node * X5 = new hrl::node();
 hrl::node * X6 = new hrl::node();
 hrl::node * X7 = new hrl::node();
  hrl::node * head = new hrl::node();
  link_nodes(head, X2, "right");
  link_nodes(head, X3, "bottom");
  link_nodes(X2, X4, "bottom");
  link_nodes(X2, X7, "right");
  link_nodes(X3, X5, "bottom");
  link_nodes(X4, X6, "bottom");
  return head;
 }

 hrl::node * shape::get_shape_seven_middle() {

  /*  X1X2
   *  X3X4X7
   *  X5X6
   */
 hrl::node * X2 = new hrl::node();
 hrl::node * X3 = new hrl::node();
 hrl::node * X4 = new hrl::node();
 hrl::node * X5 = new hrl::node();
 hrl::node * X6 = new hrl::node();
 hrl::node * X7 = new hrl::node();
  hrl::node * head = new hrl::node();
  link_nodes(head, X2, "right");
  link_nodes(head, X3, "bottom");
  link_nodes(X2, X4, "bottom");
  link_nodes(X3, X5, "bottom");
  link_nodes(X4, X6, "bottom");
  link_nodes(X4, X7, "right");
  return head;
 }


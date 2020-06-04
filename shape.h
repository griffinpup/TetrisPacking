#ifndef SHAPE_H
#define SHAPE_H
#include "node.h"

class shape
{
  public:
		shape();
		shape(hrl::node);
    hrl::node node;
    int count;
    static void         link_nodes(hrl::node *, hrl::node *, std::string);
    static hrl::node *	get_shape_one();
    static hrl::node *	get_shape_two();
    static hrl::node *	get_shape_three();
    static hrl::node *	get_shape_five_square();
    static hrl::node *	get_shape_five_l();
    static hrl::node *	get_shape_five_jagged();
    static hrl::node *	get_shape_five_plus();
    static hrl::node *	get_shape_five_cross();
    static hrl::node *	get_shape_six_square();
    static hrl::node *	get_shape_six_cross();
    static hrl::node *	get_shape_seven_bottom();
    static hrl::node *	get_shape_seven_top();
    static hrl::node *	get_shape_seven_middle();


};
#endif

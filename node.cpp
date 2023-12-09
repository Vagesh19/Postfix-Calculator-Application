#include "node.h"


Node::Node(bool sentinel)
{
    next = nullptr;
    prev = nullptr;
    is_sentinel = sentinel;
}

Node::Node(int v, Node *nxt, Node *prv)
{
    next = nxt;
    prev = prv;
    value = v;
    is_sentinel = false;
}

bool Node::is_sentinel_node()
{
    return is_sentinel;
}

int Node::get_value()
{
    return value;
}

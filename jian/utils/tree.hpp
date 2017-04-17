#pragma once

#include "yield.hpp"

BEGIN_JN

template<typename _Node>
struct TreeNodes : public IterBase {
    _Node *node, *p;
    TreeNodes *it;

    TreeNodes() : it(NULL), IterBase() {}

    _Node * operator ()() {
        itBegin;
        if (node != NULL) {
            yield_(node);
            it = new TreeNodes<_Node>;
            it->node = node->son;
            for (p = (*it)(); p != NULL; p = (*it)()) {
                yield_(p);
            }
            delete it;
            it = new TreeNodes<_Node>;
            it->node = node->bro;
            for (p = (*it)(); p != NULL; p = (*it)()) {
                yield_(p);
            }
        }
        return NULL;
        itEnd;
    }

    ~TreeNodes() {
        if (it) {
            delete it;
            it = NULL;
        }
    }
};

template<typename _Node>
TreeNodes<_Node> tree_nodes(_Node *node) {
    TreeNodes<_Node> a;
    a.node = node;
    return a;
}

template<typename _Node>
struct TreeSons : IterBase {
    _Node *node, *p;

    _Node *operator ()() {
        itBegin;
        for (p = node->son; p != NULL; p = p->bro) {
            yield_(p);
        }
        return NULL;
        itEnd;
    }
};

template<typename _Node>
TreeSons<_Node> tree_sons(_Node *node) {
    TreeSons<_Node> sons;
    sons.node = node;
    return sons;
}

template<typename _Node>
struct TreeBros : IterBase {
    _Node *node, *p;

    _Node *operator ()() {
        itBegin;
        for (p = node->bro; p != NULL; p = p->bro) {
            yield_(p);
        }
        return NULL;
        itEnd;
    }
};

template<typename _Node>
TreeBros<_Node> tree_bros(_Node *node) {
    TreeBros<_Node> bros;
    bros.node = node;
    return bros;
}

template<typename _Node>
void tree_free(_Node *node) {
    if (node == NULL) return;
    tree_free(node->son);
    tree_free(node->bro);
    delete node;
}

template<typename _Node>
_Node *tree_copy(_Node *node) {
    if (node == NULL) return NULL;
    _Node *n = new _Node(node);
    n->son = tree_copy(node->son);
    n->bro = tree_copy(node->bro);
    return n;
}

END_JN


/*
 * Copyright (C) 2018, Saul Lawliet <october dot sunbathe at gmail dot com>
 * All rights reserved.
 */

#ifndef C_DATA_STRUCTURES_BINARY_TREE_H_
#define C_DATA_STRUCTURES_BINARY_TREE_H_

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *treeNewNode(int val);
struct TreeNode *treeParse(const char *str);
char *treeToString(struct TreeNode *tree);
void treeFree(struct TreeNode *tree);

int treeHeight(struct TreeNode *tree);
int treeCount(struct TreeNode *tree);

#endif /* C_DATA_STRUCTURES_BINARY_TREE_H_ */

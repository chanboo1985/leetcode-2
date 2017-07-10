/*
 * Copyright (C) 2017, Saul Lawliet <october dot sunbathe at gmail dot com>
 * All rights reserved.
 *
 * 新学的写法 -> 指针的指针
 */

#include "../test.h"
#include "../data-structures/linked-list.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
  struct ListNode *head = NULL, **p = &head;
  while (l1 && l2) {
    if (l1->val <= l2->val) {
      *p = l1;
      l1 = l1->next;
    } else {
      *p = l2;
      l2 = l2->next;
    }
    p = &((*p)->next);
  }

  *p = l1 ? l1 : l2;
  return head;
}

void test(const char* expect, const char* s1, const char* s2) {
  struct ListNode* head = mergeTwoLists(linkedlistNewByStr(s1), linkedlistNewByStr(s2));
  EXPECT_EQ_STRING_AND_FREE_ACTUAL(expect, linkedlistToString(head));

  linkedlistFree(head);
}

int main(void) {
  test("1 -> 2 -> 3 -> 4", "1 -> 3", "2 -> 4");
  test("1 -> 3", "1 -> 3", "");

  return testOutput();
}

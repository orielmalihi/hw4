/*
 * trie.h
 *
 *  Created on: 7 Jan 2020
 *      Author: oriel
 */

#ifndef TRIE_H_
#define TRIE_H_

#define NUM_LETTERS ((int)26)
#define WORD_LENGTH 30

typedef enum {FALSE = 0, TRUE = 1} boolean;

typedef struct node {
	char letter;
	char word[WORD_LENGTH];
	long unsigned int count;
	struct node* children[NUM_LETTERS];
} node;

node* Trie_alloc();
void addWord(node* head, char* str);
void freeTrie(node* head);
void printTrie(node* head, int order);



#endif /* TRIE_H_ */

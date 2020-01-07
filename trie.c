/*
 * trie.c
 *
 *  Created on: 7 Jan 2020
 *      Author: oriel
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_LETTERS ((int)26)
#define WORD_LENGTH 30

typedef enum {FALSE = 0, TRUE = 1} boolean;

typedef struct node {
	char letter;
	char word[WORD_LENGTH];
	long unsigned int count;
	struct node* children[NUM_LETTERS];
} node;

node* Trie_alloc(){
	node* p = (node*)calloc(1,sizeof(node));
	return p;
}

void toLowerCase(char* str){
	for(int i=0; i<sizeof(str)/str[0]; i++){
		if(str[i]>= 65 && str[i]<= 90)
			str[i] += 32;
	}
}

void addWord(node* head, char* str){
	node* current = head;
	while(*str){
		char c = *str;
		if(current->children[c-97] == NULL){
			current->children[c-97] = (node*)calloc(1, sizeof(node));
			current->children[c-97]->letter = c;
			strcpy(current->children[c-97]->word, current->word);
			int index_last = strlen(current->children[c-97]->word);
			current->children[c-97]->word[index_last] = c;
//			current->children[c-97]->word[index_last+1] = 0;
		}
		current = current->children[c-97];
		str++;
	}
	current->count++;
}

void freeTrie(node* head){
	if(head == NULL)
		return;
	for(int i = 0; i<NUM_LETTERS; i++){
		freeTrie(head->children[i]);
	}
	free(head);
	return;
}

void printTrie(node* head, int order){

}





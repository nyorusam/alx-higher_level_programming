#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the head of the linked list
 * Return: 1 if it is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *current = *head;
    listint_t *stack = NULL;

    if (head == NULL || *head == NULL)
        return (1);

    // Traverse the linked list and push elements onto the stack
    while (current != NULL)
    {
        push(&stack, current->n);
        current = current->next;
    }

    current = *head;

    // Traverse the linked list again and compare with stack
    while (current != NULL)
    {
        int stack_value = pop(&stack);

        if (current->n != stack_value)
            return (0);

        current = current->next;
    }

    return (1);
}

/**
 * push - pushes a new element onto the stack
 * @head: double pointer to the head of the stack
 * @n: integer value to be pushed
 */
void push(listint_t **head, int n)
{
    listint_t *new_node = malloc(sizeof(listint_t));

    if (new_node == NULL)
        exit(EXIT_FAILURE);

    new_node->n = n;
    new_node->next = *head;
    *head = new_node;
}

/**
 * pop - pops an element from the stack
 * @head: double pointer to the head of the stack
 * Return: value popped from the stack
 */
int pop(listint_t **head)
{
    int value;
    listint_t *temp;

    if (*head == NULL)
        exit(EXIT_FAILURE);

    value = (*head)->n;
    temp = *head;
    *head = (*head)->next;
    free(temp);

    return value;
}


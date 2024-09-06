#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insert_node - Inserts a number into a sorted singly linked list.
 * @head: start of pointer
 * @number: new node
 * Return: address of the new element or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    // Create a new node to be inserted
    listint_t *new_node;
    // Initialize a pointer to the current node in the list
    listint_t *current;

    // Set the current node to the head of the list
    current = *head;

    // Allocate memory for the new node
    new_node = malloc(sizeof(listint_t));
    if (new_node)
    {
        // Initialize the new node's value and next pointer
        new_node->n = number;
        new_node->next = NULL;

        // Check if the list is empty or if the new node should be inserted at the head
        if (*head == NULL || (*head)->n >= new_node->n)
        {
            // Insert the new node at the head of the list
            new_node->next = *head;
            *head = new_node;
        }
        else
        {
            // Traverse the list to find the correct position for the new node
            while (current->next && current->next->n < new_node->n)
            {
                // Move to the next node in the list
                current = current->next;
            }
            // Insert the new node at the correct position
            new_node->next = current->next;
            current->next = new_node;
        }
        // Return the address of the new node
        return (new_node);
    }
    // Return NULL if memory allocation failed
    return (NULL);
}
#include "binary_trees.h"

/* Levelorder function declarations */
levelorder_queue_t *enqueue(levelorder_queue_t *queue, binary_tree_t *node);
levelorder_queue_t *dequeue(levelorder_queue_t *queue);

/**
 * enqueue - Enqueues a binary tree node to a level order traversal queue.
 *
 * @queue: Pointer to the queue.
 * @node: Pointer to the binary tree node to enqueue.
 *
 * Return: The updated queue.
 */
levelorder_queue_t *enqueue(levelorder_queue_t *queue, binary_tree_t *node)
{
	levelorder_queue_t *new_node, *tmp;

	new_node = malloc(sizeof(levelorder_queue_t));
	if (!new_node)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	if (!queue)
		return (new_node);

	tmp = queue;
	while (tmp->next)
		tmp = tmp->next;

	tmp->next = new_node;

	return (queue);
}

/**
 * dequeue - Removes the front node from the queue.
 *
 * @queue: Pointer to the front of the queue.
 *
 * Return: Pointer to the updated queue.
 */
levelorder_queue_t *dequeue(levelorder_queue_t *queue)
{
	levelorder_queue_t *temp = queue;

	if (queue != NULL)
	{
		queue = queue->next;
		free(temp);
	}

	return (queue);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *queue = NULL;
	binary_tree_t *node;

	if (!tree)
		return (0);

	queue = enqueue(queue, (binary_tree_t *)tree);
	while (queue)
	{
		node = queue->node;
		queue = dequeue(queue);

		if (!node)
		{
			while (queue)
			{
				node = queue->node;
				queue = dequeue(queue);

				if (node)
					return (0);
			}

			return (1);
		}

		queue = enqueue(queue, node->left);
		queue = enqueue(queue, node->right);
	}

	return (1);
}

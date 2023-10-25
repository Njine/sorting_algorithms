void check_tree(int *array, size_t size_init, size_t size, size_t i)
{
	int n, leftChild, rightChild;
	size_t leftIndex, rightIndex;

	leftIndex = i * 2 + 1;
	rightIndex = leftIndex + 1;
	leftChild = array[leftIndex];
	rightChild = array[rightIndex];

	if (leftIndex < size && rightIndex < size &&
		(leftChild >= rightChild && leftChild > array[i]) ||
		(leftIndex == size - 1 && leftChild > array[i]))
	{
		n = array[i];
		array[i] = leftChild;
		array[leftIndex] = n;
		print_array(array, size_init);
	}
	else if (leftIndex < size && rightIndex < size &&
		(rightChild > leftChild && rightChild > array[i]))
	{
		n = array[i];
		array[i] = rightChild;
		array[rightIndex] = n;
		print_array(array, size_init);
	}

	if (leftIndex < size - 1)
		check_tree(array, size_init, size, leftIndex);
	if (rightIndex < size - 1)
		check_tree(array, size_init, size, rightIndex);
}

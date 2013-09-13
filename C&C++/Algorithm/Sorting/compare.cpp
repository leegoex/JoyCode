bool less_than(int i, int j, int* counting)
{
	++ (*counting);
	return i < j;
}
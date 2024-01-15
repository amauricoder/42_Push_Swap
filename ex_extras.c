//Extras that i constructed but i am not using anymore due to refactoring and changes on the code and how the code works


//Calculate the quantity of moves that is possible to do it together
int	srt_calc_qtmvtg(t_stack *node)
{
	int qtmvtg;

	qtmvtg = 0;
	if (node->above_med == node->target->above_med)
	{
		if (node->index < node->target->index)
		{
			if (node->qt_mov_top < node->target->qt_mov_top)
				qtmvtg = node->qt_mov_top;
			else
				qtmvtg = node->target->qt_mov_top;
		}
		else if (node->index > node->target->index)
			qtmvtg = node->target->qt_mov_top;
		else
		{
			if (node->qt_mov_top > node->target->qt_mov_top)
				qtmvtg = node->target->qt_mov_top;
			else
				qtmvtg = node->qt_mov_top;
		}
	}
	else
		qtmvtg = 0;
	return (qtmvtg);
}

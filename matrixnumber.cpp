//find number in sorted array which each row  increases progressively as well as each column

bool FindInPartiallySortedMatrix(int *matrix, int columns, int rows, int number)
{
	bool find=false;
	if( (matrix!=NULL) && rows>0 && columns>0 )
	{
		int row=0;
		int column = columns-1;
		while( row<rows && column<columns )
		{
			if( maxtrix[row*columns + column] == number )
			{
				find=true;
				break;
			}
			else if( maxtrix[row*columns + column] > number )
			{
				--column;
			}
			else
			{
				++row;
			}
		}
	}
	return find;
}

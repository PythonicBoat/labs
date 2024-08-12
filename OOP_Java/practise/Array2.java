class Array2
{
	// Syntex for declaring Two Dimensional Array

	int[][]x;

	public void Array2()//it mean it is a constructor
	{
		// To Create The Array in the memory, the following statement can be used:

		x=new int[3][3];//four rows and four columns

		// This will create a two-dimensional array of 9 elements - four
		// rows and four columns.
		// To initialize this array, multiple for loops can be used.

		for(int i=0;i<3;i++)//row				// for row
		{
			for(int j=0;j<3;j++)//column			// For column
			{
				x[i][j]=0;
				//x[i]=i;
				System.out.println("The Value of the  "+i+" row and   "+j+"  column is   "+x[i][j]);
			}
		}
	}
	public static void main (String args[])
	{
		Array2 obj=new Array2();
		obj.Array2();
	}
}
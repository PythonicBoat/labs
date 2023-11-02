
class Array1
{
	//	To declare a single-dimensional array, the syntax is:
	//	data type[] variablename;
	// data type variablename [];
	//	Example

	int[]x;
	//int y[];

	//	The above statement will declare a variable that can hold an
	//	array of int type variables. After declaring the variable for
	//	the array, the array needs to be created in the memory. This
	//	can be done by using the new operator in the follwing way:

	public void Array1()	// Consttructor
	{
		x= new int[10];	//	This statement assigns ten contiguous memory
						//	locatoins of the type int to the variable x.
						//	The array can store ten elements.

		// Initializing the array can be done using the for loop as given below.

		for(int i=0;i<10;i++)
		{
			x[i]=0;
			//x[i]=i;

			//x[0]=0;
			//x[1]=0;
			//x[2]=0;

			System.out.println("The Value of the  "+i+" element  is now   "+x[i]);
		}
	}
	public static void main (String args[])
	{
		Array1 obj=new Array1();
		obj.Array1();
		//System.out.println((new int[2]).getClass());
		//System.out.println((new int[1]) instanceof Object);
		//int x[]=new int[2];
		//System.out.println(x instanceof Object);

	}
}
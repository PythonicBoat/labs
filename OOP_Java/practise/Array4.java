import java.io.*;
class Array4
{
	InputStreamReader isr;
	BufferedReader br;

	public Array4() throws IOException
	{
		isr= new InputStreamReader(System.in);
		br= new BufferedReader(isr);
		int x[][];
		int i,j;
		x=new int[4][4];
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				System.out.println("Enter the matrix value");
				x[i][j]=(Integer.parseInt(br.readLine()));
			}
		}
		System.out.println("The matrix created is");
		System.out.println("\n\n\n\n\n\n\n");
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				System.out.print(x[i][j]+ "   ");
			}
			System.out.println();
		}
	}
	static public  void  main(String args[]) throws IOException
	{
		Array4 obj=new Array4();
	}
}
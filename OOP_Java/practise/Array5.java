// Dynamic Matrix

import java.io.*;
class Array5
{
	InputStreamReader isr;
	BufferedReader br;
	int i,j,k;

	int x[][];

	public Array5() throws IOException
	{
		isr= new InputStreamReader(System.in);
		br= new BufferedReader(isr);

		System.out.println("Pls Enter the Size Of the Matrix\n\n");
		k=Integer.parseInt(br.readLine());
	}

	public void accept() throws IOException
	{
		x=new int[k][k];
		for(i=0;i<k;i++)
		{
			for(j=0;j<k;j++)
			{
				System.out.println("Now Enter the Values for Matrix");
				x[i][j]=Integer.parseInt(br.readLine());
			}
		}
	}
	public void display()
	{
		System.out.println("The Final Created Matrix Is");
		System.out.println("\n\n\n\n\n");
		for(i=0;i<k;i++)
		{
			for(j=0;j<k;j++)
			{
				System.out.print(x[i][j]+ "\t ");
			}
			System.out.println("\n\n");
		}
	}
	static public  void  main(String args[]) throws IOException
	{
		Array5 obj=new Array5();
		obj.accept();
		obj.display();
	}
}
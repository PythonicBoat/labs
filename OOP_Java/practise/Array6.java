// Dynamic Matrix

import java.io.*;
class Array6
{
	InputStreamReader isr;
	BufferedReader br;
	int i,j,k,l;
	int x[][];

	public Array6() throws IOException
	{
		isr= new InputStreamReader(System.in);
		br= new BufferedReader(isr);

		System.out.println("Pls Enter the Size Of the Matrix rows and cols both \n\n");
		k=Integer.parseInt(br.readLine());
		l=Integer.parseInt(br.readLine());
	}
	public void accept() throws IOException
	{
		x=new int[k][l];//i can give the size from the keyboard

		for(i=0;i<k;i++)//here k represents no of row
		{
			for(j=0;j<l;j++)//here l represents no of col
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
			for(j=0;j<l;j++)
			{
				System.out.print(x[i][j]+ "\t ");
			}
			System.out.println("\n\n");
		}
	}
	static public  void  main(String args[]) throws IOException
	{
		Array6 obj=new Array6();
		obj.accept();
		obj.display();
	}
}
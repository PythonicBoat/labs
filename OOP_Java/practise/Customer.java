//Customer.java
class Customer
{
 	String []custName;
 	String []custCellNo;
 	String []custPackage;
 	int []custAge;

 	public Customer()	//Construcotr
	{
		//Allocating Memory
		custName=new String[3];
		custCellNo=new String[3];
		custPackage=new String[3];
		custAge=new int[3];


		// Initialising Each Elements

		custName[0]="mmmm";	//one way of initialising.
		//custName[0]=new String("Mahendra");// another way of initialising.

		custCellNo[0]=new String("9437015466");
		custPackage[0]=new String("Standard");
		custAge[0]=22;

		custName[1]=new String("Mahendra");
		custCellNo[1]=new String("9437015466");
		custPackage[1]=new String("Standard");
		custAge[1]=22;

		custName[2]=new String("Mahendra");
		custCellNo[2]=new String("9437015466");
		custPackage[2]=new String("Standard");
		custAge[2]=22;

		//for(int i=0;i<3;i++)
		//{
			//custAge[i]=10;
		//}
	}
 	public void display()
 	{
		for(int ctr=0;ctr!=3;ctr++)
		{
 	    	System.out.println(custName[ctr]);
 	   		System.out.println(custCellNo[ctr]);
 	   		System.out.println(custPackage[ctr]);
 	   		System.out.println(custAge[ctr]);
 		}
	}
    public static void main(String args[])
    {
		Customer obj;
		obj = new Customer();
		obj.display();
    }
}

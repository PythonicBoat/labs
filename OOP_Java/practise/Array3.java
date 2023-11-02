//CustomerCollection.java
// Blue print class
class Customer
{
 	String custName;
 	String custCellNo;
 	String custPackage;
 	int custAge;

 	public void displayDetails()
 	{
 	   System.out.println(custName);
 	   System.out.println(custCellNo);
 	   System.out.println(custPackage);
 	   System.out.println(custAge);
 	}
}
//it is an implementation class
public class Array3
{
    Customer cobj[];// An Array Object is Created

    public Array3()//constructor
    {
        cobj = new Customer[3];// ihave created 3 array object

       for(int ctr=0;ctr != 3;ctr++)
       {
            cobj[ctr] = new Customer();//This is very very important here i am allocating memory to all the object
       }
     	cobj[0].custName="Tom";
       	cobj[0].custCellNo="9801014568";
        cobj[0].custPackage="Standard";
        cobj[0].custAge=27;

        cobj[1].custName="Carol";
        cobj[1].custCellNo="9851034342";
        cobj[1].custPackage="Standard";
        cobj[1].custAge=24;

        cobj[2].custName="Leonard";
        cobj[2].custCellNo="9643036348";
        cobj[2].custPackage="Executive";
        cobj[2].custAge=25;
    }
    public void displayCollection()
    {
		for(int ctr=0;ctr!=3; ctr++)
		{
  			cobj[ctr].displayDetails();
		}
    }
    public static void main(String arg1s[])
    {
		Array3 aobj=new Array3();
		aobj.displayCollection();
    }
}

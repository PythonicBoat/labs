// java otherpackage/Demo2

package otherpackage;

public class Demo2 {
    public static void main(String[] args) {
        OtherPackage op = new OtherPackage();
        op.doSomething(); // call a method on the object to use the variable
    }
}

class OtherPackage {
    public void doSomething() {
        // implementation of the method
    }
}

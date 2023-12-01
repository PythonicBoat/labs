// 10.	Define an interface Motor with a data member –capacity and two methods such
// as run() and consume(). Define a Java class ,Washing machine‟ which implements this interface and write the code to check the value of the interface data member thru an object of the class.                              

// Define the Motor interface
interface Motor {
    void run();
    void consume();
}

// Define the WashingMachine class that implements the Motor interface
class WashingMachine implements Motor {
    int capacity; // data member

    // Constructor to initialize capacity
    WashingMachine(int capacity) {
        this.capacity = capacity;
    }

    // Implement the run method
    public void run() {
        System.out.println("Washing machine is running.");
    }

    // Implement the consume method
    public void consume() {
        System.out.println("Washing machine is consuming electricity.");
    }

    // Method to check the value of the capacity data member
    public int getCapacity() {
        return this.capacity;
    }
}

// Test the WashingMachine class
public class p10 {
    public static void main(String[] args) {
        WashingMachine wm = new WashingMachine(10);
        wm.run();
        wm.consume();
        System.out.println("Capacity of the washing machine: " + wm.getCapacity());
    }
}
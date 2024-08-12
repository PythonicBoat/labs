// 5. Using ObjectInputStream and ObjectOutpputSteam write some value to the file than read from the file convert to string and display on the montor

import java.io.*;

class MyClass implements Serializable {
    private String message;

    public MyClass(String message) {
        this.message = message;
    }

    public String getMessage() {
        return message;
    }
}

public class p5 {
    public static void main(String[] args) {
        // Define the file name
        String fileName = "objectFile.dat";

        // Create an instance of MyClass
        MyClass myObject = new MyClass("Hello, ObjectInputStream and ObjectOutputStream!");

        try {
            // Write the object to the file using ObjectOutputStream
            ObjectOutputStream objectOutputStream = new ObjectOutputStream(new FileOutputStream(fileName));
            objectOutputStream.writeObject(myObject);
            objectOutputStream.close();

            // Read the object from the file using ObjectInputStream
            ObjectInputStream objectInputStream = new ObjectInputStream(new FileInputStream(fileName));
            MyClass readObject = (MyClass) objectInputStream.readObject();
            objectInputStream.close();

            // Convert the object to a string and display on the monitor
            String message = readObject.getMessage();
            System.out.println("Message from the file: " + message);

        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}

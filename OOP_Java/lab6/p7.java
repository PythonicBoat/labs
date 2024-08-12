// Use super keyword in method overriding.

class Animal {
    public void makeSound() {
        System.out.println("The animal makes a sound");
    }
}

class Dog extends Animal {
    @Override
    public void makeSound() {
        super.makeSound(); // calls the makeSound() method of the parent class
        System.out.println("The dog barks");
    }
}

public class p7 {
    public static void main(String[] args) {
        Dog myDog = new Dog();
        myDog.makeSound();
    }
}
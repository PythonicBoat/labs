class Animal {
    public void makeSound() {
        System.out.println("Some generic sound");
    }
}

class Dog extends Animal {
    @Override
    public void makeSound() {
        System.out.println("Bark");
    }
}

public class Main {
    public static void main(String[] args) {
        Animal myPet = new Dog(); // Polymorphism - myPet is a Dog but referred to as an Animal
        myPet.makeSound(); // Calls the makeSound() method of Dog
    }
}

interface Employee {
    void calculateSalary();
    void displayDetails();
}

class BaseEmployee implements Employee {
    String name;
    double salary;

    public BaseEmployee(String name) {
        this.name = name;
    }

    public void calculateSalary() {
        salary = 50000; // Assume a base salary of $50,000
    }

    public void displayDetails() {
        System.out.println("Name: " + name);
        System.out.println("Salary: $" + salary);
    }
}

class Manager extends BaseEmployee {
    double bonus;

    public Manager(String name, double bonus) {
        super(name);
        this.bonus = bonus;
    }

    @Override
    public void calculateSalary() {
        super.calculateSalary(); // Call the base class method
        salary += bonus; // Add the bonus to the salary
    }
    
    public void displayDetails() {
        super.displayDetails(); // Call the base class method
        System.out.println("Bonus: $" + bonus);
    }
}

public class inherit {
    public static void main(String[] args) {
        Employee employee1 = new BaseEmployee("John Doe");
        Employee employee2 = new Manager("Jane Smith", 10000);

        employee1.calculateSalary();
        employee1.displayDetails();

        employee2.calculateSalary();
        employee2.displayDetails();
    }
}

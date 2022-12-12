package carfactory;

import java.util.Scanner;

import carfactory.Car.Car;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("Welcome to the Car Manufacturing System.");
            System.out.println("Please chose your continental location: ");
            System.out.println("1) Asia");
            System.out.println("2) Europe");
            System.out.println("3) America");
            String s = scanner.nextLine();
            String continent = null;
            CarFactory carFactory = new CarFactory();
            if (s.equals("1")) continent = "Asia";
            else if (s.equals("2")) continent = "Europe";
            else if (s.equals("3")) continent = "America";
            else {
                System.out.println("Invalid input");
                continue;
            }

            Car c = carFactory.getCar(continent);
            System.out.println("\nCar Details: ");
            c.print();
            break;
        }
        scanner.close();
        System.exit(0);
    }
}

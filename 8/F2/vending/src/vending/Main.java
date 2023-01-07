package vending;

import java.util.Scanner;

public class Main {

    public static Scanner scanner = new Scanner(System.in);

    public static int scanInt() {
        int r;
        while (true) {
            try {
                r = Integer.parseInt(scanner.nextLine());
                break;
            } catch (NumberFormatException nfe) {
                System.out.println("Invalid input, try again.");
            }
        }
        return r;
    }

    public static void main(String[] args) throws Exception {
        System.out.println("Welcome to Vending Machine Setup.");
        int count, value;
        System.out.println("Enter the unit price of product: ");
        value = scanInt();
        System.out.println("Enter the no. of units as initial capacity of vending machine: ");
        count = scanInt();

        VendingMachine machine = new VendingMachine(count, value);
        System.out.println("Beginning machine operation...");
        while (machine.getCount() > 0) {
            while (machine.getCount() > 0) {
                System.out.println("\n" + machine.getCount() + " items in stock.");
                System.out.println("Enter the value of money to be inserted. Or, enter 0 to press the dispense button.");
                int money = scanInt();
                if (money < 0) System.out.println("Invalid value inserted, try again.");
                else if (money == 0) machine.dispenseProduct();
                else machine.insertMoney(money);
                System.out.println("");
            }
            System.out.println("Enter the no. of products to refill the machine. Or, enter 0 to quit.");
            int refill = scanInt();
            if (refill < 0) System.out.println("Invalid value inserted, try again.");
            else if (refill > 0) machine.refillMachine(refill);
        } 

        scanner.close();
        System.exit(0);
    }
}

package shakebuilder;
import java.util.*;

import shakebuilder.Builder.Director;
import shakebuilder.Builder.IBuilder;
import shakebuilder.Builder.CoffeeShake;
import shakebuilder.Builder.ChocolateShake;
import shakebuilder.Builder.ZeroShake;
import shakebuilder.Shake.Shake;


public class Main {
    public static void main (String[] args) {
        System.out.println("Welcome to Milkshake Manufacturing System.");
        Director dtor = new Director();
        Scanner scanner = new Scanner(System.in);
        String i1;

        while (true) {
            System.out.println("Enter 'O' to open an order. Enter Q to quit.");
            i1 = scanner.nextLine();

            if (i1.equalsIgnoreCase("O")) {
                LinkedList<Shake> items = new LinkedList<Shake>();  
                order: {
                    while (true) {
                        IBuilder builder = null;  
                        System.out.println("Please select numbers 1-4 to order any of the shakes below. Enter E to close order.");
                        System.out.println("1) Coffee_Shake");
                        System.out.println("2) Chocolate_Shake");
                        System.out.println("3) Zero Shake");
                        String i2 = scanner.nextLine();
                        if (i2.equalsIgnoreCase("O")) {
                            System.out.println ("An order is already ongoing. Would you like to add anything to the running order? ");
                        } else if (i2.equalsIgnoreCase("E")) {
                            if (items.size() == 0) System.out.println("Add at least one item to running order.");
                            else {
                                System.out.println("Exiting order.");
                                break order;
                            }
                        } else if (i2.trim().equals("1") || i2.trim().equals("2") || i2.trim().equals("3") || i2.trim().equals("4")) {
                            if (i2.trim().equals("1")) {
                                builder = new CoffeeShake(); 
                            } else if (i2.trim().equals("2")) {
                                builder = new ChocolateShake(); 
                            } else if (i2.trim().equals("3")) {
                                builder = new ZeroShake(); 
                            }
                            dtor.construct (builder);

                            custom: {
                                while (true) {
                                    System.out.println("You may add any of the following custom ingredients. Press C to finish.");
                                    System.out.println("1) Make lactose free / Add MORE almond milk");
                                    System.out.println("2) Cookies");
                                    System.out.println("3) Candy");
                                    String i3 = scanner.nextLine();
                                    if (i3.trim().equals("1")) dtor.removeLactose();
                                    else if (i3.trim().equals("2")) dtor.addCookies();
                                    else if (i3.trim().equals("3")) dtor.addCandy();
                                    else if (i3.trim().equalsIgnoreCase("C")) {
                                        System.out.println("Finished adding parts.");
                                        break custom;
                                    } else {
                                        System.out.println("Invalid input.");
                                    }
                                }
                            }

                            items.addLast(builder.getShake());
                            System.out.println("Item added successfully. You may add another item.");
                        } else System.out.println("Invalid intput.");
                    }
                }
                System.out.println("\n=======================================");
                System.out.println("Order summary: ");
                System.out.println("=======================================");
                for (Shake c : items) c.printDetails();
            } else if (i1.equalsIgnoreCase("E")) {
                System.out.println("There are no running orders to close now.");
            } else if (i1.equalsIgnoreCase("Q")) {
                break;
            } else System.out.println("Input not recognised");
        }
        scanner.close();
        System.exit(0);
    }
}

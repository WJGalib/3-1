package pcbuilder;
import java.util.*;

import pcbuilder.Builder.Director;
import pcbuilder.Builder.IBuilder;
import pcbuilder.Builder.Intel1Builder;
import pcbuilder.Builder.Intel2Builder;
import pcbuilder.Builder.Intel3Builder;
import pcbuilder.Builder.RyzenBuilder;
import pcbuilder.Computer.Computer;


public class Main {
    public static void main (String[] args) {
        System.out.println("Welcome to PC Manufacturing System.");
        Director dtor = new Director();
        Scanner scanner = new Scanner(System.in);
        String i1;

        while (true) {
            System.out.println("Enter 'O' to open an order. Enter Q to quit.");
            i1 = scanner.nextLine();

            if (i1.equalsIgnoreCase("O")) {
                LinkedList<Computer> items = new LinkedList<Computer>();  
                order: {
                    while (true) {
                        IBuilder builder = null;  
                        System.out.println("Please select numbers 1-4 to order any of the PC bundles below. Enter E to close order.");
                        System.out.println("1) AMD Ryzen 7 5700X Gaming PC");
                        System.out.println("2) Intel Core-i5 11th Gen PC");
                        System.out.println("3) Intel Core-i7 11th Gen PC");
                        System.out.println("4) Intel Core-i9 11th Gen PC");
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
                                builder = new RyzenBuilder(); 
                            } else if (i2.trim().equals("2")) {
                                builder = new Intel1Builder(); 
                            } else if (i2.trim().equals("3")) {
                                builder = new Intel2Builder(); 
                            } else if (i2.trim().equals("4")) {
                                builder = new Intel3Builder(); 
                            } 
                            dtor.construct (builder);

                            custom: {
                                while (true) {
                                    System.out.println("You may add any of the following custom parts. Press C to finish.");
                                    System.out.println("1) 8GB DDR4 RAM 2666MHz");
                                    System.out.println("2) 8GB DDR4 RAM 3200MHz");
                                    System.out.println("3) 2GB Graphics");
                                    System.out.println("4) 4GB Graphics");
                                    String i3 = scanner.nextLine();
                                    if (i3.trim().equals("1")) dtor.addMem2666(builder);
                                    else if (i3.trim().equals("2")) dtor.addMem3200(builder);
                                    else if (i3.trim().equals("3")) dtor.addGraphics2G(builder);
                                    else if (i3.trim().equals("4")) dtor.addGraphics4G(builder);
                                    else if (i3.trim().equalsIgnoreCase("C")) {
                                        System.out.println("Finished adding parts.");
                                        break custom;
                                    } else {
                                        System.out.println("Invalid input.");
                                    }
                                }
                            }

                            items.addLast(builder.getComputer());
                            System.out.println("Item added successfully. You may add another item.");
                        } else System.out.println("Invalid intput.");
                    }
                }
                System.out.println("\n=======================================");
                System.out.println("Order summary: ");
                System.out.println("=======================================");
                for (Computer c : items) c.printDetails();
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

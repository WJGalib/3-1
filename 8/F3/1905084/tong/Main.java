package tong;

import java.util.ArrayList;
import java.util.Scanner;

import tong.Coffee.BlackCoffee;
import tong.Coffee.Coffee;
import tong.Coffee.MilkCoffee;
import tong.Condiment.ChocolateSauce;
import tong.Condiment.CinnamonPowder;
import tong.Condiment.DairyCream;
import tong.Condiment.GrindedCoffeeBeans;

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

        while (true) {
            System.out.println("\n——————————————————");
            System.out.println("Welcome to কফির টং!");
            System.out.println("——————————————————\n");
            ArrayList<Coffee> order = new ArrayList<Coffee>();
            System.out.println("1) New Order");
            System.out.println("2) Quit");

            int j = scanInt();
            if (j == 2) break;
            else if (j != 1) {
                System.out.println("Invalid input, try again.");
                continue;
            }
            while (true) {
                System.out.println("Enter an option to add a coffee to your order. (Enter 0 to end the order)");
                System.out.println("1) Americano");
                System.out.println("2) Espresso");
                System.out.println("3) Cappuccino");
                System.out.println("4) Mocha");

                Coffee c = null;
                int input = scanInt();
                if (input == 1) {
                    c = new BlackCoffee();
                    c = new GrindedCoffeeBeans(c);
                    c.setTitle("Americano");
                    order.add(c);
                } else if (input == 2) {
                    c = new BlackCoffee();
                    c = new DairyCream(c);
                    c.setTitle("Espresso");
                    order.add(c);
                } else if (input == 3) {
                    c = new MilkCoffee();
                    c = new CinnamonPowder(c);
                    c.setTitle("Cappuccino");
                    order.add(c);
                } else if (input == 4) {
                    c = new MilkCoffee();
                    c = new ChocolateSauce(c);
                    c.setTitle("Mocha");
                    order.add(c);
                } else if (input == 0) {
                    System.out.println("==============");
                    System.out.println("Order Summary");
                    System.out.println("==============");
                    double total = 0;
                    for (Coffee cof : order) {
                        System.out.println("———————————————————————————————————");
                        System.out.println((order.indexOf(cof)+1) + ") " + cof.getTitle() + " — " + cof.cost() + "taka\n");
                        System.out.println("———————————————————————————————————");
                        System.out.println(cof.getDesc());
                        total += cof.cost();
                    }
                    System.out.println("\nORDER TOTAL: " + total + " taka.");
                    break;
                } else System.out.println("Invalid input, try again.");
            }

        }

        scanner.close();
        System.exit(0);
    }
}

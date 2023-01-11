package server;

import java.util.Scanner;

public class Input {
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
}

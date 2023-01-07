package server;

import java.util.ArrayList;

import server.Observer.PremiumUser;
import server.Observer.RegularUser;
import server.Observer.User;
import server.Subject.CompanyServer;



public class Main {


    public static void main(String[] args) throws Exception {

        System.out.println("\n———————————————————————————————————————");
        System.out.println("Welcome to the ABC Server Simulator");
        System.out.println("———————————————————————————————————————\n");

        CompanyServer abc = new CompanyServer();
        ArrayList<User> users = new ArrayList<User>();

        users.add (new PremiumUser(abc, "Jack"));
        users.add (new RegularUser(abc, "John"));
        System.out.println("Starting with 1 premium and 1 regular user, with server operational.");

        while (true) {
            System.out.println("\nEnter any of the following options: ");
            System.out.println("1) Change server state");
            System.out.println("2) Add regular user");
            System.out.println("3) Add premium user");
            System.out.println("4) Remove user");
            System.out.println("5) Exit");
            int input = Input.scanInt();
            
            if (input == 1) {
                System.out.println("Select state: ");
                for (int i=0; i<ServerState.values().length; i++) 
                    System.out.println((i+1) + ") " + ServerState.values()[i].getName());
                int s = Input.scanInt();
                abc.setCurrState(ServerState.values()[s-1]);
            } else if (input == 2 || input == 3) {
                System.out.print("Enter username: ");
                String name = Input.scanner.nextLine();

                User d = null;
                for (User u : users) if (u.getName().equalsIgnoreCase(name)) d = u;
                if (d == null) {
                    if (input == 2) users.add (new RegularUser(abc, name));
                    else if (input == 3) users.add (new PremiumUser(abc, name));
                    System.out.println("User " + name + " added!");
                } else {
                    System.out.println("Username " + name + " already exists!");
                }
            } else if (input == 4) {
                System.out.print("Enter username to delete: ");
                String name = Input.scanner.nextLine();
                User d = null;
                for (User u : users) if (u.getName().equalsIgnoreCase(name)) d = u;
                if (d != null) {
                    abc.removeObserver(name);
                    users.remove(d);
                    System.out.println("User " + name + " removed.");
                } else {
                    System.out.println("Username " + name + " not found!");
                }
            } else if (input == 5) {
                break;
            } else {
                System.out.println("Invalid selection, try again");
            }
        }

        Input.scanner.close();
        System.exit(0);
    }
}

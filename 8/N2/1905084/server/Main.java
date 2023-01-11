package server;

import java.util.ArrayList;

import server.Observer.RegularUser;
import server.Observer.User;
import server.Subject.CompanyServer;



public class Main {


    public static void main(String[] args) throws Exception {

        System.out.println("\n———————————————————————————————————————");
        System.out.println("Welcome to the Weather Forecast Simulator");
        System.out.println("———————————————————————————————————————\n");

        CompanyServer abc = new CompanyServer();
        ArrayList<User> users = new ArrayList<User>();

        users.add (new RegularUser(abc, "Jack"));
        users.add (new RegularUser(abc, "John"));
        System.out.println("Starting with 2 users, with sunny 25 degree C.");

        while (true) {
            System.out.println("\nEnter any of the following options: ");
            System.out.println("1) Change weather ");
            System.out.println("2) Add user");
            System.out.println("3) Remove user");
            System.out.println("4) Exit");
            int input = Input.scanInt();
            
            if (input == 1) {
                System.out.println("Select state: ");
                for (int i=0; i<WeatherState.values().length; i++) 
                    System.out.println((i+1) + ") " + WeatherState.values()[i].getName());
                int s = Input.scanInt();
                System.out.println("Enter temperature: ");
                int tem = Input.scanInt();
                abc.setCurrState(WeatherState.values()[s-1], tem);
            } else if (input == 2) {
                System.out.print("Enter username: ");
                String name = Input.scanner.nextLine();

                User d = null;
                for (User u : users) if (u.getName().equalsIgnoreCase(name)) d = u;
                if (d == null) {
                    users.add (new RegularUser(abc, name));
                    System.out.println("User " + name + " added!");
                } else {
                    System.out.println("Username " + name + " already exists!");
                }
            } else if (input == 3) {
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
            } else if (input == 4) {
                break;
            } else {
                System.out.println("Invalid selection, try again");
            }
        }

        Input.scanner.close();
        System.exit(0);
    }
}

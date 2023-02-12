package hierarchy;

import java.util.ArrayList;
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

        System.out.println("\n—————————————————————————————————————————————————");
        System.out.println("Welcome to the Software Company Management System!");
        System.out.println("—————————————————————————————————————————————————\n");

        ArrayList<SoftwareCompany> companies = new ArrayList<SoftwareCompany>();

        while (true) {

            System.out.println("Enter Option: ");
            System.out.println("1) Add Company");
            System.out.println("2) Add Project Manager");
            System.out.println("3) Add Developer");
            System.out.println("4) Remove Developer");
            System.out.println("5) Remove Project Manager");
            System.out.println("6) Remove Company");
            System.out.println("7) Show Developer Details");
            System.out.println("8) Show Project Manager Details");
            System.out.println("9) Show Company Details");
            System.out.println("10) Show Project Manager hierarchy");
            System.out.println("11) Show Company hierarchy");
            System.out.println("0) Exit");

            int input = scanInt();

            if (input == 1) {
                System.out.println("Enter name of company: ");
                String name = scanner.nextLine();
                boolean add = true;
                for (SoftwareCompany s : companies) if (s.getName().equalsIgnoreCase(name)) {
                    System.out.println("Company already exists!");
                    add = false;
                }
                if (add) companies.add(new SoftwareCompany(name));

            } else if (input == 2) {
                System.out.println("Select Company");
                for (SoftwareCompany s : companies) {
                    System.out.println((companies.indexOf(s)+1) + ") " + s.getName()) ;
                }
                int comp = scanInt();
                SoftwareCompany scomp = null;
                if (comp >=1 && comp <= companies.size()) {
                    scomp = companies.get(comp - 1);
                } else continue;
                System.out.println("Enter Project Manager Name: ");
                String name = scanner.nextLine();
                System.out.println("Enter Project Name: ");
                String proj = scanner.nextLine();
                if (scomp.addProject(new ProjectManager(name, proj))) System.out.println("Successfully added");
                else System.out.println("Failed to add");

            } else if (input == 3) {
                System.out.println("Select Company");
                for (SoftwareCompany s : companies) {
                    System.out.println((companies.indexOf(s)+1) + ") " + s.getName()) ;
                }
                int comp = scanInt();
                SoftwareCompany scomp = null;
                if (comp >=1 && comp <= companies.size()) {
                    scomp = companies.get(comp - 1);
                } else continue;

                System.out.println("Select Project");
                for (Component p : scomp.getChildren()) {
                    System.out.println((scomp.getChildren().indexOf(p)+1) + ") " + p.getProj()) ;
                }
                int proj = scanInt();
                ProjectManager projman = null;
                if (proj >=1 && proj <= scomp.getChildren().size()) {
                    projman = (ProjectManager)scomp.getChildren().get(proj - 1);
                } else continue;

                System.out.println("Enter Developer Name: ");
                String name = scanner.nextLine();
                if (projman.addDeveloper(new Developer(name, projman.getProj()))) System.out.println("Successfully added");
                else System.out.println("Failed to add");

            } else if (input == 4) {
                System.out.println("Select Company");
                for (SoftwareCompany s : companies) {
                    System.out.println((companies.indexOf(s)+1) + ") " + s.getName()) ;
                }
                int comp = scanInt();
                SoftwareCompany scomp = null;
                if (comp >=1 && comp <= companies.size()) {
                    scomp = companies.get(comp - 1);
                } else continue;

                System.out.println("Select Project");
                for (Component p : scomp.getChildren()) {
                    System.out.println((scomp.getChildren().indexOf(p)+1) + ") " + p.getProj()) ;
                }
                int proj = scanInt();
                ProjectManager projman = null;
                if (proj >=1 && proj <= scomp.getChildren().size()) {
                    projman = (ProjectManager)scomp.getChildren().get(proj - 1);
                } else continue;

                System.out.println("Enter Developer Name: ");
                String name = scanner.nextLine();
                if (projman.removeDeveloper(name)) System.out.println("Successfully removed");
                else System.out.println("Failed to remove");

            } else if (input == 5) {
                System.out.println("Select Company");
                for (SoftwareCompany s : companies) {
                    System.out.println((companies.indexOf(s)+1) + ") " + s.getName()) ;
                }
                int comp = scanInt();
                SoftwareCompany scomp = null;
                if (comp >=1 && comp <= companies.size()) {
                    scomp = companies.get(comp - 1);
                } else continue;
                System.out.println("Enter Project Manager Name: ");
                String name = scanner.nextLine();
                if (scomp.removeProject(name)) System.out.println("Successfully removed");
                else System.out.println("Failed to remove");
            
            } else if (input == 6) {
                    System.out.println("Enter name of company: ");
                String name = scanner.nextLine();
                boolean del = false;
                SoftwareCompany scomp = null;
                for (SoftwareCompany s : companies) if (s.getName().equalsIgnoreCase(name)) {
                    scomp = s;
                    del = true;
                }
                if (del) companies.remove(scomp);
                else System.out.println("Company not found!");

            } else if (input >= 7 && input <= 11) {
                System.out.println("Select Company");
                for (SoftwareCompany s : companies) {
                    System.out.println((companies.indexOf(s)+1) + ") " + s.getName()) ;
                }
                int comp = scanInt();
                SoftwareCompany scomp = null;
                if (comp >=1 && comp <= companies.size()) {
                    scomp = companies.get(comp - 1);
                } else continue;

                if (input == 9) {
                    scomp.showDetails();
                    continue;
                } else if (input == 11) {
                    scomp.showHierarchy();
                    continue;
                }

                System.out.println("Select Project");
                for (Component p : scomp.getChildren()) {
                    System.out.println((scomp.getChildren().indexOf(p)+1) + ") " + p.getProj()) ;
                }
                int proj = scanInt();
                ProjectManager projman = null;
                if (proj >=1 && proj <= scomp.getChildren().size()) {
                    projman = (ProjectManager)scomp.getChildren().get(proj - 1);
                } else continue;

                if (input == 8) {
                    projman.showDetails();
                    continue;
                } else if (input == 10) {
                    projman.showHierarchy();
                    continue;
                }


                System.out.println("Select Developer");
                for (Component d : projman.getChildren()) {
                    System.out.println((projman.getChildren().indexOf(d)+1) + ") " + d.getName()) ;
                }
                int d = scanInt();
                Developer dev = null;
                if (d >=1 && d <= projman.getChildren().size()) {
                    dev = (Developer)projman.getChildren().get(d - 1);
                } else continue;

                if (input == 7) {
                    dev.showDetails();
                    continue;
                }

            } else if (input == 0) break;

        }
        scanner.close();
        System.exit(0);
    }
}

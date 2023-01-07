package exam;

import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

import exam.Person.Examiner;
import exam.Person.Student;

public class Main {


    public static void main(String[] args) throws Exception {

        Scanner scanner = new Scanner(System.in);
        Random rand = new Random();
        System.out.println("\n———————————————————————————————————————");
        System.out.println("Welcome to the Exam Controller Office.");
        System.out.println("———————————————————————————————————————\n");

        ExamController ec = new ExamController();
        ArrayList<Student> students = new ArrayList<Student>();
        ArrayList<Score> scores = new ArrayList<Score>();
        ArrayList<Integer> ids = new ArrayList<>();
        for (int i=0; i<5; i++) {
            int id = 1905001 + rand.nextInt(120);
            while (ids.contains(id)) id = 1905001 + rand.nextInt(120);
            students.add(new Student(ec, Integer.toString(id)));
            scores.add(new Score(students.get(i), 20 + rand.nextInt(81)));
        };
        Examiner examiner = new Examiner(ec, "Mr. Rashid Khan");
        ec.setExaminer(examiner);
        examiner.sendForScrutiny(scores);

        System.out.println("\n---------------------");
        System.out.println("Apply for re-examine");
        System.out.println("---------------------");

        for (int i=0; i<5; i++) {
            while (true) {
                System.out.print("\nDoes " + students.get(i).getName() + " want to apply? [y/N]: ");
                String input = scanner.nextLine();
                if (input.strip().equalsIgnoreCase("Y")) {
                    students.get(i).challenge(scores.get(i));
                    break;
                } else if (!(input.strip().equalsIgnoreCase("N") || input.strip().isEmpty()))
                    System.out.print("Invalid input, try again!");
                else break;
            }
        }

        scanner.close();
        System.exit(0);
    }
}

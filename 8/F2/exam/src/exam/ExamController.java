package exam;

import java.util.ArrayList;
import java.util.Random;

import exam.Person.Person;
import exam.Person.Examiner;
import exam.Person.Student;

public class ExamController implements Mediator {
    
    // ArrayList<Student> students = new ArrayList<Student>();

    // public void setStudents (ArrayList<Student> students) {
    //     this.students = students;
    // }

    // public void addStudent (Student s) {
    //     this.students.add(s);
    // }

    Examiner examiner;

    public void setExaminer (Examiner examiner) {
        this.examiner = examiner;
    }

    public void sendFrom (Person p, Score s) {
        if (p instanceof Examiner) {
            System.out.println("Sending score to " + s.getStudent().getName() + " from Exam Controller...");
            s.getStudent().announce(s);
        } else if (p instanceof Student) {
            System.out.println("Sending " + p.getName() + "'s script to " + this.examiner.getName() + " from Exam Controller...");
            examiner.announce(s);
        }
    }


    public void scrutinizeAndSend (Examiner e, ArrayList<Score> scores) {
        System.out.print("EC received scripts and marks of ");
        for (Score s : scores) System.out.print(s.getStudent().getName() + ", ");
        System.out.print("\b\b from Examiner " + e.getName() + ".\n");

        Random rand = new Random();                 // Randomising errors in marking...
        int sum = 0, n = scores.size();             // .
        boolean[] error = new boolean[n];                   // .
        for (int i=0; i<n; i++) {                   // .
            error[i] = rand.nextBoolean();             // .
            sum += (error[i]? 1 : 0);                        // .
        };                  
        if (sum == 0) error[rand.nextInt(5)] = true;   // forcing at least one error
        for (int i=0; i<n; i++) {
            int newVal = 20 + rand.nextInt(81);
            if (error[i]) {
                System.out.println("\nError found in " + scores.get(i).getStudent().getName() + "'s script during scrutiny, correcting...");
                System.out.println("Previous score: " + scores.get(i).getValue() + ", Corrected score: " + newVal + "\n");
                scores.get(i).correctValue(newVal);
            }
            sendFrom (e, scores.get(i));
        }
    }

    public void sendForRecheck (Student st, Score score) {
        System.out.println("EC received a re-examining request from " + st.getName());
        sendFrom(st, score);
        examiner.recheck(score);
    }

    public void sendAfterRecheck (Examiner e, Score s) {
        System.out.println("EC received update on " + s.getStudent().getName() + "'s re-examine from Examiner " + examiner.getName());
        sendFrom(e, s);
    }

}

package exam.Person;

import exam.Score;

import java.util.ArrayList;
import java.util.Random;

import exam.ExamController;
import exam.Mediator;

public class Examiner extends Person {

    public Examiner (Mediator mediator, String name) {
        super(mediator);
        this.name = name;
    }

    public void sendForScrutiny (ArrayList<Score> scores) {
        System.out.print("Examiner " + this.getName() + " sending scripts and marks of ");
        for (Score s : scores) System.out.print(s.getStudent().getName() + ", ");
        System.out.print("\b\b to the Exam Conroller Office...\n");

        ((ExamController)mediator).scrutinizeAndSend(this, scores);
    }

    public void sendAfterRecheck (Score score) {
        ((ExamController)mediator).sendAfterRecheck(this, score);
    }

    public void announce (Score s) {
        System.out.println("Examiner " + name + " has received a re-examination request from " + s.getStudent().getName());
    } 

    public void recheck (Score s) {
        System.out.println("Examiner " + name + " is rechecking " + s.getStudent().getName() + "'s script...");
        Random rand = new Random(); 
        s.updateValue(rand.nextInt(101));
        sendAfterRecheck(s);
    }

}

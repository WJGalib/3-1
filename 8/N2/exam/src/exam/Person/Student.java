package exam.Person;

import exam.Score;
import exam.ExamController;
import exam.Mediator;

public class Student extends Person {
    
    public Student (Mediator mediator, String name) {
        super(mediator);
        this.name = name;
    }

    public void challenge (Score s) {
        System.out.println(this.name + " is applying to the Exam Controller for re-examine...");
        ((ExamController)mediator).sendForRecheck(this, s);
    }

    public void announce (Score s) {
        System.out.println(name + " has received a score of " + s.getValue());
        if (s.getChange()) System.out.println ("(The score was updated.)");
    } 
}

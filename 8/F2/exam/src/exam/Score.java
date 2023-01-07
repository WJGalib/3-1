package exam;

import exam.Person.Student;

public class Score {
    Student student;
    int value;
    boolean change;

    public Score (Student student, int value) {
        this.student = student;
        this.value = value;
        this.change = false;
    }

    public Student getStudent() {
        return this.student;
    }

    public int getValue() {
        return this.value;
    }

    public boolean getChange() {
        return this.change;
    }

    public void correctValue (int value) {
        this.value = value;
    }

    public void updateValue (int value) {
        if (this.value != value) {
            this.change = true;
            System.out.println(student.getName() + "'s score is being updated to " + value + " from " + this.value);
        }
        this.value = value;
    }
    
}

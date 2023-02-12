package hierarchy;

import java.util.ArrayList;

public abstract class Component {
    String name;
    String role;
    String proj;
    ArrayList<Component> children;

    public Component (String name, String role, String proj) {
        this.name = name;
        this.role = role;
        this.proj = proj;
        children = new ArrayList<Component>();
    }

    public String getName() {
        return this.name;
    }

    public String getRole() {
        return this.role;
    }

    public String getProj() {
        return this.proj;
    }

    public void setName (String name) {
        this.name = name;
    }

    public void setRole (String role) {
        this.role = role;
    }

    public void setProj (String proj) {
        this.proj = proj;
    }

    public ArrayList<Component> getChildren() {
        return this.children;
    }

    public void showDetails() {
        System.out.println("Name: " + name);
        System.out.println("Role: " + role);
        if (!(this instanceof SoftwareCompany)) System.out.println("Current Project: " + proj);
        if (this.children != null && this.children.size()>0) System.out.println("No. of Supervisees: " + this.children.size());
    }


    public void printComponent (int depth) {
        for (int i=0; i<depth; i++) System.out.print("\t");
        System.out.print("– " + getName());
        if (this instanceof ProjectManager) System.out.print(" (" + this.getProj() + ")");
        System.out.println();
    } 


}
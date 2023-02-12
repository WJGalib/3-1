package hierarchy;

public abstract class Composite extends Component {

    public Composite (String name, String role, String proj) {
        super(name, role, proj);
    }

    public boolean addChild (Component c) {
        for (Component com : this.getChildren()) {
            if (com.getName().equalsIgnoreCase(c.getName())) {
                System.out.println(com.getRole() + " " + com.getName() + " already exists under " + this.getName() + ", cannot be added.");
                return false;
            } else if (this instanceof SoftwareCompany && com.getProj().equalsIgnoreCase(c.getProj())) {
                System.out.println(com.getRole() + " " + com.getName() + " already exists under " + this.getProj() + ", cannot be added.");
                return false;
            }
        }
        getChildren().add(c);
        return true;
    }

    public boolean removeChild (String name) {
        for (Component com : this.getChildren()) {
            if (com.getName().equalsIgnoreCase(name)) {
                if (com.getChildren() == null || com.getChildren().size() == 0) {
                    this.getChildren().remove(com);
                    return true;
                } else {
                    System.out.println(this.getRole() + " " + this.getName() + " still has supervisees, cannot be deleted.");
                    return false; 
                }
            }
        }
        return false;
    }

    public void showHierarchy (int depth) {
        if (this.getChildren() != null && this.getChildren().size()>0) 
            for (Component c: this.getChildren()) {
                c.printComponent(depth);
                if (c instanceof Composite) ((Composite)c).showHierarchy(depth+1);
            }
    }

    public void showHierarchy() {
        this.printComponent(0);
        this.showHierarchy(1);
    }
}
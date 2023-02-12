package hierarchy;

public class SoftwareCompany extends Composite {
    public SoftwareCompany (String name) {
        super (name, "Software Company", null);
    }

    public boolean addProject (ProjectManager p) {
        return this.addChild((Component)p);
    }

    public boolean removeProject (String name) {
        return this.removeChild (name);
    }
}

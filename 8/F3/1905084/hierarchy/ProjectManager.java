package hierarchy;

public class ProjectManager extends Composite {
    public ProjectManager (String name, String proj) {
        super (name, "Project Manager", proj);
    }

    public boolean addDeveloper (Developer d) {
        return this.addChild((Component)d);
    }

    public boolean removeDeveloper (String name) {
        return this.removeChild (name);
    }
}

package hierarchy;

public abstract class Leaf extends Component {

    public Leaf (String name, String role, String proj) {
        super(name, role, proj);
        children = null;
    }
}
package server;

public enum ServerState {

    OPERATIONAL {
        @Override
        public String getName() {
            return "Operational";
        } 
    },
    PARTIAL_DOWN {
        @Override
        public String getName() {
            return "Partially Down";
        } 
    },
    FULL_DOWN {
        @Override
        public String getName() {
            return "Fully Down";
        } 
    };

    public abstract String getName();

}

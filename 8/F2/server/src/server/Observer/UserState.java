package server.Observer;

public enum UserState {
    ONSITE {
        @Override
        public String getName() {
            return "Operating fully on ABC Server";
        } 
    },
    PART_ON_PART_OFF {
        @Override
        public String getName() {
            return "Operating partially on ABC and partially on DEF Server";
        } 
    },
    PART_ONSITE {
        @Override
        public String getName() {
            return "Limited operation on ABC Server";
        } 
    },
    FULL_OFFSITE {
        @Override
        public String getName() {
            return "Operating entirely on DEF Server";
        } 
    },
    OFFGRID {
        @Override
        public String getName() {
            return "Not operational currently";
        } 
    };

    public abstract String getName();
}

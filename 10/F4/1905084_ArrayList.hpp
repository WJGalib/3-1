
template <typename T> class ArrayList {
    
        T* arr;
        int len = 0, currP = 0, X, X0;

        void realloc() {
            X += X0;
            T* tempArr = new T[X];
            for(int i=0; i<len; i++) tempArr[i] = arr[i];
            arr = new T[X];
            for(int i=0; i<len; i++) arr[i] = tempArr[i];
        };
    
    public:

        ArrayList() {
            this->X = X0 = 128;
            arr = new T[this->X];
        };

        ArrayList (int X) {
            this->X = X0 = X;
            arr = new T[this->X];
        };

        ArrayList (int X, int Y, T* array) {
            this->X = X0 = X;
            arr = new T[this->X];
            len = Y;
            for(int i=0; i<len; i++) arr[i] = array[i];
        };

        ~ArrayList() {
            if (len!=0) delete [] arr;
        }

        void clear() {
            len = 0;
            currP = 0;
            delete [] arr;
            arr = new T[X];
        };

        void insert (const T& item) { 
            if (len == X) realloc();
            for (int i = len; i>currP; i--) arr[i] = arr[i-1];
            arr[currP] = item;
            len++;
        };

        void append (const T& item) {
            if (len == X) realloc();
            arr[len] = item;
            len++;
        };

        T remove() {
            assert (len > 0);
            if (len == 0) return nullptr;
            T r = arr[currP];
            for (int i=currP; i<len-1; i++) arr[i] = arr[i+1];
            len--;
            return r;
        };

        void moveToStart() {
            currP = 0;
        };

        void moveToEnd() {
            currP = len;
        };

        void prev() {
            if (currP > 0) currP--;
        };

        void next() {
            if (currP < len) currP++;
        };

        int length() {
            return len;
        };

        int currPos() {
            return currP;
        };

        void moveToPos (int pos) {
            currP = pos;
        };

        T getValue() {
            assert (len > 0);
            return arr[currP];
        };

        int Search (const T& item) {
            for (int i=0; i<len; i++) if (arr[i] == item) return i;
            return -1;
        };

};

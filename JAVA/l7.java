class Phone {
    String brand;
    int memCapacity;

    Phone(String brand, int memCapacity) {
        this.brand = brand;
        this.memCapacity = memCapacity;
    }

    interface Callable {
        void makeAudioCall(String CellNum);

        void makeVideoCall(String CellNum);
    }

    void Display() {
        System.out.println("Brand : " + brand + "\nMemory Capacity : " + memCapacity);
    }
}

class BasicPhone extends Phone {
    BasicPhone(String brand, int memCapacity) {
        super(brand, memCapacity);
    }

    void makeAudioCall(String CellNumber) {
        System.out.println("Making an Audio Call to " + CellNumber + " from Basic Phone");
    }

    void makeVideoCall(String CellNumber) {
        System.out.println("Making Video Call to " + CellNumber + " from Basic Phone");
    }
}

class SmartPhone extends Phone {

    SmartPhone(String brand, int memCapacity) {
        super(brand, memCapacity);
    }

    void makeAudioCall(String CellNumber) {
        System.out.println("Making an Audio Call to " + CellNumber + " from Smart Phone");
    }

    void makeVideoCall(String CellNumber) {
        System.out.println("Making Video Call to " + CellNumber + " from Smart Phone");
    }
}

class l7 {
    public static void main(String[] args) {
        BasicPhone b1 = new BasicPhone("Nokia", 1024);
        SmartPhone s1 = new SmartPhone("Apple", 4096);
        b1.Display();
        s1.Display();
        b1.makeAudioCall("7673916996");
        b1.makeVideoCall("7673916996");
        s1.makeAudioCall("7673916996");
        s1.makeVideoCall("7673916996");
    }
}
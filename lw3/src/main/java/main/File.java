package main;

public abstract class File {
    protected String name;
    protected long size;
    protected User owner;

    public File(String name, long size, User owner) {
        this.name = name;
        this.size = size;
        this.owner = owner;
    }

    // Method to get the file name
    public String getName() {
        return name;
    }

    // Method to set the file name
    public void setName(String name) {
        this.name = name;
    }

    // Method to get the file size
    public long getSize() {
        return size;
    }

    // Method to set the file size
    public void setSize(long size) {
        this.size = size;
    }

    // Method to get the file owner
    public User getOwner() {
        return owner;
    }

    // Method to set the file owner
    public void setOwner(User owner) {
        this.owner = owner;
    }

    // Abstract method to open the file
    public abstract void open();

    // Abstract method to close the file
    public abstract void close();
}
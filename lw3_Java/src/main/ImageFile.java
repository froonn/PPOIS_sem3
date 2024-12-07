package main;

public class ImageFile extends File {
    private int width;
    private int height;

    public ImageFile(String name, long size, User owner, int width, int height) {
        super(name, size, owner);
        this.width = width;
        this.height = height;
    }

    @Override
    public void open() {
        System.out.println("Opening image file: " + name);
    }

    @Override
    public void close() {
        System.out.println("Closing image file: " + name);
    }

    // Method to get the width of the image
    public int getWidth() {
        return width;
    }

    // Method to set the width of the image
    public void setWidth(int width) {
        this.width = width;
    }

    // Method to get the height of the image
    public int getHeight() {
        return height;
    }

    // Method to set the height of the image
    public void setHeight(int height) {
        this.height = height;
    }

    // Method to resize the image
    public void resize(int newWidth, int newHeight) {
        this.width = newWidth;
        this.height = newHeight;
    }
}
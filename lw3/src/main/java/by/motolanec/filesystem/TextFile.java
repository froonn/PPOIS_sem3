package by.motolanec.filesystem;

public class TextFile extends File {
    private String content;

    public TextFile(String name, long size, User owner, String content) {
        super(name, size, owner);
        this.content = content;
    }

    @Override
    public void open() {
        System.out.println("Opening text file: " + name);
    }

    @Override
    public void close() {
        System.out.println("Closing text file: " + name);
    }

    // Method to get the content of the text file
    public String getContent() {
        return content;
    }

    // Method to set the content of the text file
    public void setContent(String content) {
        this.content = content;
    }

    // Method to append content to the text file
    public void appendContent(String additionalContent) {
        this.content += additionalContent;
    }

    // Method to clear the content of the text file
    public void clearContent() {
        this.content = "";
    }
}
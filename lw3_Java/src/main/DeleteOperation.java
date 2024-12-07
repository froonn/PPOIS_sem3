package main;

public class DeleteOperation implements FileOperation {
    @Override
    public void execute(File file) throws ExceptionHandler {
        try {
            if (file instanceof TextFile) {
                System.out.println("Deleting text file: " + file.getName());
            } else if (file instanceof ImageFile) {
                System.out.println("Deleting image file: " + file.getName());
            } else if (file instanceof AudioFile) {
                System.out.println("Deleting audio file: " + file.getName());
            } else {
                throw new IllegalArgumentException("Unsupported file type");
            }
            // Perform the actual deletion logic here
        } catch (Exception e) {
            ExceptionHandler.handle(e);
        }
    }
}
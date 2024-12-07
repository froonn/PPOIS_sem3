package by.motolanec.filesystem;

public class MoveOperation implements FileOperation {
    private Directory destination;

    public MoveOperation(Directory destination) {
        this.destination = destination;
    }

    @Override
    public void execute(File file) throws ExceptionHandler {
        try {
            if (file instanceof TextFile) {
                System.out.println("Moving text file: " + file.getName());
            } else if (file instanceof ImageFile) {
                System.out.println("Moving image file: " + file.getName());
            } else if (file instanceof AudioFile) {
                System.out.println("Moving audio file: " + file.getName());
            } else {
                throw new IllegalArgumentException("Unsupported file type");
            }
            // Perform the actual move logic here
            destination.addFile(file);
            System.out.println("File moved to: " + destination.getName());
        } catch (Exception e) {
            ExceptionHandler.handle(e);
        }
    }
}
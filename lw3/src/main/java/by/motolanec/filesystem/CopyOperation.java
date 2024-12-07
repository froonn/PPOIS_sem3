package by.motolanec.filesystem;

public class CopyOperation implements FileOperation {
    private Directory destination;

    public CopyOperation(Directory destination) {
        this.destination = destination;
    }

    @Override
    public void execute(File file) throws ExceptionHandler {
        try {
            File copiedFile;
            if (file instanceof TextFile) {
                TextFile textFile = (TextFile) file;
                copiedFile = new TextFile(textFile.getName(), textFile.getSize(), textFile.getOwner(), textFile.getContent());
                System.out.println("Coping text file: " + file.getName());
            } else if (file instanceof ImageFile) {
                ImageFile imageFile = (ImageFile) file;
                copiedFile = new ImageFile(imageFile.getName(), imageFile.getSize(), imageFile.getOwner(), imageFile.getWidth(), imageFile.getHeight());
                System.out.println("Coping image file: " + file.getName());
            } else if (file instanceof AudioFile) {
                AudioFile audioFile = (AudioFile) file;
                copiedFile = new AudioFile(audioFile.getName(), audioFile.getSize(), audioFile.getOwner(), audioFile.getDuration());
                System.out.println("Coping audio file: " + file.getName());
            } else {
                throw new IllegalArgumentException("Unsupported file type");
            }
            destination.addFile(copiedFile);
            System.out.println("File copied to: " + destination.getName());
        } catch (Exception e) {
            ExceptionHandler.handle(e);
        }
    }
}
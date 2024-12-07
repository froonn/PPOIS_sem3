package by.motolanec.filesystem;

public class AudioFile extends File {
    private int duration;

    public AudioFile(String name, long size, User owner, int duration) {
        super(name, size, owner);
        this.duration = duration;
    }

    @Override
    public void open() {
        System.out.println("Playing audio file: " + name);
    }

    @Override
    public void close() {
        System.out.println("Stopping audio file: " + name);
    }

    // Method to get the duration of the audio file
    public int getDuration() {
        return duration;
    }

    // Method to set the duration of the audio file
    public void setDuration(int duration) {
        this.duration = duration;
    }

    // Method to play the audio file
    public void play() {
        System.out.println("Playing audio file: " + name);
    }

    // Method to pause the audio file
    public void pause() {
        System.out.println("Pausing audio file: " + name);
    }

    // Method to stop the audio file
    public void stop() {
        System.out.println("Stopping audio file: " + name);
    }
}
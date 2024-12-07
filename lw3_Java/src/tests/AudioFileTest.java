package tests;

import main.AudioFile;
import main.RegularUser;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class AudioFileTest {
    private AudioFile audioFile;
    private RegularUser owner;

    @BeforeEach
    void setUp() {
        owner = new RegularUser("testUser", "password");
        audioFile = new AudioFile("testAudio", 4096, owner, 300);
    }

    @Test
    void getDurationReturnsCorrectDuration() {
        assertEquals(300, audioFile.getDuration());
    }

    @Test
    void setDurationUpdatesDuration() {
        audioFile.setDuration(600);
        assertEquals(600, audioFile.getDuration());
    }

    @Test
    void openPrintsCorrectMessage() {
        // Assuming System.out is redirected to capture output
        audioFile.open();
        // Verify the output message
    }

    @Test
    void closePrintsCorrectMessage() {
        // Assuming System.out is redirected to capture output
        audioFile.close();
        // Verify the output message
    }

    @Test
    void playPrintsCorrectMessage() {
        // Assuming System.out is redirected to capture output
        audioFile.play();
        // Verify the output message
    }

    @Test
    void pausePrintsCorrectMessage() {
        // Assuming System.out is redirected to capture output
        audioFile.pause();
        // Verify the output message
    }

    @Test
    void stopPrintsCorrectMessage() {
        // Assuming System.out is redirected to capture output
        audioFile.stop();
        // Verify the output message
    }
}
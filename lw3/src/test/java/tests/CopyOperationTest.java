package tests;

import main.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class CopyOperationTest {
    private Directory destination;
    private CopyOperation copyOperation;
    private User owner;

    @BeforeEach
    void setUp() {
        destination = new Directory("destination");
        copyOperation = new CopyOperation(destination);
        owner = new RegularUser("testUser", "password");
    }

    @Test
    void executeCopiesTextFile() throws ExceptionHandler {
        TextFile textFile = new TextFile("testText", 1024, owner, "Content");
        copyOperation.execute(textFile);
        assertEquals(1, destination.getFiles().size());
        assertTrue(destination.getFiles().get(0) instanceof TextFile);
        assertEquals("testText", destination.getFiles().get(0).getName());
    }

    @Test
    void executeCopiesImageFile() throws ExceptionHandler {
        ImageFile imageFile = new ImageFile("testImage", 2048, owner, 1920, 1080);
        copyOperation.execute(imageFile);
        assertEquals(1, destination.getFiles().size());
        assertTrue(destination.getFiles().get(0) instanceof ImageFile);
        assertEquals("testImage", destination.getFiles().get(0).getName());
    }

    @Test
    void executeCopiesAudioFile() throws ExceptionHandler {
        AudioFile audioFile = new AudioFile("testAudio", 4096, owner, 300);
        copyOperation.execute(audioFile);
        assertEquals(1, destination.getFiles().size());
        assertTrue(destination.getFiles().get(0) instanceof AudioFile);
        assertEquals("testAudio", destination.getFiles().get(0).getName());
    }

    @Test
    void executeHandlesException() {
        File file = new TextFile("testFile", 100, owner, "content"); {

        };
        assertDoesNotThrow(() -> copyOperation.execute(file));
    }
}
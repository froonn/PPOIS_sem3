package tests;

import by.motolanec.filesystem.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class MoveOperationTest {
    private Directory destination;
    private MoveOperation moveOperation;
    private User owner;

    @BeforeEach
    void setUp() {
        destination = new Directory("destination");
        moveOperation = new MoveOperation(destination);
        owner = new RegularUser("testUser", "password");
    }

    @Test
    void executeMovesTextFile() throws ExceptionHandler {
        TextFile textFile = new TextFile("testText", 1024, owner, "Content");
        moveOperation.execute(textFile);
        assertEquals(1, destination.getFiles().size());
        assertTrue(destination.getFiles().get(0) instanceof TextFile);
        assertEquals("testText", destination.getFiles().get(0).getName());
    }

    @Test
    void executeMovesImageFile() throws ExceptionHandler {
        ImageFile imageFile = new ImageFile("testImage", 2048, owner, 1920, 1080);
        moveOperation.execute(imageFile);
        assertEquals(1, destination.getFiles().size());
        assertTrue(destination.getFiles().get(0) instanceof ImageFile);
        assertEquals("testImage", destination.getFiles().get(0).getName());
    }

    @Test
    void executeMovesAudioFile() throws ExceptionHandler {
        AudioFile audioFile = new AudioFile("testAudio", 4096, owner, 300);
        moveOperation.execute(audioFile);
        assertEquals(1, destination.getFiles().size());
        assertTrue(destination.getFiles().get(0) instanceof AudioFile);
        assertEquals("testAudio", destination.getFiles().get(0).getName());
    }

}
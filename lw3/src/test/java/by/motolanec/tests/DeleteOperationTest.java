package by.motolanec.tests;

import by.motolanec.filesystem.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class DeleteOperationTest {
    private DeleteOperation deleteOperation;
    private User owner;

    @BeforeEach
    void setUp() {
        deleteOperation = new DeleteOperation();
        owner = new RegularUser("testUser", "password");
    }

    @Test
    void executeDeletesTextFile() throws ExceptionHandler {
        TextFile textFile = new TextFile("testText", 1024, owner, "Content");
        deleteOperation.execute(textFile);
        // Verify the deletion logic
    }

    @Test
    void executeDeletesImageFile() throws ExceptionHandler {
        ImageFile imageFile = new ImageFile("testImage", 2048, owner, 1920, 1080);
        deleteOperation.execute(imageFile);
        // Verify the deletion logic
    }

    @Test
    void executeDeletesAudioFile() throws ExceptionHandler {
        AudioFile audioFile = new AudioFile("testAudio", 4096, owner, 300);
        deleteOperation.execute(audioFile);
        // Verify the deletion logic
    }
}
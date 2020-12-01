import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.lang.Math;
import java.util.Random;
import java.awt.event.KeyAdapter;
import javax.imageio.ImageIO;
import javax.swing.*;
import java.util.Random;



public class Window extends JFrame{

    public Window() throws IOException {
        add(new Board());
        setTitle("Snake");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(800, 800);
        setLocationRelativeTo(null);
        setVisible(true);
        setResizable(false);
    }

    public static void main(String [] args) throws IOException {
        new Window();
    }


}
import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseListener;
import java.awt.image.BufferedImage;
import java.io.*;
import java.util.Random;
import java.util.ArrayList;


public class Board extends JPanel implements Runnable, KeyListener
{

    boolean ingame = true;
    private Dimension d;
    int BOARD_WIDTH=800;
    int BOARD_HEIGHT=800;
    private Thread animator;
    public static ArrayList<SnakeSegment> snake;
    private static Apple apple;
    private char direction = 'R';
    public Board() throws IOException {
        addKeyListener(this);
        setFocusable(true);
        d = new Dimension(BOARD_WIDTH, BOARD_HEIGHT);
        snake = new ArrayList<>();
        snake.add(new SnakeSegment(100, 60));
        snake.add(new SnakeSegment(80, 60));
        snake.add(new SnakeSegment(60, 60));
        apple = new Apple(400, 60);
        setBackground(Color.white);

        if(animator == null || !ingame){
            animator = new Thread(this);
            animator.start();
        }
        setDoubleBuffered(true);
    }


    @Override
    public void keyTyped(KeyEvent e) {

    }

    @Override
    public void keyPressed(KeyEvent e){
        int keyCode = e.getKeyCode();
        if(keyCode == KeyEvent.VK_UP){
            direction = 'U';
        }

        if (keyCode == KeyEvent.VK_DOWN){
            direction = 'D';
        }
        if(keyCode == KeyEvent.VK_RIGHT){
           direction = 'R';
        }           
        if(keyCode == KeyEvent.VK_LEFT){
            direction = 'L';
        }
    }



    public void move(){
        if(direction == 'U'){
            SnakeSegment head = snake.get(0);
            SnakeSegment new_head = new SnakeSegment(head.getX(), head.getY() - 20);
            snake.add(0, new_head);
            snake.remove(snake.size() - 1);
        }

        if (direction == 'D'){
            SnakeSegment head = snake.get(0);
            SnakeSegment new_head = new SnakeSegment(head.getX(), head.getY() + 20);
            snake.add(0, new_head);
            snake.remove(snake.size() - 1);
        }
        if(direction == 'R'){
            SnakeSegment head = snake.get(0);
            SnakeSegment new_head = new SnakeSegment(head.getX() + 20, head.getY());
            snake.add(0, new_head);
            snake.remove(snake.size() - 1);
        }           
        if(direction == 'L'){
            SnakeSegment head = snake.get(0);
            SnakeSegment new_head = new SnakeSegment(head.getX() - 20, head.getY());
            snake.add(0, new_head);
            snake.remove(snake.size() - 1);
        }    
    }

    public boolean eatenApple(){
        SnakeSegment head = snake.get(0);
        double distance = Math.sqrt(Math.pow(apple.getX() - head.getX(), 2) + Math.pow(apple.getY() - head.getY(), 2));
        return distance < 20;
    }

    public boolean touchesWalls(){
        SnakeSegment head = snake.get(0);
        return head.getX() == 800 || head.getY() == 800 || head.getX() == 0 || head.getY() == 0;
    }

    public boolean touchesIteslf(){
        SnakeSegment head = snake.get(0);
        for(int i = 1; i < snake.size(); i++){
            SnakeSegment part = snake.get(i);
            if(head.getX() == part.getX() && head.getY() == part.getY()){
                return true;
            }
        }
        return false;
    }

    @Override
    public void keyReleased(KeyEvent e) {

    }

    @Override
    public void run() {
        long beforeTime, timeDiff, sleep;
        beforeTime = System.currentTimeMillis();
        int animationDelay = 100;
        long time = System.currentTimeMillis();

        while (true){
            repaint();
            try{
                time += animationDelay;



                Thread.sleep(Math.max(0, time - System.currentTimeMillis() ));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

        }
    }

    public void paint(Graphics g){
    }

}
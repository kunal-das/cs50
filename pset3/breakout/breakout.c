//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 400
#define WIDTH 600

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 11

// radius of ball in pixels
#define RADIUS 15

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    
    //velocity of the ball initially
    double xVelocity = 2.0;
    double yVelocity = 2.0;

    
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        
        move(ball, xVelocity, yVelocity);    

        //checks if the ball hits the right edge of the window
        if((getX(ball)+getWidth(ball))>= WIDTH)
        {
            xVelocity = -(xVelocity);
        }
        //checks if the ball hits the left edge of the window
        else if(getX(ball) <= 0)
        {
            xVelocity = -(xVelocity);
        }

        //checks if the ball hits the bottom edge of the window
        if((getY(ball) + getHeight(ball)) >=HEIGHT)
        {
            lives = lives - 1;
            removeGWindow(window, ball);
            freeGObject(ball);            
            GEvent mouseclick = getNextEvent(MOUSE_EVENT);
            if(mouseclick != NULL)
            {
                if(getEventType(mouseclick) == MOUSE_CLICKED)
                {
                    ball = initBall(window);
                    xVelocity = - xVelocity;
                    continue;     
                }
            }
            
        }
        //checks if the ball hits the top edge of the window
        else if(getY(ball) <= 0)
        {
            yVelocity = -yVelocity;
        }

        pause(10);

        
        if (detectCollision(window, ball) != NULL)
        {
           GObject  collision = detectCollision(window, ball);
        
            // checks if the ball collides with the paddle
            if(collision == paddle)
            {
                yVelocity = - yVelocity;
            }
            //check if the ball collided with a brick
            else if(strcmp(getType(collision), "GRect") == 0)
            {
                //printf("collision with brick detected");
                removeGWindow(window, collision);
                yVelocity = - yVelocity;
                yVelocity = yVelocity + 0.05;
                xVelocity = xVelocity + 0.05;
                freeGObject(collision);
                points = points + 1;
                updateScoreboard(window, label, points);

            }
        }

        GEvent event = getNextEvent(MOUSE_EVENT);
        if(event != NULL)
        {
           if(getEventType(event)==MOUSE_MOVED)
            {            
                double X = getX(event);
                //move the center of the paddle in the X-Axis along 
                //mouse movements and within the width of the window

                if(((X-50) >=0) && ((X+50) < 601 ))
                {
                    setLocation(paddle, (X-50), 370);
                }
             
             } 
        }


    }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
   int brickWidth = 50;
   int brickHeight = 10;
   GRect brick;
   int brickX = 0;
   int brickY = 30;

   for(int i = 0; i < 5; i++)
   {
       
       for(int j = 0; j < 11; j++)
       {
          string colors[] = {"RED", "GREEN", "BLUE", "CYAN", "ORANGE"};
          brick = newGRect(brickX, brickY, brickWidth, brickHeight);
          setColor(brick, colors[i]);
          setFilled(brick, true);
          add(window, brick);
          brickX = brickX + 55;
       }
       brickY = brickY + 15;
       brickX = 0;
   }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    
    GOval ball = newGOval((WIDTH-RADIUS)/2, (HEIGHT-RADIUS)/2, RADIUS, RADIUS);
    setColor(ball, "BLACK");
    setFilled(ball, true);
    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    int paddleWidth = 100;
    int paddleHeight = 10;
    GRect paddle = newGRect((WIDTH-paddleWidth)/2, 370, paddleWidth, paddleHeight);
    setColor(paddle, "BLACK");
    setFilled(paddle, true);
    add(window, paddle);
    return paddle;
}



/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    double x, y;
    GLabel label = newGLabel("0");
    setFont(label, "SansSerif-36");
    x = (WIDTH - getWidth(label))/2;
    y = (HEIGHT - getHeight(label))/2;
    setLocation(label, x, y);
    add(window, label);
    
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}

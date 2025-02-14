#include "Player.h"
#include "utils.h"
#include <math.h>
#include <algorithm>

const sf::Keyboard::Key KEY_LEFT = sf::Keyboard::Key::Left;
const sf::Keyboard::Key KEY_RIGHT = sf::Keyboard::Key::Right;
const sf::Keyboard::Key KEY_UP = sf::Keyboard::Key::Up;
const sf::Keyboard::Key KEY_DOWN = sf::Keyboard::Key::Down;
const sf::Keyboard::Key KEY_JUMP = sf::Keyboard::Key::X;
const sf::Keyboard::Key KEY_DASH = sf::Keyboard::Key::C;

// Construction of Player, initialting data
Player::Player() {
    MAX_D_JUMP = 1;
    pJump = false;
    pDash = false;
    grace = 0;
    jBuffer = 0;
    dJump = MAX_D_JUMP;
    dashTime = 0;
    dashEffectTime = 0;
    dashTarget = {0, 0};
    dashAccel = {0, 0};
    hitboxCenter = {1, 3};
    hitboxSize = {6, 5};
    sprOff = 0;
    spr = 0;
    direction = 1;
    wasOnGround = false;
}

void Player::update(float deltaTime) {
    // Get horizontal input
    int input = 0;
    if (sf::Keyboard::isKeyPressed(KEY_LEFT))
        input = -1;
    else if (sf::Keyboard::isKeyPressed(KEY_RIGHT))
        input = 1;
    
    // TODO: Detect spikes collides
    // if spikesAt(position.x+hitboxCenter.x, position.y+hitboxCenter.y, hitboxSize.x, hitboxSize.y, velocity.x, velocity.y) {
        // killPlayer(this);
    // }

    // TODO: Detect bottom deaths
    // if (position.y > 128) {
        // killPlayer(this);
    // }

    // Detect the ground properties
    bool onGround = isSolid(0, 1);
    bool onIce = isIce(0, 1);

    // TODO: Smoke particles
    if (onGround && !wasOnGround) {     // If landed on ground
        // TODO: Generate smoke particles
    }

    // Jump input detection
    bool jump = false;
    if (sf::Keyboard::isKeyPressed(KEY_JUMP) && !pJump)
        jump = true;
    if (sf::Keyboard::isKeyPressed(KEY_JUMP))
        pJump = true;
    if (jump)   // Set 4 frames of jump input buffer
        jBuffer = 4;
    else if (jBuffer > 0)
        jBuffer -= 1;
    
    // Dash input detection
    bool dash = false;
    if (sf::Keyboard::isKeyPressed(KEY_DASH) && !pDash)
        dash = true;
    if (sf::Keyboard::isKeyPressed(KEY_DASH))
        pDash = true;
   
    // Handle coyate time
    if (onGround) {
        grace = 6;
        if (dJump < MAX_D_JUMP) {
            // psfx(54)    To be figured out
            dJump = MAX_D_JUMP;
        }
    }
    else if (grace > 0)
        grace -= 1;
    
    // Handle dash sound effects
    dashEffectTime -= 1;
    if (dashTime > 0) {
        // Dash not finished, no new input can be made
        // TODO: sound effects
    }
    else {
        // Dash finished, can accept new inputs

        // MOVE
        int maxRun = 1;
        float accel = 0.6;
        float deccel = 0.15;

        if (!onGround)
            accel = 0.4;
        else if (onIce) {
            accel = 0.05;
            if (input == direction)
                accel = 0.05;
        }

        if (fabs(velocity.x) > maxRun) 
            velocity.x = appr(velocity.x, sign(velocity.x) * maxRun, deccel);
        else 
            velocity.x  = appr(velocity.x, input * maxRun, accel);

        // FACING
        if (velocity.x != 0)
            direction = velocity.x > 0 ? 1 : -1;
        
        // GRAVITY
        float maxfall = 2;
        float gravity = 0.21;
        if (fabs(velocity.y) <= 0.15)
            gravity *= 0.5;     // Lower gravity at the top of the projectile for better control

        // WALL SLIDE
        if (input != 0 && isSolid(input, 0) && !isIce(input, 0)) {
            maxfall = 0.4;  // Slow descent
            if (rand() < 0.2) {
                // TODO: Generate Smoke
            }
        }
        
        if (!onGround)
            velocity.y = appr(velocity.y, maxfall, gravity);
        
        // JUMP
        if (jBuffer > 0) {  // There is a jump operation in the buffer
            if (grace > 0) {
                // Normal jump
                // TODO: Play sound effect
                jBuffer = 0;
                grace = 0;
                velocity.y -= 2;
                // TODO: Generate Smoke
            }
            else {
                // Wall Jump
                int wallDir = (isSolid(-3, 0) ? -1 : isSolid(3, 0) ? 1 : 0);
                if (wallDir != 0) {
                    // TODO: Play sound effect
                    jBuffer = 0;
                    velocity.y -= 2;
                    velocity.x = -wallDir * (maxRun + 1);
                    if (!isIce(wallDir * 3, 0)) {
                        // TODO: Generate Smoke
                    }
                }
            }
        } 

        // DASH
        float dFull = 5.0;  // Horizontal or Vertical
        float dHalf = dFull * 0.70710678118; // Diagnol
        
        if (dJump > 0 && dash) {    // Can dash
            // TODO: Generate Smoke
            dJump -= 1;
            dashTime = 4;
            //hasDashed = true;     // For room achievement control not for now
            dashEffectTime = 10;

            // Detect vertical input
            int vInput = 0;
            if (sf::Keyboard::isKeyPressed(KEY_UP))
                vInput = -1;
            else if (sf::Keyboard::isKeyPressed(KEY_DOWN))
                vInput = 1;
            
            if (input != 0) {   // Has Horizontal Input
                if (vInput != 0) {  // Has Vertical Input
                    // Dash diagnolly
                    velocity.x = input * dHalf;
                    velocity.y = vInput * dHalf;
                }
                else {
                    // Dash horizontally
                    velocity.x = input * dFull;
                    velocity.y = 0;
                }
            }
            else if (vInput != 0) {
                // Dash vertically
                velocity.x = 0;
                velocity.y = vInput * dFull;
            }
            else {
                // No directional input, slow dash?
                velocity.x = direction;
                velocity.y = 0;
            }


            // TODO: Play sound effect
            int freeze = 2;
            int shake = 6;
            dashTarget.x = 2 * sign(velocity.x);
            dashTarget.y = 2 * sign(velocity.y);
            dashAccel.x = dashAccel.y = 1.5;

            if (velocity.y < 0)
                dashTarget.y *= 0.75;
        
            if (velocity.y != 0)
                dashAccel.x *= 0.70710678118;
            if (velocity.x != 0)
                dashAccel.y *= 0.70710678118;
        }
        else if (dash && dJump <= 0) {
            // No dashes left, dash failed.            
            // TODO: Sound effect
            // TODO: Generate smoke
        }
    }


    // ANIMATION
    sprOff += 0.25;
    if (!onGround) {
        if (isSolid(input, 0))
            spr = 6;
        else
            spr = 3;
    }
    else if (sf::Keyboard::isKeyPressed(KEY_DOWN))
        spr = 6;
    else if (sf::Keyboard::isKeyPressed(KEY_UP))
        spr = 7;
    else if (velocity.x == 0 || (!sf::Keyboard::isKeyPressed(KEY_LEFT) && !sf::Keyboard::isKeyPressed(KEY_RIGHT)))
        spr = 1;
    else
        spr = 1 + static_cast<int>(sprOff) % 4;

        
    // NEXT LEVEL
    // TODO
    // if (position.y < -4 && levelIndex() < 30)
        // nextRoom();

    // WAS ON THE GROUND
    wasOnGround = onGround;

    // Update Hair
    // Initial Point depending on crouch
    int iniVal = 3;
    if (sf::Keyboard::isKeyPressed(KEY_DOWN))
        iniVal = 4;
    hair.updateHair(*this, iniVal);
}

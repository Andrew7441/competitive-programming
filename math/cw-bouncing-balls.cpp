// Codewars — Bouncing Balls
// Topic: math | Tags: simulation, geometric-sequence
// Complexity (yours): O(log(h/window) / log(1/bounce)) time, O(1) space

/*
A child is playing with a ball on the nth floor of a tall building. The height of this floor
above ground level, h, is known.

He drops the ball out of the window. The ball bounces (for example), to two-thirds of its height
(a bounce of 0.66).

His mother looks out of a window 1.5 meters from the ground.

How many times will the mother see the ball pass in front of her window (including when it's
falling and bouncing)?

Three conditions must be met for a valid experiment:
- Float parameter "h" in meters must be greater than 0
- Float parameter "bounce" must be greater than 0 and less than 1
- Float parameter "window" must be less than h.

If all three conditions above are fulfilled, return a positive integer, otherwise return -1.

Note: The ball can only be seen if the height of the rebounding ball is strictly greater than the
window parameter.

- h = 3, bounce = 0.66, window = 1.5, result is 3
- h = 3, bounce = 1, window = 1.5, result is -1 (Condition 2 not fulfilled).
*/

using namespace std;
class Bouncingball
{
public:
    static int bouncingBall(double h, double bounce, double window){
      if(bounce<=0 or bounce>=1){
        return -1;
      }
      
      int bounces = -1;
      while(h>window){
        h*=bounce;
        bounces +=2;
      }
      return bounces;
    }
};

/*
💭 First Idea: simulate: each time the height is above the window, the ball passes twice (down + up); start at -1 because the first drop has no "up".
🧩 Key Property / Invariant: answer = 2 * (#heights h·bounce^k > window, k ≥ 0) - 1.
✅ Key insight: starting the counter at -1 makes "window >= h" (and h <= 0 with a positive window) return -1 automatically.
🔁 Recognition cue for next time: repeated multiply-by-ratio until below a threshold -> geometric sequence; simulate (log steps).
⏱  Speed fix for next time: check all three validity conditions explicitly (h > 0, 0 < bounce < 1, window < h) to be safe.
🛠  Review: correct; O(log) simulation → Already optimal (closed form with log() risks float edge cases).
*/

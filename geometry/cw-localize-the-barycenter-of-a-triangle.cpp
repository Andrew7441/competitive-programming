// Codewars — Localize The Barycenter of a Triangle
// Topic: geometry | Tags: math, rounding
// Complexity (yours): O(1)

#include <utility>
#include <cmath>
/*
The medians of a triangle are the segments that unit the vertices with the midpoint of their opposite sides. The three medians of a triangle intersect at the same point, called the barycenter or the centroid. Given a triangle, defined by the cartesian coordinates of its vertices, we need to localize its barycenter or centroid.

Your function receives the coordinates of the three vertices `A`, `B` and `C`  as three different arguments and outputs the coordinates of the barycenter `O`, rounded to `4` decimals, in an array `[xO, yO]`.

You know that the coordinates of the barycenter are given by the following formulas:

xO=xA+xB+xC3yO=yA+yB+yC3xO​=3xA​+xB​+xC​​yO​=3yA​+yB​+yC​​

The given points form a real or a degenerate triangle but in each case the above formulas can be used.

For additional information about this important point of a triangle see at: ([https://en.wikipedia.org/wiki/Centroid](https://en.wikipedia.org/wiki/Centroid))

Let's see some cases:

([4, 6], [12, 4], [10, 10]) ------> [8.6667, 6.6667]

([4, 2], [12, 2], [6, 10]) ------> [7.3333, 4.6667]

*/
using point = const std::pair<double, double>;

std::pair<double, double> barTriang(point p1, point p2, point p3) {
  double x = (p1.first + p2.first + p3.first)/3;
  double y = (p1.second + p2.second + p3.second)/3;
  x = std::round(x * 10000.0) / 10000.0;
  y = std::round(y * 10000.0) / 10000.0;
  
  return {x, y};
}

/*
💭 First Idea: Average the x's and y's, then round to 4 decimals via round(x*1e4)/1e4.
🧩 Key Property / Invariant: Centroid = arithmetic mean of the vertices (also for degenerate triangles).
✅ Key insight: Direct formula; only care point is the rounding.
🔁 Recognition cue for next time: "centroid/barycenter" -> mean of coordinates.
⏱  Speed fix for next time: Nothing to speed up.
🛠  Review: correct; O(1) — Already optimal.
*/

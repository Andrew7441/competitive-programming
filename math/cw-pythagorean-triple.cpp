// Codewars — Pythagorean Triple
// Topic: math | Tags: sorting
// Complexity (yours): O(1)

/*
Given an **unsorted** array of 3 positive integers `[ n1, n2, n3 ]`, determine if it is possible to form a [Pythagorean Triple](https://en.wikipedia.org/wiki/Pythagorean_triple) using those 3 integers.

A [Pythagorean Triple](https://en.wikipedia.org/wiki/Pythagorean_triple) consists of arranging 3 integers, such that:

**a2 + b2 = c2**

### Examples

[5, 3, 4] : it **is possible** to form a Pythagorean Triple using these 3 integers: 32 + 42 = 52

[3, 4, 5] : it **is possible** to form a Pythagorean Triple using these 3 integers: 32 + 42 = 52

[13, 12, 5] : it **is possible** to form a Pythagorean Triple using these 3 integers: 52 + 122 = 132

[100, 3, 999] : it **is NOT possible** to form a Pythagorean Triple using these 3 integers - no matter how you arrange them, you will never find a way to satisfy the equation a2 + b2 = c2

### Return Values

- For Python: return `True` or `False`
- For JavaScript: return `true` or `false`
- Other languages: return `1` or `0` or refer to Sample Tests.
*/

#include<algorithm>
bool PythagoreanTriple(const int b, const int c, const int d)
{
  int a[] = {b,c,d};
  
  std::sort(a,a+3);
  
  return (a[0] * a[0] + a[1] * a[1]) == a[2]*a[2];
}
//BEST PRACTICES
namespace best_practice {  // (added wrapper: same signature as yours, would be a redefinition)
bool PythagoreanTriple(const int a, const int b, const int c)
{
  return (a * a + b * b) == (c * c);
}
}  // namespace best_practice


/*
💭 First Idea: Sort the three numbers, then check a² + b² == c².
🧩 Key Property / Invariant: Only the largest can be the hypotenuse.
✅ Key insight: Sort 3 values, test one equation.
🔁 Recognition cue for next time: "unordered triple, check a²+b²=c²" -> sort first.
⏱  Speed fix for next time: Use long long products if inputs can exceed ~46340. Note: the copied 'best practice' assumes c is already the largest — it fails on [5, 3, 4].
🛠  Review: correct (yours); O(1) — Already optimal.
*/

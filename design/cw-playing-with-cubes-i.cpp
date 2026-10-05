// Codewars — Playing with cubes I
// Topic: design | Tags: oop, getters-setters
// Complexity (yours): O(1) per call
// From: Codewars/Functions July 2024.md — section "Function create a simple Cube class"
/*
Kata description:
Create a public class called Cube without a constructor which gets one single private integer variable Side, a getter GetSide() and a setter SetSide(int num) method for this property. (Getters/setters are not the usual style in C#; the next kata of the series refactors it.)
*/

class Cube{
  private:
    int side = 0;
  public:
    int GetSide(){
      return side;
    }
  
    int SetSide(int num){
      side = num;
      return side;
    }

};

/*
💭 First Idea: Private int with a default of 0, public getter and setter.
🧩 Key Property / Invariant: Encapsulation: the field is only changed through SetSide.
✅ Key insight: Default member initializer (int side = 0) replaces a constructor.
🔁 Recognition cue for next time: "class with getter/setter" -> private field + public accessors.
⏱  Speed fix for next time: Mark the getter const: int GetSide() const.
🛠  Review: correct; O(1) -> Already optimal.
*/

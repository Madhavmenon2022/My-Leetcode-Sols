// Last updated: 6/5/2026, 6:17:58 PM
1class Solution {
2public:
3    bool isNumber(string s) {
4        enum InputType {
5            INVALID,    // 0
6            SPACE,      // 1
7            SIGN,       // 2
8            DIGIT,      // 3
9            DOT,        // 4
10            EXPONENT,   // 5
11            NUM_INPUTS  // 6
12        };
13        int transitionTable[][NUM_INPUTS] = {
14            -1,  0,  3,  1,  2, -1,     // next states for state 0
15            -1,  8, -1,  1,  4,  5,     // next states for state 1
16            -1, -1, -1,  4, -1, -1,     // next states for state 2
17            -1, -1, -1,  1,  2, -1,     // next states for state 3
18            -1,  8, -1,  4, -1,  5,     // next states for state 4
19            -1, -1,  6,  7, -1, -1,     // next states for state 5
20            -1, -1, -1,  7, -1, -1,     // next states for state 6
21            -1,  8, -1,  7, -1, -1,     // next states for state 7
22            -1,  8, -1, -1, -1, -1,     // next states for state 8
23        };
24
25        int state = 0;
26        for (const auto& c: s) {
27            InputType inputType = INVALID;
28            if (isspace(c)) {
29                inputType = SPACE;
30            } else if (c == '+' || c == '-') {
31                inputType = SIGN;
32            } else if (isdigit(c)) {
33                inputType = DIGIT;
34            } else if (c == '.') {
35                inputType = DOT;
36            } else if (c == 'e' || c == 'E') {
37                inputType = EXPONENT;
38            }
39            // Get next state from current state and input symbol
40            state = transitionTable[state][inputType];
41
42            // Invalid input
43            if (state == -1) {
44                return false;
45            }
46        }
47        // If the current state belongs to one of the accepting (final) states,
48        // then the number is valid
49        return state == 1 || state == 4 || state == 7 || state == 8;
50    }
51};
52
53#include <regex>
54class Solution_TLE {
55public:
56    bool isNumber(string s) {
57        regex e("^\\s*[\\+-]?((\\d+(\\.\\d*)?)|\\.\\d+)([eE][\\+-]?\\d+)?\\s*$");
58        return regex_match(s, e);
59    }
60};
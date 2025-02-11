
# Cricket Score Sheet Generator

## Overview
The **Cricket Score Sheet Generator** is a C++ program designed to simulate and generate detailed score sheets for cricket matches. It allows users to create, store, display, and search cricket match data in a structured format. The program uses randomization to simulate match outcomes, including runs scored, wickets taken, and extras, while providing a comprehensive output of the match statistics.

---

## Features
1. **Match Simulation**:
   - Simulates two innings of a cricket match.
   - Randomly generates scores, wickets, and extras for each ball.
   - Handles toss outcomes and assigns batting/bowling roles to teams.

2. **Score Sheet Generation**:
   - Produces detailed score sheets with:
     - Runs scored by each batsman.
     - Wickets taken by each bowler.
     - Extras (wides, no-balls).
     - Economy rates for bowlers.
     - Total runs and wickets for each team.

3. **Data Storage**:
   - Stores match data in a binary file (`cric.dat`) for future reference.

4. **Search Functionality**:
   - Allows users to search for specific matches by:
     - Team name.
     - League name.
     - Match number.

5. **User-Friendly Interface**:
   - Provides a menu-driven interface for easy navigation.
   - Displays all stored matches or specific matches based on user input.

---
##How to Use
###Prerequisites
- C++ compiler.
- Basic knowledge of running C++ programs.
  
###Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/Balaji-spyder/cric_scoresheet.git
   cd cric_scoresheet
   ```
2. Compile the program using a C++ compiler:
   ```bash
   c++ cricket.cpp
   ```
3. Run the compiled executable:
   ```bash
   ./a.out
   ```
---

## Example Output

### Creating a New Score Sheet
```
Enter your choice:1
Enter the league name:IPL
ENter the match no:1
Enter the Team names:CSK MI
ENter the start time(in 24hour format):19:00
Enter the Venue name:chepauk

 **************************Created a scoresheet successfully********************** 

```

### Displaying a Score Sheet
```
				 			Cricket score sheet.
LEAGUE: IPL
MATCH NO: 1
MATCH: CSK VS MI
START TIME: 19:00
Toss won be CSK And elected to bat first
VENUE: Chepauk
1st Innings
BATTING:CSK
---------------------------------------------------------------------------------------------------------------------------------
OVERS			 	 	 		  | Batsman 	    1's	 2's	 3's	 4's	 6's 	Runs 	 HOW OUT
---------------------------------------------------------------------------------------------------------------------------------
Over 1:6	0	3	4	0	W	| BATSMAN 1: 	0	    0	    1	    1	    1  	13 Runs	BOWLED
Over 2:3	6	1	W	1	0	| BATSMAN 2: 	1	    0	    1	    0	    1	  10 Runs	CAUGHT
Over 3:W	6	3	1	1	0	| BATSMAN 3: 	1	    0	    0	    0	    0  	1 Runs	CAUGHT
Over 4:6	1	4	W	6	W	| BATSMAN 4: 	3	    0    	1	    1	    2	  22 Runs	CAUGHT
Over 5:0	3	4	2	3	3	| BATSMAN 5: 	0	    0	    0	    0	    1	  6 Runs	CAUGHT
Over 6:3	0	2	1	2	4	| BATSMAN 6: 	6	    7	    6    	4	    0	  54 Runs	CAUGHT
Over 7:2	3	1	2	1	1	| BATSMAN 7: 	2	    2	    2	    1	    1  	22 Runs	NA
Over 8:0	3	4	4	2	1	| BATSMAN 8: 	0	    0    	0	    0	    0  	0 Runs	NA
Over 9:1	0	2	W	6	4	| BATSMAN 9: 	0    	0	    0	    0    	0	  0 Runs	NA
Over 10:1	2	3	1	2	3	| BATSMAN 10: 0    	0	    0	    0    	0	  0 Runs	NA
							      | BATSMAN 11: 0	    0	    0	    0    	0	  0 Runs	NA
---------------------------------------------------------------------------------------------------------------------------------
Extras = 7(7 w,0 nb)	 	 	 	 	 	 	 	 	Total runs scored = 135( 7-4's,6-6's )
----------------------------------------------------------------------------------------------------------------------------------

-----------------------------------------------------------------------------------------------------------------------
BOWLING:MI 	 				 		          | Bowler 	  Overs	  Wicket	 RUNS 	 ECONOMY
-----------------------------------------------------------------------------------------------------------------------
Over 1:1 Wicket 	13 Runs  	 	 		| Bowler 1: 	2.0	   1	    25	     12.5
Over 2:1 Wicket 	11 Runs  	 	 		| Bowler 2: 	2.0	   1	    21	     10.5
Over 3:1 Wicket 	11 Runs  	 	 		| Bowler 3: 	2.0	   1	    25	     12.5
Over 4:2 Wicket 	17 Runs  	 	 		| Bowler 4: 	2.0	   3	    30	     15
Over 5:0 Wicket 	15 Runs  	 	 		| Bowler 5: 	2.0	   0	    27	     13.5
Over 6:0 Wicket 	12 Runs 
Over 7:0 Wicket 	10 Runs 
Over 8:0 Wicket 	14 Runs 
Over 9:1 Wicket 	13 Runs 
Over 10:0 Wicket 	12 Runs 
-----------------------------------------------------------------------------------------------------------------------
Total wickets taken = 6
-----------------------------------------------------------------------------------------------------------------------

MI required 136 runs to the win the match in 60 Balls.

2nd Innings
BATTING: MI
---------------------------------------------------------------------------------------------------------------------------------
OVERS			 	 	 		  | Batsman 	  1's	 2's	 3's	  4's	 6's 	Runs	 HOW OUT
----------------------------------------------------------------------------------------------------------------------------------
Over 1:6	1	3	1	1	W	| BATSMAN 1: 	3	    0	    1	    0	    1	  12 Runs	CAUGHT
Over 2:0	2	0	1	2	2	| BATSMAN 2: 	3	    5	    6	    1	    1	  41 Runs	BOWLED
Over 3:3	3	3	2	1	3	| BATSMAN 3: 	5    	0	    4	    2	    3	  43 Runs	CAUGHT
Over 4:3	6	3	4	1	0	| BATSMAN 4: 	0	    0	    0    	0	    0  	0 Runs	BOWLED
Over 5:2	W	0	3	6	3	| BATSMAN 5: 	0	    0	    0	    0	    0	  0 Runs	CAUGHT
Over 6:1	4	3	3	1	6	| BATSMAN 6: 	0	    0	    0	    0	    0  	0 Runs	CAUGHT
Over 7:1	4	1	6	1	W	| BATSMAN 7: 	0    	0    	0	    2	    0	  8 Runs	CAUGHT
Over 8:W	0	0	W	W	4	| BATSMAN 8: 	5	    0    	1    	1	    0  	12 Runs	NA
Over 9:4	W	1	0	1	1	| BATSMAN 9: 	0	    0	    0	    0	    0	   0 Runs	NA
Over 10:1	0	1	4	0	3	| BATSMAN 10: 0	    0	    0	    0    	0	  0 Runs	NA
							      | BATSMAN 11: 0	    0	    0    	0	    0	  0 Runs	NA
---------------------------------------------------------------------------------------------------------------------------------
Extras = 5(2 w,3 nb)		 	 	 	 	 	 	 	Total runs scored = 121( 6-4's,5-6's )
--------------------------------------------------------------------------------------------------------------------------------

-----------------------------------------------------------------------------------------------------------------------
BOWLING:CSK 	 				 		        | Bowler 	    Overs	  Wicket	 RUNS 	 ECONOMY
-----------------------------------------------------------------------------------------------------------------------
Over 1:1 Wicket 	12 Runs  	 	 		| Bowler 1: 	2.0	       1	    30	    15
Over 2:0 Wicket 	7 Runs  	 	 		| Bowler 2: 	2.0	       1	    20	    10
Over 3:0 Wicket 	15 Runs  	 	 		| Bowler 3: 	2.0	       3	    19	    9.5
Over 4:0 Wicket 	17 Runs  	 	 		| Bowler 4: 	2.0	       1	    24	    12
Over 5:1 Wicket 	14 Runs  	 	 		| Bowler 5: 	2.0	       1	    23    	11.5
Over 6:0 Wicket 	18 Runs 
Over 7:1 Wicket 	13 Runs 
Over 8:3 Wicket 	4 Runs 
Over 9:1 Wicket 	7 Runs 
Over 10:0 Wicket 	9 Runs 
-----------------------------------------------------------------------------------------------------------------------
Total wickets taken = 7
-----------------------------------------------------------------------------------------------------------------------

 CSK Won the match by 14Runs.
MAN OF THE MATCH: CSK BOWLER 3( 3 WICKETS in 2 overs at 9.5 economy rate)

```

---

## File Structure
- **`cricket_score_sheet.cpp`**: The main source code file containing the program logic.
- **`cric.dat`**: Binary file used to store match data.

---

## Note
1. **Randomization**:
   - The program uses random numbers to simulate match outcomes. Results may vary each time the program is run.
   
2. **Binary File**:
   - Ensure that `cric.dat` is not manually modified, as it may corrupt the stored data.
     

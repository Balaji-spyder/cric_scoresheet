#include<iostream>

#include<fstream>

#include<experimental/random>

#include<stdlib.h>

using namespace std;
class team {
  char hout[3][10] = {
    "CAUGHT\0",
    "BOWLED\0",
    "NA\0"
  };
  int h12[11], h22[11], a[10][6], b[10][6];
  int hg, hg1, count1 = 0, count = 0, ba = 0, h = 0, h1 = 0;
  char tims[10];
  float eco[5], eco1[5];
  int oc[10], oc1[10];
  int four = 0, sqx = 0, four1 = 0, sx1 = 0;
  int s1[11][6], s2[11][6];
  int ro[11], ro1[11], bat[11], bat1[11];
  int ex = 0, ex1 = 0, nb1 = 0, w1 = 0, tot = 0, nb, w, tot1 = 0;
  int bowl1[5][2], bowl2[5][2], ovb[10], over[10], ovb1[10], over1[10];
  string tos, dos;
  public:
    string team1, team2;
  string ven, le;
  int t, n;
  /*Getting the match details*/
  void get() {
    cout << "Enter the league name:";
    cin >> le;
    cout << "ENter the match no:";
    cin >> n;
    cout << "Enter the Team names:";
    cin >> team1 >> team2;
    cout << "ENter the start time(in 24hour format):";
    cin >> tims;
    cout << "Enter the Venue name:";
    cin >> ven;
    /*USing random function producing the random toss(heads or tails). In default,if
    team1 tosses and wins the toss he chose bat same when team2 wins the toss
    he chose to bat*/
    t = experimental::randint(0, 1);
    if (t == 0) {
      tos = team1;
      dos = team2;
    } else {
      tos = team2;
      dos = team1;
    }
  }
  /*calculating the score of each section is done using calc() function*/
  void calc() {
    /*Assigning random numbers in between range to genrate the no
    ball and wides in a innings*/
    nb = experimental::randint(0, 3);
    w = experimental::randint(0, 7);
    ex = nb + w;
    nb1 = experimental::randint(0, 3);
    w1 = experimental::randint(0, 7);
    ex1 = nb1 + w1;
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 2; j++) {
        bowl1[i][j] = 0;
        bowl2[i][j] = 0;
      }
    }
    for (int j = 0; j < 10; j++) {
      ovb[j] = 0;
      over[j] = 0;
      ovb1[j] = 0, over1[j] = 0;
    }
    for (int i = 0; i < 11; i++) {
      oc[i] = 0;
      ro[i] = 0;
      bat[i] = 0;
      h12[i] = 2;
      h22[i] = 2;
    }
    for (int i = 0; i < 11; i++) {
      for (int j = 0; j < 6; j++) {
        if (i < 10) {
          a[i][j] = 0;
        }
        s1[i][j] = 0;
      }
    }
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 6; j++) {
        ovb[i]++;
        a[i][j] = experimental::randint(0, 7);
        //random generation of runs per ball
        if (a[i][j] == 5) {
          a[i][j] = 1;
        }
        if (a[i][j] == 1) {
          s1[ba][0]++;
        }
        if (a[i][j] == 2) {
          s1[ba][1]++;
        }
        if (a[i][j] == 3) {
          s1[ba][2]++;
        }
        if (a[i][j] == 4) {
          s1[ba][3]++;
        }
        if (a[i][j] == 6) {
          s1[ba][4]++;
        }
        ro[i] += a[i][j];
        bat[ba] += a[i][j];
        if (a[i][j] == 7) { //7 is out
          bat[ba] -= 7;
          ba++;
          count++;
          oc[i]++;
          tot -= 7;
          ro[i] -= 7;
          h12[ba] = experimental::randint(0, 1);
        }
        if (count == 10) {
          break;
        }
        tot += a[i][j];
      }
      if (count == 10) {
        break;
      }
    }
    tot += ex;
    ba = 0;
    for (int i = 0; i < 5; i++) {
      bowl1[i][0] = ro[i] + ro[i + 5];
      eco[i] = float(bowl1[i][0]) / 2.0;
      bowl1[i][1] = oc[i] + oc[i + 5];
    }
    for (int i = 0; i < 11; i++) {
      oc1[i] = 0;
      ro1[i] = 0;
      bat1[i] = 0;
    }
    for (int i = 0; i < 11; i++) {
      for (int j = 0; j < 6; j++) {
        if (i < 10) {
          b[i][j] = 0;
        }
        s2[i][j] = 0;
      }
    }
    tot1 += ex1;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 6; j++) {
        ovb1[i]++;
        b[i][j] = experimental::randint(0, 7);
        if (b[i][j] == 5) {
          b[i][j] = 1;
        }
        if (b[i][j] == 1) {
          s2[ba][0]++;
        }
        if (b[i][j] == 2) {
          s2[ba][1]++;
        }
        if (b[i][j] == 3) {
          s2[ba][2]++;
        }
        if (b[i][j] == 4) {
          s2[ba][3]++;
        }
        if (b[i][j] == 6) {
          s2[ba][4]++;
        }
        ro1[i] += b[i][j];
        bat1[ba] += b[i][j];
        if (b[i][j] == 7) {
          bat1[ba] -= 7;
          ba++;
          count1++;
          oc1[i]++;
          tot1 -= 7;
          ro1[i] -= 7;
          h22[ba] = experimental::randint(0, 1);
        }
        if (count1 == 10) {
          break;
        }
        tot1 += b[i][j];
        if (tot1 >= tot + 1) {
          break;
        }
      }
      if (count1 == 10) {
        break;
      }
      if (tot1 >= tot + 1) {
        break;
      }
    }
    hg = bowl1[0][1];
    hg1 = bat1[0];
    h12[0] = 1;
    h22[0] = 0;
    h12[count] = 2;
    h22[count1] = 2;
    int r, q, r1, q1;
    for (int i = 0; i < 5; i++) {
      ovb[i] = ovb[i] + ovb[i + 5];
      ovb1[i] = ovb1[i] + ovb1[i + 5];
      bowl2[i][0] = ro1[i] + ro1[i + 5];
      eco1[i] = float(bowl2[i][0]) / 2.0;
      bowl2[i][1] = oc1[i] + oc1[i + 5];
      if (ovb[i] / 6 == 0) {
        r = ovb[i] % 6;
        over[i] += r;
      } else if (ovb1[i] / 6 == 0) {
        r = ovb1[i] % 6;
        over1[i] += r;
      }
      if (ovb[i] > 6) {
        r = ovb[i] % 6;
        q = ovb[i] / 6;
        over[i] += q;
        ovb[i] = r;
      }
      if (ovb1[i] > 6) {
        r1 = ovb1[i] % 6;
        q1 = ovb1[i] / 6;
        over1[i] += q1;
        ovb1[i] = r1;
      }
    }
  }
  /*clr() helps to clear the values and brings them to 0 after the write
  operation is over*/
  void clr() {
    tot = 0;
    tot1 = 0;
    count = 0;
    count1 = 0;
  }
  /*display helps to print all the scoresheet details in detailed manner*/
  void display() {

    cout << "\t\t\t\t \t\t\tCricket score sheet." << endl;
    cout << "LEAGUE: " << le << endl;
    cout << "MATCH NO: " << n << endl;
    cout << "MATCH: " << team1 << " VS " << team2 << endl;
    cout << "START TIME: " << tims << endl;
    cout << "Toss won be " << tos << " And elected to bat first" << endl;
    cout << "VENUE: " << ven << endl;
    cout << "1st Innings" << endl;
    cout << "BATTING:" << tos << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "OVERS" << "\t\t\t" << " \t \t \t\t| Batsman \t1's\t 2's\t 3's\t 4's\t 6's \tRuns \t HOW OUT" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < 11; i++) {
      if (i < 10) {
        cout << "Over " << i + 1 << ":";
        for (int j = 0; j < 6; j++) {
          if (a[i][j] == 7) {
            cout << "W" << '\t';
          } else {
            cout << a[i][j] << '\t';
          }
        }
      }
      if (i == 10) {
        cout << "\t\t\t\t\t\t\t";
      }
      four += s1[i][3];
      sqx += s1[i][4];
      if (tos == team1) {
        cout << "| " << "BATSMAN " << i + 1 << ": \t" << s1[i][0] << '\t' << s1[i][1] << '\t' << s1[i][2] << '\t' << s1[i][3] << '\t' << s1[i][4] << "\t" << bat[i] << " Runs\t" << hout[h12[i]] << endl;
      } else {
        cout << "| " << "BATSMAN " << i + 1 << ": \t" << s1[i][0] << '\t' << s1[i][1] << '\t' << s1[i][2] << '\t' << s1[i][3] << '\t' << s1[i][4] << "\t" << bat[i] << " Runs\t" << hout[h12[i]] << endl;
      }
    }
    cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Extras = " << ex << "(" << w << " w," << nb << " nb)" << "\t \t \t \t \t \t \t \t \t" << "Total runs scored = " << tot << "( " << four << "-4's," << sqx << "-6's )" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "BOWLING:" << dos << " \t \t\t\t\t \t\t| Bowler \tOvers\tWicket\t RUNS \t ECONOMY" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < 10; i++) {
      cout << "Over " << i + 1 << ":" << oc[i] << " Wicket \t" << ro[i] << " Runs ";
      if (i < 5) {
        cout << " \t \t \t\t| Bowler " << i + 1 << ": \t" << over[i] << '.' << ovb[i] << "\t " << bowl1[i][1] << "\t" << bowl1[i][0] << "\t" << eco[i] << endl;
      } else {
        cout << endl;
      }
    }
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Total wickets taken = " << count << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << dos << " required " << tot + 1 << " runs to the win the match in 60 Balls." << endl;
    cout << endl;
    cout << "2nd Innings" << endl;
    cout << "BATTING: " << dos << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "OVERS" << "\t\t\t" << " \t \t \t\t| Batsman \t1's\t 2's\t 3's\t4's\t 6's \tRuns\t HOW OUT" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < 11; i++) {
      if (i < 10) {
        cout << "Over " << i + 1 << ":";
        for (int j = 0; j < 6; j++) {
          if (b[i][j] == 7) {
            cout << "W" << '\t';
          } else {
            cout << b[i][j] << '\t';
          }
        }
        if (i < 5) {
          if (bowl2[i][1] >= hg) {
            if (eco1[i] < eco1[h]) {
              hg = bowl2[i][1];
              h = i;
            }
          }
        }
        if (bat1[i] > hg1) {
          hg1 = bat1[i];
          h1 = i;
        }
      }
      if (i == 10) {
        cout << "\t\t\t\t\t\t\t";
      }
      four1 += s2[i][3];
      sx1 += s2[i][4];
      if (dos == team1) {
        cout << "| " << "BATSMAN" << i + 1 << ": \t" << s2[i][0] << '\t' << s2[i][1] << '\t' << s2[i][2] << '\t' << s2[i][3] << '\t' << s2[i][4] << "\t" << bat1[i] << " Runs\t" << hout[h22[i]] << endl;
      } else {
        cout << "| " << "BATSMAN " << i + 1 << ": \t" << s2[i][0] << '\t' << s2[i][1] << '\t' << s2[i][2] << '\t' << s2[i][3] << '\t' << s2[i][4] << "\t" << bat1[i] << " Runs\t" << hout[h22[i]] << endl;
      }
    }
    cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Extras = " << ex1 << "(" << w1 << " w," << nb1 << " nb)" << "\t\t \t \t \t \t \t \t \t" << "Total runs scored = " << tot1 << "( " << four1 << "-4's," << sx1 << "-6's )" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "BOWLING:" << tos << " \t \t\t\t\t \t\t| Bowler \tOvers\tWicket\t RUNS \t ECONOMY" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < 10; i++) {
      cout << "Over " << i + 1 << ":" << oc1[i] << " Wicket \t" << ro1[i] << " Runs ";
      if (i < 5) {
        cout << " \t \t \t\t| Bowler " << i + 1 << ": \t" << over1[i] << '.' << ovb1[i] << "\t " << bowl2[i][1] << "\t" << bowl2[i][0] << "\t" << eco1[i] << endl;
      } else {
        cout << endl;
      }
    }
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Total wickets taken = " << count1 << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    if (tot1 >= tot + 1) {
      cout << "\n " << dos << " Won the match by " << 10 - count1 << " wickets." << endl;
      cout << "MAN OF THE MATCH: " << dos << " BATSMAN " << h1 + 1 << "(scored " << hg1 << " runs)" << endl;
    } else {
      cout << "\n " << tos << " Won the match by " << tot - tot1 << "Runs." << endl;
      cout << "MAN OF THE MATCH: " << tos << " BOWLER " << h + 1 << "( " << hg << " WICKETS in 2 overs at " << eco1[h] << " economy rate)" << endl;
    }
    cout << endl;
  }
};

int main() {
  int ch,da = 1;
  do {
    cout << "******************************Cricket scoresheet generator*************************************" << endl;
    cout << "OPTIONS:" << endl;
    cout << "1)Create a new cricket scoresheet." << endl;
    cout << "2)Display all the cricket scoresheet." << endl;
    cout << "3)Search a specific cricket scoresheet." << endl;
    cout << "4)exit" << endl;
    cout << "Enter your choice:";
    cin >> ch;
    ifstream in ("cric.dat", ios::binary);
    switch (ch) {
    case 1: {
      team t;
      ofstream out("cric.dat", ios::app);
      if (!out) {
        cout << "Cannot open file." << endl;
        return 1;
      }
      t.get();
      t.calc();
      out.write((char * ) & t, sizeof(t));
      t.clr();
      out.close();
      cout << "\n **************************Created a scoresheet successfully********************** " << endl;
      break;
    }
    case 2: {
      team t;
      if (!in) {
        cout << "Can't open file.";
        return 1;
      }
      while (1) {
        in.read((char * ) & t, sizeof(t));
        if (in.eof()) {
          break;
        }
        t.display();
      }
      in.close();
      break;
    }
    case 3: {
      team t;
      int ca;
      if (!in) {
        cout << "Can't open file.";
        return 1;
      }
      cout << "SEARCH BY:" << endl;
      cout << "1)Team name \n2)League \n3)Match no\n";
      cout << "Enter the choice:";
      cin >> ca;
      if (ca == 1) {
        string t11;
        cout << "Enter the team name to be searched:";
        cin >> t11;
        while (1) {
          in.read((char * ) & t, sizeof(t));
          if (in.eof()) {
            break;
          }
          if (t.team1 == t11 || t.team2 == t11) {
            t.display();
          }
        }
      }
      if (ca == 2) {
        string t11;
        cout << "Enter the league name to be searched:";
        cin >> t11;
        while (1) {
          in.read((char * ) & t, sizeof(t));
          if (in.eof()) {
            break;
          }
          if (t.le == t11) {
            t.display();
          }
        }
      }
      if (ca == 3) {
        int t11;
        cout << "Enter the match no to searched:";
        cin >> t11;
        while (1) {
          in.read((char * ) & t, sizeof(t));
          if (in.eof()) {
            break;
          }
          if (t.n == t11) {
            t.display();
          }
        }
      }
      break;
    }
    case 4: {
      exit(1);
    }
    default: {
      cout << "INVALID INPUT." << endl;
    }
    }
    in.close();
    cout << "Press 1 to continue:";
    cin >> da;
  } while (da == 1);
  return 0;
}
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int alice_arrive_month=stoi(arriveAlice.substr(0,2));
        int alice_arrive_day=stoi(arriveAlice.substr(3));
        int alice_leave_month=stoi(leaveAlice.substr(0,2));
        int alice_leave_day=stoi(leaveAlice.substr(3));

        int bob_arrive_month=stoi(arriveBob.substr(0,2));
        int bob_arrive_day=stoi(arriveBob.substr(3));
        int bob_leave_month=stoi(leaveBob.substr(0,2));
        int bob_leave_day=stoi(leaveBob.substr(3));

        int month[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int prefix_month[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i=1;i<12;i++)
            prefix_month[i]+=prefix_month[i-1];

        int alice_arrive=0,alice_leave=0,bob_arrive=0,bob_leave=0;

        alice_arrive=prefix_month[alice_arrive_month-1]+alice_arrive_day-month[alice_arrive_month-1];
        alice_leave=prefix_month[alice_leave_month-1]+alice_leave_day-month[alice_leave_month-1];
        bob_arrive=prefix_month[bob_arrive_month-1]+bob_arrive_day-month[bob_arrive_month-1];
        bob_leave=prefix_month[bob_leave_month-1]+bob_leave_day-month[bob_leave_month-1];
        
        int end= min(alice_leave,bob_leave);
        int start= max(alice_arrive,bob_arrive);

        if(start>end) return 0;
        return end-start+1;
        
    }
};